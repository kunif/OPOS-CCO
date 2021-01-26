

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for SpeechSynthesis.idl:
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

#ifndef __SpeechSynthesis_h__
#define __SpeechSynthesis_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSSpeechSynthesis_1_16_FWD_DEFINED__
#define __IOPOSSpeechSynthesis_1_16_FWD_DEFINED__
typedef interface IOPOSSpeechSynthesis_1_16 IOPOSSpeechSynthesis_1_16;

#endif 	/* __IOPOSSpeechSynthesis_1_16_FWD_DEFINED__ */


#ifndef __IOPOSSpeechSynthesis_FWD_DEFINED__
#define __IOPOSSpeechSynthesis_FWD_DEFINED__
typedef interface IOPOSSpeechSynthesis IOPOSSpeechSynthesis;

#endif 	/* __IOPOSSpeechSynthesis_FWD_DEFINED__ */


#ifndef ___IOPOSSpeechSynthesisEvents_FWD_DEFINED__
#define ___IOPOSSpeechSynthesisEvents_FWD_DEFINED__
typedef interface _IOPOSSpeechSynthesisEvents _IOPOSSpeechSynthesisEvents;

#endif 	/* ___IOPOSSpeechSynthesisEvents_FWD_DEFINED__ */


#ifndef __OPOSSpeechSynthesis_FWD_DEFINED__
#define __OPOSSpeechSynthesis_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSSpeechSynthesis OPOSSpeechSynthesis;
#else
typedef struct OPOSSpeechSynthesis OPOSSpeechSynthesis;
#endif /* __cplusplus */

#endif 	/* __OPOSSpeechSynthesis_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSSpeechSynthesis_1_16_INTERFACE_DEFINED__
#define __IOPOSSpeechSynthesis_1_16_INTERFACE_DEFINED__

