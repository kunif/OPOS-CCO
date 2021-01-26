

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for GraphicDisplay.idl:
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

#ifndef __GraphicDisplay_h__
#define __GraphicDisplay_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSGraphicDisplay_1_16_FWD_DEFINED__
#define __IOPOSGraphicDisplay_1_16_FWD_DEFINED__
typedef interface IOPOSGraphicDisplay_1_16 IOPOSGraphicDisplay_1_16;

#endif 	/* __IOPOSGraphicDisplay_1_16_FWD_DEFINED__ */


#ifndef __IOPOSGraphicDisplay_FWD_DEFINED__
#define __IOPOSGraphicDisplay_FWD_DEFINED__
typedef interface IOPOSGraphicDisplay IOPOSGraphicDisplay;

#endif 	/* __IOPOSGraphicDisplay_FWD_DEFINED__ */


#ifndef ___IOPOSGraphicDisplayEvents_FWD_DEFINED__
#define ___IOPOSGraphicDisplayEvents_FWD_DEFINED__
typedef interface _IOPOSGraphicDisplayEvents _IOPOSGraphicDisplayEvents;

#endif 	/* ___IOPOSGraphicDisplayEvents_FWD_DEFINED__ */


#ifndef __OPOSGraphicDisplay_FWD_DEFINED__
#define __OPOSGraphicDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSGraphicDisplay OPOSGraphicDisplay;
#else
typedef struct OPOSGraphicDisplay OPOSGraphicDisplay;
#endif /* __cplusplus */

#endif 	/* __OPOSGraphicDisplay_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSGraphicDisplay_1_16_INTERFACE_DEFINED__
#define __IOPOSGraphicDisplay_1_16_INTERFACE_DEFINED__

