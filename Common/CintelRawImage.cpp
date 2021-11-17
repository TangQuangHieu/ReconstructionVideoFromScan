/* -LICENSE-START-
** Copyright (c) 2021 Blackmagic Design
** Permission is hereby granted, free of charge, to any person or organization obtaining a copy
** of the software and accompanying documentation (the "Software") to use, reproduce,
** display, distribute, sub-license, execute, and transmit the Software, and to prepare
** derivative works of the Software, and to permit third-parties to whom the Software is
** furnished to do so, in accordance with:
**
** (1) if the Software is obtained from Blackmagic Design, the End User License Agreement for
** the Software Development Kit (“EULA”) available at
** https://downloads.blackmagicdesign.com/EULA/Cintel/Cintel-End-User-License-Agreement.pdf; or
**
** (2) if the Software is obtained from any third party, such licensing terms as notified by
** that third party,
** and all subject to the following:
**
** (3) the copyright notices in the Software and this entire statement, including the above
** license grant, this restriction and the following disclaimer, must be included in all copies
** of the Software, in whole or in part, and all derivative works of the Software, unless
** such copies or derivative works are solely in the form of machine-executable object code
** generated by a source language processor.
**
** (4) THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
** INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE
** DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT,
** TORT OR OTHERWISE,  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
** OTHER DEALINGS IN THE SOFTWARE.
**
** A copy of the Software is available free of charge at
** https://www.blackmagicdesign.com/developer/product/cintel
**
** -LICENSE-END-
*/

#include "pch.h"
#include "CintelRawImage.h"
#include "ProcessImage.h"
#include "KLV.h"
#include "KeyKode.h"
#include "TimeCode.h"
#include "ScannerAPI.h"

#include <cmath>
#include <unordered_set>
#include <algorithm>

namespace 
{
	// Macro to make calling COM API easier to read and to throw an exception on failure
	#define CHECK_API(x) { HRESULT hr; if (FAILED(hr = x)) throw std::runtime_error("API call " #x " failed: hr=" + std::to_string(hr)); }

	CintelRawImage::FilmType deckLinkFilmTypeToCRIFilmType(int64_t value)
	{
		// Map the DeckLink film type value to the CRI film type stored value
		switch (value)
		{
			case 0:		return CintelRawImage::FilmType::Negative;
			case 1:		return CintelRawImage::FilmType::Positive;
			case 2:		return CintelRawImage::FilmType::InterPositive;
			case 3:		return CintelRawImage::FilmType::InterNegative;
			default:	throw std::runtime_error("CintelRawImage: Unexpected film type " + std::to_string(value));
		}
	}

	template <size_t N, typename T, typename U>
	void convertArray(std::array<T, N>& in, std::array<U, N>& out)
	{
		for (auto it = in.cbegin(); it != in.cend(); it++)
			out[std::distance(in.cbegin(), it)] = (U)*it;
	}

	template <size_t N, typename T, typename U>
	void convertArray(std::vector<T> in, std::array<U, N>& out)
	{
		for (auto it = in.cbegin(); it != in.cend(); it++)
			out[std::distance(in.cbegin(), it)] = (U)*it;
	}
}

