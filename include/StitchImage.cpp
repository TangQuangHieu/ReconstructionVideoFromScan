#include "pch.h"
#include "StitchImage.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <future>
#include <cstring>

#include "ProcessImage.h"
#include "CintelRawImage.h"
#include "FilesystemUtils.h"
#include "KLV.h"

namespace
{
    std::mutex	printingMutex;
    bool		exceptionThrown = false;

    void waitForThreads(std::vector<std::future<void>>& myThreads)
    {
        for (auto& thread : myThreads)
            thread.get();
    }

    int usage()
    {
        using namespace std;

        cout << "Usage: ProcessImage [options] [frame.cri ...]" << endl;
        cout << endl;
        cout << "    ProcessImage reads frames from CRI files, recorded using DaVinci Resolve or CaptureImage," << endl;
        cout << "    and processes them using metadata in the CRI, writing a 16-bit RGB TIFF for each input frame." << endl;
        cout << "    When used with --input-dir <directory> it will process all CRI files in that directory to .TIFF files" << endl;
        cout << "    in the same directory. Use --output-dir to specify a different output directory." << endl;
        cout << endl;
        cout << "    [frame.cri ...]               Specify individual CRI files instead of an input directory" << endl;
        cout << "    -i, --input-dir <directory>   Input directory to read CRI files from" << endl;
        cout << "    -o, --output-dir <directory>  Output directory to write processed images as 16-bit RGB TIFF files" << endl;
        cout << "    --hdr                         Combine high and low exposure frames into a single high dynamic range image" << endl;
        cout << endl;
        cout << "    -d, --dump-metadata           Dump metadata from CRI file without processing" << endl;
        cout << "    -u, --save-uncompressed-cri   Convert a CRI with compressed frame data to uncompressed CRI without processing" << endl;
        cout << "    -r, --save-raw                Extract uncompressed raw image data from CRI file and save as 16-bit Grayscale TIFF without processing" << endl;
        cout << "        --save-raw-data           Extract uncompressed raw image data from CRI file and save as .raw without processing" << endl;
        cout << "        --save-raw-rgb-data       Extract uncompressed raw image data from CRI file and save as .raw with processing" << endl;
        cout << "    -q, --quiet                   Disable verbose logging" << endl;
        cout << endl;

        return 1;
    }
}

StitchImage::StitchImage()
{
}

StitchImage::~StitchImage()
{
    cv::destroyAllWindows();
    cv::waitKey(1);
}

cv::Mat StitchImage::RectifyBlackBorder(cv::Mat Image, const std::string& strImagOutName)
{
    const int threshVal = 20;
    const float borderThresh = 0.05f; // 5%

    //cv::Mat img = cv::imread("..\\data\\Cintel_2021-10-29_1008_C0031_00086408.tiff");
    //cv::namedWindow("source", 0);
    //cv::imshow("source", img);
    cv::Mat imgGray; cv::cvtColor(Image, imgGray, cv::COLOR_BGR2GRAY);
    cv::Mat thresholded;
    cv::threshold(imgGray, thresholded, threshVal, 255, cv::THRESH_BINARY);
    cv::morphologyEx(thresholded, thresholded, cv::MORPH_CLOSE,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)),
        cv::Point(-1, -1), 2, cv::BORDER_CONSTANT, cv::Scalar(0));
    //cv::namedWindow("thresholded", 0);
    //cv::imshow("thresholded", thresholded);

    cv::Point tl, br;

    for (int row = 0; row < thresholded.rows; row++)
    {
        if (cv::countNonZero(thresholded.row(row)) > borderThresh * thresholded.cols)
        {
            tl.y = row;
            break;
        }
    }

    for (int col = 0; col < thresholded.cols; col++)
    {
        if (cv::countNonZero(thresholded.col(col)) > borderThresh * thresholded.rows)
        {
            tl.x = col;
            break;
        }
    }

    for (int row = thresholded.rows - 1; row >= 0; row--)
    {
        if (cv::countNonZero(thresholded.row(row)) > borderThresh * thresholded.cols)
        {
            br.y = row;
            break;
        }
    }

    for (int col = thresholded.cols - 1; col >= 0; col--)
    {
        if (cv::countNonZero(thresholded.col(col)) > borderThresh * thresholded.rows)
        {
            br.x = col;
            break;
        }
    }
    //last step: just rop one row and one col each dimension to make sure there is no shadow effect (not black border but not 
    // image content either)
    tl += cv::Point(1, 1);
    br -= cv::Point(1, 1);
    cv::Rect roi(tl, br);
    cv::Mat cropped(cv::Size(roi.width,roi.height),CV_8UC3); 
    Image(roi).copyTo(cropped);
    //cv::namedWindow("cropped", 0);
    //cv::imshow("cropped", cropped);
    if (strImagOutName.size() > 0)
    {
        cv::imwrite(m_strImagePath+"\\"+strImagOutName, cropped);
        cv::waitKey(1);
    }
    return cropped;
}

