#pragma once
#ifndef _IMAGERECONSTRUCTIONDLL
#define _IMAGERECONSTRUCTIONDLL
#include <string>
#include <vector>

#ifdef IMAGERECONSTRUCTIONDLL_EXPORT
#define IMAGERECONSTRUCTIONDLL_API __declspec(dllexport)
#else
#define IMAGERECONSTRUCTIONDLL_API __declspec(dllimport)
#endif

extern "C" IMAGERECONSTRUCTIONDLL_API void ProcessFolder(const std::string & strInputPath, const std::string & strOutputPath);

#endif