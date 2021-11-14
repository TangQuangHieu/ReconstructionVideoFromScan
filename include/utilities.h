#pragma once
#include <atlstr.h>

#include "opencv2/opencv.hpp"
//#include "viDefine.h"

#ifdef _DEBUG
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)""CVAUX_STR(CV_VERSION_MINOR)""CVAUX_STR(CV_VERSION_REVISION)"d"
#else
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)""CVAUX_STR(CV_VERSION_MINOR)""CVAUX_STR(CV_VERSION_REVISION)
#endif
#pragma comment(lib, "opencv_world" OPENCV_VERSION ".lib")
#pragma message("opencv_world" OPENCV_VERSION".lib")


// you need these includes for the function
#ifdef _WINDOWS
#include <windows.h> // for windows systems
#else
#include <dirent.h> // for linux systems
#include <sys/stat.h> // for linux systems
#endif
/* Returns a list of files in a directory (except the ones that begin with a dot) */