cv::Mat StitchImage::RectifyDeepBlueColumns(cv::Mat inputImage, const std::string& strImagOutName)
{
    const float borderThresh = 0.7f; // 5%
    cv::Mat imgGray; cv::cvtColor(inputImage, imgGray, cv::COLOR_BGR2GRAY);
    cv::Mat thresholdedLow;
    cv::Mat thresholdedHigh;
    cv::Mat thresholded;
    cv::threshold(imgGray, thresholdedLow, 40, 255, cv::THRESH_BINARY);
    cv::threshold(imgGray, thresholdedHigh, 60, 255, cv::THRESH_BINARY_INV);
    cv::absdiff(thresholdedLow, thresholdedHigh, thresholded);
    cv::threshold(thresholded, thresholded, 20, 255, cv::THRESH_BINARY_INV);
    cv::morphologyEx(thresholded, thresholded, cv::MORPH_CLOSE,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)),
        cv::Point(-1, -1), 2, cv::BORDER_CONSTANT, cv::Scalar(0));
    //cv::namedWindow("thresholded", 0);
    //cv::imshow("thresholded", thresholded);
    cv::Point tl, br;
    tl.y = 0; tl.x = 0; br.y = inputImage.rows - 1; br.x = inputImage.cols - 1;
    //for (int row = 0; row < thresholded.rows; row++)
    //{
    //    if (cv::countNonZero(thresholded.row(row)) > borderThresh * thresholded.cols)
    //    {
    //        tl.y = row;
    //        break;
    //    }
    //}

    for (int col = 0; col < thresholded.cols; col++)
    {
        if (cv::countNonZero(thresholded.col(col)) > borderThresh * thresholded.rows)
        {
            if (col < thresholded.cols / 2)
            {
                tl.x = col;
            }
            else
            {
                br.x = col; break;
            }
            //break;
        }
    }

    cv::Rect roi(tl, br);
    cv::Mat cropped(cv::Size(roi.width, roi.height), CV_8UC3);
    inputImage(roi).copyTo(cropped);
    ////cv::namedWindow("cropped", 0);
    ////cv::imshow("cropped", cropped);
    if (strImagOutName.size() > 0)
    {
        cv::imwrite(m_strImagePath + "\\" + strImagOutName, cropped);
        cv::waitKey(1);
    }
    return cropped;
    //return cv::Mat();
}

