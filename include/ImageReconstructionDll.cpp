#include "pch.h"
#include "ImageReconstructionDll.h"
#include "StitchImage.h"
#include "pch.h"
#include "StitchImage.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <future>
#include <cstring>

#include "pch.h"
#include "ProcessImage.h"
#include "CintelRawImage.h"
#include "FilesystemUtils.h"
#include "KLV.h"


void ProcessFolder(const std::string& strInputPath, const std::string& strOutputPath)
{
	StitchImage m_StitchImage;
	std::string strIntermediateFolder = strOutputPath + "_Intermediate";
	m_StitchImage.DecodeTiff(strInputPath, strIntermediateFolder);
	m_StitchImage.RunOptimize(strIntermediateFolder, strOutputPath);
}
