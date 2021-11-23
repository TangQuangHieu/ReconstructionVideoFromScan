

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ..\Win\include\ScannerAPI.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ScannerAPI_h__
#define __ScannerAPI_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScannerAPIInformation_FWD_DEFINED__
#define __IScannerAPIInformation_FWD_DEFINED__
typedef interface IScannerAPIInformation IScannerAPIInformation;

#endif 	/* __IScannerAPIInformation_FWD_DEFINED__ */


#ifndef __IScanner_FWD_DEFINED__
#define __IScanner_FWD_DEFINED__
typedef interface IScanner IScanner;

#endif 	/* __IScanner_FWD_DEFINED__ */


#ifndef __IScannerDiscovery_FWD_DEFINED__
#define __IScannerDiscovery_FWD_DEFINED__
typedef interface IScannerDiscovery IScannerDiscovery;

#endif 	/* __IScannerDiscovery_FWD_DEFINED__ */


#ifndef __IScannerInput_FWD_DEFINED__
#define __IScannerInput_FWD_DEFINED__
typedef interface IScannerInput IScannerInput;

#endif 	/* __IScannerInput_FWD_DEFINED__ */


#ifndef __IScannerInputFrame_FWD_DEFINED__
#define __IScannerInputFrame_FWD_DEFINED__
typedef interface IScannerInputFrame IScannerInputFrame;

#endif 	/* __IScannerInputFrame_FWD_DEFINED__ */


#ifndef __IScannerInputCallback_FWD_DEFINED__
#define __IScannerInputCallback_FWD_DEFINED__
typedef interface IScannerInputCallback IScannerInputCallback;

#endif 	/* __IScannerInputCallback_FWD_DEFINED__ */


#ifndef __IScannerDeviceNotificationCallback_FWD_DEFINED__
#define __IScannerDeviceNotificationCallback_FWD_DEFINED__
typedef interface IScannerDeviceNotificationCallback IScannerDeviceNotificationCallback;

#endif 	/* __IScannerDeviceNotificationCallback_FWD_DEFINED__ */


#ifndef __IScannerNotifications_FWD_DEFINED__
#define __IScannerNotifications_FWD_DEFINED__
typedef interface IScannerNotifications IScannerNotifications;

#endif 	/* __IScannerNotifications_FWD_DEFINED__ */


#ifndef __IScannerFilmConfiguration_FWD_DEFINED__
#define __IScannerFilmConfiguration_FWD_DEFINED__
typedef interface IScannerFilmConfiguration IScannerFilmConfiguration;

#endif 	/* __IScannerFilmConfiguration_FWD_DEFINED__ */


#ifndef __IScannerTransport_FWD_DEFINED__
#define __IScannerTransport_FWD_DEFINED__
typedef interface IScannerTransport IScannerTransport;

#endif 	/* __IScannerTransport_FWD_DEFINED__ */


#ifndef __IScannerColorProperties_FWD_DEFINED__
#define __IScannerColorProperties_FWD_DEFINED__
typedef interface IScannerColorProperties IScannerColorProperties;

#endif 	/* __IScannerColorProperties_FWD_DEFINED__ */


#ifndef __IScannerImageStabilizer_FWD_DEFINED__
#define __IScannerImageStabilizer_FWD_DEFINED__
typedef interface IScannerImageStabilizer IScannerImageStabilizer;

#endif 	/* __IScannerImageStabilizer_FWD_DEFINED__ */


#ifndef __IScannerCapture_FWD_DEFINED__
#define __IScannerCapture_FWD_DEFINED__
typedef interface IScannerCapture IScannerCapture;

#endif 	/* __IScannerCapture_FWD_DEFINED__ */


#ifndef __IScannerAudioSelect_FWD_DEFINED__
#define __IScannerAudioSelect_FWD_DEFINED__
typedef interface IScannerAudioSelect IScannerAudioSelect;

#endif 	/* __IScannerAudioSelect_FWD_DEFINED__ */


#ifndef __IScannerReader_FWD_DEFINED__
#define __IScannerReader_FWD_DEFINED__
typedef interface IScannerReader IScannerReader;

#endif 	/* __IScannerReader_FWD_DEFINED__ */


#ifndef __CScannerDiscovery_FWD_DEFINED__
#define __CScannerDiscovery_FWD_DEFINED__

#ifdef __cplusplus
typedef class CScannerDiscovery CScannerDiscovery;
#else
typedef struct CScannerDiscovery CScannerDiscovery;
#endif /* __cplusplus */

#endif 	/* __CScannerDiscovery_FWD_DEFINED__ */


#ifndef __CScannerAPIInformation_FWD_DEFINED__
#define __CScannerAPIInformation_FWD_DEFINED__

#ifdef __cplusplus
typedef class CScannerAPIInformation CScannerAPIInformation;
#else
typedef struct CScannerAPIInformation CScannerAPIInformation;
#endif /* __cplusplus */

#endif 	/* __CScannerAPIInformation_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ScannerAPI_LIBRARY_DEFINED__
#define __ScannerAPI_LIBRARY_DEFINED__

/* library ScannerAPI */
/* [helpstring][version][uuid] */ 

#define	DESKTOPVIDEO_MINIMUM_VERSION	( 0xc000000 )

typedef unsigned int BMDScannerTimecodeBCD;

typedef LONGLONG BMDScannerTimeValue;

typedef LONGLONG BMDScannerTimeScale;

typedef uint32_t BMDScannerFrameFlags;
typedef uint32_t BMDScannerAdvancedFlag;
#if 0
typedef enum _BMDScannerFrameFlags BMDScannerFrameFlags;

typedef enum _BMDScannerAdvancedFlag BMDScannerAdvancedFlag;

#endif
typedef /* [v1_enum] */ 
enum _BMDScannerAPIInformationID
    {
        bmdScannerAPIVersion	= 0x76657273
    } 	BMDScannerAPIInformationID;

typedef /* [v1_enum] */ 
enum _BMDScannerDisplayMode
    {
        bmdScannerModeCintelRAW	= 0x72776369,
        bmdScannerModeCintelCompressedRAW	= 0x72776363,
        bmdScannerModeUnknown	= 0x69756e6b
    } 	BMDScannerDisplayMode;

typedef /* [v1_enum] */ 
enum _BMDScannerPixelFormat
    {
        bmdScannerFormatUnspecified	= 0,
        bmdScannerFormat12BitRAWGRBG	= 0x72313270,
        bmdScannerFormat12BitRAWJPEG	= 0x72313670,
        bmdScannerFormat12BitRAWDeprecated	= 0x76323130
    } 	BMDScannerPixelFormat;

typedef /* [v1_enum] */ 
enum _BMDScannerAudioSampleRate
    {
        bmdScannerAudioSampleRate48kHz	= 48000
    } 	BMDScannerAudioSampleRate;

typedef /* [v1_enum] */ 
enum _BMDScannerAudioSampleType
    {
        bmdScannerAudioSampleType16bitInteger	= 16,
        bmdScannerAudioSampleType32bitInteger	= 32
    } 	BMDScannerAudioSampleType;

/* [v1_enum] */ 
enum _BMDScannerFrameFlags
    {
        bmdScannerFrameFlagDefault	= 0,
        bmdScannerFrameContainsCintelMetadata	= ( 1 << 2 ) ,
        bmdScannerFrameHasNoInputSource	= ( 1 << 31 ) 
    } ;
typedef /* [v1_enum] */ 
enum _BMDScannerTransportCommand
    {
        bmdScannerCommandStop	= 0x53746f70,
        bmdScannerCommandRunForward	= 0x52467764,
        bmdScannerCommandRunReverse	= 0x52526576,
        bmdScannerCommandFastForward	= 0x46467764,
        bmdScannerCommandFastReverse	= 0x46526576,
        bmdScannerCommandInchForward	= 0x49467764,
        bmdScannerCommandInchReverse	= 0x49526576,
        bmdScannerCommandPerfForward	= 0x50467764,
        bmdScannerCommandPerfReverse	= 0x50526576,
        bmdScannerCommandFramingUp	= 0x46725570,
        bmdScannerCommandFramingDown	= 0x4672446e,
        bmdScannerCommandSlowForward	= 0x536c7746,
        bmdScannerCommandSlowReverse	= 0x536c7752
    } 	BMDScannerTransportCommand;

typedef /* [v1_enum] */ 
enum _BMDScannerFilmType
    {
        bmdScannerFilmTypeNegative	= 0x464e4547,
        bmdScannerFilmTypePositive	= 0x46504f53,
        bmdScannerFilmTypeInterPositive	= 0x4649504f,
        bmdScannerFilmTypeInterNegative	= 0x46494e45
    } 	BMDScannerFilmType;

typedef /* [v1_enum] */ 
enum _BMDScannerFilmGauge
    {
        bmdScannerFilmGauge16mm	= 0x31364d4d,
        bmdScannerFilmGauge35mm2Perf	= 0x33354d32,
        bmdScannerFilmGauge35mm3Perf	= 0x33354d33,
        bmdScannerFilmGauge35mm4Perf	= 0x33354d34
    } 	BMDScannerFilmGauge;

typedef /* [v1_enum] */ 
enum _BMDScannerWindType
    {
        bmdScannerWindTypeA	= 0x41576e64,
        bmdScannerWindTypeB	= 0x42576e64
    } 	BMDScannerWindType;

typedef /* [v1_enum] */ 
enum _BMDScannerCompressionType
    {
        bmdScannerCompressionLossless	= 0x436d4c6c,
        bmdScannerCompressionLossy3To1	= 0x43333231,
        bmdScannerCompressionNone	= 0x436d4e6e
    } 	BMDScannerCompressionType;

typedef /* [v1_enum] */ 
enum _BMDScannerRollType
    {
        bmdScannerRollTypeCore	= 0x436f7265,
        bmdScannerRollTypeReel	= 0x5265656c
    } 	BMDScannerRollType;

typedef /* [v1_enum] */ 
enum _BMDScannerState
    {
        bmdScannerStateError	= 0x53457272,
        bmdScannerStateUnloaded	= 0x53556c64,
        bmdScannerStateLoading	= 0x534c6467,
        bmdScannerStateFramingUp	= 0x53467255,
        bmdScannerStateFramingDown	= 0x53467244,
        bmdScannerStatePerfNudgingUp	= 0x53504e55,
        bmdScannerStatePerfNudgingDown	= 0x53504e44,
        bmdScannerStateInchingForward	= 0x53494677,
        bmdScannerStateInchingReverse	= 0x53495276,
        bmdScannerStateStopped	= 0x534c6464,
        bmdScannerStateRunForwards	= 0x53467764,
        bmdScannerStateRunReverse	= 0x53526576,
        bmdScannerStateShuttleForwards	= 0x53534677,
        bmdScannerStateShuttleReverse	= 0x53535276,
        bmdScannerStateCueingForward	= 0x53434677,
        bmdScannerStateCueingReverse	= 0x53435276,
        bmdScannerStateStopping	= 0x53537467,
        bmdScannerStateUnloading	= 0x53556e6c,
        bmdScannerStateLEDCalibrating	= 0x53434c44,
        bmdScannerStateCalibratingFixedPatternGain	= 0x53434647,
        bmdScannerStateSleeping	= 0x53536c70,
        bmdScannerStateCapturing	= 0x53436170,
        bmdScannerStateCapturingHDRForward	= 0x53434846,
        bmdScannerStateCapturingHDRReverse	= 0x53434852
    } 	BMDScannerState;