/* interface IOPOSGraphicDisplay_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSGraphicDisplay_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90401-B81E-11D2-AB74-0040054C3719")
    IOPOSGraphicDisplay_1_16 : public IDispatch
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
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOOutputComplete( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputID( 
            /* [retval][out] */ long *pOutputID) = 0;
        
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearOutput( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [retval][out] */ long *pBrightness) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [in] */ long Brightness) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAssociatedHardTotalsDevice( 
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapBrightness( 
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapImageType( 
            /* [retval][out] */ VARIANT_BOOL *pCapImageType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapStorage( 
            /* [retval][out] */ LONG *pCapStorage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapURLBack( 
            /* [retval][out] */ VARIANT_BOOL *pCapURLBack) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapURLForward( 
            /* [retval][out] */ VARIANT_BOOL *pCapURLForward) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVideoType( 
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVolume( 
            /* [retval][out] */ VARIANT_BOOL *pCapVolume) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayMode( 
            /* [retval][out] */ long *pDisplayMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayMode( 
            /* [in] */ long DisplayMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageType( 
            /* [retval][out] */ BSTR *pImageType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageType( 
            /* [in] */ BSTR ImageType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageTypeList( 
            /* [retval][out] */ BSTR *pImageTypeList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoadStatus( 
            /* [retval][out] */ long *pLoadStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ long *pStorage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Storage( 
            /* [in] */ long Storage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_URL( 
            /* [retval][out] */ BSTR *pURL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoType( 
            /* [retval][out] */ BSTR *pVideoType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoType( 
            /* [in] */ BSTR VideoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoTypeList( 
            /* [retval][out] */ BSTR *pVideoTypeList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long *pVolume) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long Volume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelLoading( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoURLBack( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoURLForward( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadImage( 
            /* [in] */ BSTR FileName,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadURL( 
            /* [in] */ BSTR URL,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayVideo( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopVideo( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdatePage( 
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSGraphicDisplay_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSGraphicDisplay_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSGraphicDisplay_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSGraphicDisplay_1_16 * This,
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
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pBrightness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Brightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapBrightness )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapImageType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapImageType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ LONG *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapURLBack )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapURLBack);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapURLForward )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapURLForward);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayMode )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pDisplayMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayMode )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long DisplayMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pImageType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR ImageType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageTypeList )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pImageTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoadStatus )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pLoadStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoType )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR VideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoTypeList )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ BSTR *pVideoTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelLoading )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoURLBack )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoURLForward )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadImage )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadURL )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR URL,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayVideo )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopVideo )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdatePage )( 
            IOPOSGraphicDisplay_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSGraphicDisplay_1_16Vtbl;

    interface IOPOSGraphicDisplay_1_16
    {
        CONST_VTBL struct IOPOSGraphicDisplay_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSGraphicDisplay_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSGraphicDisplay_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSGraphicDisplay_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSGraphicDisplay_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSGraphicDisplay_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSGraphicDisplay_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSGraphicDisplay_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSGraphicDisplay_1_16_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSGraphicDisplay_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSGraphicDisplay_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSGraphicDisplay_1_16_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSGraphicDisplay_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSGraphicDisplay_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSGraphicDisplay_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSGraphicDisplay_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSGraphicDisplay_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSGraphicDisplay_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSGraphicDisplay_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSGraphicDisplay_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSGraphicDisplay_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSGraphicDisplay_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSGraphicDisplay_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSGraphicDisplay_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSGraphicDisplay_1_16_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSGraphicDisplay_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSGraphicDisplay_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSGraphicDisplay_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSGraphicDisplay_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSGraphicDisplay_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSGraphicDisplay_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSGraphicDisplay_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSGraphicDisplay_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSGraphicDisplay_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSGraphicDisplay_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSGraphicDisplay_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSGraphicDisplay_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSGraphicDisplay_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSGraphicDisplay_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSGraphicDisplay_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSGraphicDisplay_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSGraphicDisplay_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSGraphicDisplay_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSGraphicDisplay_1_16_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSGraphicDisplay_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSGraphicDisplay_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSGraphicDisplay_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSGraphicDisplay_1_16_get_Brightness(This,pBrightness)	\
    ( (This)->lpVtbl -> get_Brightness(This,pBrightness) ) 

#define IOPOSGraphicDisplay_1_16_put_Brightness(This,Brightness)	\
    ( (This)->lpVtbl -> put_Brightness(This,Brightness) ) 

#define IOPOSGraphicDisplay_1_16_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSGraphicDisplay_1_16_get_CapBrightness(This,pCapBrightness)	\
    ( (This)->lpVtbl -> get_CapBrightness(This,pCapBrightness) ) 

#define IOPOSGraphicDisplay_1_16_get_CapImageType(This,pCapImageType)	\
    ( (This)->lpVtbl -> get_CapImageType(This,pCapImageType) ) 

#define IOPOSGraphicDisplay_1_16_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSGraphicDisplay_1_16_get_CapURLBack(This,pCapURLBack)	\
    ( (This)->lpVtbl -> get_CapURLBack(This,pCapURLBack) ) 

#define IOPOSGraphicDisplay_1_16_get_CapURLForward(This,pCapURLForward)	\
    ( (This)->lpVtbl -> get_CapURLForward(This,pCapURLForward) ) 

#define IOPOSGraphicDisplay_1_16_get_CapVideoType(This,pCapVideoType)	\
    ( (This)->lpVtbl -> get_CapVideoType(This,pCapVideoType) ) 

#define IOPOSGraphicDisplay_1_16_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSGraphicDisplay_1_16_get_DisplayMode(This,pDisplayMode)	\
    ( (This)->lpVtbl -> get_DisplayMode(This,pDisplayMode) ) 

#define IOPOSGraphicDisplay_1_16_put_DisplayMode(This,DisplayMode)	\
    ( (This)->lpVtbl -> put_DisplayMode(This,DisplayMode) ) 

#define IOPOSGraphicDisplay_1_16_get_ImageType(This,pImageType)	\
    ( (This)->lpVtbl -> get_ImageType(This,pImageType) ) 

#define IOPOSGraphicDisplay_1_16_put_ImageType(This,ImageType)	\
    ( (This)->lpVtbl -> put_ImageType(This,ImageType) ) 

#define IOPOSGraphicDisplay_1_16_get_ImageTypeList(This,pImageTypeList)	\
    ( (This)->lpVtbl -> get_ImageTypeList(This,pImageTypeList) ) 

#define IOPOSGraphicDisplay_1_16_get_LoadStatus(This,pLoadStatus)	\
    ( (This)->lpVtbl -> get_LoadStatus(This,pLoadStatus) ) 

#define IOPOSGraphicDisplay_1_16_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSGraphicDisplay_1_16_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSGraphicDisplay_1_16_get_URL(This,pURL)	\
    ( (This)->lpVtbl -> get_URL(This,pURL) ) 

#define IOPOSGraphicDisplay_1_16_get_VideoType(This,pVideoType)	\
    ( (This)->lpVtbl -> get_VideoType(This,pVideoType) ) 

#define IOPOSGraphicDisplay_1_16_put_VideoType(This,VideoType)	\
    ( (This)->lpVtbl -> put_VideoType(This,VideoType) ) 

#define IOPOSGraphicDisplay_1_16_get_VideoTypeList(This,pVideoTypeList)	\
    ( (This)->lpVtbl -> get_VideoTypeList(This,pVideoTypeList) ) 

#define IOPOSGraphicDisplay_1_16_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSGraphicDisplay_1_16_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSGraphicDisplay_1_16_CancelLoading(This,pRC)	\
    ( (This)->lpVtbl -> CancelLoading(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_GoURLBack(This,pRC)	\
    ( (This)->lpVtbl -> GoURLBack(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_GoURLForward(This,pRC)	\
    ( (This)->lpVtbl -> GoURLForward(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_LoadImage(This,FileName,pRC)	\
    ( (This)->lpVtbl -> LoadImage(This,FileName,pRC) ) 

#define IOPOSGraphicDisplay_1_16_LoadURL(This,URL,pRC)	\
    ( (This)->lpVtbl -> LoadURL(This,URL,pRC) ) 

#define IOPOSGraphicDisplay_1_16_PlayVideo(This,FileName,Loop,pRC)	\
    ( (This)->lpVtbl -> PlayVideo(This,FileName,Loop,pRC) ) 

#define IOPOSGraphicDisplay_1_16_StopVideo(This,pRC)	\
    ( (This)->lpVtbl -> StopVideo(This,pRC) ) 

#define IOPOSGraphicDisplay_1_16_UpdatePage(This,pRC)	\
    ( (This)->lpVtbl -> UpdatePage(This,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSGraphicDisplay_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSGraphicDisplay_INTERFACE_DEFINED__
#define __IOPOSGraphicDisplay_INTERFACE_DEFINED__

/* interface IOPOSGraphicDisplay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSGraphicDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91401-B81E-11D2-AB74-0040054C3719")
    IOPOSGraphicDisplay : public IOPOSGraphicDisplay_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSGraphicDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSGraphicDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSGraphicDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSGraphicDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSGraphicDisplay * This,
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
            IOPOSGraphicDisplay * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSGraphicDisplay * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pBrightness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Brightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapBrightness )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapBrightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapImageType )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapImageType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ LONG *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapURLBack )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapURLBack);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapURLForward )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapURLForward);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVideoType )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayMode )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pDisplayMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayMode )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long DisplayMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageType )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pImageType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageType )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR ImageType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageTypeList )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pImageTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoadStatus )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pLoadStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoType )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoType )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR VideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoTypeList )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ BSTR *pVideoTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelLoading )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoURLBack )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoURLForward )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadImage )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR FileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadURL )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR URL,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayVideo )( 
            IOPOSGraphicDisplay * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopVideo )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdatePage )( 
            IOPOSGraphicDisplay * This,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSGraphicDisplayVtbl;

    interface IOPOSGraphicDisplay
    {
        CONST_VTBL struct IOPOSGraphicDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSGraphicDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSGraphicDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSGraphicDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSGraphicDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSGraphicDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSGraphicDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSGraphicDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSGraphicDisplay_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSGraphicDisplay_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSGraphicDisplay_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSGraphicDisplay_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSGraphicDisplay_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSGraphicDisplay_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSGraphicDisplay_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSGraphicDisplay_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSGraphicDisplay_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSGraphicDisplay_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSGraphicDisplay_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSGraphicDisplay_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSGraphicDisplay_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSGraphicDisplay_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSGraphicDisplay_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSGraphicDisplay_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSGraphicDisplay_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSGraphicDisplay_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSGraphicDisplay_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSGraphicDisplay_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSGraphicDisplay_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSGraphicDisplay_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSGraphicDisplay_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSGraphicDisplay_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSGraphicDisplay_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSGraphicDisplay_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSGraphicDisplay_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSGraphicDisplay_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSGraphicDisplay_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSGraphicDisplay_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSGraphicDisplay_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSGraphicDisplay_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSGraphicDisplay_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSGraphicDisplay_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSGraphicDisplay_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSGraphicDisplay_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSGraphicDisplay_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSGraphicDisplay_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSGraphicDisplay_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSGraphicDisplay_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSGraphicDisplay_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSGraphicDisplay_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSGraphicDisplay_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSGraphicDisplay_get_Brightness(This,pBrightness)	\
    ( (This)->lpVtbl -> get_Brightness(This,pBrightness) ) 

#define IOPOSGraphicDisplay_put_Brightness(This,Brightness)	\
    ( (This)->lpVtbl -> put_Brightness(This,Brightness) ) 

#define IOPOSGraphicDisplay_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSGraphicDisplay_get_CapBrightness(This,pCapBrightness)	\
    ( (This)->lpVtbl -> get_CapBrightness(This,pCapBrightness) ) 

#define IOPOSGraphicDisplay_get_CapImageType(This,pCapImageType)	\
    ( (This)->lpVtbl -> get_CapImageType(This,pCapImageType) ) 

#define IOPOSGraphicDisplay_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSGraphicDisplay_get_CapURLBack(This,pCapURLBack)	\
    ( (This)->lpVtbl -> get_CapURLBack(This,pCapURLBack) ) 

#define IOPOSGraphicDisplay_get_CapURLForward(This,pCapURLForward)	\
    ( (This)->lpVtbl -> get_CapURLForward(This,pCapURLForward) ) 

#define IOPOSGraphicDisplay_get_CapVideoType(This,pCapVideoType)	\
    ( (This)->lpVtbl -> get_CapVideoType(This,pCapVideoType) ) 

#define IOPOSGraphicDisplay_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSGraphicDisplay_get_DisplayMode(This,pDisplayMode)	\
    ( (This)->lpVtbl -> get_DisplayMode(This,pDisplayMode) ) 

#define IOPOSGraphicDisplay_put_DisplayMode(This,DisplayMode)	\
    ( (This)->lpVtbl -> put_DisplayMode(This,DisplayMode) ) 

#define IOPOSGraphicDisplay_get_ImageType(This,pImageType)	\
    ( (This)->lpVtbl -> get_ImageType(This,pImageType) ) 

#define IOPOSGraphicDisplay_put_ImageType(This,ImageType)	\
    ( (This)->lpVtbl -> put_ImageType(This,ImageType) ) 

#define IOPOSGraphicDisplay_get_ImageTypeList(This,pImageTypeList)	\
    ( (This)->lpVtbl -> get_ImageTypeList(This,pImageTypeList) ) 

#define IOPOSGraphicDisplay_get_LoadStatus(This,pLoadStatus)	\
    ( (This)->lpVtbl -> get_LoadStatus(This,pLoadStatus) ) 

#define IOPOSGraphicDisplay_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSGraphicDisplay_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSGraphicDisplay_get_URL(This,pURL)	\
    ( (This)->lpVtbl -> get_URL(This,pURL) ) 

#define IOPOSGraphicDisplay_get_VideoType(This,pVideoType)	\
    ( (This)->lpVtbl -> get_VideoType(This,pVideoType) ) 

#define IOPOSGraphicDisplay_put_VideoType(This,VideoType)	\
    ( (This)->lpVtbl -> put_VideoType(This,VideoType) ) 

#define IOPOSGraphicDisplay_get_VideoTypeList(This,pVideoTypeList)	\
    ( (This)->lpVtbl -> get_VideoTypeList(This,pVideoTypeList) ) 

#define IOPOSGraphicDisplay_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSGraphicDisplay_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSGraphicDisplay_CancelLoading(This,pRC)	\
    ( (This)->lpVtbl -> CancelLoading(This,pRC) ) 

#define IOPOSGraphicDisplay_GoURLBack(This,pRC)	\
    ( (This)->lpVtbl -> GoURLBack(This,pRC) ) 

#define IOPOSGraphicDisplay_GoURLForward(This,pRC)	\
    ( (This)->lpVtbl -> GoURLForward(This,pRC) ) 

#define IOPOSGraphicDisplay_LoadImage(This,FileName,pRC)	\
    ( (This)->lpVtbl -> LoadImage(This,FileName,pRC) ) 

#define IOPOSGraphicDisplay_LoadURL(This,URL,pRC)	\
    ( (This)->lpVtbl -> LoadURL(This,URL,pRC) ) 

#define IOPOSGraphicDisplay_PlayVideo(This,FileName,Loop,pRC)	\
    ( (This)->lpVtbl -> PlayVideo(This,FileName,Loop,pRC) ) 

#define IOPOSGraphicDisplay_StopVideo(This,pRC)	\
    ( (This)->lpVtbl -> StopVideo(This,pRC) ) 

#define IOPOSGraphicDisplay_UpdatePage(This,pRC)	\
    ( (This)->lpVtbl -> UpdatePage(This,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSGraphicDisplay_INTERFACE_DEFINED__ */



#ifndef __OposGraphicDisplay_CCO_LIBRARY_DEFINED__
#define __OposGraphicDisplay_CCO_LIBRARY_DEFINED__

/* library OposGraphicDisplay_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposGraphicDisplay_CCO;

#ifndef ___IOPOSGraphicDisplayEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSGraphicDisplayEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSGraphicDisplayEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSGraphicDisplayEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90403-B81E-11D2-AB74-0040054C3719")
    _IOPOSGraphicDisplayEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSGraphicDisplayEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSGraphicDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSGraphicDisplayEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSGraphicDisplayEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSGraphicDisplayEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSGraphicDisplayEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSGraphicDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSGraphicDisplayEvents * This,
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
    } _IOPOSGraphicDisplayEventsVtbl;

    interface _IOPOSGraphicDisplayEvents
    {
        CONST_VTBL struct _IOPOSGraphicDisplayEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSGraphicDisplayEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSGraphicDisplayEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSGraphicDisplayEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSGraphicDisplayEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSGraphicDisplayEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSGraphicDisplayEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSGraphicDisplayEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSGraphicDisplayEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSGraphicDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90402-B81E-11D2-AB74-0040054C3719")
OPOSGraphicDisplay;
#endif
#endif /* __OposGraphicDisplay_CCO_LIBRARY_DEFINED__ */

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