bool StitchImage::DetectNewFrame(cv::Mat inputImage, bool bShow , int deltaFrame, int deltaY)
{
    const float borderThresh = 0.7f; // 5%
    cv::Mat imgGray; cv::cvtColor(inputImage, imgGray, cv::COLOR_BGR2GRAY);
    cv::Mat thresholdedLow;
    cv::Mat thresholdedHigh;
    cv::Mat thresholded;
    cv::threshold(imgGray, thresholdedLow, 40, 255, cv::THRESH_BINARY);
    cv::threshold(imgGray, thresholdedHigh, 60, 255, cv::THRESH_BINARY_INV);
    cv::absdiff(thresholdedLow, thresholdedHigh, thresholded);
    cv::threshold(thresholded, thresholded, 20, 255, cv::THRESH_BINARY_INV);
    cv::morphologyEx(thresholded, thresholded, cv::MORPH_CLOSE,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)),
        cv::Point(-1, -1), 2, cv::BORDER_CONSTANT, cv::Scalar(0));

    bool bFoundUp = false;
    bool bFoundDown = false;
    bool bFound = false;
    int yUp = thresholded.rows - 1;
    int yDown = 0;
    int yPrevious = m_ROIYList.size() > 0 ? m_ROIYList.back() + deltaFrame : 0;
    
    for (int row = thresholded.rows-1; row > yPrevious; --row)
    {
        if (cv::countNonZero(thresholded.row(row)) > borderThresh * thresholded.cols)
        {
            if (yDown < row)
            {
                yDown = row;
                bFoundDown = true;
            }
            if (yUp > row)
            {
                yUp = row;
                bFoundUp = true;
            }
        }
    }
    if (bFoundUp && bFoundDown)
    {
        if (yDown - yUp > deltaY)
        {
            bFound = true;
        }
    }
    if (bFound) 
    {
        m_ROIYList.push_back(yUp);
        m_ROIYList.push_back(yDown);
    }
    if (bShow && bFound) 
    {
        printf(" Found new frame at (yUp,yDown)=(%d,%d)\n", yUp, yDown);

        cv::Rect roiUp(cv::Point(0,0), cv::Point(inputImage.cols,yUp));
        cv::Mat cvmFrameUp(cv::Size(roiUp.width, roiUp.height), CV_8UC3);
        inputImage(roiUp).copyTo(cvmFrameUp);
        cv::Rect roiDown(cv::Point(0, yDown), cv::Point(inputImage.cols, inputImage.rows));
        cv::Mat cvmFrameDown(cv::Size(roiDown.width, roiDown.height), CV_8UC3);
        inputImage(roiDown).copyTo(cvmFrameDown);
        cv::namedWindow("FrameUp", 0);
        cv::namedWindow("FrameDown", 0);
        cv::imshow("FrameUp", cvmFrameUp);
        cv::imshow("FrameDown", cvmFrameDown);
        cv::waitKey(0);
    }
    return bFound;
}

void StitchImage::Stitch2Images(cv::Mat imgUp, cv::Mat imgDown, bool bShow, int deltaX, int deltaY)
{
    int yShiftOptimize = -1;
    float fMinDifferent = FLT_MAX;
    int xShiftOptimize = 0;
    //int commonWidth = imgUp.cols < imgDown.cols ? imgUp.cols : imgDown.cols;
    for (int rShift = 1; rShift < deltaY ; ++rShift)
    {
        //cv::Mat cvmUpPath = imgUp(cv::Rect(0, imgUp.rows - 1 - rShift, commonWidth, rShift));
        cv::Mat cvmUpPath;
        for (int cShift = -deltaX; cShift < deltaX; ++cShift)
        {           
            cv::Mat cvmDownPath;
            if (cShift <= 0)
            {
                //shift left lower image
                int commonWidth = imgDown.cols + cShift < imgUp.cols ? imgDown.cols + cShift : imgUp.cols;
                cvmUpPath = imgUp(cv::Rect(0, imgUp.rows  - rShift, commonWidth, rShift));
                cvmDownPath = imgDown(cv::Rect(-cShift, 0, commonWidth, rShift));
            }
            else
            {
                int commonWidth = imgUp.cols - cShift < imgDown.cols ? imgUp.cols - cShift : imgDown.cols;
                cvmUpPath = imgUp(cv::Rect(cShift, imgUp.rows  - rShift, commonWidth, rShift));
                cvmDownPath = imgDown(cv::Rect(0, 0, commonWidth, rShift));
            }
            //cv::Mat cvmDownPath = imgDown(cv::Rect(0, 0, commonWidth, rShift));
            float fDiff = CompareBlockDifferent(cvmUpPath, cvmDownPath);
            if (fDiff < fMinDifferent)
            {
                fMinDifferent = fDiff;
                yShiftOptimize = rShift;
                xShiftOptimize = cShift;
            }

        }
    }
    cv::Mat imgMix(cv::Size(imgUp.cols, imgUp.rows + imgDown.rows - yShiftOptimize), CV_8UC3);
    imgUp.copyTo(imgMix(cv::Rect(0, 0, imgUp.cols, imgUp.rows)));
    if (xShiftOptimize <= 0)
    {
        //shift left
        int commonWidth = imgDown.cols + xShiftOptimize < imgUp.cols ? imgDown.cols + xShiftOptimize : imgUp.cols;
        imgDown(cv::Rect(-xShiftOptimize,0, commonWidth, imgDown.rows)).copyTo(imgMix(cv::Rect(0, imgUp.rows - yShiftOptimize , commonWidth, imgDown.rows)));

    }
    else
    {
        //shift right
        int commonWidth = imgDown.cols < imgUp.cols - xShiftOptimize ? imgDown.cols : imgUp.cols - xShiftOptimize;
        imgDown(cv::Rect(0, 0, commonWidth, imgDown.rows)).copyTo(imgMix(cv::Rect(xShiftOptimize, imgUp.rows - yShiftOptimize , commonWidth, imgDown.rows)));
    }
    std::cout << " Optmize overlap (DeltaX,Y)  = (" <<xShiftOptimize<<","<< yShiftOptimize << "); Score = " << fMinDifferent << std::endl;
    if (bShow)
    {
        cv::namedWindow("Img Up", 0);
        cv::line(imgUp, cv::Point(0, imgUp.rows - yShiftOptimize), cv::Point(imgUp.cols , imgUp.rows - yShiftOptimize), cv::Scalar(0, 0, 255), 2);
        cv::imshow("Img Up", imgUp);
        cv::namedWindow("Img Down", 0);
        cv::line(imgDown, cv::Point(0, yShiftOptimize), cv::Point(imgDown.cols , yShiftOptimize), cv::Scalar(0, 0, 255), 2);
        cv::imshow("Img Down", imgDown);
        cv::namedWindow("Img Mix", 0);
        cv::imshow("Img Mix", imgMix);
        cv::waitKey(0);
    }
    m_cvmOutImg = imgMix;
}