CintelRawImage::CintelRawImage(COMPtr<IScannerInputFrame> deckLinkVideoFrame) : 
	m_deckLinkFrame(deckLinkVideoFrame)
{
	// All integral metadata values are passed as int64_t.  Extract and convert to appropriate member types.
	int64_t					filmType;
	int64_t					filmGauge;
	int64_t					width;
	int64_t					height;
	int64_t					filmFrameRate;
	std::array<int64_t, 2>	rawKeykode;
	std::array<int64_t, 4>	tileSize;
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelFilmType,		&filmType));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelFilmGauge,	&filmGauge));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelImageWidth,	&width));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelImageHeight,	&height));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelFilmFrameRate,&filmFrameRate));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelKeykodeHigh,	&rawKeykode[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelKeykodeLow,	&rawKeykode[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelTile1Size,	&tileSize[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelTile2Size,	&tileSize[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelTile3Size,	&tileSize[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataInt(bmdScannerFrameMetadataCintelTile4Size,	&tileSize[3]));
	m_filmType = deckLinkFilmTypeToCRIFilmType(filmType);
	m_filmGauge = FilmGauge(filmGauge);
	m_width = unsigned(width);
	m_height = unsigned(height);
	m_filmFrameRate = float(filmFrameRate);
	m_keykode = Keykode(rawKeykode).toString();
	convertArray(tileSize, m_tileSize);

	// Flip horizontal flag depends on film gauge and film type
	m_flipHorizontal = m_filmGauge == FilmGauge::Gauge16mm ||
						(m_filmType == FilmType::Positive || m_filmType == FilmType::InterPositive);

	// All floating point metadata values are passed as doubles.  Extract and convert to suitable member types.
	std::array<double, 9>	linearMask;
	std::array<double, 9>	logMask;
	std::array<double, 3>	gains;
	std::array<double, 3>	lifts;
	std::array<double, 3>	hdrGains;
	double					offsetToApplyHorizontal;
	double					offsetToApplyVertical;
	double					skewToApply;
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingRedInRed,		&linearMask[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingRedInGreen,	&linearMask[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingRedInBlue,		&linearMask[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingGreenInRed,	&linearMask[3]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingGreenInGreen,	&linearMask[4]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingGreenInBlue,	&linearMask[5]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingBlueInRed,		&linearMask[6]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingBlueInGreen,	&linearMask[7]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLinearMaskingBlueInBlue,	&linearMask[8]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingRedInRed,			&logMask[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingRedInGreen,		&logMask[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingRedInBlue,		&logMask[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingGreenInRed,		&logMask[3]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingGreenInGreen,		&logMask[4]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingGreenInBlue,		&logMask[5]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingBlueInRed,		&logMask[6]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingBlueInGreen,		&logMask[7]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLogMaskingBlueInBlue,		&logMask[8]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelGainRed,					&gains[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelGainGreen,					&gains[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelGainBlue,					&gains[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLiftRed,					&lifts[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLiftGreen,					&lifts[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelLiftBlue,					&lifts[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelHDRGainRed,					&hdrGains[0]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelHDRGainGreen,				&hdrGains[1]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelHDRGainBlue,				&hdrGains[2]));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelOffsetToApplyHorizontal,	&offsetToApplyHorizontal));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelOffsetToApplyVertical,		&offsetToApplyVertical));
	CHECK_API(deckLinkVideoFrame->GetMetadataFloat(bmdScannerFrameMetadataCintelSkewToApply,				&skewToApply));
	// Convert doubles to the native CRI floating point type (32-bit float)
	convertArray(linearMask, m_linearMask);
	convertArray(logMask, m_logMask);
	convertArray(gains, m_gains);
	convertArray(lifts, m_lifts);
	convertArray(hdrGains, m_hdrGains);
	m_offsetToApplyHorizontal = float(offsetToApplyHorizontal);
	m_offsetToApplyVertical = float(offsetToApplyVertical);
	m_skewToApply = float(skewToApply);

	m_timeCodeBCD = deckLinkVideoFrame->GetTimecode();

	// Determine whether the image data is compressed
	BMDScannerDisplayMode displayMode = deckLinkVideoFrame->GetDisplayMode();
	m_isCompressed = (displayMode == bmdScannerModeCintelCompressedRAW);

	// We defer decompressing the compressed data in GetBytes() to the getRawFrame()
	// method since the user may wish to simply save it to a file with save().
}

void CintelRawImage::save(const std::string& filename) const
{
	if (! m_deckLinkFrame)
		throw std::logic_error("CintelRawImage: save currently supported only when constructed from IDeckLinkVideoFrame");

	// Create the output file
	std::ofstream	file(filename, std::ofstream::binary);

	if (! file.is_open())
		throw std::runtime_error("Could not open file: " + filename);

	writeMetadataAndFiller(file, m_isCompressed);

	// Write the video data
	void*			data;
	m_deckLinkFrame->GetBytes(&data);

	const uint8_t*	bytes = static_cast<const uint8_t*>(data);
	// Entire DeckLink frame container (not necessarily all image data)
	size_t	bufferSize;

	if (m_isCompressed)
	{
		bufferSize = m_deckLinkFrame->GetRowBytes() * m_deckLinkFrame->GetHeight();
		// Write sparsely layed out compressed tiles as one contiguous value,
		// skipping over padding bytes between tiles in the DeckLink frame container.
		KLV::write(file, KLV::FrameData, bufferSize, bytes, m_tileSize);
	}
	else
	{
		// At present all Cintel formats are 12 bit pixels, this converts to bytes only for the size of the image data
		bufferSize = (size_t)(m_width * m_height * 12 / 8);
		KLV::write(file, KLV::FrameData, bufferSize, bytes);		// write entire uncompressed buffer
	}
}

void CintelRawImage::writeMetadataAndFiller(std::ofstream& file, bool isCompressed) const
{
	const auto colorModel = isCompressed ? KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_16 : KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_12;
	KLV::write(file, KLV::Header,			KLV::HEADER_STRING);
	KLV::write(file, KLV::FrameInfo,		std::vector<uint32_t> { (uint32_t)m_width, (uint32_t)m_height, (uint32_t)colorModel, KLV::ENDIAN_LITTLE });
	KLV::write(file, KLV::CodecType,		std::vector<uint32_t> { KLV::CODEC_TYPE_NONE });
	KLV::write(file, KLV::FilmFrameRate,	std::vector<float> { m_filmFrameRate });
	KLV::write(file, KLV::TimeCode,			TimeCode(m_timeCodeBCD).toString(unsigned(std::round(m_filmFrameRate))));
	KLV::write(file, KLV::FilmType,			std::vector<uint8_t> { (uint8_t)m_filmType });
	KLV::write(file, KLV::FilmGauge,		std::vector<uint8_t> { (uint8_t)m_filmGauge });
	if (m_flipHorizontal)
		KLV::write(file, KLV::FlipHorizontal,	std::vector<uint8_t> { (uint8_t)m_flipHorizontal });
	if (m_flipVertical)
		KLV::write(file, KLV::FlipVertical,		std::vector<uint8_t> { (uint8_t)m_flipVertical });
	KLV::write(file, KLV::LinearMask,		std::vector<float> { m_linearMask.begin(), m_linearMask.end() });
	KLV::write(file, KLV::LogMask,			std::vector<float> { m_logMask.begin(), m_logMask.end() });
	KLV::write(file, KLV::OffsetToApplyH,	std::vector<float> { m_offsetToApplyHorizontal });
	KLV::write(file, KLV::OffsetToApplyV,	std::vector<float> { m_offsetToApplyVertical });
	KLV::write(file, KLV::SkewToApply,		std::vector<float> { m_skewToApply });
	if (isCompressed)
	{
		KLV::write(file, KLV::CodecName,	KLV::COMPRESSED_CODEC_NAME);
		KLV::write(file, KLV::TileSizes,	std::vector<int64_t> { m_tileSize.begin(), m_tileSize.end() });
	}
	KLV::write(file, KLV::Gains,			std::vector<float> { m_gains.begin(), m_gains.end() });
	KLV::write(file, KLV::Lifts,			std::vector<float> { m_lifts.begin(), m_lifts.end() });
	KLV::write(file, KLV::HDRGains,			std::vector<float> { m_hdrGains.begin(), m_hdrGains.end() });
	if (! m_keykode.empty())
		KLV::write(file, KLV::Keykode,		m_keykode);

	// Use Filler field to pad to next 8kB boundary for performance compatibility with DaVinci Resolve
	const size_t currentSize = (size_t)file.tellp();
	const size_t next8KBoundary = ((currentSize + 8192 - 1) / 8192) * 8192;
	const size_t sizeOfKL = sizeof(uint32_t) * 2;
	KLV::write(file, KLV::Filler, std::vector<uint8_t>(next8KBoundary - currentSize - sizeOfKL - sizeOfKL, 0));
}

void CintelRawImage::saveAsUncompressed(const std::string& filename) const
{
	// Create the output file
	std::ofstream	file(filename, std::ofstream::binary);

	if (! file.is_open())
		throw std::runtime_error("Could not open file: " + filename);

	writeMetadataAndFiller(file, /* isCompressed= */ false);

	const auto packed = ProcessImageUtil::pack16BitUnpackedFrame(ProcessImageUtil::vector_uint16_t_data { getRawFrame() });

	KLV::write(file, KLV::FrameData, packed.size() * sizeof(uint8_t), packed.data());
}

std::vector<uint16_t> CintelRawImage::getRawFrame() const
{
	if (m_rawFrame.size() > 0)
		return m_rawFrame;

	if (! m_deckLinkFrame)
		throw std::logic_error("getRawFrame: empty DeckLink video frame and no frame data read from file");

	// Decompress or unpack from DeckLink frame data
	void*			data;
	m_deckLinkFrame->GetBytes(&data);

	const uint8_t*			bytes = static_cast<const uint8_t*>(data);
	const long				bufferSize = m_deckLinkFrame->GetRowBytes() * m_deckLinkFrame->GetHeight();
	std::vector<uint8_t>	compressedFrame(bytes, bytes + bufferSize);

	if (m_isCompressed)
	{
		// When transmitted in a DeckLink frame the JPEG tiles are sparsely layed out in the buffer pointed
		// to by GetBytes(). The scanner hardware always writes compressed data at these fixed offsets.
		unsigned sparseTileOffset = unsigned(bufferSize / m_tileSize.size());
		return ProcessImageUtil::decodeJPEGFrame(ProcessImageUtil::vector_uint8_t_data { compressedFrame }, m_width, m_height, ProcessImageUtil::array_uint32_t_tiles{m_tileSize}, sparseTileOffset);
	}
	else
		return ProcessImageUtil::unpack12BitPackedFrame(ProcessImageUtil::vector_uint8_t_data { compressedFrame });
}

CintelRawImage::CintelRawImage(const std::string& filename)
{
	try
	{
		std::ifstream	file(filename, std::ifstream::binary);

		if (! file.is_open())
			throw std::runtime_error("Could not open file: " + filename);

		KLV::Key	key;
		uint32_t	length;
		std::unordered_set<KLV::Key>	keysProcessed;
		std::vector<uint8_t>			compressedFrame;

		while (KLV::readKeyLength(file, key, length))
		{
			switch (key)
			{
				case KLV::Header:
				{
					const std::string header = KLV::readString(file, length);
					if (header != KLV::HEADER_STRING)
						throw std::runtime_error("Invalid header: " + header + ", expected " + KLV::HEADER_STRING);
					break;
				}
				case KLV::FrameInfo:
				{
					const auto frameInfo = KLV::readValue<uint32_t>(file, length);
					m_width = frameInfo.at(0);
					m_height = frameInfo.at(1);
					m_colorModel = KLV::ColorModel(frameInfo.at(2));
					if ((m_colorModel != KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_10) && (m_colorModel != KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_12) && (m_colorModel != KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_16))
						throw std::logic_error("Unsupported color model " + std::to_string(m_colorModel));
					if (frameInfo.at(3) != KLV::ENDIAN_LITTLE)
						throw std::runtime_error("Only little endian KLV is currently supported");
					break;
				}
				case KLV::CodecType:
				{
					const auto value = KLV::readValue<uint8_t>(file, length);
					if (value.at(0) != KLV::CODEC_TYPE_NONE)
						throw std::runtime_error("Only codec type none is currently supported");
					break;
				}
				case KLV::CodecName:
				{
					const auto value = KLV::readString(file, length);
					m_isCompressed = (value == KLV::COMPRESSED_CODEC_NAME);
					break;
				}
				case KLV::FrameData:
				{
					compressedFrame = KLV::readValue<uint8_t>(file, length);
					break;
				}
				case KLV::FlipHorizontal:
				{
					m_flipHorizontal = KLV::readValue<uint8_t>(file, length).at(0) != 0;
					break;
				}
				case KLV::FlipVertical:
				{
					m_flipVertical = KLV::readValue<uint8_t>(file, length).at(0) != 0;
					break;
				}
				case KLV::FilmFrameRate:
				{
					m_filmFrameRate = KLV::readValue<float>(file, length).at(0);
					break;
				}
				case KLV::FilmType:
				{
					uint8_t value = KLV::readValue<uint8_t>(file, length).at(0);
					if (value > uint8_t(FilmType::InterNegative))
						throw std::runtime_error("Unknown film type: " + std::to_string(value));
					m_filmType = FilmType(value);
					break;
				}
				case KLV::LinearMask:
				{
					const auto linearMask = KLV::readValue<float>(file, length);
					std::copy(linearMask.begin(), linearMask.end(), m_linearMask.begin());
					break;
				}
				case KLV::TimeCode:
				{
					m_timeCodeBCD = TimeCode(KLV::readString(file, length)).toBCD();
					break;
				}
				case KLV::FilmGauge:
				{
					uint8_t value = KLV::readValue<uint8_t>(file, length).at(0);
					if (value > uint8_t(FilmGauge::Gauge35mm4Perf))
						throw std::runtime_error("Unknown film gauge: " + std::to_string(value));
					m_filmGauge = FilmGauge(value);
					break;
				}
				case KLV::LogMask:
				{
					const auto logMask = KLV::readValue<float>(file, length);
					std::copy(logMask.begin(), logMask.end(), m_logMask.begin());
					break;
				}
				case KLV::OffsetDetectedH:
				{
					// Legacy CRI files have this integer offset field instead of the floating point OffsetToApplyH field
					m_offsetToApplyHorizontal = float(KLV::readValue<int16_t>(file, length).at(0));
					break;
				}
				case KLV::OffsetDetectedV:
				{
					// Legacy CRI files have this integer offset field instead of the floating point OffsetToApplyV field
					m_offsetToApplyVertical = float(KLV::readValue<int16_t>(file, length).at(0));
					break;
				}
				case KLV::Keykode:
				{
					m_keykode = KLV::readString(file, length);
					break;
				}
				case KLV::TileSizes:
				{
					const auto tileSize = KLV::readValue<int64_t>(file, length);
					convertArray(tileSize, m_tileSize);
					break;
				}
				case KLV::Gains:
				{
					const auto gains = KLV::readValue<float>(file, length);
					std::copy(gains.begin(), gains.end(), m_gains.begin());
					break;
				}
				case KLV::Lifts:
				{
					const auto lifts = KLV::readValue<float>(file, length);
					std::copy(lifts.begin(), lifts.end(), m_lifts.begin());
					break;
				}
				case KLV::HDRGains:
				{
					const auto hdrGains = KLV::readValue<float>(file, length);
					std::copy(hdrGains.begin(), hdrGains.end(), m_hdrGains.begin());
					break;
				}
				case KLV::OffsetToApplyH:
				{
					m_offsetToApplyHorizontal = KLV::readValue<float>(file, length).at(0);
					break;
				}
				case KLV::OffsetToApplyV:
				{
					m_offsetToApplyVertical = KLV::readValue<float>(file, length).at(0);
					break;
				}
				case KLV::SkewToApply:
				{
					m_skewToApply = KLV::readValue<float>(file, length).at(0);
					break;
				}
				case KLV::Filler:
				default:
					// Skip over Filler and to be forward compatible skip over KLVs we don't recognise
					file.seekg(length, std::ios::cur);
					continue;
			}

			keysProcessed.insert(key);
		}

		// The minimum required fields for the earliest CRI files. Other fields have sensible defaults.
		for (const auto k : {	KLV::Header, KLV::FrameInfo, KLV::FilmType, KLV::FilmGauge, KLV::FilmFrameRate,
								KLV::LinearMask, KLV::LogMask, KLV::FrameData })
		{
			if (keysProcessed.find(k) == keysProcessed.end())
				throw std::runtime_error("Did not read required keys");
		}

		if (m_isCompressed)
		{
			if (std::find(m_tileSize.begin(), m_tileSize.end(), 0U) != m_tileSize.end())
				throw std::runtime_error("Tile sizes must be non-zero for compressed data");
			m_rawFrame = ProcessImageUtil::decodeJPEGFrame(ProcessImageUtil::vector_uint8_t_data { compressedFrame }, m_width, m_height, ProcessImageUtil::array_uint32_t_tiles { m_tileSize });
		}
		else if (m_colorModel != KLV::COLOR_MODEL_BAYER_GRGR_CINTEL_10)
			m_rawFrame = ProcessImageUtil::unpack12BitPackedFrame(ProcessImageUtil::vector_uint8_t_data { compressedFrame });
		else
			m_rawFrame = ProcessImageUtil::unpackCintelVideoFrame12BitLegacyPacking(ProcessImageUtil::vector_uint8_t_data { compressedFrame }, m_width, m_height);
	}
	catch (const std::exception& e)
	{
		// Rethrow prepending the filename so caller can see which file failed
		throw std::runtime_error(filename + ": " + e.what());
	}
}