typedef /* [v1_enum] */ 
enum _BMDScannerMessage
    {
        bmdScannerUnused	= 0x5a5a5a5a,
        bmdScannerMessageAmplifierOverTemperature	= 0x484f7654,
        bmdScannerMessageAmplifierError	= 0x48416d45,
        bmdScannerMessageAmplifierOverCurrent	= 0x416d7043,
        bmdScannerMessagePulserError	= 0x506c7345,
        bmdScannerMessagePulserOverCurrent	= 0x506c7343,
        bmdScannerMessageFPGAOverTemperature	= 0x46504754,
        bmdScannerMessageFPGAFanFail	= 0x46504646,
        bmdScannerMessageSensorTemperatureOutOfRange	= 0x536e7354,
        bmdScannerMessageSensorFanFail	= 0x536e7346,
        bmdScannerMessageFeedSlipping	= 0x53465665,
        bmdScannerMessageTakeupSlipping	= 0x53545665,
        bmdScannerMessageTransportError	= 0x546e7345,
        bmdScannerMessageStepperSlipping	= 0x5374536c,
        bmdScannerMessageMagHeadEngaged	= 0x4d674473,
        bmdScannerMessageMagHeadDisengaged	= 0x4d67456e,
        bmdScannerMessageProgrammingStarted	= 0x50726772,
        bmdScannerMessageReaderIncompatible	= 0x5264496e,
        bmdScannerMessageCodecError	= 0x434f4445,
        bmdScannerMessageHDRUnavailable	= 0x4e6f4844,
        bmdScannerMessageImageClipped	= 0x496d436c,
        bmdScannerMessageInfillClipped	= 0x496e436c,
        bmdScannerMessageFilmConfigurationChanged	= 0x466c4366,
        bmdScannerMessageTransportParametersChanged	= 0x54705061,
        bmdScannerMessageColorPropertiesChanged	= 0x436c5070,
        bmdScannerMessageImageStabilizerChanged	= 0x496d5374,
        bmdScannerMessageCaptureSettingsChanged	= 0x43705374,
        bmdScannerMessageReaderSettingsChanged	= 0x52645374,
        bmdScannerMessageAudioSelectSettingsChanged	= 0x41535374
    } 	BMDScannerMessage;

typedef /* [v1_enum] */ 
enum _BMDScannerMessageSeverity
    {
        bmdScannerMessageSeverityError	= 0x45726f72,
        bmdScannerMessageSeverityWarning	= 0x5761726e,
        bmdScannerMessageSeverityInformation	= 0x496e666f
    } 	BMDScannerMessageSeverity;

typedef /* [v1_enum] */ 
enum _BMDScannerCalibrationStatus
    {
        bmdScannerCalibrationNotRun	= 0x4e74526e,
        bmdScannerCalibrationRunning	= 0x526e6e67,
        bmdScannerCalibrationComplete	= 0x436d706c,
        bmdScannerCalibrationCompromised	= 0x436d7072,
        bmdScannerCalibrationFailed	= 0x466c6c64
    } 	BMDScannerCalibrationStatus;

typedef /* [v1_enum] */ 
enum _BMDReaderMode
    {
        bmdReaderModeKeyKodePerfs	= 0x4d644b4b,
        bmdReaderModeKeyKodeFrames	= 0x4d644b66,
        bmdReaderModeAudio	= 0x4d644175,
        bmdReaderModeAudioNarrowSlit	= 0x4d64414e,
        bmdReaderModeAudioMagnetic	= 0x4d64414d
    } 	BMDReaderMode;

typedef /* [v1_enum] */ 
enum _BMDReaderAudioMode
    {
        bmdReaderAudioModeMono	= 0x414d4d6f,
        bmdReaderAudioModeStereo	= 0x414d5374
    } 	BMDReaderAudioMode;

typedef /* [v1_enum] */ 
enum _BMDScannerCaptureMode
    {
        bmdScannerCaptureModePreview	= 0x43704e6e,
        bmdScannerCaptureModeNormal	= 0x43704e6c,
        bmdScannerCaptureModeHigh	= 0x43484677
    } 	BMDScannerCaptureMode;

typedef /* [v1_enum] */ 
enum _BMDScannerAudioSelectSource
    {
        bmdScannerAudioSourceNone	= 0x41534e6f,
        bmdScannerAudioSourceReader	= 0x41535265,
        bmdScannerAudioSourceExternal	= 0x41534578
    } 	BMDScannerAudioSelectSource;

typedef /* [v1_enum] */ 
enum _BMDScannerExternalAudioFormat
    {
        bmdScannerExternalAudioAnalog	= 0x4541416e,
        bmdScannerExternalAudioAES	= 0x45414145
    } 	BMDScannerExternalAudioFormat;

/* [v1_enum] */ 
enum _BMDScannerAdvancedFlag
    {
        bmdScannerFlagsFullStepper	= ( 1 << 0 ) ,
        bmdScannerFlagsRunRewind	= ( 1 << 2 ) 
    } ;
typedef /* [v1_enum] */ 
enum _BMDScannerSyncLTCConfig
    {
        bmdScannerSync1ppf	= 0x53317070,
        bmdScannerSync2ppf	= 0x53327070,
        bmdScannerSync5ppf	= 0x53357070,
        bmdScannerSync10ppf	= 0x53417070,
        bmdScannerLTCFrameSync	= 0x4c544653,
        bmdScannerLTCFreeRun	= 0x4c544652,
        bmdScannerSyncLTCUnsupported	= 0x556e5370
    } 	BMDScannerSyncLTCConfig;

typedef /* [v1_enum] */ 
enum _BMDScannerFrameMetadataID
    {
        bmdScannerFrameMetadataCintelFilmType	= 0x63667479,
        bmdScannerFrameMetadataCintelFilmGauge	= 0x63666761,
        bmdScannerFrameMetadataCintelKeykodeLow	= 0x636b6b6c,
        bmdScannerFrameMetadataCintelKeykodeHigh	= 0x636b6b68,
        bmdScannerFrameMetadataCintelTile1Size	= 0x63743173,
        bmdScannerFrameMetadataCintelTile2Size	= 0x63743273,
        bmdScannerFrameMetadataCintelTile3Size	= 0x63743373,
        bmdScannerFrameMetadataCintelTile4Size	= 0x63743473,
        bmdScannerFrameMetadataCintelImageWidth	= 0x49575078,
        bmdScannerFrameMetadataCintelImageHeight	= 0x49485078,
        bmdScannerFrameMetadataCintelFilmFrameRate	= 0x63666672,
        bmdScannerFrameMetadataCintelLinearMaskingRedInRed	= 0x6d726972,
        bmdScannerFrameMetadataCintelLinearMaskingGreenInRed	= 0x6d676972,
        bmdScannerFrameMetadataCintelLinearMaskingBlueInRed	= 0x6d626972,
        bmdScannerFrameMetadataCintelLinearMaskingRedInGreen	= 0x6d726967,
        bmdScannerFrameMetadataCintelLinearMaskingGreenInGreen	= 0x6d676967,
        bmdScannerFrameMetadataCintelLinearMaskingBlueInGreen	= 0x6d626967,
        bmdScannerFrameMetadataCintelLinearMaskingRedInBlue	= 0x6d726962,
        bmdScannerFrameMetadataCintelLinearMaskingGreenInBlue	= 0x6d676962,
        bmdScannerFrameMetadataCintelLinearMaskingBlueInBlue	= 0x6d626962,
        bmdScannerFrameMetadataCintelLogMaskingRedInRed	= 0x6d6c7272,
        bmdScannerFrameMetadataCintelLogMaskingGreenInRed	= 0x6d6c6772,
        bmdScannerFrameMetadataCintelLogMaskingBlueInRed	= 0x6d6c6272,
        bmdScannerFrameMetadataCintelLogMaskingRedInGreen	= 0x6d6c7267,
        bmdScannerFrameMetadataCintelLogMaskingGreenInGreen	= 0x6d6c6767,
        bmdScannerFrameMetadataCintelLogMaskingBlueInGreen	= 0x6d6c6267,
        bmdScannerFrameMetadataCintelLogMaskingRedInBlue	= 0x6d6c7262,
        bmdScannerFrameMetadataCintelLogMaskingGreenInBlue	= 0x6d6c6762,
        bmdScannerFrameMetadataCintelLogMaskingBlueInBlue	= 0x6d6c6262,
        bmdScannerFrameMetadataCintelOffsetToApplyHorizontal	= 0x6f746168,
        bmdScannerFrameMetadataCintelOffsetToApplyVertical	= 0x6f746176,
        bmdScannerFrameMetadataCintelSkewToApply	= 0x536b6577,
        bmdScannerFrameMetadataCintelGainRed	= 0x4c665264,
        bmdScannerFrameMetadataCintelGainGreen	= 0x4c664772,
        bmdScannerFrameMetadataCintelGainBlue	= 0x4c66426c,
        bmdScannerFrameMetadataCintelLiftRed	= 0x476e5264,
        bmdScannerFrameMetadataCintelLiftGreen	= 0x476e4772,
        bmdScannerFrameMetadataCintelLiftBlue	= 0x476e426c,
        bmdScannerFrameMetadataCintelHDRGainRed	= 0x48475264,
        bmdScannerFrameMetadataCintelHDRGainGreen	= 0x48474772,
        bmdScannerFrameMetadataCintelHDRGainBlue	= 0x4847426c
    } 	BMDScannerFrameMetadataID;
















EXTERN_C IScannerDiscovery* CreateScannerDiscoveryInstance(void);
EXTERN_C IScannerAPIInformation* CreateScannerAPIInformationInstance(void);

EXTERN_C const IID LIBID_ScannerAPI;

#ifndef __IScannerAPIInformation_INTERFACE_DEFINED__
#define __IScannerAPIInformation_INTERFACE_DEFINED__