/* interface IOPOSSpeechSynthesis_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSpeechSynthesis_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90441-B81E-11D2-AB74-0040054C3719")
    IOPOSSpeechSynthesis_1_16 : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapLanguage( 
            /* [retval][out] */ VARIANT_BOOL *pCapLanguage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapPitch( 
            /* [retval][out] */ VARIANT_BOOL *pCapPitch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapSpeed( 
            /* [retval][out] */ VARIANT_BOOL *pCapSpeed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVoice( 
            /* [retval][out] */ VARIANT_BOOL *pCapVoice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapVolume( 
            /* [retval][out] */ VARIANT_BOOL *pCapVolume) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pLanguage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Language( 
            /* [in] */ BSTR Language) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageList( 
            /* [retval][out] */ BSTR *pLanguageList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputIDList( 
            /* [retval][out] */ BSTR *pOutputIDList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pitch( 
            /* [retval][out] */ long *pPitch) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pitch( 
            /* [in] */ long Pitch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ long *pSpeed) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Speed( 
            /* [in] */ long Speed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR *pVoice) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Voice( 
            /* [in] */ BSTR Voice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VoiceList( 
            /* [retval][out] */ BSTR *pVoiceList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long *pVolume) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long Volume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpeakImmediate( 
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopCurrentSpeaking( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopSpeaking( 
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSpeechSynthesis_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSpeechSynthesis_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSpeechSynthesis_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSpeechSynthesis_1_16 * This,
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
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapLanguage )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapLanguage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPitch )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPitch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSpeed )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSpeed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVoice )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVoice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pLanguage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR Language);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageList )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pLanguageList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputIDList )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pOutputIDList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pitch )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pPitch);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pitch )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Pitch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Speed )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Speed )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Voice )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pVoice);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Voice )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR Voice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VoiceList )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ BSTR *pVoiceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Speak )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SpeakImmediate )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopCurrentSpeaking )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopSpeaking )( 
            IOPOSSpeechSynthesis_1_16 * This,
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSpeechSynthesis_1_16Vtbl;

    interface IOPOSSpeechSynthesis_1_16
    {
        CONST_VTBL struct IOPOSSpeechSynthesis_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSpeechSynthesis_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSpeechSynthesis_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSpeechSynthesis_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSpeechSynthesis_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSpeechSynthesis_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSpeechSynthesis_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSpeechSynthesis_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSpeechSynthesis_1_16_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSSpeechSynthesis_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSpeechSynthesis_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSpeechSynthesis_1_16_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSSpeechSynthesis_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSpeechSynthesis_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSpeechSynthesis_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSpeechSynthesis_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSpeechSynthesis_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSpeechSynthesis_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSpeechSynthesis_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSpeechSynthesis_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSpeechSynthesis_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSpeechSynthesis_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSpeechSynthesis_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSpeechSynthesis_1_16_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSSpeechSynthesis_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSpeechSynthesis_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSpeechSynthesis_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSpeechSynthesis_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSpeechSynthesis_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSpeechSynthesis_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSpeechSynthesis_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSpeechSynthesis_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSpeechSynthesis_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSpeechSynthesis_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSpeechSynthesis_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSpeechSynthesis_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSpeechSynthesis_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapLanguage(This,pCapLanguage)	\
    ( (This)->lpVtbl -> get_CapLanguage(This,pCapLanguage) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapPitch(This,pCapPitch)	\
    ( (This)->lpVtbl -> get_CapPitch(This,pCapPitch) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapSpeed(This,pCapSpeed)	\
    ( (This)->lpVtbl -> get_CapSpeed(This,pCapSpeed) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapVoice(This,pCapVoice)	\
    ( (This)->lpVtbl -> get_CapVoice(This,pCapVoice) ) 

#define IOPOSSpeechSynthesis_1_16_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSSpeechSynthesis_1_16_get_Language(This,pLanguage)	\
    ( (This)->lpVtbl -> get_Language(This,pLanguage) ) 

#define IOPOSSpeechSynthesis_1_16_put_Language(This,Language)	\
    ( (This)->lpVtbl -> put_Language(This,Language) ) 

#define IOPOSSpeechSynthesis_1_16_get_LanguageList(This,pLanguageList)	\
    ( (This)->lpVtbl -> get_LanguageList(This,pLanguageList) ) 

#define IOPOSSpeechSynthesis_1_16_get_OutputIDList(This,pOutputIDList)	\
    ( (This)->lpVtbl -> get_OutputIDList(This,pOutputIDList) ) 

#define IOPOSSpeechSynthesis_1_16_get_Pitch(This,pPitch)	\
    ( (This)->lpVtbl -> get_Pitch(This,pPitch) ) 

#define IOPOSSpeechSynthesis_1_16_put_Pitch(This,Pitch)	\
    ( (This)->lpVtbl -> put_Pitch(This,Pitch) ) 

#define IOPOSSpeechSynthesis_1_16_get_Speed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_Speed(This,pSpeed) ) 

#define IOPOSSpeechSynthesis_1_16_put_Speed(This,Speed)	\
    ( (This)->lpVtbl -> put_Speed(This,Speed) ) 

#define IOPOSSpeechSynthesis_1_16_get_Voice(This,pVoice)	\
    ( (This)->lpVtbl -> get_Voice(This,pVoice) ) 

#define IOPOSSpeechSynthesis_1_16_put_Voice(This,Voice)	\
    ( (This)->lpVtbl -> put_Voice(This,Voice) ) 

#define IOPOSSpeechSynthesis_1_16_get_VoiceList(This,pVoiceList)	\
    ( (This)->lpVtbl -> get_VoiceList(This,pVoiceList) ) 

#define IOPOSSpeechSynthesis_1_16_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSSpeechSynthesis_1_16_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSSpeechSynthesis_1_16_Speak(This,Text,pRC)	\
    ( (This)->lpVtbl -> Speak(This,Text,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_SpeakImmediate(This,Text,pRC)	\
    ( (This)->lpVtbl -> SpeakImmediate(This,Text,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_StopCurrentSpeaking(This,pRC)	\
    ( (This)->lpVtbl -> StopCurrentSpeaking(This,pRC) ) 

#define IOPOSSpeechSynthesis_1_16_StopSpeaking(This,OutputID,pRC)	\
    ( (This)->lpVtbl -> StopSpeaking(This,OutputID,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSpeechSynthesis_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSSpeechSynthesis_INTERFACE_DEFINED__
#define __IOPOSSpeechSynthesis_INTERFACE_DEFINED__

/* interface IOPOSSpeechSynthesis */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSpeechSynthesis;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91441-B81E-11D2-AB74-0040054C3719")
    IOPOSSpeechSynthesis : public IOPOSSpeechSynthesis_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSpeechSynthesisVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSpeechSynthesis * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSpeechSynthesis * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSpeechSynthesis * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSpeechSynthesis * This,
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
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputComplete )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputID )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pOutputID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearOutput )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSpeechSynthesis * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapLanguage )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapLanguage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPitch )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapPitch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSpeed )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSpeed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVoice )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVoice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapVolume )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ VARIANT_BOOL *pCapVolume);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pLanguage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR Language);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageList )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pLanguageList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputIDList )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pOutputIDList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pitch )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pPitch);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pitch )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Pitch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Speed )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Speed )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Voice )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pVoice);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Voice )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR Voice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VoiceList )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ BSTR *pVoiceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pVolume);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long Volume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Speak )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SpeakImmediate )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopCurrentSpeaking )( 
            IOPOSSpeechSynthesis * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopSpeaking )( 
            IOPOSSpeechSynthesis * This,
            /* [in] */ long OutputID,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSpeechSynthesisVtbl;

    interface IOPOSSpeechSynthesis
    {
        CONST_VTBL struct IOPOSSpeechSynthesisVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSpeechSynthesis_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSpeechSynthesis_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSpeechSynthesis_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSpeechSynthesis_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSpeechSynthesis_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSpeechSynthesis_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSpeechSynthesis_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSpeechSynthesis_SODataDummy(This,Status)	\
    ( (This)->lpVtbl -> SODataDummy(This,Status) ) 

#define IOPOSSpeechSynthesis_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSpeechSynthesis_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSpeechSynthesis_SOOutputComplete(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputComplete(This,OutputID) ) 

#define IOPOSSpeechSynthesis_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSpeechSynthesis_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSpeechSynthesis_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSpeechSynthesis_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSpeechSynthesis_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSpeechSynthesis_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSpeechSynthesis_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSpeechSynthesis_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSpeechSynthesis_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSpeechSynthesis_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSpeechSynthesis_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSpeechSynthesis_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSpeechSynthesis_get_OutputID(This,pOutputID)	\
    ( (This)->lpVtbl -> get_OutputID(This,pOutputID) ) 

#define IOPOSSpeechSynthesis_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSpeechSynthesis_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSpeechSynthesis_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSpeechSynthesis_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSpeechSynthesis_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSpeechSynthesis_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSpeechSynthesis_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSpeechSynthesis_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSpeechSynthesis_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSpeechSynthesis_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSpeechSynthesis_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSpeechSynthesis_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSpeechSynthesis_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSpeechSynthesis_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSpeechSynthesis_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSpeechSynthesis_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSpeechSynthesis_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSpeechSynthesis_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSpeechSynthesis_ClearOutput(This,pRC)	\
    ( (This)->lpVtbl -> ClearOutput(This,pRC) ) 

#define IOPOSSpeechSynthesis_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSpeechSynthesis_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSpeechSynthesis_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSpeechSynthesis_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSpeechSynthesis_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSpeechSynthesis_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSpeechSynthesis_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSpeechSynthesis_get_CapLanguage(This,pCapLanguage)	\
    ( (This)->lpVtbl -> get_CapLanguage(This,pCapLanguage) ) 

#define IOPOSSpeechSynthesis_get_CapPitch(This,pCapPitch)	\
    ( (This)->lpVtbl -> get_CapPitch(This,pCapPitch) ) 

#define IOPOSSpeechSynthesis_get_CapSpeed(This,pCapSpeed)	\
    ( (This)->lpVtbl -> get_CapSpeed(This,pCapSpeed) ) 

#define IOPOSSpeechSynthesis_get_CapVoice(This,pCapVoice)	\
    ( (This)->lpVtbl -> get_CapVoice(This,pCapVoice) ) 

#define IOPOSSpeechSynthesis_get_CapVolume(This,pCapVolume)	\
    ( (This)->lpVtbl -> get_CapVolume(This,pCapVolume) ) 

#define IOPOSSpeechSynthesis_get_Language(This,pLanguage)	\
    ( (This)->lpVtbl -> get_Language(This,pLanguage) ) 

#define IOPOSSpeechSynthesis_put_Language(This,Language)	\
    ( (This)->lpVtbl -> put_Language(This,Language) ) 

#define IOPOSSpeechSynthesis_get_LanguageList(This,pLanguageList)	\
    ( (This)->lpVtbl -> get_LanguageList(This,pLanguageList) ) 

#define IOPOSSpeechSynthesis_get_OutputIDList(This,pOutputIDList)	\
    ( (This)->lpVtbl -> get_OutputIDList(This,pOutputIDList) ) 

#define IOPOSSpeechSynthesis_get_Pitch(This,pPitch)	\
    ( (This)->lpVtbl -> get_Pitch(This,pPitch) ) 

#define IOPOSSpeechSynthesis_put_Pitch(This,Pitch)	\
    ( (This)->lpVtbl -> put_Pitch(This,Pitch) ) 

#define IOPOSSpeechSynthesis_get_Speed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_Speed(This,pSpeed) ) 

#define IOPOSSpeechSynthesis_put_Speed(This,Speed)	\
    ( (This)->lpVtbl -> put_Speed(This,Speed) ) 

#define IOPOSSpeechSynthesis_get_Voice(This,pVoice)	\
    ( (This)->lpVtbl -> get_Voice(This,pVoice) ) 

#define IOPOSSpeechSynthesis_put_Voice(This,Voice)	\
    ( (This)->lpVtbl -> put_Voice(This,Voice) ) 

#define IOPOSSpeechSynthesis_get_VoiceList(This,pVoiceList)	\
    ( (This)->lpVtbl -> get_VoiceList(This,pVoiceList) ) 

#define IOPOSSpeechSynthesis_get_Volume(This,pVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,pVolume) ) 

#define IOPOSSpeechSynthesis_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define IOPOSSpeechSynthesis_Speak(This,Text,pRC)	\
    ( (This)->lpVtbl -> Speak(This,Text,pRC) ) 

#define IOPOSSpeechSynthesis_SpeakImmediate(This,Text,pRC)	\
    ( (This)->lpVtbl -> SpeakImmediate(This,Text,pRC) ) 

#define IOPOSSpeechSynthesis_StopCurrentSpeaking(This,pRC)	\
    ( (This)->lpVtbl -> StopCurrentSpeaking(This,pRC) ) 

#define IOPOSSpeechSynthesis_StopSpeaking(This,OutputID,pRC)	\
    ( (This)->lpVtbl -> StopSpeaking(This,OutputID,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSpeechSynthesis_INTERFACE_DEFINED__ */



#ifndef __OposSpeechSynthesis_CCO_LIBRARY_DEFINED__
#define __OposSpeechSynthesis_CCO_LIBRARY_DEFINED__

/* library OposSpeechSynthesis_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposSpeechSynthesis_CCO;

#ifndef ___IOPOSSpeechSynthesisEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSSpeechSynthesisEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSSpeechSynthesisEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSSpeechSynthesisEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90443-B81E-11D2-AB74-0040054C3719")
    _IOPOSSpeechSynthesisEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSSpeechSynthesisEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSSpeechSynthesisEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSSpeechSynthesisEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSSpeechSynthesisEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSSpeechSynthesisEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSSpeechSynthesisEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSSpeechSynthesisEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSSpeechSynthesisEvents * This,
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
    } _IOPOSSpeechSynthesisEventsVtbl;

    interface _IOPOSSpeechSynthesisEvents
    {
        CONST_VTBL struct _IOPOSSpeechSynthesisEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSSpeechSynthesisEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSSpeechSynthesisEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSSpeechSynthesisEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSSpeechSynthesisEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSSpeechSynthesisEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSSpeechSynthesisEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSSpeechSynthesisEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSSpeechSynthesisEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSSpeechSynthesis;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90442-B81E-11D2-AB74-0040054C3719")
OPOSSpeechSynthesis;
#endif
#endif /* __OposSpeechSynthesis_CCO_LIBRARY_DEFINED__ */

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


