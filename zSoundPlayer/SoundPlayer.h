

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for SoundPlayer.idl:
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

#ifndef __SoundPlayer_h__
#define __SoundPlayer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSSoundPlayer_1_16_FWD_DEFINED__
#define __IOPOSSoundPlayer_1_16_FWD_DEFINED__
typedef interface IOPOSSoundPlayer_1_16 IOPOSSoundPlayer_1_16;

#endif 	/* __IOPOSSoundPlayer_1_16_FWD_DEFINED__ */


#ifndef __IOPOSSoundPlayer_FWD_DEFINED__
#define __IOPOSSoundPlayer_FWD_DEFINED__
typedef interface IOPOSSoundPlayer IOPOSSoundPlayer;

#endif 	/* __IOPOSSoundPlayer_FWD_DEFINED__ */


#ifndef ___IOPOSSoundPlayerEvents_FWD_DEFINED__
#define ___IOPOSSoundPlayerEvents_FWD_DEFINED__
typedef interface _IOPOSSoundPlayerEvents _IOPOSSoundPlayerEvents;

#endif 	/* ___IOPOSSoundPlayerEvents_FWD_DEFINED__ */


#ifndef __OPOSSoundPlayer_FWD_DEFINED__
#define __OPOSSoundPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSSoundPlayer OPOSSoundPlayer;
#else
typedef struct OPOSSoundPlayer OPOSSoundPlayer;
#endif /* __cplusplus */

#endif 	/* __OPOSSoundPlayer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSSoundPlayer_1_16_INTERFACE_DEFINED__
#define __IOPOSSoundPlayer_1_16_INTERFACE_DEFINED__