void StitchImage::SplitFrame(cv::Mat inputImage)
{
    int width = m_cvmOutImg.cols;
    
    for (int iSplitIdx = 0; iSplitIdx < m_ROIYList.size(); ++iSplitIdx)
    {
        if (iSplitIdx == 0)
        {
            m_cvmFrameList.push_back(m_cvmOutImg(cv::Rect(0, 0, width, m_ROIYList[iSplitIdx])));
        }
        else if (iSplitIdx == m_ROIYList.size() - 1)
        {
            m_cvmFrameList.push_back(m_cvmOutImg(cv::Rect(0, m_ROIYList[iSplitIdx], width, m_cvmOutImg.rows - m_ROIYList[iSplitIdx])));
        }
        else 
        {
            m_cvmFrameList.push_back(m_cvmOutImg(cv::Rect(0, m_ROIYList[iSplitIdx], width, m_ROIYList[iSplitIdx+1] - m_ROIYList[iSplitIdx])));
        }
    }
}

void StitchImage::WriteResult(cv::Mat inputImage, const std::string& strOutputImageName)
{
    cv::imwrite(m_strImagePath + "\\" + strOutputImageName, inputImage);
    cv::waitKey(1);
}

void StitchImage::SetImagePath(const std::string& strPath)
{
    if (!MgIsDirectoryExists(strPath.c_str()))
    {
        CreateDirectory(strPath.c_str(),NULL);
    }
    m_strImagePath = strPath;

}

void StitchImage::SetImageOutPath(const std::string& strOutPath)
{
    m_strImageOutPath = strOutPath;
}

void StitchImage::SetFirstImage(cv::Mat Img)
{
    m_cvmOutImg = Img;
}

void StitchImage::Run(const std::string& strInputPath, const std::string& strOutputPath)
{
    cv::TickMeter tm;
    tm.start();
    //1st. read image name from input path
    SetImagePath(strInputPath);
    SetImageOutPath(strOutputPath);
    m_strImageNameList.clear();
    m_cvmFrameList.clear();
    readFilenames(m_strImageNameList,strInputPath);

    //2nd. stitch all images together
    for (int iImgIdx = 0; iImgIdx < m_strImageNameList.size(); ++iImgIdx)
    {
        std::cout << "Processing image " << m_strImageNameList[iImgIdx] << std::endl;
        if (iImgIdx == 0)
        {
            m_cvmOutImg = cv::imread(m_strImageNameList[iImgIdx]);
            m_cvmOutImg = RectifyBlackBorder(m_cvmOutImg, "");
        }
        else
        {
            cv::Mat cvmImage = cv::imread(m_strImageNameList[iImgIdx]);
            cvmImage = RectifyBlackBorder(cvmImage, "");
            Stitch2Images(m_cvmOutImg, cvmImage);
        }
        //3rd. Detect new frame everytime new image is concatenated
        DetectNewFrame(m_cvmOutImg);
    }

    //4th. Rectify deep blue columns
    m_cvmOutImg = RectifyDeepBlueColumns(m_cvmOutImg, "");

    //5th. split frames from stitched image
    SplitFrame(m_cvmOutImg);

    //6th. Write Image
    for(int iFrameIdx = 0; iFrameIdx< m_cvmFrameList.size();++iFrameIdx)
    {
        std::string strFrameName = m_strImageOutPath + "\\Frame" + std::to_string(iFrameIdx) + ".tiff";
        std::cout << "Writing Frame " << strFrameName << std::endl;
        cv::imwrite(strFrameName, m_cvmFrameList[iFrameIdx]);
        cv::waitKey(1);
        //WriteResult(m_cvmFrameList[iFrameIdx], strFrameName);
    }
    std::cout << "Done!" << std::endl;
    tm.stop();
    std::cout << " Processing time for Run " << tm.getAvgTimeSec() << " sec" << std::endl;

}

