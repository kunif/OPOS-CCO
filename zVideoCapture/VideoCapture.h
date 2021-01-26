

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for VideoCapture.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __VideoCapture_h__
#define __VideoCapture_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSVideoCapture_1_16_FWD_DEFINED__
#define __IOPOSVideoCapture_1_16_FWD_DEFINED__
typedef interface IOPOSVideoCapture_1_16 IOPOSVideoCapture_1_16;

#endif 	/* __IOPOSVideoCapture_1_16_FWD_DEFINED__ */


#ifndef __IOPOSVideoCapture_FWD_DEFINED__
#define __IOPOSVideoCapture_FWD_DEFINED__
typedef interface IOPOSVideoCapture IOPOSVideoCapture;

#endif 	/* __IOPOSVideoCapture_FWD_DEFINED__ */


#ifndef ___IOPOSVideoCaptureEvents_FWD_DEFINED__
#define ___IOPOSVideoCaptureEvents_FWD_DEFINED__
typedef interface _IOPOSVideoCaptureEvents _IOPOSVideoCaptureEvents;

#endif 	/* ___IOPOSVideoCaptureEvents_FWD_DEFINED__ */


#ifndef __OPOSVideoCapture_FWD_DEFINED__
#define __OPOSVideoCapture_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSVideoCapture OPOSVideoCapture;
#else
typedef struct OPOSVideoCapture OPOSVideoCapture;
#endif /* __cplusplus */

#endif 	/* __OPOSVideoCapture_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSVideoCapture_1_16_INTERFACE_DEFINED__
#define __IOPOSVideoCapture_1_16_INTERFACE_DEFINED__