/* interface IScannerAPIInformation */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerAPIInformation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C341960D-9F21-4977-8714-C1C6E38E3FD0")
    IScannerAPIInformation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFlag( 
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInt( 
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ int64_t *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFloat( 
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ BSTR *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerAPIInformationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerAPIInformation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerAPIInformation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerAPIInformation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlag )( 
            IScannerAPIInformation * This,
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetInt )( 
            IScannerAPIInformation * This,
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ int64_t *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetFloat )( 
            IScannerAPIInformation * This,
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IScannerAPIInformation * This,
            /* [in] */ BMDScannerAPIInformationID cfgID,
            /* [out] */ BSTR *value);
        
        END_INTERFACE
    } IScannerAPIInformationVtbl;

    interface IScannerAPIInformation
    {
        CONST_VTBL struct IScannerAPIInformationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerAPIInformation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerAPIInformation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerAPIInformation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerAPIInformation_GetFlag(This,cfgID,value)	\
    ( (This)->lpVtbl -> GetFlag(This,cfgID,value) ) 

#define IScannerAPIInformation_GetInt(This,cfgID,value)	\
    ( (This)->lpVtbl -> GetInt(This,cfgID,value) ) 

#define IScannerAPIInformation_GetFloat(This,cfgID,value)	\
    ( (This)->lpVtbl -> GetFloat(This,cfgID,value) ) 

#define IScannerAPIInformation_GetString(This,cfgID,value)	\
    ( (This)->lpVtbl -> GetString(This,cfgID,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerAPIInformation_INTERFACE_DEFINED__ */


#ifndef __IScanner_INTERFACE_DEFINED__
#define __IScanner_INTERFACE_DEFINED__

/* interface IScanner */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScanner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0EDC95F-95B2-472C-965F-F91B4A7941A4")
    IScanner : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InstallScannerNotifications( 
            /* [in] */ IScannerNotifications *scannerNotificationCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UninstallScannerNotifications( 
            /* [in] */ IScannerNotifications *scannerNotificationCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeckLinkDevice( 
            /* [out] */ IUnknown **deckLinkDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModelName( 
            /* [out] */ BSTR *modelName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [out] */ BSTR *displayName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTemperature( 
            /* [out] */ uint32_t *temperature) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScanner * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScanner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *InstallScannerNotifications )( 
            IScanner * This,
            /* [in] */ IScannerNotifications *scannerNotificationCallback);
        
        HRESULT ( STDMETHODCALLTYPE *UninstallScannerNotifications )( 
            IScanner * This,
            /* [in] */ IScannerNotifications *scannerNotificationCallback);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeckLinkDevice )( 
            IScanner * This,
            /* [out] */ IUnknown **deckLinkDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetModelName )( 
            IScanner * This,
            /* [out] */ BSTR *modelName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IScanner * This,
            /* [out] */ BSTR *displayName);
        
        HRESULT ( STDMETHODCALLTYPE *GetTemperature )( 
            IScanner * This,
            /* [out] */ uint32_t *temperature);
        
        END_INTERFACE
    } IScannerVtbl;

    interface IScanner
    {
        CONST_VTBL struct IScannerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScanner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScanner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScanner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScanner_InstallScannerNotifications(This,scannerNotificationCallback)	\
    ( (This)->lpVtbl -> InstallScannerNotifications(This,scannerNotificationCallback) ) 

#define IScanner_UninstallScannerNotifications(This,scannerNotificationCallback)	\
    ( (This)->lpVtbl -> UninstallScannerNotifications(This,scannerNotificationCallback) ) 

#define IScanner_GetDeckLinkDevice(This,deckLinkDevice)	\
    ( (This)->lpVtbl -> GetDeckLinkDevice(This,deckLinkDevice) ) 

#define IScanner_GetModelName(This,modelName)	\
    ( (This)->lpVtbl -> GetModelName(This,modelName) ) 

#define IScanner_GetDisplayName(This,displayName)	\
    ( (This)->lpVtbl -> GetDisplayName(This,displayName) ) 

#define IScanner_GetTemperature(This,temperature)	\
    ( (This)->lpVtbl -> GetTemperature(This,temperature) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScanner_INTERFACE_DEFINED__ */


#ifndef __IScannerDiscovery_INTERFACE_DEFINED__
#define __IScannerDiscovery_INTERFACE_DEFINED__

/* interface IScannerDiscovery */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerDiscovery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("747E5F2E-A0E0-41B2-B567-D539B9FD93C9")
    IScannerDiscovery : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InstallDeviceNotifications( 
            /* [in] */ IScannerDeviceNotificationCallback *deviceNotificationCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UninstallDeviceNotifications( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerDiscoveryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerDiscovery * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerDiscovery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerDiscovery * This);
        
        HRESULT ( STDMETHODCALLTYPE *InstallDeviceNotifications )( 
            IScannerDiscovery * This,
            /* [in] */ IScannerDeviceNotificationCallback *deviceNotificationCallback);
        
        HRESULT ( STDMETHODCALLTYPE *UninstallDeviceNotifications )( 
            IScannerDiscovery * This);
        
        END_INTERFACE
    } IScannerDiscoveryVtbl;

    interface IScannerDiscovery
    {
        CONST_VTBL struct IScannerDiscoveryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerDiscovery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerDiscovery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerDiscovery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerDiscovery_InstallDeviceNotifications(This,deviceNotificationCallback)	\
    ( (This)->lpVtbl -> InstallDeviceNotifications(This,deviceNotificationCallback) ) 

#define IScannerDiscovery_UninstallDeviceNotifications(This)	\
    ( (This)->lpVtbl -> UninstallDeviceNotifications(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerDiscovery_INTERFACE_DEFINED__ */


#ifndef __IScannerInput_INTERFACE_DEFINED__
#define __IScannerInput_INTERFACE_DEFINED__

/* interface IScannerInput */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CDAA2D18-C6BB-4189-8EFD-C411A8FAB9B1")
    IScannerInput : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoesSupportVideoMode( 
            /* [in] */ BMDScannerDisplayMode requestedMode,
            /* [in] */ BMDScannerPixelFormat requestedPixelFormat,
            /* [out] */ BOOL *supported) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableVideoInput( 
            /* [in] */ BMDScannerDisplayMode displayMode,
            /* [in] */ BMDScannerPixelFormat pixelFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableVideoInput( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAvailableVideoFrameCount( 
            /* [out] */ uint32_t *availableFrameCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableAudioInput( 
            /* [in] */ BMDScannerAudioSampleType sampleType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableAudioInput( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAvailableAudioSampleFrameCount( 
            /* [out] */ uint32_t *availableSampleFrameCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartStreams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopStreams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PauseStreams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushStreams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCallback( 
            /* [in] */ IScannerInputCallback *theCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHardwareReferenceClock( 
            /* [in] */ BMDScannerTimeScale desiredTimeScale,
            /* [out] */ BMDScannerTimeValue *hardwareTime,
            /* [out] */ BMDScannerTimeValue *timeInFrame,
            /* [out] */ BMDScannerTimeValue *ticksPerFrame) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerInput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerInput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoesSupportVideoMode )( 
            IScannerInput * This,
            /* [in] */ BMDScannerDisplayMode requestedMode,
            /* [in] */ BMDScannerPixelFormat requestedPixelFormat,
            /* [out] */ BOOL *supported);
        
        HRESULT ( STDMETHODCALLTYPE *EnableVideoInput )( 
            IScannerInput * This,
            /* [in] */ BMDScannerDisplayMode displayMode,
            /* [in] */ BMDScannerPixelFormat pixelFormat);
        
        HRESULT ( STDMETHODCALLTYPE *DisableVideoInput )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAvailableVideoFrameCount )( 
            IScannerInput * This,
            /* [out] */ uint32_t *availableFrameCount);
        
        HRESULT ( STDMETHODCALLTYPE *EnableAudioInput )( 
            IScannerInput * This,
            /* [in] */ BMDScannerAudioSampleType sampleType);
        
        HRESULT ( STDMETHODCALLTYPE *DisableAudioInput )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAvailableAudioSampleFrameCount )( 
            IScannerInput * This,
            /* [out] */ uint32_t *availableSampleFrameCount);
        
        HRESULT ( STDMETHODCALLTYPE *StartStreams )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopStreams )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *PauseStreams )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *FlushStreams )( 
            IScannerInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetCallback )( 
            IScannerInput * This,
            /* [in] */ IScannerInputCallback *theCallback);
        
        HRESULT ( STDMETHODCALLTYPE *GetHardwareReferenceClock )( 
            IScannerInput * This,
            /* [in] */ BMDScannerTimeScale desiredTimeScale,
            /* [out] */ BMDScannerTimeValue *hardwareTime,
            /* [out] */ BMDScannerTimeValue *timeInFrame,
            /* [out] */ BMDScannerTimeValue *ticksPerFrame);
        
        END_INTERFACE
    } IScannerInputVtbl;

    interface IScannerInput
    {
        CONST_VTBL struct IScannerInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerInput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerInput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerInput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerInput_DoesSupportVideoMode(This,requestedMode,requestedPixelFormat,supported)	\
    ( (This)->lpVtbl -> DoesSupportVideoMode(This,requestedMode,requestedPixelFormat,supported) ) 

#define IScannerInput_EnableVideoInput(This,displayMode,pixelFormat)	\
    ( (This)->lpVtbl -> EnableVideoInput(This,displayMode,pixelFormat) ) 

#define IScannerInput_DisableVideoInput(This)	\
    ( (This)->lpVtbl -> DisableVideoInput(This) ) 

#define IScannerInput_GetAvailableVideoFrameCount(This,availableFrameCount)	\
    ( (This)->lpVtbl -> GetAvailableVideoFrameCount(This,availableFrameCount) ) 

#define IScannerInput_EnableAudioInput(This,sampleType)	\
    ( (This)->lpVtbl -> EnableAudioInput(This,sampleType) ) 

#define IScannerInput_DisableAudioInput(This)	\
    ( (This)->lpVtbl -> DisableAudioInput(This) ) 

#define IScannerInput_GetAvailableAudioSampleFrameCount(This,availableSampleFrameCount)	\
    ( (This)->lpVtbl -> GetAvailableAudioSampleFrameCount(This,availableSampleFrameCount) ) 

#define IScannerInput_StartStreams(This)	\
    ( (This)->lpVtbl -> StartStreams(This) ) 

#define IScannerInput_StopStreams(This)	\
    ( (This)->lpVtbl -> StopStreams(This) ) 

#define IScannerInput_PauseStreams(This)	\
    ( (This)->lpVtbl -> PauseStreams(This) ) 

#define IScannerInput_FlushStreams(This)	\
    ( (This)->lpVtbl -> FlushStreams(This) ) 

#define IScannerInput_SetCallback(This,theCallback)	\
    ( (This)->lpVtbl -> SetCallback(This,theCallback) ) 

#define IScannerInput_GetHardwareReferenceClock(This,desiredTimeScale,hardwareTime,timeInFrame,ticksPerFrame)	\
    ( (This)->lpVtbl -> GetHardwareReferenceClock(This,desiredTimeScale,hardwareTime,timeInFrame,ticksPerFrame) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerInput_INTERFACE_DEFINED__ */


#ifndef __IScannerInputFrame_INTERFACE_DEFINED__
#define __IScannerInputFrame_INTERFACE_DEFINED__

/* interface IScannerInputFrame */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerInputFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2EB0F08-613A-4406-BA0A-97E83BBCB77D")
    IScannerInputFrame : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMetadataInt( 
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ int64_t *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadataFloat( 
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadataFlag( 
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadataString( 
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ BSTR *value) = 0;
        
        virtual BOOL STDMETHODCALLTYPE HasVideo( void) = 0;
        
        virtual uint32_t STDMETHODCALLTYPE GetWidth( void) = 0;
        
        virtual uint32_t STDMETHODCALLTYPE GetHeight( void) = 0;
        
        virtual uint32_t STDMETHODCALLTYPE GetRowBytes( void) = 0;
        
        virtual BMDScannerPixelFormat STDMETHODCALLTYPE GetPixelFormat( void) = 0;
        
        virtual BMDScannerFrameFlags STDMETHODCALLTYPE GetFlags( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBytes( 
            /* [out] */ void **buffer) = 0;
        
        virtual BMDScannerTimecodeBCD STDMETHODCALLTYPE GetTimecode( void) = 0;
        
        virtual BMDScannerDisplayMode STDMETHODCALLTYPE GetDisplayMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamTime( 
            /* [out] */ BMDScannerTimeValue *frameTime,
            /* [out] */ BMDScannerTimeValue *frameDuration,
            /* [in] */ BMDScannerTimeScale timeScale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHardwareReferenceTimestamp( 
            /* [in] */ BMDScannerTimeScale timeScale,
            /* [out] */ BMDScannerTimeValue *frameTime,
            /* [out] */ BMDScannerTimeValue *frameDuration) = 0;
        
        virtual BOOL STDMETHODCALLTYPE HasAudio( void) = 0;
        
        virtual uint32_t STDMETHODCALLTYPE GetAudioSampleFrameCount( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioBytes( 
            /* [out] */ void **buffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerInputFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerInputFrame * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerInputFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerInputFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadataInt )( 
            IScannerInputFrame * This,
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ int64_t *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadataFloat )( 
            IScannerInputFrame * This,
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadataFlag )( 
            IScannerInputFrame * This,
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadataString )( 
            IScannerInputFrame * This,
            /* [in] */ BMDScannerFrameMetadataID metadataID,
            /* [out] */ BSTR *value);
        
        BOOL ( STDMETHODCALLTYPE *HasVideo )( 
            IScannerInputFrame * This);
        
        uint32_t ( STDMETHODCALLTYPE *GetWidth )( 
            IScannerInputFrame * This);
        
        uint32_t ( STDMETHODCALLTYPE *GetHeight )( 
            IScannerInputFrame * This);
        
        uint32_t ( STDMETHODCALLTYPE *GetRowBytes )( 
            IScannerInputFrame * This);
        
        BMDScannerPixelFormat ( STDMETHODCALLTYPE *GetPixelFormat )( 
            IScannerInputFrame * This);
        
        BMDScannerFrameFlags ( STDMETHODCALLTYPE *GetFlags )( 
            IScannerInputFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytes )( 
            IScannerInputFrame * This,
            /* [out] */ void **buffer);
        
        BMDScannerTimecodeBCD ( STDMETHODCALLTYPE *GetTimecode )( 
            IScannerInputFrame * This);
        
        BMDScannerDisplayMode ( STDMETHODCALLTYPE *GetDisplayMode )( 
            IScannerInputFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetStreamTime )( 
            IScannerInputFrame * This,
            /* [out] */ BMDScannerTimeValue *frameTime,
            /* [out] */ BMDScannerTimeValue *frameDuration,
            /* [in] */ BMDScannerTimeScale timeScale);
        
        HRESULT ( STDMETHODCALLTYPE *GetHardwareReferenceTimestamp )( 
            IScannerInputFrame * This,
            /* [in] */ BMDScannerTimeScale timeScale,
            /* [out] */ BMDScannerTimeValue *frameTime,
            /* [out] */ BMDScannerTimeValue *frameDuration);
        
        BOOL ( STDMETHODCALLTYPE *HasAudio )( 
            IScannerInputFrame * This);
        
        uint32_t ( STDMETHODCALLTYPE *GetAudioSampleFrameCount )( 
            IScannerInputFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioBytes )( 
            IScannerInputFrame * This,
            /* [out] */ void **buffer);
        
        END_INTERFACE
    } IScannerInputFrameVtbl;

    interface IScannerInputFrame
    {
        CONST_VTBL struct IScannerInputFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerInputFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerInputFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerInputFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerInputFrame_GetMetadataInt(This,metadataID,value)	\
    ( (This)->lpVtbl -> GetMetadataInt(This,metadataID,value) ) 

#define IScannerInputFrame_GetMetadataFloat(This,metadataID,value)	\
    ( (This)->lpVtbl -> GetMetadataFloat(This,metadataID,value) ) 

#define IScannerInputFrame_GetMetadataFlag(This,metadataID,value)	\
    ( (This)->lpVtbl -> GetMetadataFlag(This,metadataID,value) ) 

#define IScannerInputFrame_GetMetadataString(This,metadataID,value)	\
    ( (This)->lpVtbl -> GetMetadataString(This,metadataID,value) ) 

#define IScannerInputFrame_HasVideo(This)	\
    ( (This)->lpVtbl -> HasVideo(This) ) 

#define IScannerInputFrame_GetWidth(This)	\
    ( (This)->lpVtbl -> GetWidth(This) ) 

#define IScannerInputFrame_GetHeight(This)	\
    ( (This)->lpVtbl -> GetHeight(This) ) 

#define IScannerInputFrame_GetRowBytes(This)	\
    ( (This)->lpVtbl -> GetRowBytes(This) ) 

#define IScannerInputFrame_GetPixelFormat(This)	\
    ( (This)->lpVtbl -> GetPixelFormat(This) ) 

#define IScannerInputFrame_GetFlags(This)	\
    ( (This)->lpVtbl -> GetFlags(This) ) 

#define IScannerInputFrame_GetBytes(This,buffer)	\
    ( (This)->lpVtbl -> GetBytes(This,buffer) ) 

#define IScannerInputFrame_GetTimecode(This)	\
    ( (This)->lpVtbl -> GetTimecode(This) ) 

#define IScannerInputFrame_GetDisplayMode(This)	\
    ( (This)->lpVtbl -> GetDisplayMode(This) ) 

#define IScannerInputFrame_GetStreamTime(This,frameTime,frameDuration,timeScale)	\
    ( (This)->lpVtbl -> GetStreamTime(This,frameTime,frameDuration,timeScale) ) 

#define IScannerInputFrame_GetHardwareReferenceTimestamp(This,timeScale,frameTime,frameDuration)	\
    ( (This)->lpVtbl -> GetHardwareReferenceTimestamp(This,timeScale,frameTime,frameDuration) ) 

#define IScannerInputFrame_HasAudio(This)	\
    ( (This)->lpVtbl -> HasAudio(This) ) 

#define IScannerInputFrame_GetAudioSampleFrameCount(This)	\
    ( (This)->lpVtbl -> GetAudioSampleFrameCount(This) ) 

#define IScannerInputFrame_GetAudioBytes(This,buffer)	\
    ( (This)->lpVtbl -> GetAudioBytes(This,buffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerInputFrame_INTERFACE_DEFINED__ */


#ifndef __IScannerInputCallback_INTERFACE_DEFINED__
#define __IScannerInputCallback_INTERFACE_DEFINED__

/* interface IScannerInputCallback */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerInputCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E9397F80-50A8-4560-83A0-DE46CC4F06B2")
    IScannerInputCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ScannerInputFrameArrived( 
            /* [in] */ IScannerInputFrame *videoFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScannerInputFormatChanged( 
            /* [in] */ BMDScannerDisplayMode newDisplayMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerInputCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerInputCallback * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerInputCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerInputCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScannerInputFrameArrived )( 
            IScannerInputCallback * This,
            /* [in] */ IScannerInputFrame *videoFrame);
        
        HRESULT ( STDMETHODCALLTYPE *ScannerInputFormatChanged )( 
            IScannerInputCallback * This,
            /* [in] */ BMDScannerDisplayMode newDisplayMode);
        
        END_INTERFACE
    } IScannerInputCallbackVtbl;

    interface IScannerInputCallback
    {
        CONST_VTBL struct IScannerInputCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerInputCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerInputCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerInputCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerInputCallback_ScannerInputFrameArrived(This,videoFrame)	\
    ( (This)->lpVtbl -> ScannerInputFrameArrived(This,videoFrame) ) 

#define IScannerInputCallback_ScannerInputFormatChanged(This,newDisplayMode)	\
    ( (This)->lpVtbl -> ScannerInputFormatChanged(This,newDisplayMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerInputCallback_INTERFACE_DEFINED__ */


#ifndef __IScannerDeviceNotificationCallback_INTERFACE_DEFINED__
#define __IScannerDeviceNotificationCallback_INTERFACE_DEFINED__

/* interface IScannerDeviceNotificationCallback */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerDeviceNotificationCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2A963D1-9671-4099-8A65-EFE56EF9983B")
    IScannerDeviceNotificationCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ScannerDeviceArrived( 
            /* [in] */ IScanner *scannerDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScannerDeviceRemoved( 
            /* [in] */ IScanner *scannerDevice) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerDeviceNotificationCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerDeviceNotificationCallback * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerDeviceNotificationCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerDeviceNotificationCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScannerDeviceArrived )( 
            IScannerDeviceNotificationCallback * This,
            /* [in] */ IScanner *scannerDevice);
        
        HRESULT ( STDMETHODCALLTYPE *ScannerDeviceRemoved )( 
            IScannerDeviceNotificationCallback * This,
            /* [in] */ IScanner *scannerDevice);
        
        END_INTERFACE
    } IScannerDeviceNotificationCallbackVtbl;

    interface IScannerDeviceNotificationCallback
    {
        CONST_VTBL struct IScannerDeviceNotificationCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerDeviceNotificationCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerDeviceNotificationCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerDeviceNotificationCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerDeviceNotificationCallback_ScannerDeviceArrived(This,scannerDevice)	\
    ( (This)->lpVtbl -> ScannerDeviceArrived(This,scannerDevice) ) 

#define IScannerDeviceNotificationCallback_ScannerDeviceRemoved(This,scannerDevice)	\
    ( (This)->lpVtbl -> ScannerDeviceRemoved(This,scannerDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerDeviceNotificationCallback_INTERFACE_DEFINED__ */


#ifndef __IScannerNotifications_INTERFACE_DEFINED__
#define __IScannerNotifications_INTERFACE_DEFINED__

/* interface IScannerNotifications */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77D127A3-DF50-42D3-A6DE-1A8A5AFD2C57")
    IScannerNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SystemStateChanged( 
            /* [in] */ BMDScannerState state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MessageEvent( 
            /* [in] */ BMDScannerMessage eventCode,
            /* [in] */ BMDScannerMessageSeverity severity,
            /* [in] */ uint32_t numParams,
            /* [in] */ uint64_t *params) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerNotifications * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerNotifications * This);
        
        HRESULT ( STDMETHODCALLTYPE *SystemStateChanged )( 
            IScannerNotifications * This,
            /* [in] */ BMDScannerState state);
        
        HRESULT ( STDMETHODCALLTYPE *MessageEvent )( 
            IScannerNotifications * This,
            /* [in] */ BMDScannerMessage eventCode,
            /* [in] */ BMDScannerMessageSeverity severity,
            /* [in] */ uint32_t numParams,
            /* [in] */ uint64_t *params);
        
        END_INTERFACE
    } IScannerNotificationsVtbl;

    interface IScannerNotifications
    {
        CONST_VTBL struct IScannerNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerNotifications_SystemStateChanged(This,state)	\
    ( (This)->lpVtbl -> SystemStateChanged(This,state) ) 

#define IScannerNotifications_MessageEvent(This,eventCode,severity,numParams,params)	\
    ( (This)->lpVtbl -> MessageEvent(This,eventCode,severity,numParams,params) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerNotifications_INTERFACE_DEFINED__ */


#ifndef __IScannerFilmConfiguration_INTERFACE_DEFINED__
#define __IScannerFilmConfiguration_INTERFACE_DEFINED__

/* interface IScannerFilmConfiguration */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerFilmConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("350F33F1-E5A5-456B-854B-A05A2F5E56C5")
    IScannerFilmConfiguration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFilmType( 
            /* [in] */ BMDScannerFilmType filmType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilmType( 
            /* [out] */ BMDScannerFilmType *filmType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFilmType( 
            /* [out] */ BMDScannerFilmType *filmType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilmGauge( 
            /* [in] */ BMDScannerFilmGauge filmGauge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilmGauge( 
            /* [out] */ BMDScannerFilmGauge *filmGauge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFilmGauge( 
            /* [out] */ BMDScannerFilmGauge *filmGauge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilmGaugeAvailable( 
            /* [in] */ BMDScannerFilmGauge filmGauge,
            /* [out] */ BOOL *available) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilmFrameRate( 
            /* [in] */ uint16_t framesPerSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilmFrameRate( 
            /* [out] */ uint16_t *framesPerSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFilmFrameRate( 
            /* [out] */ uint16_t *framesPerSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumFilmFrameRate( 
            /* [out] */ uint16_t *framesPerSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumFilmFrameRate( 
            /* [out] */ uint16_t *framesPerSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFeedWind( 
            /* [in] */ BMDScannerWindType wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeedWind( 
            /* [out] */ BMDScannerWindType *wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFeedWind( 
            /* [out] */ BMDScannerWindType *wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTakeupWind( 
            /* [in] */ BMDScannerWindType wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTakeupWind( 
            /* [out] */ BMDScannerWindType *wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultTakeupWind( 
            /* [out] */ BMDScannerWindType *wind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFeedRollType( 
            /* [in] */ BMDScannerRollType roll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeedRollType( 
            /* [out] */ BMDScannerRollType *roll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFeedRollType( 
            /* [out] */ BMDScannerRollType *roll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTakeupRollType( 
            /* [in] */ BMDScannerRollType roll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTakeupRollType( 
            /* [out] */ BMDScannerRollType *roll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultTakeupRollType( 
            /* [out] */ BMDScannerRollType *roll) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerFilmConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerFilmConfiguration * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerFilmConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerFilmConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilmType )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerFilmType filmType);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilmType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerFilmType *filmType);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFilmType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerFilmType *filmType);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilmGauge )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerFilmGauge filmGauge);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilmGauge )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerFilmGauge *filmGauge);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFilmGauge )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerFilmGauge *filmGauge);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilmGaugeAvailable )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerFilmGauge filmGauge,
            /* [out] */ BOOL *available);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilmFrameRate )( 
            IScannerFilmConfiguration * This,
            /* [in] */ uint16_t framesPerSecond);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilmFrameRate )( 
            IScannerFilmConfiguration * This,
            /* [out] */ uint16_t *framesPerSecond);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFilmFrameRate )( 
            IScannerFilmConfiguration * This,
            /* [out] */ uint16_t *framesPerSecond);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumFilmFrameRate )( 
            IScannerFilmConfiguration * This,
            /* [out] */ uint16_t *framesPerSecond);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumFilmFrameRate )( 
            IScannerFilmConfiguration * This,
            /* [out] */ uint16_t *framesPerSecond);
        
        HRESULT ( STDMETHODCALLTYPE *SetFeedWind )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerWindType wind);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeedWind )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerWindType *wind);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFeedWind )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerWindType *wind);
        
        HRESULT ( STDMETHODCALLTYPE *SetTakeupWind )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerWindType wind);
        
        HRESULT ( STDMETHODCALLTYPE *GetTakeupWind )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerWindType *wind);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultTakeupWind )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerWindType *wind);
        
        HRESULT ( STDMETHODCALLTYPE *SetFeedRollType )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerRollType roll);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeedRollType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerRollType *roll);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFeedRollType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerRollType *roll);
        
        HRESULT ( STDMETHODCALLTYPE *SetTakeupRollType )( 
            IScannerFilmConfiguration * This,
            /* [in] */ BMDScannerRollType roll);
        
        HRESULT ( STDMETHODCALLTYPE *GetTakeupRollType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerRollType *roll);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultTakeupRollType )( 
            IScannerFilmConfiguration * This,
            /* [out] */ BMDScannerRollType *roll);
        
        END_INTERFACE
    } IScannerFilmConfigurationVtbl;

    interface IScannerFilmConfiguration
    {
        CONST_VTBL struct IScannerFilmConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerFilmConfiguration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerFilmConfiguration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerFilmConfiguration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerFilmConfiguration_SetFilmType(This,filmType)	\
    ( (This)->lpVtbl -> SetFilmType(This,filmType) ) 

#define IScannerFilmConfiguration_GetFilmType(This,filmType)	\
    ( (This)->lpVtbl -> GetFilmType(This,filmType) ) 

#define IScannerFilmConfiguration_GetDefaultFilmType(This,filmType)	\
    ( (This)->lpVtbl -> GetDefaultFilmType(This,filmType) ) 

#define IScannerFilmConfiguration_SetFilmGauge(This,filmGauge)	\
    ( (This)->lpVtbl -> SetFilmGauge(This,filmGauge) ) 

#define IScannerFilmConfiguration_GetFilmGauge(This,filmGauge)	\
    ( (This)->lpVtbl -> GetFilmGauge(This,filmGauge) ) 

#define IScannerFilmConfiguration_GetDefaultFilmGauge(This,filmGauge)	\
    ( (This)->lpVtbl -> GetDefaultFilmGauge(This,filmGauge) ) 

#define IScannerFilmConfiguration_GetFilmGaugeAvailable(This,filmGauge,available)	\
    ( (This)->lpVtbl -> GetFilmGaugeAvailable(This,filmGauge,available) ) 

#define IScannerFilmConfiguration_SetFilmFrameRate(This,framesPerSecond)	\
    ( (This)->lpVtbl -> SetFilmFrameRate(This,framesPerSecond) ) 

#define IScannerFilmConfiguration_GetFilmFrameRate(This,framesPerSecond)	\
    ( (This)->lpVtbl -> GetFilmFrameRate(This,framesPerSecond) ) 

#define IScannerFilmConfiguration_GetDefaultFilmFrameRate(This,framesPerSecond)	\
    ( (This)->lpVtbl -> GetDefaultFilmFrameRate(This,framesPerSecond) ) 

#define IScannerFilmConfiguration_GetMinimumFilmFrameRate(This,framesPerSecond)	\
    ( (This)->lpVtbl -> GetMinimumFilmFrameRate(This,framesPerSecond) ) 

#define IScannerFilmConfiguration_GetMaximumFilmFrameRate(This,framesPerSecond)	\
    ( (This)->lpVtbl -> GetMaximumFilmFrameRate(This,framesPerSecond) ) 

#define IScannerFilmConfiguration_SetFeedWind(This,wind)	\
    ( (This)->lpVtbl -> SetFeedWind(This,wind) ) 

#define IScannerFilmConfiguration_GetFeedWind(This,wind)	\
    ( (This)->lpVtbl -> GetFeedWind(This,wind) ) 

#define IScannerFilmConfiguration_GetDefaultFeedWind(This,wind)	\
    ( (This)->lpVtbl -> GetDefaultFeedWind(This,wind) ) 

#define IScannerFilmConfiguration_SetTakeupWind(This,wind)	\
    ( (This)->lpVtbl -> SetTakeupWind(This,wind) ) 

#define IScannerFilmConfiguration_GetTakeupWind(This,wind)	\
    ( (This)->lpVtbl -> GetTakeupWind(This,wind) ) 

#define IScannerFilmConfiguration_GetDefaultTakeupWind(This,wind)	\
    ( (This)->lpVtbl -> GetDefaultTakeupWind(This,wind) ) 

#define IScannerFilmConfiguration_SetFeedRollType(This,roll)	\
    ( (This)->lpVtbl -> SetFeedRollType(This,roll) ) 

#define IScannerFilmConfiguration_GetFeedRollType(This,roll)	\
    ( (This)->lpVtbl -> GetFeedRollType(This,roll) ) 

#define IScannerFilmConfiguration_GetDefaultFeedRollType(This,roll)	\
    ( (This)->lpVtbl -> GetDefaultFeedRollType(This,roll) ) 

#define IScannerFilmConfiguration_SetTakeupRollType(This,roll)	\
    ( (This)->lpVtbl -> SetTakeupRollType(This,roll) ) 

#define IScannerFilmConfiguration_GetTakeupRollType(This,roll)	\
    ( (This)->lpVtbl -> GetTakeupRollType(This,roll) ) 

#define IScannerFilmConfiguration_GetDefaultTakeupRollType(This,roll)	\
    ( (This)->lpVtbl -> GetDefaultTakeupRollType(This,roll) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerFilmConfiguration_INTERFACE_DEFINED__ */


#ifndef __IScannerTransport_INTERFACE_DEFINED__
#define __IScannerTransport_INTERFACE_DEFINED__

/* interface IScannerTransport */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerTransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6646375D-9995-43EA-A33D-3EA957FBAC02")
    IScannerTransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRunSpeed( 
            /* [in] */ uint16_t runSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRunSpeed( 
            /* [out] */ uint16_t *runSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumRunSpeed( 
            /* [out] */ uint16_t *minimumRunSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumRunSpeed( 
            /* [out] */ uint16_t *maximumRunSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultRunSpeed( 
            /* [out] */ uint16_t *defaultRunSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetShuttleSpeed( 
            /* [in] */ uint16_t shuttleSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShuttleSpeed( 
            /* [out] */ uint16_t *shuttleSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumShuttleSpeed( 
            /* [out] */ uint16_t *minimumShuttleSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumShuttleSpeed( 
            /* [out] */ uint16_t *maximumShuttleSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultShuttleSpeed( 
            /* [out] */ uint16_t *defaultShuttleSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAcceleration( 
            /* [in] */ uint16_t acceleration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAcceleration( 
            /* [out] */ uint16_t *acceleration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumAcceleration( 
            /* [out] */ uint16_t *minimumAcceleration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumAcceleration( 
            /* [out] */ uint16_t *maximumAcceleration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultAcceleration( 
            /* [out] */ uint16_t *defaultAcceleration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilmTension( 
            /* [in] */ uint16_t tension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilmTension( 
            /* [out] */ uint16_t *tension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumFilmTension( 
            /* [out] */ uint16_t *minimumTension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumFilmTension( 
            /* [out] */ uint16_t *maximumTension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFilmTension( 
            /* [out] */ uint16_t *defaultTension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimecode( 
            /* [in] */ BMDScannerTimecodeBCD timecodeBcd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimecode( 
            /* [out] */ BMDScannerTimecodeBCD *timecodeBcd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCue( 
            /* [in] */ BMDScannerTimecodeBCD timecodeBcd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ BMDScannerTransportCommand command) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCaptureMode( 
            /* [in] */ BMDScannerCaptureMode mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaptureMode( 
            /* [out] */ BMDScannerCaptureMode *mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultCaptureMode( 
            /* [out] */ BMDScannerCaptureMode *mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeedFramesRemaining( 
            /* [out] */ uint32_t *frames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTakeupFramesRemaining( 
            /* [out] */ uint32_t *frames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreroll( 
            /* [out] */ uint32_t *frames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdvancedFlags( 
            /* [in] */ uint32_t flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdvancedFlags( 
            /* [out] */ uint32_t *flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHDRCaptureAvailable( 
            /* [out] */ BOOL *available) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerTransportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerTransport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerTransport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerTransport * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetRunSpeed )( 
            IScannerTransport * This,
            /* [in] */ uint16_t runSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetRunSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *runSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumRunSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *minimumRunSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumRunSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *maximumRunSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultRunSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *defaultRunSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *SetShuttleSpeed )( 
            IScannerTransport * This,
            /* [in] */ uint16_t shuttleSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetShuttleSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *shuttleSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumShuttleSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *minimumShuttleSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumShuttleSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *maximumShuttleSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultShuttleSpeed )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *defaultShuttleSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *SetAcceleration )( 
            IScannerTransport * This,
            /* [in] */ uint16_t acceleration);
        
        HRESULT ( STDMETHODCALLTYPE *GetAcceleration )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *acceleration);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumAcceleration )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *minimumAcceleration);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumAcceleration )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *maximumAcceleration);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultAcceleration )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *defaultAcceleration);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilmTension )( 
            IScannerTransport * This,
            /* [in] */ uint16_t tension);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilmTension )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *tension);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumFilmTension )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *minimumTension);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumFilmTension )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *maximumTension);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFilmTension )( 
            IScannerTransport * This,
            /* [out] */ uint16_t *defaultTension);
        
        HRESULT ( STDMETHODCALLTYPE *SetTimecode )( 
            IScannerTransport * This,
            /* [in] */ BMDScannerTimecodeBCD timecodeBcd);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimecode )( 
            IScannerTransport * This,
            /* [out] */ BMDScannerTimecodeBCD *timecodeBcd);
        
        HRESULT ( STDMETHODCALLTYPE *SetCue )( 
            IScannerTransport * This,
            /* [in] */ BMDScannerTimecodeBCD timecodeBcd);
        
        HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IScannerTransport * This,
            /* [in] */ BMDScannerTransportCommand command);
        
        HRESULT ( STDMETHODCALLTYPE *SetCaptureMode )( 
            IScannerTransport * This,
            /* [in] */ BMDScannerCaptureMode mode);
        
        HRESULT ( STDMETHODCALLTYPE *GetCaptureMode )( 
            IScannerTransport * This,
            /* [out] */ BMDScannerCaptureMode *mode);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultCaptureMode )( 
            IScannerTransport * This,
            /* [out] */ BMDScannerCaptureMode *mode);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeedFramesRemaining )( 
            IScannerTransport * This,
            /* [out] */ uint32_t *frames);
        
        HRESULT ( STDMETHODCALLTYPE *GetTakeupFramesRemaining )( 
            IScannerTransport * This,
            /* [out] */ uint32_t *frames);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreroll )( 
            IScannerTransport * This,
            /* [out] */ uint32_t *frames);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdvancedFlags )( 
            IScannerTransport * This,
            /* [in] */ uint32_t flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdvancedFlags )( 
            IScannerTransport * This,
            /* [out] */ uint32_t *flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetHDRCaptureAvailable )( 
            IScannerTransport * This,
            /* [out] */ BOOL *available);
        
        END_INTERFACE
    } IScannerTransportVtbl;

    interface IScannerTransport
    {
        CONST_VTBL struct IScannerTransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerTransport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerTransport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerTransport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerTransport_SetRunSpeed(This,runSpeed)	\
    ( (This)->lpVtbl -> SetRunSpeed(This,runSpeed) ) 

#define IScannerTransport_GetRunSpeed(This,runSpeed)	\
    ( (This)->lpVtbl -> GetRunSpeed(This,runSpeed) ) 

#define IScannerTransport_GetMinimumRunSpeed(This,minimumRunSpeed)	\
    ( (This)->lpVtbl -> GetMinimumRunSpeed(This,minimumRunSpeed) ) 

#define IScannerTransport_GetMaximumRunSpeed(This,maximumRunSpeed)	\
    ( (This)->lpVtbl -> GetMaximumRunSpeed(This,maximumRunSpeed) ) 

#define IScannerTransport_GetDefaultRunSpeed(This,defaultRunSpeed)	\
    ( (This)->lpVtbl -> GetDefaultRunSpeed(This,defaultRunSpeed) ) 

#define IScannerTransport_SetShuttleSpeed(This,shuttleSpeed)	\
    ( (This)->lpVtbl -> SetShuttleSpeed(This,shuttleSpeed) ) 

#define IScannerTransport_GetShuttleSpeed(This,shuttleSpeed)	\
    ( (This)->lpVtbl -> GetShuttleSpeed(This,shuttleSpeed) ) 

#define IScannerTransport_GetMinimumShuttleSpeed(This,minimumShuttleSpeed)	\
    ( (This)->lpVtbl -> GetMinimumShuttleSpeed(This,minimumShuttleSpeed) ) 

#define IScannerTransport_GetMaximumShuttleSpeed(This,maximumShuttleSpeed)	\
    ( (This)->lpVtbl -> GetMaximumShuttleSpeed(This,maximumShuttleSpeed) ) 

#define IScannerTransport_GetDefaultShuttleSpeed(This,defaultShuttleSpeed)	\
    ( (This)->lpVtbl -> GetDefaultShuttleSpeed(This,defaultShuttleSpeed) ) 

#define IScannerTransport_SetAcceleration(This,acceleration)	\
    ( (This)->lpVtbl -> SetAcceleration(This,acceleration) ) 

#define IScannerTransport_GetAcceleration(This,acceleration)	\
    ( (This)->lpVtbl -> GetAcceleration(This,acceleration) ) 

#define IScannerTransport_GetMinimumAcceleration(This,minimumAcceleration)	\
    ( (This)->lpVtbl -> GetMinimumAcceleration(This,minimumAcceleration) ) 

#define IScannerTransport_GetMaximumAcceleration(This,maximumAcceleration)	\
    ( (This)->lpVtbl -> GetMaximumAcceleration(This,maximumAcceleration) ) 

#define IScannerTransport_GetDefaultAcceleration(This,defaultAcceleration)	\
    ( (This)->lpVtbl -> GetDefaultAcceleration(This,defaultAcceleration) ) 

#define IScannerTransport_SetFilmTension(This,tension)	\
    ( (This)->lpVtbl -> SetFilmTension(This,tension) ) 

#define IScannerTransport_GetFilmTension(This,tension)	\
    ( (This)->lpVtbl -> GetFilmTension(This,tension) ) 

#define IScannerTransport_GetMinimumFilmTension(This,minimumTension)	\
    ( (This)->lpVtbl -> GetMinimumFilmTension(This,minimumTension) ) 

#define IScannerTransport_GetMaximumFilmTension(This,maximumTension)	\
    ( (This)->lpVtbl -> GetMaximumFilmTension(This,maximumTension) ) 

#define IScannerTransport_GetDefaultFilmTension(This,defaultTension)	\
    ( (This)->lpVtbl -> GetDefaultFilmTension(This,defaultTension) ) 

#define IScannerTransport_SetTimecode(This,timecodeBcd)	\
    ( (This)->lpVtbl -> SetTimecode(This,timecodeBcd) ) 

#define IScannerTransport_GetTimecode(This,timecodeBcd)	\
    ( (This)->lpVtbl -> GetTimecode(This,timecodeBcd) ) 

#define IScannerTransport_SetCue(This,timecodeBcd)	\
    ( (This)->lpVtbl -> SetCue(This,timecodeBcd) ) 

#define IScannerTransport_SendCommand(This,command)	\
    ( (This)->lpVtbl -> SendCommand(This,command) ) 

#define IScannerTransport_SetCaptureMode(This,mode)	\
    ( (This)->lpVtbl -> SetCaptureMode(This,mode) ) 

#define IScannerTransport_GetCaptureMode(This,mode)	\
    ( (This)->lpVtbl -> GetCaptureMode(This,mode) ) 

#define IScannerTransport_GetDefaultCaptureMode(This,mode)	\
    ( (This)->lpVtbl -> GetDefaultCaptureMode(This,mode) ) 

#define IScannerTransport_GetFeedFramesRemaining(This,frames)	\
    ( (This)->lpVtbl -> GetFeedFramesRemaining(This,frames) ) 

#define IScannerTransport_GetTakeupFramesRemaining(This,frames)	\
    ( (This)->lpVtbl -> GetTakeupFramesRemaining(This,frames) ) 

#define IScannerTransport_GetPreroll(This,frames)	\
    ( (This)->lpVtbl -> GetPreroll(This,frames) ) 

#define IScannerTransport_SetAdvancedFlags(This,flags)	\
    ( (This)->lpVtbl -> SetAdvancedFlags(This,flags) ) 

#define IScannerTransport_GetAdvancedFlags(This,flags)	\
    ( (This)->lpVtbl -> GetAdvancedFlags(This,flags) ) 

#define IScannerTransport_GetHDRCaptureAvailable(This,available)	\
    ( (This)->lpVtbl -> GetHDRCaptureAvailable(This,available) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerTransport_INTERFACE_DEFINED__ */


#ifndef __IScannerColorProperties_INTERFACE_DEFINED__
#define __IScannerColorProperties_INTERFACE_DEFINED__

/* interface IScannerColorProperties */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerColorProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3BD9411E-9A5E-47F1-845E-2188DCCAC741")
    IScannerColorProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetLEDIllumination( 
            /* [in] */ uint16_t red,
            /* [in] */ uint16_t green,
            /* [in] */ uint16_t blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLEDIllumination( 
            /* [out] */ uint16_t *red,
            /* [out] */ uint16_t *green,
            /* [out] */ uint16_t *blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultLEDIllumination( 
            /* [out] */ uint16_t *red,
            /* [out] */ uint16_t *green,
            /* [out] */ uint16_t *blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartFixedPatternGainCalibration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFixedPatternGainCalibrated( 
            /* [out] */ BOOL *calibrated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartLEDCalibration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLEDCalibrationStatus( 
            /* [out] */ BMDScannerCalibrationStatus *status) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHDRCalibrationStatus( 
            /* [out] */ BMDScannerCalibrationStatus *status) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFixedPatternGainCalibrationStatus( 
            /* [out] */ BMDScannerCalibrationStatus *status) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFocusPeakingEnable( 
            /* [in] */ BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFocusPeakingEnable( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFocusPeakingEnable( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableHDRMode( 
            /* [in] */ BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableHDRMode( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultEnableHDRMode( 
            /* [out] */ BOOL *enable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerColorPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerColorProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerColorProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerColorProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetLEDIllumination )( 
            IScannerColorProperties * This,
            /* [in] */ uint16_t red,
            /* [in] */ uint16_t green,
            /* [in] */ uint16_t blue);
        
        HRESULT ( STDMETHODCALLTYPE *GetLEDIllumination )( 
            IScannerColorProperties * This,
            /* [out] */ uint16_t *red,
            /* [out] */ uint16_t *green,
            /* [out] */ uint16_t *blue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultLEDIllumination )( 
            IScannerColorProperties * This,
            /* [out] */ uint16_t *red,
            /* [out] */ uint16_t *green,
            /* [out] */ uint16_t *blue);
        
        HRESULT ( STDMETHODCALLTYPE *StartFixedPatternGainCalibration )( 
            IScannerColorProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFixedPatternGainCalibrated )( 
            IScannerColorProperties * This,
            /* [out] */ BOOL *calibrated);
        
        HRESULT ( STDMETHODCALLTYPE *StartLEDCalibration )( 
            IScannerColorProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLEDCalibrationStatus )( 
            IScannerColorProperties * This,
            /* [out] */ BMDScannerCalibrationStatus *status);
        
        HRESULT ( STDMETHODCALLTYPE *GetHDRCalibrationStatus )( 
            IScannerColorProperties * This,
            /* [out] */ BMDScannerCalibrationStatus *status);
        
        HRESULT ( STDMETHODCALLTYPE *GetFixedPatternGainCalibrationStatus )( 
            IScannerColorProperties * This,
            /* [out] */ BMDScannerCalibrationStatus *status);
        
        HRESULT ( STDMETHODCALLTYPE *SetFocusPeakingEnable )( 
            IScannerColorProperties * This,
            /* [in] */ BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetFocusPeakingEnable )( 
            IScannerColorProperties * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFocusPeakingEnable )( 
            IScannerColorProperties * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *SetEnableHDRMode )( 
            IScannerColorProperties * This,
            /* [in] */ BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnableHDRMode )( 
            IScannerColorProperties * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultEnableHDRMode )( 
            IScannerColorProperties * This,
            /* [out] */ BOOL *enable);
        
        END_INTERFACE
    } IScannerColorPropertiesVtbl;

    interface IScannerColorProperties
    {
        CONST_VTBL struct IScannerColorPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerColorProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerColorProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerColorProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerColorProperties_SetLEDIllumination(This,red,green,blue)	\
    ( (This)->lpVtbl -> SetLEDIllumination(This,red,green,blue) ) 

#define IScannerColorProperties_GetLEDIllumination(This,red,green,blue)	\
    ( (This)->lpVtbl -> GetLEDIllumination(This,red,green,blue) ) 

#define IScannerColorProperties_GetDefaultLEDIllumination(This,red,green,blue)	\
    ( (This)->lpVtbl -> GetDefaultLEDIllumination(This,red,green,blue) ) 

#define IScannerColorProperties_StartFixedPatternGainCalibration(This)	\
    ( (This)->lpVtbl -> StartFixedPatternGainCalibration(This) ) 

#define IScannerColorProperties_GetFixedPatternGainCalibrated(This,calibrated)	\
    ( (This)->lpVtbl -> GetFixedPatternGainCalibrated(This,calibrated) ) 

#define IScannerColorProperties_StartLEDCalibration(This)	\
    ( (This)->lpVtbl -> StartLEDCalibration(This) ) 

#define IScannerColorProperties_GetLEDCalibrationStatus(This,status)	\
    ( (This)->lpVtbl -> GetLEDCalibrationStatus(This,status) ) 

#define IScannerColorProperties_GetHDRCalibrationStatus(This,status)	\
    ( (This)->lpVtbl -> GetHDRCalibrationStatus(This,status) ) 

#define IScannerColorProperties_GetFixedPatternGainCalibrationStatus(This,status)	\
    ( (This)->lpVtbl -> GetFixedPatternGainCalibrationStatus(This,status) ) 

#define IScannerColorProperties_SetFocusPeakingEnable(This,enable)	\
    ( (This)->lpVtbl -> SetFocusPeakingEnable(This,enable) ) 

#define IScannerColorProperties_GetFocusPeakingEnable(This,enable)	\
    ( (This)->lpVtbl -> GetFocusPeakingEnable(This,enable) ) 

#define IScannerColorProperties_GetDefaultFocusPeakingEnable(This,enable)	\
    ( (This)->lpVtbl -> GetDefaultFocusPeakingEnable(This,enable) ) 

#define IScannerColorProperties_SetEnableHDRMode(This,enable)	\
    ( (This)->lpVtbl -> SetEnableHDRMode(This,enable) ) 

#define IScannerColorProperties_GetEnableHDRMode(This,enable)	\
    ( (This)->lpVtbl -> GetEnableHDRMode(This,enable) ) 

#define IScannerColorProperties_GetDefaultEnableHDRMode(This,enable)	\
    ( (This)->lpVtbl -> GetDefaultEnableHDRMode(This,enable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerColorProperties_INTERFACE_DEFINED__ */


#ifndef __IScannerImageStabilizer_INTERFACE_DEFINED__
#define __IScannerImageStabilizer_INTERFACE_DEFINED__

/* interface IScannerImageStabilizer */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerImageStabilizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("702C52DC-E4F1-4FB1-8C4E-9DC02BFED2DB")
    IScannerImageStabilizer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStabilizationEnable( 
            /* [in] */ BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStabilizationEnable( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultStabilizationEnable( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStabilizationEnableXY( 
            /* [in] */ BOOL enableX,
            /* [in] */ BOOL enableY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStabilizationEnableXY( 
            /* [out] */ BOOL *enableX,
            /* [out] */ BOOL *enableY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultStabilizationEnableXY( 
            /* [out] */ BOOL *enableX,
            /* [out] */ BOOL *enableY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStabilizationViewRegion( 
            /* [in] */ BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStabilizationViewRegion( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultStabilizationViewRegion( 
            /* [out] */ BOOL *enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStabilizationOffsetX( 
            /* [in] */ int16_t stabilizationOffsetX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStabilizationOffsetX( 
            /* [out] */ int16_t *stabilizationOffsetX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumStabilizationOffsetX( 
            /* [out] */ int16_t *stabilizationOffsetX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumStabilizationOffsetX( 
            /* [out] */ int16_t *stabilizationOffsetX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultStabilizationOffsetX( 
            /* [out] */ int16_t *stabilizationOffsetX) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerImageStabilizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerImageStabilizer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerImageStabilizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerImageStabilizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetStabilizationEnable )( 
            IScannerImageStabilizer * This,
            /* [in] */ BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetStabilizationEnable )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultStabilizationEnable )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *SetStabilizationEnableXY )( 
            IScannerImageStabilizer * This,
            /* [in] */ BOOL enableX,
            /* [in] */ BOOL enableY);
        
        HRESULT ( STDMETHODCALLTYPE *GetStabilizationEnableXY )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enableX,
            /* [out] */ BOOL *enableY);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultStabilizationEnableXY )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enableX,
            /* [out] */ BOOL *enableY);
        
        HRESULT ( STDMETHODCALLTYPE *SetStabilizationViewRegion )( 
            IScannerImageStabilizer * This,
            /* [in] */ BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetStabilizationViewRegion )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultStabilizationViewRegion )( 
            IScannerImageStabilizer * This,
            /* [out] */ BOOL *enable);
        
        HRESULT ( STDMETHODCALLTYPE *SetStabilizationOffsetX )( 
            IScannerImageStabilizer * This,
            /* [in] */ int16_t stabilizationOffsetX);
        
        HRESULT ( STDMETHODCALLTYPE *GetStabilizationOffsetX )( 
            IScannerImageStabilizer * This,
            /* [out] */ int16_t *stabilizationOffsetX);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumStabilizationOffsetX )( 
            IScannerImageStabilizer * This,
            /* [out] */ int16_t *stabilizationOffsetX);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumStabilizationOffsetX )( 
            IScannerImageStabilizer * This,
            /* [out] */ int16_t *stabilizationOffsetX);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultStabilizationOffsetX )( 
            IScannerImageStabilizer * This,
            /* [out] */ int16_t *stabilizationOffsetX);
        
        END_INTERFACE
    } IScannerImageStabilizerVtbl;

    interface IScannerImageStabilizer
    {
        CONST_VTBL struct IScannerImageStabilizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerImageStabilizer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerImageStabilizer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerImageStabilizer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerImageStabilizer_SetStabilizationEnable(This,enable)	\
    ( (This)->lpVtbl -> SetStabilizationEnable(This,enable) ) 

#define IScannerImageStabilizer_GetStabilizationEnable(This,enable)	\
    ( (This)->lpVtbl -> GetStabilizationEnable(This,enable) ) 

#define IScannerImageStabilizer_GetDefaultStabilizationEnable(This,enable)	\
    ( (This)->lpVtbl -> GetDefaultStabilizationEnable(This,enable) ) 

#define IScannerImageStabilizer_SetStabilizationEnableXY(This,enableX,enableY)	\
    ( (This)->lpVtbl -> SetStabilizationEnableXY(This,enableX,enableY) ) 

#define IScannerImageStabilizer_GetStabilizationEnableXY(This,enableX,enableY)	\
    ( (This)->lpVtbl -> GetStabilizationEnableXY(This,enableX,enableY) ) 

#define IScannerImageStabilizer_GetDefaultStabilizationEnableXY(This,enableX,enableY)	\
    ( (This)->lpVtbl -> GetDefaultStabilizationEnableXY(This,enableX,enableY) ) 

#define IScannerImageStabilizer_SetStabilizationViewRegion(This,enable)	\
    ( (This)->lpVtbl -> SetStabilizationViewRegion(This,enable) ) 

#define IScannerImageStabilizer_GetStabilizationViewRegion(This,enable)	\
    ( (This)->lpVtbl -> GetStabilizationViewRegion(This,enable) ) 

#define IScannerImageStabilizer_GetDefaultStabilizationViewRegion(This,enable)	\
    ( (This)->lpVtbl -> GetDefaultStabilizationViewRegion(This,enable) ) 

#define IScannerImageStabilizer_SetStabilizationOffsetX(This,stabilizationOffsetX)	\
    ( (This)->lpVtbl -> SetStabilizationOffsetX(This,stabilizationOffsetX) ) 

#define IScannerImageStabilizer_GetStabilizationOffsetX(This,stabilizationOffsetX)	\
    ( (This)->lpVtbl -> GetStabilizationOffsetX(This,stabilizationOffsetX) ) 

#define IScannerImageStabilizer_GetMinimumStabilizationOffsetX(This,stabilizationOffsetX)	\
    ( (This)->lpVtbl -> GetMinimumStabilizationOffsetX(This,stabilizationOffsetX) ) 

#define IScannerImageStabilizer_GetMaximumStabilizationOffsetX(This,stabilizationOffsetX)	\
    ( (This)->lpVtbl -> GetMaximumStabilizationOffsetX(This,stabilizationOffsetX) ) 

#define IScannerImageStabilizer_GetDefaultStabilizationOffsetX(This,stabilizationOffsetX)	\
    ( (This)->lpVtbl -> GetDefaultStabilizationOffsetX(This,stabilizationOffsetX) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerImageStabilizer_INTERFACE_DEFINED__ */


#ifndef __IScannerCapture_INTERFACE_DEFINED__
#define __IScannerCapture_INTERFACE_DEFINED__

/* interface IScannerCapture */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerCapture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12B23298-5ABC-4B48-9A22-CEB11630D17C")
    IScannerCapture : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCompressionType( 
            /* [in] */ BMDScannerCompressionType type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompressionType( 
            /* [out] */ BMDScannerCompressionType *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultCompressionType( 
            /* [out] */ BMDScannerCompressionType *type) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerCaptureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerCapture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerCapture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerCapture * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompressionType )( 
            IScannerCapture * This,
            /* [in] */ BMDScannerCompressionType type);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompressionType )( 
            IScannerCapture * This,
            /* [out] */ BMDScannerCompressionType *type);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultCompressionType )( 
            IScannerCapture * This,
            /* [out] */ BMDScannerCompressionType *type);
        
        END_INTERFACE
    } IScannerCaptureVtbl;

    interface IScannerCapture
    {
        CONST_VTBL struct IScannerCaptureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerCapture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerCapture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerCapture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerCapture_SetCompressionType(This,type)	\
    ( (This)->lpVtbl -> SetCompressionType(This,type) ) 

#define IScannerCapture_GetCompressionType(This,type)	\
    ( (This)->lpVtbl -> GetCompressionType(This,type) ) 

#define IScannerCapture_GetDefaultCompressionType(This,type)	\
    ( (This)->lpVtbl -> GetDefaultCompressionType(This,type) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerCapture_INTERFACE_DEFINED__ */


#ifndef __IScannerAudioSelect_INTERFACE_DEFINED__
#define __IScannerAudioSelect_INTERFACE_DEFINED__

/* interface IScannerAudioSelect */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerAudioSelect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("778680C3-3C05-40D9-B855-0FDC588182BF")
    IScannerAudioSelect : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAudioSelectSource( 
            /* [in] */ BMDScannerAudioSelectSource audioSelectSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioSelectSource( 
            /* [out] */ BMDScannerAudioSelectSource *audioSelectSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultAudioSelectSource( 
            /* [out] */ BMDScannerAudioSelectSource *audioSelectSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioSourceAvailable( 
            /* [in] */ BMDScannerAudioSelectSource audioSource,
            /* [out] */ BOOL *available) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExternalAudioFormat( 
            /* [in] */ BMDScannerExternalAudioFormat externalAudioFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExternalAudioFormat( 
            /* [out] */ BMDScannerExternalAudioFormat *externalAudioFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultExternalAudioFormat( 
            /* [out] */ BMDScannerExternalAudioFormat *externalAudioFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncConfiguration( 
            /* [in] */ BMDScannerSyncLTCConfig syncltc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncConfiguration( 
            /* [out] */ BMDScannerSyncLTCConfig *syncltc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultSyncConfiguration( 
            /* [out] */ BMDScannerSyncLTCConfig *syncltc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerAudioSelectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerAudioSelect * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerAudioSelect * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerAudioSelect * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAudioSelectSource )( 
            IScannerAudioSelect * This,
            /* [in] */ BMDScannerAudioSelectSource audioSelectSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioSelectSource )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerAudioSelectSource *audioSelectSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultAudioSelectSource )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerAudioSelectSource *audioSelectSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioSourceAvailable )( 
            IScannerAudioSelect * This,
            /* [in] */ BMDScannerAudioSelectSource audioSource,
            /* [out] */ BOOL *available);
        
        HRESULT ( STDMETHODCALLTYPE *SetExternalAudioFormat )( 
            IScannerAudioSelect * This,
            /* [in] */ BMDScannerExternalAudioFormat externalAudioFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetExternalAudioFormat )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerExternalAudioFormat *externalAudioFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultExternalAudioFormat )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerExternalAudioFormat *externalAudioFormat);
        
        HRESULT ( STDMETHODCALLTYPE *SetSyncConfiguration )( 
            IScannerAudioSelect * This,
            /* [in] */ BMDScannerSyncLTCConfig syncltc);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncConfiguration )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerSyncLTCConfig *syncltc);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultSyncConfiguration )( 
            IScannerAudioSelect * This,
            /* [out] */ BMDScannerSyncLTCConfig *syncltc);
        
        END_INTERFACE
    } IScannerAudioSelectVtbl;

    interface IScannerAudioSelect
    {
        CONST_VTBL struct IScannerAudioSelectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerAudioSelect_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerAudioSelect_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerAudioSelect_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerAudioSelect_SetAudioSelectSource(This,audioSelectSource)	\
    ( (This)->lpVtbl -> SetAudioSelectSource(This,audioSelectSource) ) 

#define IScannerAudioSelect_GetAudioSelectSource(This,audioSelectSource)	\
    ( (This)->lpVtbl -> GetAudioSelectSource(This,audioSelectSource) ) 

#define IScannerAudioSelect_GetDefaultAudioSelectSource(This,audioSelectSource)	\
    ( (This)->lpVtbl -> GetDefaultAudioSelectSource(This,audioSelectSource) ) 

#define IScannerAudioSelect_GetAudioSourceAvailable(This,audioSource,available)	\
    ( (This)->lpVtbl -> GetAudioSourceAvailable(This,audioSource,available) ) 

#define IScannerAudioSelect_SetExternalAudioFormat(This,externalAudioFormat)	\
    ( (This)->lpVtbl -> SetExternalAudioFormat(This,externalAudioFormat) ) 

#define IScannerAudioSelect_GetExternalAudioFormat(This,externalAudioFormat)	\
    ( (This)->lpVtbl -> GetExternalAudioFormat(This,externalAudioFormat) ) 

#define IScannerAudioSelect_GetDefaultExternalAudioFormat(This,externalAudioFormat)	\
    ( (This)->lpVtbl -> GetDefaultExternalAudioFormat(This,externalAudioFormat) ) 

#define IScannerAudioSelect_SetSyncConfiguration(This,syncltc)	\
    ( (This)->lpVtbl -> SetSyncConfiguration(This,syncltc) ) 

#define IScannerAudioSelect_GetSyncConfiguration(This,syncltc)	\
    ( (This)->lpVtbl -> GetSyncConfiguration(This,syncltc) ) 

#define IScannerAudioSelect_GetDefaultSyncConfiguration(This,syncltc)	\
    ( (This)->lpVtbl -> GetDefaultSyncConfiguration(This,syncltc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerAudioSelect_INTERFACE_DEFINED__ */


#ifndef __IScannerReader_INTERFACE_DEFINED__
#define __IScannerReader_INTERFACE_DEFINED__

/* interface IScannerReader */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScannerReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18BED793-3D95-4332-B28B-E5F69B87DB42")
    IScannerReader : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetReaderPresent( 
            /* [out] */ BOOL *present) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReaderMode( 
            /* [out] */ BMDReaderMode *mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultReaderMode( 
            /* [out] */ BMDReaderMode *mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReaderMode( 
            /* [in] */ BMDReaderMode mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMagneticAudioAllowed( 
            /* [out] */ BOOL *magneticAudioAllowed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioMode( 
            /* [in] */ BMDReaderAudioMode audioMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioMode( 
            /* [out] */ BMDReaderAudioMode *audioMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultAudioMode( 
            /* [out] */ BMDReaderAudioMode *audioMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioPresent( 
            /* [out] */ BOOL *present) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScannerReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerReader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerReader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerReader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetReaderPresent )( 
            IScannerReader * This,
            /* [out] */ BOOL *present);
        
        HRESULT ( STDMETHODCALLTYPE *GetReaderMode )( 
            IScannerReader * This,
            /* [out] */ BMDReaderMode *mode);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultReaderMode )( 
            IScannerReader * This,
            /* [out] */ BMDReaderMode *mode);
        
        HRESULT ( STDMETHODCALLTYPE *SetReaderMode )( 
            IScannerReader * This,
            /* [in] */ BMDReaderMode mode);
        
        HRESULT ( STDMETHODCALLTYPE *GetMagneticAudioAllowed )( 
            IScannerReader * This,
            /* [out] */ BOOL *magneticAudioAllowed);
        
        HRESULT ( STDMETHODCALLTYPE *SetAudioMode )( 
            IScannerReader * This,
            /* [in] */ BMDReaderAudioMode audioMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioMode )( 
            IScannerReader * This,
            /* [out] */ BMDReaderAudioMode *audioMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultAudioMode )( 
            IScannerReader * This,
            /* [out] */ BMDReaderAudioMode *audioMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioPresent )( 
            IScannerReader * This,
            /* [out] */ BOOL *present);
        
        END_INTERFACE
    } IScannerReaderVtbl;

    interface IScannerReader
    {
        CONST_VTBL struct IScannerReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScannerReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScannerReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScannerReader_GetReaderPresent(This,present)	\
    ( (This)->lpVtbl -> GetReaderPresent(This,present) ) 

#define IScannerReader_GetReaderMode(This,mode)	\
    ( (This)->lpVtbl -> GetReaderMode(This,mode) ) 

#define IScannerReader_GetDefaultReaderMode(This,mode)	\
    ( (This)->lpVtbl -> GetDefaultReaderMode(This,mode) ) 

#define IScannerReader_SetReaderMode(This,mode)	\
    ( (This)->lpVtbl -> SetReaderMode(This,mode) ) 

#define IScannerReader_GetMagneticAudioAllowed(This,magneticAudioAllowed)	\
    ( (This)->lpVtbl -> GetMagneticAudioAllowed(This,magneticAudioAllowed) ) 

#define IScannerReader_SetAudioMode(This,audioMode)	\
    ( (This)->lpVtbl -> SetAudioMode(This,audioMode) ) 

#define IScannerReader_GetAudioMode(This,audioMode)	\
    ( (This)->lpVtbl -> GetAudioMode(This,audioMode) ) 

#define IScannerReader_GetDefaultAudioMode(This,audioMode)	\
    ( (This)->lpVtbl -> GetDefaultAudioMode(This,audioMode) ) 

#define IScannerReader_GetAudioPresent(This,present)	\
    ( (This)->lpVtbl -> GetAudioPresent(This,present) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScannerReader_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CScannerDiscovery;

#ifdef __cplusplus

class DECLSPEC_UUID("B60B1DC4-CF79-4478-987B-5B962202B71B")
CScannerDiscovery;
#endif

EXTERN_C const CLSID CLSID_CScannerAPIInformation;

#ifdef __cplusplus

class DECLSPEC_UUID("EAA3246E-B9C8-4436-ADE2-44702400CEB8")
CScannerAPIInformation;
#endif
#endif /* __ScannerAPI_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