int StitchImage::DecodeTiff(const std::string& strInputPath, const std::string& strOutputPath)
{
    std::string					inputDirectory = strInputPath;
    std::string					outputDirectory = strOutputPath;
    bool						verbose = true;
    bool						dumpMedata = false;
    bool						saveRawTiff = false;
    bool						saveRawData = false;
    bool						saveRawRGBData = false;
    bool						saveUncompressedCRI = false;
    bool						hdr = false;
    std::vector<std::string>	filenameArgs;

    int								processThreadsMax = (std::thread::hardware_concurrency() ? std::thread::hardware_concurrency() : 4); // Default to 4 if not supported feature
    std::vector<std::future<void>>	processThreads;
    try
    {
        // Check for misuse of command line args
        if (!inputDirectory.empty())
        {
            if (filenameArgs.size() > 0)
                throw std::runtime_error("Cannot specify -i <directory> together with individual CRI filenames");

            filenameArgs = getCRIFilesFromDirectory(inputDirectory);
            if (filenameArgs.size() == 0)
                throw std::runtime_error("No .CRI files found in directory " + inputDirectory);
        }
        else if (filenameArgs.size() == 0)
            return usage();

        if (saveUncompressedCRI && (outputDirectory.empty() || outputDirectory == inputDirectory))
        {
            throw std::runtime_error("Output directory must be specified and different to input directory when writing CRI files to avoid overwriting input CRI files");
        }

        if (!outputDirectory.empty())
            makeSingleDir(outputDirectory);

        // Process the images
        for (const auto& filename : filenameArgs)
        {
            if (dumpMedata)
            {
                if (verbose)
                    std::cout << "Metadata for: " << filename << std::endl;
                KLV::dumpMetadata(filename);
                if (verbose)
                    std::cout << std::endl;
                continue;
            }

            auto processLambda = [](std::string filename, bool hdr, bool saveRawTiff, bool verbose, bool saveRawData, bool saveUncompressedCRI, bool saveRawRGBData, std::string outputDirectory)
            {
                try
                {
                    const auto cri = CintelRawImage(filename);

                    if (saveRawTiff)
                    {
                        // Save RAW grayscale TIFFs with an extra "_raw" in their name to distinguish them from processed RGB TIFFs
                        const auto outputFile = getOutputFilename(outputDirectory, filename, "_raw.tiff");

                        ProcessImageUtil::saveGrayscaleTIFF(cri.width(), cri.height(), cri.getRawFrame().data(), outputFile.c_str());

                        if (verbose)
                        {
                            std::lock_guard<std::mutex> printingLock(printingMutex);
                            std::cout << "Saved RAW 16-bit grayscale TIFF: " << outputFile << std::endl;
                        }
                    }

                    if (saveRawData)
                    {
                        const auto outputFile = getOutputFilename(outputDirectory, filename, ".raw");

                        saveBinaryFile(outputFile, cri.getRawFrame());

                        if (verbose)
                        {
                            std::lock_guard<std::mutex> printingLock(printingMutex);
                            std::cout << "Saved Uncompressed raw image data: " << outputFile << std::endl;
                        }
                    }

                    if (saveUncompressedCRI)
                    {
                        const auto outputFile = getOutputFilename(outputDirectory, filename, ".cri");

                        cri.saveAsUncompressed(outputFile);
                        if (verbose)
                        {
                            std::lock_guard<std::mutex> printingLock(printingMutex);
                            std::cout << "Saved Uncompressed CRI: " << outputFile << std::endl;
                        }
                    }

                    if (verbose)
                    {
                        std::lock_guard<std::mutex> printingLock(printingMutex);
                        std::cout << "Processing: " << filename << std::endl;
                    }

                    // Perform the steps necessary to process RAW linear image sensor data into a color RGB image
                    ProcessImage	img(cri);

                    // Interpolate missing RGB pixels from bayer pattern image sensor data
                    // NOTE: Leaves in log gamma for stability
                    img.debayer(DebayerMethod::HighQuality);

                    // Apply the horizontal and vertical stability offsets to the whole image.
                    // NOTE: Converts back to linear gamma for continued processing so must be run after debayer
                    img.applyStabilityOffsets(StabilizerMethod::SubPixel);

                    // Combine the normal frame with the high exposure frame to improve signal to noise
                    // This must happen after debayer and stabilisation in order for frame alignment to match
                    // It must also be before any masking or downstream gains in order to have the correct
                    // color match between the high and low exposure captured frames
                    if (hdr)
                    {
                        std::string		highExposureFilename = getHDRFilename(filename);
                        // Read in the high exposure frame
                        ProcessImage	highimg(CintelRawImage(highExposureFilename.c_str()));
                        if (verbose)
                            std::cout << "Processing high exposure frame: " << highExposureFilename << std::endl;

                        // Match the processing of the normal frame to this point on the high pass frame
                        highimg.debayer(DebayerMethod::HighQuality);
                        highimg.applyStabilityOffsets(StabilizerMethod::SubPixel);

                        // Now combine the two into the original image
                        img.combineHDR(highimg);
                    }

                    // Compensate for the overlapping photosensitivity functions of each color filter in the bayer mask
                    img.linearMask();

                    // Convert linear sensor data to film log data using a log function specific to the film type
                    // and apply the log mask (a calibration specific to each Cintel scanner)
                    img.logMask();

                    // Apply a gain to each color if specified in the metadata
                    img.gains();

                    // Apply an offset to each color if specified in the metadata
                    img.lifts();

                    // Apply the blanking and image flips last
                    img.applyBlankingAndFlips();

                    std::string rgbFilename;
                    if (saveRawRGBData)
                    {
                        // Save a color RGB RAW data array
                        rgbFilename = getOutputFilename(outputDirectory, filename, ".raw");
                        saveBinaryFileRGB(rgbFilename, img.getRgbFrame());
                    }
                    else
                    {
                        // Save a color RGB TIFF
                        rgbFilename = getOutputFilename(outputDirectory, filename, ".tiff");
                        ProcessImageUtil::saveColorTIFF(cri.width(), cri.height(), ProcessImageUtil::array_vector_float_data{ img.getRgbFrame() }, rgbFilename.c_str());
                    }

                    if (verbose)
                    {
                        std::lock_guard<std::mutex> printingLock(printingMutex);
                        std::cout << "Wrote RGB:  " << rgbFilename << std::endl;
                    }
                }
                catch (const std::exception& e)
                {
                    std::lock_guard<std::mutex> printingLock(printingMutex);
                    std::cerr << e.what() << std::endl;
                    exceptionThrown = true;
                }
            };

            if (!exceptionThrown)
            {
                if (processThreads.size() >= processThreadsMax || filename == filenameArgs.back())
                {
                    // Wait for completion and cleanup
                    waitForThreads(processThreads);
                    processThreads.clear();
                }
                // Spawn a new thread to process the next image
                processThreads.push_back(std::async(std::launch::async, processLambda, filename, hdr, saveRawTiff, verbose, saveRawData, saveUncompressedCRI, saveRawRGBData, outputDirectory));
            }
            else
            {
                // An exception occurred within the processing threads, let final processors complete and then abort
                waitForThreads(processThreads);
                throw std::runtime_error("Processor threads caused an exception, exiting");
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void StitchImage::RunOptimize(const std::string& strInputPath, const std::string& strOutputPath)
{
    cv::TickMeter tm;
    tm.start();
    //1st. read image name from input path
    SetImagePath(strInputPath);
    SetImageOutPath(strOutputPath);
    m_strImageNameList.clear();
    m_cvmFrameList.clear();
    readFilenames(m_strImageNameList, strInputPath);
    if (!strOutputPath.empty() && !MgIsFileExists(strOutputPath.c_str()))
        makeSingleDir(strOutputPath);
    //2nd. stitch all images together
    for (int iImgIdx = 0; iImgIdx < m_strImageNameList.size(); ++iImgIdx)
    {
        std::cout << "Processing image " << m_strImageNameList[iImgIdx] << std::endl;
        if (iImgIdx == 0)
        {
            m_cvmOutImg = cv::imread(m_strImageNameList[iImgIdx]);
            m_cvmOutImg = RectifyBlackBorder(m_cvmOutImg, "");
        }
        else
        {
            cv::Mat cvmImage = cv::imread(m_strImageNameList[iImgIdx]);
            cvmImage = RectifyBlackBorder(cvmImage, "");
            Stitch2Images(m_cvmOutImg, cvmImage);
        }
        //3rd. Detect new frame everytime new image is concatenated
        if (DetectNewFrame(m_cvmOutImg))
        {
            //5th. split frames from stitched image
            SplitFrame(m_cvmOutImg);
            m_cvmOutImg = m_cvmFrameList.back();
            if(iImgIdx != m_strImageNameList.size()-1)
                m_cvmFrameList.erase(m_cvmFrameList.end()-1);
            m_ROIYList.clear();
        }
    }
    //4th. Rectify deep blue columns
    //m_cvmOutImg = RectifyDeepBlueColumns(m_cvmOutImg, "");

    //5th. split frames from stitched image
    //SplitFrame(m_cvmOutImg);

    //6th. Write Image
    for (int iFrameIdx = 0; iFrameIdx < m_cvmFrameList.size(); ++iFrameIdx)
    {
        m_cvmFrameList[iFrameIdx] = RectifyDeepBlueColumns(m_cvmFrameList[iFrameIdx],"");
        std::string strFrameName = m_strImageOutPath + "\\Frame" + std::to_string(iFrameIdx) + ".tiff";
        std::cout << "Writing Frame " << strFrameName << std::endl;
        cv::imwrite(strFrameName, m_cvmFrameList[iFrameIdx]);
        cv::waitKey(1);
        //WriteResult(m_cvmFrameList[iFrameIdx], strFrameName);
    }
    std::cout << "Done!" << std::endl;
    tm.stop();
    std::cout << " Processing time for RunOptimize " << tm.getAvgTimeSec() << " sec" << std::endl;
}

std::string StitchImage::GetImagePath() const
{
    return m_strImagePath;
}

std::string StitchImage::GetImageOutPath() const
{
    return m_strImageOutPath;
}

cv::Mat StitchImage::GetImageResult(bool bCopy)
{
    if (bCopy)
    {
        return m_cvmOutImg.clone();
    }
    else
        return m_cvmOutImg;
}

float StitchImage::CompareBlockDifferent(cv::Mat block1, cv::Mat block2)
{
    cv::Mat blockDiff;
    cv::absdiff(block1, block2, blockDiff);
    auto sumDiff = cv::sum(blockDiff);
    /*if (block1.rows > 30)
    {
        std::cout << " Debug here" << std::endl;
    }*/
    float fDiff = (sumDiff[0] + sumDiff[1] + sumDiff[2]) / 3. / (blockDiff.rows * blockDiff.cols);
    return fDiff;
}

void readFilenames(std::vector<std::string>& filenames, const std::string& directory)
{
#ifdef _WINDOWS
    HANDLE dir;
    WIN32_FIND_DATA file_data;

    if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
        return; /* No files found */

    do {
        const std::string file_name = file_data.cFileName;
        const std::string full_file_name = directory + "/" + file_name;
        const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

        if (file_name[0] == '.')
            continue;

        if (is_directory)
            continue;

        filenames.push_back(full_file_name);
    } while (FindNextFile(dir, &file_data));

    FindClose(dir);
#else
    DIR* dir;
    class dirent* ent;
    class stat st;

    dir = opendir(directory.c_str());
    while ((ent = readdir(dir)) != NULL) {
        const string file_name = ent->d_name;
        const string full_file_name = directory + "/" + file_name;

        if (file_name[0] == '.')
            continue;

        if (stat(full_file_name.c_str(), &st) == -1)
            continue;

        const bool is_directory = (st.st_mode & S_IFDIR) != 0;

        if (is_directory)
            continue;

        //        filenames.push_back(full_file_name); // returns full path
        filenames.push_back(file_name); // returns just filename
    }
    closedir(dir);
#endif
} // GetFilesInDirectory