/* interface IOPOSSoundPlayer_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSoundPlayer_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90421-B81E-11D2-AB74-0040054C3719")
    IOPOSSoundPlayer_1_16 : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAssociatedHardTotalsDevice( 
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapMultiPlay( 
            /* [retval][out] */ VARIANT_BOOL *pCapMultiPlay) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapSoundTypeList( 
            /* [retval][out] */ BSTR *pCapSoundTypeList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapStorage( 
            /* [retval][out] */ long *pCapStorage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVolume( 
            /* [retval][out] */ VARIANT_BOOL *pCapVolume) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceSoundList( 
            /* [retval][out] */ BSTR *pDeviceSoundList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputIDList( 
            /* [retval][out] */ BSTR *pOutputIDList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ long *pStorage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Storage( 
            /* [in] */ long Storage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long *pVolume) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long Volume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlaySound( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopSound( 
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSoundPlayer_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSoundPlayer_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSoundPlayer_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSoundPlayer_1_16 * This,
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
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapMultiPlay )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapMultiPlay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSoundTypeList )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pCapSoundTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSoundList )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceSoundList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputIDList )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ BSTR *pOutputIDList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlaySound )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopSound )( 
            IOPOSSoundPlayer_1_16 * This,
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSoundPlayer_1_16Vtbl;

    interface IOPOSSoundPlayer_1_16
    {
        CONST_VTBL struct IOPOSSoundPlayer_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSoundPlayer_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSoundPlayer_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSoundPlayer_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSoundPlayer_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSoundPlayer_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSoundPlayer_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSoundPlayer_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSoundPlayer_1_16_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSSoundPlayer_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSoundPlayer_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSoundPlayer_1_16_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSSoundPlayer_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSoundPlayer_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSoundPlayer_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSoundPlayer_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSoundPlayer_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSoundPlayer_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSoundPlayer_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSoundPlayer_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSoundPlayer_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSoundPlayer_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSoundPlayer_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSoundPlayer_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSoundPlayer_1_16_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSSoundPlayer_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSoundPlayer_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSoundPlayer_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSoundPlayer_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSoundPlayer_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSoundPlayer_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSoundPlayer_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSoundPlayer_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSoundPlayer_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSoundPlayer_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSoundPlayer_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSoundPlayer_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSoundPlayer_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSoundPlayer_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSoundPlayer_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSoundPlayer_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSoundPlayer_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSoundPlayer_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSoundPlayer_1_16_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSSoundPlayer_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSoundPlayer_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSoundPlayer_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSoundPlayer_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSoundPlayer_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSoundPlayer_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSoundPlayer_1_16_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSSoundPlayer_1_16_get_CapMultiPlay(This,pCapMultiPlay)	\
    ( (This)->lpVtbl -> get_CapMultiPlay(This,pCapMultiPlay) ) 

#define IOPOSSoundPlayer_1_16_get_CapSoundTypeList(This,pCapSoundTypeList)	\
    ( (This)->lpVtbl -> get_CapSoundTypeList(This,pCapSoundTypeList) ) 

#define IOPOSSoundPlayer_1_16_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSSoundPlayer_1_16_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSSoundPlayer_1_16_get_DeviceSoundList(This,pDeviceSoundList)	\
    ( (This)->lpVtbl -> get_DeviceSoundList(This,pDeviceSoundList) ) 

#define IOPOSSoundPlayer_1_16_get_OutputIDList(This,pOutputIDList)	\
    ( (This)->lpVtbl -> get_OutputIDList(This,pOutputIDList) ) 

#define IOPOSSoundPlayer_1_16_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSSoundPlayer_1_16_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSSoundPlayer_1_16_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSSoundPlayer_1_16_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSSoundPlayer_1_16_PlaySound(This,FileName,Loop,pRC)	\
    ( (This)->lpVtbl -> PlaySound(This,FileName,Loop,pRC) ) 

#define IOPOSSoundPlayer_1_16_StopSound(This,OutputID,pRC)	\
    ( (This)->lpVtbl -> StopSound(This,OutputID,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSoundPlayer_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSSoundPlayer_INTERFACE_DEFINED__
#define __IOPOSSoundPlayer_INTERFACE_DEFINED__

/* interface IOPOSSoundPlayer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSoundPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91421-B81E-11D2-AB74-0040054C3719")
    IOPOSSoundPlayer : public IOPOSSoundPlayer_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSoundPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSoundPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSoundPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSoundPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSoundPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSoundPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSoundPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSoundPlayer * This,
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
            IOPOSSoundPlayer * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSoundPlayer * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSoundPlayer * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSoundPlayer * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapMultiPlay )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapMultiPlay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSoundTypeList )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pCapSoundTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSoundList )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pDeviceSoundList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputIDList )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ BSTR *pOutputIDList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSSoundPlayer * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlaySound )( 
            IOPOSSoundPlayer * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Loop,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopSound )( 
            IOPOSSoundPlayer * This,
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSoundPlayerVtbl;

    interface IOPOSSoundPlayer
    {
        CONST_VTBL struct IOPOSSoundPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSoundPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSoundPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSoundPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSoundPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSoundPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSoundPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSoundPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSoundPlayer_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSSoundPlayer_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSoundPlayer_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSoundPlayer_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSSoundPlayer_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSoundPlayer_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSoundPlayer_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSoundPlayer_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSoundPlayer_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSoundPlayer_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSoundPlayer_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSoundPlayer_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSoundPlayer_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSoundPlayer_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSoundPlayer_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSoundPlayer_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSoundPlayer_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSSoundPlayer_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSoundPlayer_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSoundPlayer_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSoundPlayer_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSoundPlayer_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSoundPlayer_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSoundPlayer_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSoundPlayer_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSoundPlayer_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSoundPlayer_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSoundPlayer_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSoundPlayer_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSoundPlayer_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSoundPlayer_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSoundPlayer_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSoundPlayer_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSoundPlayer_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSoundPlayer_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSoundPlayer_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSSoundPlayer_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSoundPlayer_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSoundPlayer_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSoundPlayer_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSoundPlayer_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundPlayer_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSoundPlayer_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSoundPlayer_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSSoundPlayer_get_CapMultiPlay(This,pCapMultiPlay)	\
    ( (This)->lpVtbl -> get_CapMultiPlay(This,pCapMultiPlay) ) 

#define IOPOSSoundPlayer_get_CapSoundTypeList(This,pCapSoundTypeList)	\
    ( (This)->lpVtbl -> get_CapSoundTypeList(This,pCapSoundTypeList) ) 

#define IOPOSSoundPlayer_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSSoundPlayer_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSSoundPlayer_get_DeviceSoundList(This,pDeviceSoundList)	\
    ( (This)->lpVtbl -> get_DeviceSoundList(This,pDeviceSoundList) ) 

#define IOPOSSoundPlayer_get_OutputIDList(This,pOutputIDList)	\
    ( (This)->lpVtbl -> get_OutputIDList(This,pOutputIDList) ) 

#define IOPOSSoundPlayer_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSSoundPlayer_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSSoundPlayer_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSSoundPlayer_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSSoundPlayer_PlaySound(This,FileName,Loop,pRC)	\
    ( (This)->lpVtbl -> PlaySound(This,FileName,Loop,pRC) ) 

#define IOPOSSoundPlayer_StopSound(This,OutputID,pRC)	\
    ( (This)->lpVtbl -> StopSound(This,OutputID,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSoundPlayer_INTERFACE_DEFINED__ */



#ifndef __OposSoundPlayer_CCO_LIBRARY_DEFINED__
#define __OposSoundPlayer_CCO_LIBRARY_DEFINED__

/* library OposSoundPlayer_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposSoundPlayer_CCO;

#ifndef ___IOPOSSoundPlayerEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSSoundPlayerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSSoundPlayerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSSoundPlayerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90423-B81E-11D2-AB74-0040054C3719")
    _IOPOSSoundPlayerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSSoundPlayerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSSoundPlayerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSSoundPlayerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSSoundPlayerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSSoundPlayerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSSoundPlayerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSSoundPlayerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSSoundPlayerEvents * This,
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
    } _IOPOSSoundPlayerEventsVtbl;

    interface _IOPOSSoundPlayerEvents
    {
        CONST_VTBL struct _IOPOSSoundPlayerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSSoundPlayerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSSoundPlayerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSSoundPlayerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSSoundPlayerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSSoundPlayerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSSoundPlayerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSSoundPlayerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSSoundPlayerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSSoundPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90422-B81E-11D2-AB74-0040054C3719")
OPOSSoundPlayer;
#endif
#endif /* __OposSoundPlayer_CCO_LIBRARY_DEFINED__ */

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


