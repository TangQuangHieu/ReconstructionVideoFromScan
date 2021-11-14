#include "pch.h"
#include "StitchImage.h"

StitchImage::StitchImage()
{
}

StitchImage::~StitchImage()
{
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