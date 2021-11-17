#pragma once
#include "utilities.h"
void readFilenames(std::vector<std::string>& filenames, const std::string& directory);
	inline CString MgGetModuleFileName()
	{
		TCHAR buff[256];
		GetModuleFileName(NULL, buff, sizeof(buff));
		return buff;
	}
	inline CString MgGetFileExt(LPCTSTR pszFullPath)
	{
		TCHAR ext[_MAX_EXT];
		_tsplitpath(pszFullPath, NULL, NULL, NULL, ext);
		return ext;
	}
	inline BOOL MgIsDirectoryExists(LPCTSTR szDirPath)
	{
		BOOL isExists = FALSE;
		DWORD dwAttr = GetFileAttributes(szDirPath);
		//if ((dwAttr != 0xFFFFFFFFUL) && (dwAttr&FILE_ATTRIBUTE_DIRECTORY))
		if ((dwAttr != (DWORD)-1) && (dwAttr & FILE_ATTRIBUTE_DIRECTORY))
			isExists = TRUE;

		return isExists;
	}
	inline CString MgFormatString(LPCTSTR szFormat, ...)
	{
		TCHAR buffer[4096];
		va_list args;
		va_start(args, szFormat);
		_vstprintf(buffer, szFormat, args); //wvsprintf
		va_end(args);
		return CString(buffer);
	}
	inline FILETIME MgFileTime(unsigned __int64 ft64)
	{
		FILETIME ft = { ft64 & 0xFFFFFFFF, ft64 >> 32 };
		return ft;
	}
	inline CString MgGetFileName(LPCTSTR pszFullPath)
	{
		TCHAR fileTitle[_MAX_FNAME];
		TCHAR ext[_MAX_EXT];
		_tsplitpath(pszFullPath, NULL, NULL, fileTitle, ext);
		CString fileName = fileTitle;
		fileName += ext;
		return fileName;
	}

	inline CString MgGetModuleFileDirectory()
	{
		TCHAR CurDir[_MAX_PATH] = { 0, };
		int index = ::GetModuleFileName(NULL, CurDir, sizeof(CurDir));
		index++;
		while (CurDir[--index] != '\\') {
			CurDir[index] = 0x00;
		}
		CurDir[index] = 0x00;
		return CString(CurDir);
	}

	inline CString MgGetFileTitle(LPCTSTR pszFullPath)
	{
		TCHAR fileTitle[_MAX_FNAME];
		_tsplitpath(pszFullPath, NULL, NULL, fileTitle, NULL);
		return fileTitle;
	}

	inline BOOL MgIsFileExists(LPCTSTR szFilePath)
	{
		//WIN32_FIND_DATA findData;
		//HANDLE hContext = ::FindFirstFile(szFilePath, (WIN32_FIND_DATA*)&findData);
		//if (hContext == INVALID_HANDLE_VALUE) {
		//	return FALSE;
		//}
		//::FindClose(hContext);
		//return TRUE;
		DWORD dwAttr = GetFileAttributes(szFilePath);
		if (dwAttr == 0xffffffff)
			return FALSE;
		else
			return TRUE;
	}


class StitchImage
{
public:
	StitchImage();
	~StitchImage();
public:
	void WriteResult(cv::Mat inputImage, const std::string& strOutputImageName);
	void SetImagePath(const std::string& strPath);
	void SetImageOutPath(const std::string& strOutPath);
	void RunOptimize(const std::string& strInputPath, const std::string& strOutputPath);
	void Run(const std::string& strInputPath, const std::string& strOutputPath);
	std::string GetImagePath() const;
	std::string GetImageOutPath() const;
	cv::Mat GetImageResult(bool bCopy = false);
	int DecodeTiff(const std::string& strInputPath, const std::string& strOutputPath);

private:
	
	std::vector<int> m_ROIYList;//ROI Y axis point list, contain list of start and stop point in Y axis 
	//of each frame, used for cropping frame from stitched image
	
	std::string m_strImagePath;
	std::vector<std::string> m_strImageNameList;
	std::string m_strImageOutPath;
	cv::Mat m_cvmOutImg;
	std::vector<cv::Mat> m_cvmFrameList;
	//cv::Mat m_cvmFirstImg;
	cv::Mat RectifyDeepBlueColumns(cv::Mat inputImage,const std::string& strImagOutName);
	void Stitch2Images(cv::Mat imgUp, cv::Mat imgDown, bool bShow = false, int deltaX = 40, int deltaY =100);
	void SetFirstImage(cv::Mat Img);
	cv::Mat RectifyBlackBorder(cv::Mat inputImage, const std::string& strImagOutName);
	bool DetectNewFrame(cv::Mat inputImage, bool bShow = false, int deltaFrame = 300, int deltaY = 30);
	void SplitFrame(cv::Mat inputImage);
	float CompareBlockDifferent(cv::Mat block1, cv::Mat block2);	
};