/* interface IOPOSVideoCapture_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSVideoCapture_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90451-B81E-11D2-AB74-0040054C3719")
    IOPOSVideoCapture_1_16 : public IDispatch
    {
    public:
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SODataDummy( 
            /* [in] */ long Status) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SODirectIO( 
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOError( 
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOOutputCompleteDummy( 
            /* [in] */ long OutputID) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOStatusUpdate( 
            /* [in] */ long Data) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOProcessID( 
            /* [retval][out] */ long *pProcessID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OpenResult( 
            /* [retval][out] */ long *pOpenResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BinaryConversion( 
            /* [retval][out] */ long *pBinaryConversion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BinaryConversion( 
            /* [in] */ long BinaryConversion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPowerReporting( 
            /* [retval][out] */ long *pCapPowerReporting) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CheckHealthText( 
            /* [retval][out] */ BSTR *pCheckHealthText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Claimed( 
            /* [retval][out] */ VARIANT_BOOL *pClaimed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DeviceEnabled( 
            /* [in] */ VARIANT_BOOL DeviceEnabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FreezeEvents( 
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FreezeEvents( 
            /* [in] */ VARIANT_BOOL FreezeEvents) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PowerNotify( 
            /* [retval][out] */ long *pPowerNotify) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PowerNotify( 
            /* [in] */ long PowerNotify) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PowerState( 
            /* [retval][out] */ long *pPowerState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResultCode( 
            /* [retval][out] */ long *pResultCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResultCodeExtended( 
            /* [retval][out] */ long *pResultCodeExtended) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ long *pState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ControlObjectDescription( 
            /* [retval][out] */ BSTR *pControlObjectDescription) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ControlObjectVersion( 
            /* [retval][out] */ long *pControlObjectVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceObjectDescription( 
            /* [retval][out] */ BSTR *pServiceObjectDescription) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceObjectVersion( 
            /* [retval][out] */ long *pServiceObjectVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceDescription( 
            /* [retval][out] */ BSTR *pDeviceDescription) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceName( 
            /* [retval][out] */ BSTR *pDeviceName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapStatisticsReporting( 
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapUpdateStatistics( 
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapCompareFirmwareVersion( 
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapUpdateFirmware( 
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckHealth( 
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClaimDevice( 
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearInput( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DirectIO( 
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseDevice( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetStatistics( 
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RetrieveStatistics( 
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateStatistics( 
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CompareFirmwareVersion( 
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateFirmware( 
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoExposure( 
            /* [retval][out] */ VARIANT_BOOL *pAutoExposure) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoExposure( 
            /* [in] */ VARIANT_BOOL AutoExposure) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoFocus( 
            /* [retval][out] */ VARIANT_BOOL *pAutoFocus) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoFocus( 
            /* [in] */ VARIANT_BOOL AutoFocus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoGain( 
            /* [retval][out] */ VARIANT_BOOL *pAutoGain) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoGain( 
            /* [in] */ VARIANT_BOOL AutoGain) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoWhiteBalance( 
            /* [retval][out] */ VARIANT_BOOL *pAutoWhiteBalance) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoWhiteBalance( 
            /* [in] */ VARIANT_BOOL AutoWhiteBalance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [retval][out] */ long *pBrightness) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [in] */ long Brightness) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAssociatedHardTotalsDevice( 
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAutoExposure( 
            /* [retval][out] */ VARIANT_BOOL *pCapAutoExposure) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAutoFocus( 
            /* [retval][out] */ VARIANT_BOOL *pCapAutoFocus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAutoGain( 
            /* [retval][out] */ VARIANT_BOOL *pCapAutoGain) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAutoWhiteBalance( 
            /* [retval][out] */ VARIANT_BOOL *pCapAutoWhiteBalance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapBrightness( 
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapContrast( 
            /* [retval][out] */ VARIANT_BOOL *pCapContrast) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapExposure( 
            /* [retval][out] */ VARIANT_BOOL *pCapExposure) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapGain( 
            /* [retval][out] */ VARIANT_BOOL *pCapGain) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapHorizontalFlip( 
            /* [retval][out] */ VARIANT_BOOL *pCapHorizontalFlip) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapHue( 
            /* [retval][out] */ VARIANT_BOOL *pCapHue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPhoto( 
            /* [retval][out] */ VARIANT_BOOL *pCapPhoto) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPhotoColorSpace( 
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoColorSpace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPhotoFrameRate( 
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPhotoResolution( 
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoResolution) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPhotoType( 
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapSaturation( 
            /* [retval][out] */ VARIANT_BOOL *pCapSaturation) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapStorage( 
            /* [retval][out] */ long *pCapStorage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVerticalFlip( 
            /* [retval][out] */ VARIANT_BOOL *pCapVerticalFlip) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideo( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideoColorSpace( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideoColorSpace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideoFrameRate( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideoFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideoResolution( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideoResolution) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideoType( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Contrast( 
            /* [retval][out] */ long *pContrast) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Contrast( 
            /* [in] */ long Contrast) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Exposure( 
            /* [retval][out] */ long *pExposure) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Exposure( 
            /* [in] */ long Exposure) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gain( 
            /* [retval][out] */ long *pGain) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gain( 
            /* [in] */ long Gain) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalFlip( 
            /* [retval][out] */ VARIANT_BOOL *pHorizontalFlip) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HorizontalFlip( 
            /* [in] */ VARIANT_BOOL HorizontalFlip) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hue( 
            /* [retval][out] */ long *pHue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Hue( 
            /* [in] */ long Hue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoColorSpace( 
            /* [retval][out] */ BSTR *pPhotoColorSpace) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhotoColorSpace( 
            /* [in] */ BSTR PhotoColorSpace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoColorSpaceList( 
            /* [retval][out] */ BSTR *pPhotoColorSpaceList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoFrameRate( 
            /* [retval][out] */ long *pPhotoFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhotoFrameRate( 
            /* [in] */ long PhotoFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoMaxFrameRate( 
            /* [retval][out] */ long *pPhotoMaxFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoResolution( 
            /* [retval][out] */ BSTR *pPhotoResolution) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhotoResolution( 
            /* [in] */ BSTR PhotoResolution) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoResolutionList( 
            /* [retval][out] */ BSTR *pPhotoResolutionList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoType( 
            /* [retval][out] */ BSTR *pPhotoType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PhotoType( 
            /* [in] */ BSTR PhotoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PhotoTypeList( 
            /* [retval][out] */ BSTR *pPhotoTypeList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemainingRecordingTimeInSec( 
            /* [retval][out] */ long *pRemainingRecordingTimeInSec) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Saturation( 
            /* [retval][out] */ long *pSaturation) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Saturation( 
            /* [in] */ long Saturation) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ long *pStorage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Storage( 
            /* [in] */ long Storage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VerticalFlip( 
            /* [retval][out] */ VARIANT_BOOL *pVerticalFlip) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VerticalFlip( 
            /* [in] */ VARIANT_BOOL VerticalFlip) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoCaptureMode( 
            /* [retval][out] */ long *pVideoCaptureMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoCaptureMode( 
            /* [in] */ long VideoCaptureMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoColorSpace( 
            /* [retval][out] */ BSTR *pVideoColorSpace) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoColorSpace( 
            /* [in] */ BSTR VideoColorSpace) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoColorSpaceList( 
            /* [retval][out] */ BSTR *pVideoColorSpaceList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoFrameRate( 
            /* [retval][out] */ long *pVideoFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoFrameRate( 
            /* [in] */ long VideoFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoMaxFrameRate( 
            /* [retval][out] */ long *pVideoMaxFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoResolution( 
            /* [retval][out] */ BSTR *pVideoResolution) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoResolution( 
            /* [in] */ BSTR VideoResolution) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoResolutionList( 
            /* [retval][out] */ BSTR *pVideoResolutionList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoType( 
            /* [retval][out] */ BSTR *pVideoType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoType( 
            /* [in] */ BSTR VideoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoTypeList( 
            /* [retval][out] */ BSTR *pVideoTypeList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartVideo( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopVideo( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TakePhoto( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSVideoCapture_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSVideoCapture_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSVideoCapture_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSVideoCapture_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSVideoCapture_1_16 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODataDummy )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSVideoCapture_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoExposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoExposure);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoExposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoFocus )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoFocus);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoFocus )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoFocus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoGain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoGain);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoGain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoWhiteBalance )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoWhiteBalance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoWhiteBalance )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoWhiteBalance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pBrightness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Brightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoExposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoFocus )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoFocus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoGain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoWhiteBalance )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoWhiteBalance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapBrightness )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapContrast )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapContrast);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapExposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapGain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapHorizontalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapHorizontalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapHue )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapHue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhoto )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhoto);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSaturation )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSaturation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVerticalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVerticalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideo )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Contrast )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pContrast);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Contrast )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Contrast);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Exposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pExposure);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Exposure )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Exposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pGain);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gain )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Gain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pHorizontalFlip);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HorizontalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL HorizontalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pHue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Hue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoColorSpace);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR PhotoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoColorSpaceList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoColorSpaceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pPhotoFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long PhotoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoMaxFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pPhotoMaxFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoResolution);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR PhotoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoResolutionList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoResolutionList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR PhotoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoTypeList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pPhotoTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemainingRecordingTimeInSec )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pRemainingRecordingTimeInSec);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Saturation )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pSaturation);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Saturation )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Saturation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pVerticalFlip);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VerticalFlip )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ VARIANT_BOOL VerticalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoCaptureMode )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pVideoCaptureMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoCaptureMode )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long VideoCaptureMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoColorSpace);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoColorSpace )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR VideoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoColorSpaceList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoColorSpaceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pVideoFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ long VideoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoMaxFrameRate )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pVideoMaxFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoResolution);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoResolution )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR VideoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoResolutionList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoResolutionList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoType )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR VideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoTypeList )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ BSTR *pVideoTypeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartVideo )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopVideo )( 
            IOPOSVideoCapture_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TakePhoto )( 
            IOPOSVideoCapture_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSVideoCapture_1_16Vtbl;

    interface IOPOSVideoCapture_1_16
    {
        CONST_VTBL struct IOPOSVideoCapture_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSVideoCapture_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSVideoCapture_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSVideoCapture_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSVideoCapture_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSVideoCapture_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSVideoCapture_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSVideoCapture_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSVideoCapture_1_16_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSVideoCapture_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSVideoCapture_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSVideoCapture_1_16_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSVideoCapture_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSVideoCapture_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSVideoCapture_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSVideoCapture_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSVideoCapture_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSVideoCapture_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSVideoCapture_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSVideoCapture_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSVideoCapture_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSVideoCapture_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSVideoCapture_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSVideoCapture_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSVideoCapture_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSVideoCapture_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSVideoCapture_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSVideoCapture_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSVideoCapture_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSVideoCapture_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSVideoCapture_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSVideoCapture_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSVideoCapture_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSVideoCapture_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSVideoCapture_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSVideoCapture_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSVideoCapture_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSVideoCapture_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSVideoCapture_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSVideoCapture_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSVideoCapture_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSVideoCapture_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSVideoCapture_1_16_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSVideoCapture_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSVideoCapture_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSVideoCapture_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSVideoCapture_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSVideoCapture_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSVideoCapture_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSVideoCapture_1_16_get_AutoExposure(This,pAutoExposure)	\
    ( (This)->lpVtbl -> get_AutoExposure(This,pAutoExposure) ) 

#define IOPOSVideoCapture_1_16_put_AutoExposure(This,AutoExposure)	\
    ( (This)->lpVtbl -> put_AutoExposure(This,AutoExposure) ) 

#define IOPOSVideoCapture_1_16_get_AutoFocus(This,pAutoFocus)	\
    ( (This)->lpVtbl -> get_AutoFocus(This,pAutoFocus) ) 

#define IOPOSVideoCapture_1_16_put_AutoFocus(This,AutoFocus)	\
    ( (This)->lpVtbl -> put_AutoFocus(This,AutoFocus) ) 

#define IOPOSVideoCapture_1_16_get_AutoGain(This,pAutoGain)	\
    ( (This)->lpVtbl -> get_AutoGain(This,pAutoGain) ) 

#define IOPOSVideoCapture_1_16_put_AutoGain(This,AutoGain)	\
    ( (This)->lpVtbl -> put_AutoGain(This,AutoGain) ) 

#define IOPOSVideoCapture_1_16_get_AutoWhiteBalance(This,pAutoWhiteBalance)	\
    ( (This)->lpVtbl -> get_AutoWhiteBalance(This,pAutoWhiteBalance) ) 

#define IOPOSVideoCapture_1_16_put_AutoWhiteBalance(This,AutoWhiteBalance)	\
    ( (This)->lpVtbl -> put_AutoWhiteBalance(This,AutoWhiteBalance) ) 

#define IOPOSVideoCapture_1_16_get_Brightness(This,pBrightness)	\
    ( (This)->lpVtbl -> get_Brightness(This,pBrightness) ) 

#define IOPOSVideoCapture_1_16_put_Brightness(This,Brightness)	\
    ( (This)->lpVtbl -> put_Brightness(This,Brightness) ) 

#define IOPOSVideoCapture_1_16_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSVideoCapture_1_16_get_CapAutoExposure(This,pCapAutoExposure)	\
    ( (This)->lpVtbl -> get_CapAutoExposure(This,pCapAutoExposure) ) 

#define IOPOSVideoCapture_1_16_get_CapAutoFocus(This,pCapAutoFocus)	\
    ( (This)->lpVtbl -> get_CapAutoFocus(This,pCapAutoFocus) ) 

#define IOPOSVideoCapture_1_16_get_CapAutoGain(This,pCapAutoGain)	\
    ( (This)->lpVtbl -> get_CapAutoGain(This,pCapAutoGain) ) 

#define IOPOSVideoCapture_1_16_get_CapAutoWhiteBalance(This,pCapAutoWhiteBalance)	\
    ( (This)->lpVtbl -> get_CapAutoWhiteBalance(This,pCapAutoWhiteBalance) ) 

#define IOPOSVideoCapture_1_16_get_CapBrightness(This,pCapBrightness)	\
    ( (This)->lpVtbl -> get_CapBrightness(This,pCapBrightness) ) 

#define IOPOSVideoCapture_1_16_get_CapContrast(This,pCapContrast)	\
    ( (This)->lpVtbl -> get_CapContrast(This,pCapContrast) ) 

#define IOPOSVideoCapture_1_16_get_CapExposure(This,pCapExposure)	\
    ( (This)->lpVtbl -> get_CapExposure(This,pCapExposure) ) 

#define IOPOSVideoCapture_1_16_get_CapGain(This,pCapGain)	\
    ( (This)->lpVtbl -> get_CapGain(This,pCapGain) ) 

#define IOPOSVideoCapture_1_16_get_CapHorizontalFlip(This,pCapHorizontalFlip)	\
    ( (This)->lpVtbl -> get_CapHorizontalFlip(This,pCapHorizontalFlip) ) 

#define IOPOSVideoCapture_1_16_get_CapHue(This,pCapHue)	\
    ( (This)->lpVtbl -> get_CapHue(This,pCapHue) ) 

#define IOPOSVideoCapture_1_16_get_CapPhoto(This,pCapPhoto)	\
    ( (This)->lpVtbl -> get_CapPhoto(This,pCapPhoto) ) 

#define IOPOSVideoCapture_1_16_get_CapPhotoColorSpace(This,pCapPhotoColorSpace)	\
    ( (This)->lpVtbl -> get_CapPhotoColorSpace(This,pCapPhotoColorSpace) ) 

#define IOPOSVideoCapture_1_16_get_CapPhotoFrameRate(This,pCapPhotoFrameRate)	\
    ( (This)->lpVtbl -> get_CapPhotoFrameRate(This,pCapPhotoFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_CapPhotoResolution(This,pCapPhotoResolution)	\
    ( (This)->lpVtbl -> get_CapPhotoResolution(This,pCapPhotoResolution) ) 

#define IOPOSVideoCapture_1_16_get_CapPhotoType(This,pCapPhotoType)	\
    ( (This)->lpVtbl -> get_CapPhotoType(This,pCapPhotoType) ) 

#define IOPOSVideoCapture_1_16_get_CapSaturation(This,pCapSaturation)	\
    ( (This)->lpVtbl -> get_CapSaturation(This,pCapSaturation) ) 

#define IOPOSVideoCapture_1_16_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSVideoCapture_1_16_get_CapVerticalFlip(This,pCapVerticalFlip)	\
    ( (This)->lpVtbl -> get_CapVerticalFlip(This,pCapVerticalFlip) ) 

#define IOPOSVideoCapture_1_16_get_CapVideo(This,pCapVideo)	\
    ( (This)->lpVtbl -> get_CapVideo(This,pCapVideo) ) 

#define IOPOSVideoCapture_1_16_get_CapVideoColorSpace(This,pCapVideoColorSpace)	\
    ( (This)->lpVtbl -> get_CapVideoColorSpace(This,pCapVideoColorSpace) ) 

#define IOPOSVideoCapture_1_16_get_CapVideoFrameRate(This,pCapVideoFrameRate)	\
    ( (This)->lpVtbl -> get_CapVideoFrameRate(This,pCapVideoFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_CapVideoResolution(This,pCapVideoResolution)	\
    ( (This)->lpVtbl -> get_CapVideoResolution(This,pCapVideoResolution) ) 

#define IOPOSVideoCapture_1_16_get_CapVideoType(This,pCapVideoType)	\
    ( (This)->lpVtbl -> get_CapVideoType(This,pCapVideoType) ) 

#define IOPOSVideoCapture_1_16_get_Contrast(This,pContrast)	\
    ( (This)->lpVtbl -> get_Contrast(This,pContrast) ) 

#define IOPOSVideoCapture_1_16_put_Contrast(This,Contrast)	\
    ( (This)->lpVtbl -> put_Contrast(This,Contrast) ) 

#define IOPOSVideoCapture_1_16_get_Exposure(This,pExposure)	\
    ( (This)->lpVtbl -> get_Exposure(This,pExposure) ) 

#define IOPOSVideoCapture_1_16_put_Exposure(This,Exposure)	\
    ( (This)->lpVtbl -> put_Exposure(This,Exposure) ) 

#define IOPOSVideoCapture_1_16_get_Gain(This,pGain)	\
    ( (This)->lpVtbl -> get_Gain(This,pGain) ) 

#define IOPOSVideoCapture_1_16_put_Gain(This,Gain)	\
    ( (This)->lpVtbl -> put_Gain(This,Gain) ) 

#define IOPOSVideoCapture_1_16_get_HorizontalFlip(This,pHorizontalFlip)	\
    ( (This)->lpVtbl -> get_HorizontalFlip(This,pHorizontalFlip) ) 

#define IOPOSVideoCapture_1_16_put_HorizontalFlip(This,HorizontalFlip)	\
    ( (This)->lpVtbl -> put_HorizontalFlip(This,HorizontalFlip) ) 

#define IOPOSVideoCapture_1_16_get_Hue(This,pHue)	\
    ( (This)->lpVtbl -> get_Hue(This,pHue) ) 

#define IOPOSVideoCapture_1_16_put_Hue(This,Hue)	\
    ( (This)->lpVtbl -> put_Hue(This,Hue) ) 

#define IOPOSVideoCapture_1_16_get_PhotoColorSpace(This,pPhotoColorSpace)	\
    ( (This)->lpVtbl -> get_PhotoColorSpace(This,pPhotoColorSpace) ) 

#define IOPOSVideoCapture_1_16_put_PhotoColorSpace(This,PhotoColorSpace)	\
    ( (This)->lpVtbl -> put_PhotoColorSpace(This,PhotoColorSpace) ) 

#define IOPOSVideoCapture_1_16_get_PhotoColorSpaceList(This,pPhotoColorSpaceList)	\
    ( (This)->lpVtbl -> get_PhotoColorSpaceList(This,pPhotoColorSpaceList) ) 

#define IOPOSVideoCapture_1_16_get_PhotoFrameRate(This,pPhotoFrameRate)	\
    ( (This)->lpVtbl -> get_PhotoFrameRate(This,pPhotoFrameRate) ) 

#define IOPOSVideoCapture_1_16_put_PhotoFrameRate(This,PhotoFrameRate)	\
    ( (This)->lpVtbl -> put_PhotoFrameRate(This,PhotoFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_PhotoMaxFrameRate(This,pPhotoMaxFrameRate)	\
    ( (This)->lpVtbl -> get_PhotoMaxFrameRate(This,pPhotoMaxFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_PhotoResolution(This,pPhotoResolution)	\
    ( (This)->lpVtbl -> get_PhotoResolution(This,pPhotoResolution) ) 

#define IOPOSVideoCapture_1_16_put_PhotoResolution(This,PhotoResolution)	\
    ( (This)->lpVtbl -> put_PhotoResolution(This,PhotoResolution) ) 

#define IOPOSVideoCapture_1_16_get_PhotoResolutionList(This,pPhotoResolutionList)	\
    ( (This)->lpVtbl -> get_PhotoResolutionList(This,pPhotoResolutionList) ) 

#define IOPOSVideoCapture_1_16_get_PhotoType(This,pPhotoType)	\
    ( (This)->lpVtbl -> get_PhotoType(This,pPhotoType) ) 

#define IOPOSVideoCapture_1_16_put_PhotoType(This,PhotoType)	\
    ( (This)->lpVtbl -> put_PhotoType(This,PhotoType) ) 

#define IOPOSVideoCapture_1_16_get_PhotoTypeList(This,pPhotoTypeList)	\
    ( (This)->lpVtbl -> get_PhotoTypeList(This,pPhotoTypeList) ) 

#define IOPOSVideoCapture_1_16_get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec)	\
    ( (This)->lpVtbl -> get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec) ) 

#define IOPOSVideoCapture_1_16_get_Saturation(This,pSaturation)	\
    ( (This)->lpVtbl -> get_Saturation(This,pSaturation) ) 

#define IOPOSVideoCapture_1_16_put_Saturation(This,Saturation)	\
    ( (This)->lpVtbl -> put_Saturation(This,Saturation) ) 

#define IOPOSVideoCapture_1_16_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSVideoCapture_1_16_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSVideoCapture_1_16_get_VerticalFlip(This,pVerticalFlip)	\
    ( (This)->lpVtbl -> get_VerticalFlip(This,pVerticalFlip) ) 

#define IOPOSVideoCapture_1_16_put_VerticalFlip(This,VerticalFlip)	\
    ( (This)->lpVtbl -> put_VerticalFlip(This,VerticalFlip) ) 

#define IOPOSVideoCapture_1_16_get_VideoCaptureMode(This,pVideoCaptureMode)	\
    ( (This)->lpVtbl -> get_VideoCaptureMode(This,pVideoCaptureMode) ) 

#define IOPOSVideoCapture_1_16_put_VideoCaptureMode(This,VideoCaptureMode)	\
    ( (This)->lpVtbl -> put_VideoCaptureMode(This,VideoCaptureMode) ) 

#define IOPOSVideoCapture_1_16_get_VideoColorSpace(This,pVideoColorSpace)	\
    ( (This)->lpVtbl -> get_VideoColorSpace(This,pVideoColorSpace) ) 

#define IOPOSVideoCapture_1_16_put_VideoColorSpace(This,VideoColorSpace)	\
    ( (This)->lpVtbl -> put_VideoColorSpace(This,VideoColorSpace) ) 

#define IOPOSVideoCapture_1_16_get_VideoColorSpaceList(This,pVideoColorSpaceList)	\
    ( (This)->lpVtbl -> get_VideoColorSpaceList(This,pVideoColorSpaceList) ) 

#define IOPOSVideoCapture_1_16_get_VideoFrameRate(This,pVideoFrameRate)	\
    ( (This)->lpVtbl -> get_VideoFrameRate(This,pVideoFrameRate) ) 

#define IOPOSVideoCapture_1_16_put_VideoFrameRate(This,VideoFrameRate)	\
    ( (This)->lpVtbl -> put_VideoFrameRate(This,VideoFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_VideoMaxFrameRate(This,pVideoMaxFrameRate)	\
    ( (This)->lpVtbl -> get_VideoMaxFrameRate(This,pVideoMaxFrameRate) ) 

#define IOPOSVideoCapture_1_16_get_VideoResolution(This,pVideoResolution)	\
    ( (This)->lpVtbl -> get_VideoResolution(This,pVideoResolution) ) 

#define IOPOSVideoCapture_1_16_put_VideoResolution(This,VideoResolution)	\
    ( (This)->lpVtbl -> put_VideoResolution(This,VideoResolution) ) 

#define IOPOSVideoCapture_1_16_get_VideoResolutionList(This,pVideoResolutionList)	\
    ( (This)->lpVtbl -> get_VideoResolutionList(This,pVideoResolutionList) ) 

#define IOPOSVideoCapture_1_16_get_VideoType(This,pVideoType)	\
    ( (This)->lpVtbl -> get_VideoType(This,pVideoType) ) 

#define IOPOSVideoCapture_1_16_put_VideoType(This,VideoType)	\
    ( (This)->lpVtbl -> put_VideoType(This,VideoType) ) 

#define IOPOSVideoCapture_1_16_get_VideoTypeList(This,pVideoTypeList)	\
    ( (This)->lpVtbl -> get_VideoTypeList(This,pVideoTypeList) ) 

#define IOPOSVideoCapture_1_16_StartVideo(This,FileName,OverWrite,RecordingTime,pRC)	\
    ( (This)->lpVtbl -> StartVideo(This,FileName,OverWrite,RecordingTime,pRC) ) 

#define IOPOSVideoCapture_1_16_StopVideo(This,pRC)	\
    ( (This)->lpVtbl -> StopVideo(This,pRC) ) 

#define IOPOSVideoCapture_1_16_TakePhoto(This,FileName,OverWrite,Timeout,pRC)	\
    ( (This)->lpVtbl -> TakePhoto(This,FileName,OverWrite,Timeout,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOPOSVideoCapture_1_16_StartVideo_Proxy( 
    IOPOSVideoCapture_1_16 * This,
    /* [in] */ BSTR FileName,
    /* [in] */ VARIANT_BOOL OverWrite,
    /* [in] */ long RecordingTime,
    /* [retval][out] */ long *pRC);


void __RPC_STUB IOPOSVideoCapture_1_16_StartVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOPOSVideoCapture_1_16_StopVideo_Proxy( 
    IOPOSVideoCapture_1_16 * This,
    /* [retval][out] */ long *pRC);


void __RPC_STUB IOPOSVideoCapture_1_16_StopVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOPOSVideoCapture_1_16_TakePhoto_Proxy( 
    IOPOSVideoCapture_1_16 * This,
    /* [in] */ BSTR FileName,
    /* [in] */ VARIANT_BOOL OverWrite,
    /* [in] */ long Timeout,
    /* [retval][out] */ long *pRC);


void __RPC_STUB IOPOSVideoCapture_1_16_TakePhoto_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPOSVideoCapture_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSVideoCapture_INTERFACE_DEFINED__
#define __IOPOSVideoCapture_INTERFACE_DEFINED__

/* interface IOPOSVideoCapture */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSVideoCapture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91451-B81E-11D2-AB74-0040054C3719")
    IOPOSVideoCapture : public IOPOSVideoCapture_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSVideoCaptureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSVideoCapture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSVideoCapture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSVideoCapture * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSVideoCapture * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSVideoCapture * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSVideoCapture * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSVideoCapture * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODataDummy )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSVideoCapture * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSVideoCapture * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSVideoCapture * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSVideoCapture * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSVideoCapture * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSVideoCapture * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoExposure )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoExposure);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoExposure )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL AutoExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoFocus )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoFocus);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoFocus )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL AutoFocus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoGain )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoGain);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoGain )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL AutoGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoWhiteBalance )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoWhiteBalance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoWhiteBalance )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL AutoWhiteBalance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pBrightness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Brightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoExposure )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoFocus )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoFocus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoGain )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAutoWhiteBalance )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapAutoWhiteBalance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapBrightness )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapContrast )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapContrast);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapExposure )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapExposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapGain )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapGain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapHorizontalFlip )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapHorizontalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapHue )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapHue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhoto )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhoto);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoResolution )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPhotoType )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPhotoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSaturation )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSaturation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVerticalFlip )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVerticalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideo )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoResolution )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoType )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Contrast )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pContrast);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Contrast )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Contrast);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Exposure )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pExposure);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Exposure )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Exposure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gain )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pGain);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gain )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Gain);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalFlip )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pHorizontalFlip);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HorizontalFlip )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL HorizontalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pHue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Hue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoColorSpace);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR PhotoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoColorSpaceList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoColorSpaceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pPhotoFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [in] */ long PhotoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoMaxFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pPhotoMaxFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoResolution )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoResolution);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoResolution )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR PhotoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoResolutionList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoResolutionList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoType )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PhotoType )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR PhotoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhotoTypeList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pPhotoTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemainingRecordingTimeInSec )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pRemainingRecordingTimeInSec);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Saturation )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pSaturation);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Saturation )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Saturation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSVideoCapture * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalFlip )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ VARIANT_BOOL *pVerticalFlip);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VerticalFlip )( 
            IOPOSVideoCapture * This,
            /* [in] */ VARIANT_BOOL VerticalFlip);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoCaptureMode )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pVideoCaptureMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoCaptureMode )( 
            IOPOSVideoCapture * This,
            /* [in] */ long VideoCaptureMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoColorSpace);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoColorSpace )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR VideoColorSpace);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoColorSpaceList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoColorSpaceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pVideoFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoFrameRate )( 
            IOPOSVideoCapture * This,
            /* [in] */ long VideoFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoMaxFrameRate )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pVideoMaxFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoResolution )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoResolution);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoResolution )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR VideoResolution);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoResolutionList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoResolutionList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoType )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoType )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR VideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoTypeList )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ BSTR *pVideoTypeList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartVideo )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopVideo )( 
            IOPOSVideoCapture * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TakePhoto )( 
            IOPOSVideoCapture * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSVideoCaptureVtbl;

    interface IOPOSVideoCapture
    {
        CONST_VTBL struct IOPOSVideoCaptureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSVideoCapture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSVideoCapture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSVideoCapture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSVideoCapture_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSVideoCapture_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSVideoCapture_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSVideoCapture_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSVideoCapture_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSVideoCapture_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSVideoCapture_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSVideoCapture_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSVideoCapture_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSVideoCapture_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSVideoCapture_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSVideoCapture_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSVideoCapture_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSVideoCapture_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSVideoCapture_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSVideoCapture_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSVideoCapture_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSVideoCapture_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSVideoCapture_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSVideoCapture_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSVideoCapture_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSVideoCapture_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSVideoCapture_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSVideoCapture_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSVideoCapture_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSVideoCapture_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSVideoCapture_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSVideoCapture_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSVideoCapture_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSVideoCapture_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSVideoCapture_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSVideoCapture_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSVideoCapture_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSVideoCapture_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSVideoCapture_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSVideoCapture_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSVideoCapture_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSVideoCapture_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSVideoCapture_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSVideoCapture_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSVideoCapture_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSVideoCapture_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSVideoCapture_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSVideoCapture_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSVideoCapture_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSVideoCapture_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSVideoCapture_get_AutoExposure(This,pAutoExposure)	\
    ( (This)->lpVtbl -> get_AutoExposure(This,pAutoExposure) ) 

#define IOPOSVideoCapture_put_AutoExposure(This,AutoExposure)	\
    ( (This)->lpVtbl -> put_AutoExposure(This,AutoExposure) ) 

#define IOPOSVideoCapture_get_AutoFocus(This,pAutoFocus)	\
    ( (This)->lpVtbl -> get_AutoFocus(This,pAutoFocus) ) 

#define IOPOSVideoCapture_put_AutoFocus(This,AutoFocus)	\
    ( (This)->lpVtbl -> put_AutoFocus(This,AutoFocus) ) 

#define IOPOSVideoCapture_get_AutoGain(This,pAutoGain)	\
    ( (This)->lpVtbl -> get_AutoGain(This,pAutoGain) ) 

#define IOPOSVideoCapture_put_AutoGain(This,AutoGain)	\
    ( (This)->lpVtbl -> put_AutoGain(This,AutoGain) ) 

#define IOPOSVideoCapture_get_AutoWhiteBalance(This,pAutoWhiteBalance)	\
    ( (This)->lpVtbl -> get_AutoWhiteBalance(This,pAutoWhiteBalance) ) 

#define IOPOSVideoCapture_put_AutoWhiteBalance(This,AutoWhiteBalance)	\
    ( (This)->lpVtbl -> put_AutoWhiteBalance(This,AutoWhiteBalance) ) 

#define IOPOSVideoCapture_get_Brightness(This,pBrightness)	\
    ( (This)->lpVtbl -> get_Brightness(This,pBrightness) ) 

#define IOPOSVideoCapture_put_Brightness(This,Brightness)	\
    ( (This)->lpVtbl -> put_Brightness(This,Brightness) ) 

#define IOPOSVideoCapture_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSVideoCapture_get_CapAutoExposure(This,pCapAutoExposure)	\
    ( (This)->lpVtbl -> get_CapAutoExposure(This,pCapAutoExposure) ) 

#define IOPOSVideoCapture_get_CapAutoFocus(This,pCapAutoFocus)	\
    ( (This)->lpVtbl -> get_CapAutoFocus(This,pCapAutoFocus) ) 

#define IOPOSVideoCapture_get_CapAutoGain(This,pCapAutoGain)	\
    ( (This)->lpVtbl -> get_CapAutoGain(This,pCapAutoGain) ) 

#define IOPOSVideoCapture_get_CapAutoWhiteBalance(This,pCapAutoWhiteBalance)	\
    ( (This)->lpVtbl -> get_CapAutoWhiteBalance(This,pCapAutoWhiteBalance) ) 

#define IOPOSVideoCapture_get_CapBrightness(This,pCapBrightness)	\
    ( (This)->lpVtbl -> get_CapBrightness(This,pCapBrightness) ) 

#define IOPOSVideoCapture_get_CapContrast(This,pCapContrast)	\
    ( (This)->lpVtbl -> get_CapContrast(This,pCapContrast) ) 

#define IOPOSVideoCapture_get_CapExposure(This,pCapExposure)	\
    ( (This)->lpVtbl -> get_CapExposure(This,pCapExposure) ) 

#define IOPOSVideoCapture_get_CapGain(This,pCapGain)	\
    ( (This)->lpVtbl -> get_CapGain(This,pCapGain) ) 

#define IOPOSVideoCapture_get_CapHorizontalFlip(This,pCapHorizontalFlip)	\
    ( (This)->lpVtbl -> get_CapHorizontalFlip(This,pCapHorizontalFlip) ) 

#define IOPOSVideoCapture_get_CapHue(This,pCapHue)	\
    ( (This)->lpVtbl -> get_CapHue(This,pCapHue) ) 

#define IOPOSVideoCapture_get_CapPhoto(This,pCapPhoto)	\
    ( (This)->lpVtbl -> get_CapPhoto(This,pCapPhoto) ) 

#define IOPOSVideoCapture_get_CapPhotoColorSpace(This,pCapPhotoColorSpace)	\
    ( (This)->lpVtbl -> get_CapPhotoColorSpace(This,pCapPhotoColorSpace) ) 

#define IOPOSVideoCapture_get_CapPhotoFrameRate(This,pCapPhotoFrameRate)	\
    ( (This)->lpVtbl -> get_CapPhotoFrameRate(This,pCapPhotoFrameRate) ) 

#define IOPOSVideoCapture_get_CapPhotoResolution(This,pCapPhotoResolution)	\
    ( (This)->lpVtbl -> get_CapPhotoResolution(This,pCapPhotoResolution) ) 

#define IOPOSVideoCapture_get_CapPhotoType(This,pCapPhotoType)	\
    ( (This)->lpVtbl -> get_CapPhotoType(This,pCapPhotoType) ) 

#define IOPOSVideoCapture_get_CapSaturation(This,pCapSaturation)	\
    ( (This)->lpVtbl -> get_CapSaturation(This,pCapSaturation) ) 

#define IOPOSVideoCapture_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSVideoCapture_get_CapVerticalFlip(This,pCapVerticalFlip)	\
    ( (This)->lpVtbl -> get_CapVerticalFlip(This,pCapVerticalFlip) ) 

#define IOPOSVideoCapture_get_CapVideo(This,pCapVideo)	\
    ( (This)->lpVtbl -> get_CapVideo(This,pCapVideo) ) 

#define IOPOSVideoCapture_get_CapVideoColorSpace(This,pCapVideoColorSpace)	\
    ( (This)->lpVtbl -> get_CapVideoColorSpace(This,pCapVideoColorSpace) ) 

#define IOPOSVideoCapture_get_CapVideoFrameRate(This,pCapVideoFrameRate)	\
    ( (This)->lpVtbl -> get_CapVideoFrameRate(This,pCapVideoFrameRate) ) 

#define IOPOSVideoCapture_get_CapVideoResolution(This,pCapVideoResolution)	\
    ( (This)->lpVtbl -> get_CapVideoResolution(This,pCapVideoResolution) ) 

#define IOPOSVideoCapture_get_CapVideoType(This,pCapVideoType)	\
    ( (This)->lpVtbl -> get_CapVideoType(This,pCapVideoType) ) 

#define IOPOSVideoCapture_get_Contrast(This,pContrast)	\
    ( (This)->lpVtbl -> get_Contrast(This,pContrast) ) 

#define IOPOSVideoCapture_put_Contrast(This,Contrast)	\
    ( (This)->lpVtbl -> put_Contrast(This,Contrast) ) 

#define IOPOSVideoCapture_get_Exposure(This,pExposure)	\
    ( (This)->lpVtbl -> get_Exposure(This,pExposure) ) 

#define IOPOSVideoCapture_put_Exposure(This,Exposure)	\
    ( (This)->lpVtbl -> put_Exposure(This,Exposure) ) 

#define IOPOSVideoCapture_get_Gain(This,pGain)	\
    ( (This)->lpVtbl -> get_Gain(This,pGain) ) 

#define IOPOSVideoCapture_put_Gain(This,Gain)	\
    ( (This)->lpVtbl -> put_Gain(This,Gain) ) 

#define IOPOSVideoCapture_get_HorizontalFlip(This,pHorizontalFlip)	\
    ( (This)->lpVtbl -> get_HorizontalFlip(This,pHorizontalFlip) ) 

#define IOPOSVideoCapture_put_HorizontalFlip(This,HorizontalFlip)	\
    ( (This)->lpVtbl -> put_HorizontalFlip(This,HorizontalFlip) ) 

#define IOPOSVideoCapture_get_Hue(This,pHue)	\
    ( (This)->lpVtbl -> get_Hue(This,pHue) ) 

#define IOPOSVideoCapture_put_Hue(This,Hue)	\
    ( (This)->lpVtbl -> put_Hue(This,Hue) ) 

#define IOPOSVideoCapture_get_PhotoColorSpace(This,pPhotoColorSpace)	\
    ( (This)->lpVtbl -> get_PhotoColorSpace(This,pPhotoColorSpace) ) 

#define IOPOSVideoCapture_put_PhotoColorSpace(This,PhotoColorSpace)	\
    ( (This)->lpVtbl -> put_PhotoColorSpace(This,PhotoColorSpace) ) 

#define IOPOSVideoCapture_get_PhotoColorSpaceList(This,pPhotoColorSpaceList)	\
    ( (This)->lpVtbl -> get_PhotoColorSpaceList(This,pPhotoColorSpaceList) ) 

#define IOPOSVideoCapture_get_PhotoFrameRate(This,pPhotoFrameRate)	\
    ( (This)->lpVtbl -> get_PhotoFrameRate(This,pPhotoFrameRate) ) 

#define IOPOSVideoCapture_put_PhotoFrameRate(This,PhotoFrameRate)	\
    ( (This)->lpVtbl -> put_PhotoFrameRate(This,PhotoFrameRate) ) 

#define IOPOSVideoCapture_get_PhotoMaxFrameRate(This,pPhotoMaxFrameRate)	\
    ( (This)->lpVtbl -> get_PhotoMaxFrameRate(This,pPhotoMaxFrameRate) ) 

#define IOPOSVideoCapture_get_PhotoResolution(This,pPhotoResolution)	\
    ( (This)->lpVtbl -> get_PhotoResolution(This,pPhotoResolution) ) 

#define IOPOSVideoCapture_put_PhotoResolution(This,PhotoResolution)	\
    ( (This)->lpVtbl -> put_PhotoResolution(This,PhotoResolution) ) 

#define IOPOSVideoCapture_get_PhotoResolutionList(This,pPhotoResolutionList)	\
    ( (This)->lpVtbl -> get_PhotoResolutionList(This,pPhotoResolutionList) ) 

#define IOPOSVideoCapture_get_PhotoType(This,pPhotoType)	\
    ( (This)->lpVtbl -> get_PhotoType(This,pPhotoType) ) 

#define IOPOSVideoCapture_put_PhotoType(This,PhotoType)	\
    ( (This)->lpVtbl -> put_PhotoType(This,PhotoType) ) 

#define IOPOSVideoCapture_get_PhotoTypeList(This,pPhotoTypeList)	\
    ( (This)->lpVtbl -> get_PhotoTypeList(This,pPhotoTypeList) ) 

#define IOPOSVideoCapture_get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec)	\
    ( (This)->lpVtbl -> get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec) ) 

#define IOPOSVideoCapture_get_Saturation(This,pSaturation)	\
    ( (This)->lpVtbl -> get_Saturation(This,pSaturation) ) 

#define IOPOSVideoCapture_put_Saturation(This,Saturation)	\
    ( (This)->lpVtbl -> put_Saturation(This,Saturation) ) 

#define IOPOSVideoCapture_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSVideoCapture_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSVideoCapture_get_VerticalFlip(This,pVerticalFlip)	\
    ( (This)->lpVtbl -> get_VerticalFlip(This,pVerticalFlip) ) 

#define IOPOSVideoCapture_put_VerticalFlip(This,VerticalFlip)	\
    ( (This)->lpVtbl -> put_VerticalFlip(This,VerticalFlip) ) 

#define IOPOSVideoCapture_get_VideoCaptureMode(This,pVideoCaptureMode)	\
    ( (This)->lpVtbl -> get_VideoCaptureMode(This,pVideoCaptureMode) ) 

#define IOPOSVideoCapture_put_VideoCaptureMode(This,VideoCaptureMode)	\
    ( (This)->lpVtbl -> put_VideoCaptureMode(This,VideoCaptureMode) ) 

#define IOPOSVideoCapture_get_VideoColorSpace(This,pVideoColorSpace)	\
    ( (This)->lpVtbl -> get_VideoColorSpace(This,pVideoColorSpace) ) 

#define IOPOSVideoCapture_put_VideoColorSpace(This,VideoColorSpace)	\
    ( (This)->lpVtbl -> put_VideoColorSpace(This,VideoColorSpace) ) 

#define IOPOSVideoCapture_get_VideoColorSpaceList(This,pVideoColorSpaceList)	\
    ( (This)->lpVtbl -> get_VideoColorSpaceList(This,pVideoColorSpaceList) ) 

#define IOPOSVideoCapture_get_VideoFrameRate(This,pVideoFrameRate)	\
    ( (This)->lpVtbl -> get_VideoFrameRate(This,pVideoFrameRate) ) 

#define IOPOSVideoCapture_put_VideoFrameRate(This,VideoFrameRate)	\
    ( (This)->lpVtbl -> put_VideoFrameRate(This,VideoFrameRate) ) 

#define IOPOSVideoCapture_get_VideoMaxFrameRate(This,pVideoMaxFrameRate)	\
    ( (This)->lpVtbl -> get_VideoMaxFrameRate(This,pVideoMaxFrameRate) ) 

#define IOPOSVideoCapture_get_VideoResolution(This,pVideoResolution)	\
    ( (This)->lpVtbl -> get_VideoResolution(This,pVideoResolution) ) 

#define IOPOSVideoCapture_put_VideoResolution(This,VideoResolution)	\
    ( (This)->lpVtbl -> put_VideoResolution(This,VideoResolution) ) 

#define IOPOSVideoCapture_get_VideoResolutionList(This,pVideoResolutionList)	\
    ( (This)->lpVtbl -> get_VideoResolutionList(This,pVideoResolutionList) ) 

#define IOPOSVideoCapture_get_VideoType(This,pVideoType)	\
    ( (This)->lpVtbl -> get_VideoType(This,pVideoType) ) 

#define IOPOSVideoCapture_put_VideoType(This,VideoType)	\
    ( (This)->lpVtbl -> put_VideoType(This,VideoType) ) 

#define IOPOSVideoCapture_get_VideoTypeList(This,pVideoTypeList)	\
    ( (This)->lpVtbl -> get_VideoTypeList(This,pVideoTypeList) ) 

#define IOPOSVideoCapture_StartVideo(This,FileName,OverWrite,RecordingTime,pRC)	\
    ( (This)->lpVtbl -> StartVideo(This,FileName,OverWrite,RecordingTime,pRC) ) 

#define IOPOSVideoCapture_StopVideo(This,pRC)	\
    ( (This)->lpVtbl -> StopVideo(This,pRC) ) 

#define IOPOSVideoCapture_TakePhoto(This,FileName,OverWrite,Timeout,pRC)	\
    ( (This)->lpVtbl -> TakePhoto(This,FileName,OverWrite,Timeout,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSVideoCapture_INTERFACE_DEFINED__ */



#ifndef __OposVideoCapture_CCO_LIBRARY_DEFINED__
#define __OposVideoCapture_CCO_LIBRARY_DEFINED__

/* library OposVideoCapture_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposVideoCapture_CCO;

#ifndef ___IOPOSVideoCaptureEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSVideoCaptureEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSVideoCaptureEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSVideoCaptureEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90453-B81E-11D2-AB74-0040054C3719")
    _IOPOSVideoCaptureEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSVideoCaptureEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSVideoCaptureEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSVideoCaptureEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSVideoCaptureEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSVideoCaptureEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSVideoCaptureEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSVideoCaptureEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSVideoCaptureEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IOPOSVideoCaptureEventsVtbl;

    interface _IOPOSVideoCaptureEvents
    {
        CONST_VTBL struct _IOPOSVideoCaptureEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSVideoCaptureEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSVideoCaptureEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSVideoCaptureEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSVideoCaptureEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSVideoCaptureEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSVideoCaptureEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSVideoCaptureEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSVideoCaptureEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSVideoCapture;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90452-B81E-11D2-AB74-0040054C3719")
OPOSVideoCapture;
#endif
#endif /* __OposVideoCapture_CCO_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


