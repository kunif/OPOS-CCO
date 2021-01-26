

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for SoundRecorder.idl:
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

#ifndef __SoundRecorder_h__
#define __SoundRecorder_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSSoundRecorder_1_16_FWD_DEFINED__
#define __IOPOSSoundRecorder_1_16_FWD_DEFINED__
typedef interface IOPOSSoundRecorder_1_16 IOPOSSoundRecorder_1_16;

#endif 	/* __IOPOSSoundRecorder_1_16_FWD_DEFINED__ */


#ifndef __IOPOSSoundRecorder_FWD_DEFINED__
#define __IOPOSSoundRecorder_FWD_DEFINED__
typedef interface IOPOSSoundRecorder IOPOSSoundRecorder;

#endif 	/* __IOPOSSoundRecorder_FWD_DEFINED__ */


#ifndef ___IOPOSSoundRecorderEvents_FWD_DEFINED__
#define ___IOPOSSoundRecorderEvents_FWD_DEFINED__
typedef interface _IOPOSSoundRecorderEvents _IOPOSSoundRecorderEvents;

#endif 	/* ___IOPOSSoundRecorderEvents_FWD_DEFINED__ */


#ifndef __OPOSSoundRecorder_FWD_DEFINED__
#define __OPOSSoundRecorder_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSSoundRecorder OPOSSoundRecorder;
#else
typedef struct OPOSSoundRecorder OPOSSoundRecorder;
#endif /* __cplusplus */

#endif 	/* __OPOSSoundRecorder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSSoundRecorder_1_16_INTERFACE_DEFINED__
#define __IOPOSSoundRecorder_1_16_INTERFACE_DEFINED__

/* interface IOPOSSoundRecorder_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSoundRecorder_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90431-B81E-11D2-AB74-0040054C3719")
    IOPOSSoundRecorder_1_16 : public IDispatch
    {
    public:
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE SOData( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoDisable( 
            /* [retval][out] */ VARIANT_BOOL *pAutoDisable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoDisable( 
            /* [in] */ VARIANT_BOOL AutoDisable) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataCount( 
            /* [retval][out] */ long *pDataCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataEventEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pDataEventEnabled) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataEventEnabled( 
            /* [in] */ VARIANT_BOOL DataEventEnabled) = 0;
        
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearInputProperties( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapAssociatedHardTotalsDevice( 
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapChannel( 
            /* [retval][out] */ VARIANT_BOOL *pCapChannel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapRecordingLevel( 
            /* [retval][out] */ VARIANT_BOOL *pCapRecordingLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapSamplingRate( 
            /* [retval][out] */ VARIANT_BOOL *pCapSamplingRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapSoundType( 
            /* [retval][out] */ VARIANT_BOOL *pCapSoundType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CapStorage( 
            /* [retval][out] */ long *pCapStorage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Channel( 
            /* [retval][out] */ BSTR *pChannel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Channel( 
            /* [in] */ BSTR Channel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelList( 
            /* [retval][out] */ BSTR *pChannelList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingLevel( 
            /* [retval][out] */ long *pRecordingLevel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RecordingLevel( 
            /* [in] */ long RecordingLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemainingRecordingTimeInSec( 
            /* [retval][out] */ long *pRemainingRecordingTimeInSec) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SamplingRate( 
            /* [retval][out] */ BSTR *pSamplingRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SamplingRate( 
            /* [in] */ BSTR SamplingRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SamplingRateList( 
            /* [retval][out] */ BSTR *pSamplingRateList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoundData( 
            /* [retval][out] */ BSTR *pSoundData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoundType( 
            /* [retval][out] */ BSTR *pSoundType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SoundType( 
            /* [in] */ BSTR SoundType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoundTypeList( 
            /* [retval][out] */ BSTR *pSoundTypeList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ long *pStorage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Storage( 
            /* [in] */ long Storage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartRecording( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopRecording( 
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSoundRecorder_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSoundRecorder_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSoundRecorder_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSoundRecorder_1_16 * This,
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
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOData )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDisable )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoDisable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDisable )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoDisable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataCount )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pDataCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataEventEnabled )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDataEventEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataEventEnabled )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ VARIANT_BOOL DataEventEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInputProperties )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapChannel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapChannel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapRecordingLevel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapRecordingLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSamplingRate )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSamplingRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSoundType )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSoundType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pChannel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Channel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR Channel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelList )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pChannelList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingLevel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRecordingLevel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RecordingLevel )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long RecordingLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemainingRecordingTimeInSec )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRemainingRecordingTimeInSec);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplingRate )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pSamplingRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SamplingRate )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR SamplingRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplingRateList )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pSamplingRateList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundData )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pSoundData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundType )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pSoundType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SoundType )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR SoundType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundTypeList )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ BSTR *pSoundTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartRecording )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopRecording )( 
            IOPOSSoundRecorder_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSoundRecorder_1_16Vtbl;

    interface IOPOSSoundRecorder_1_16
    {
        CONST_VTBL struct IOPOSSoundRecorder_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSoundRecorder_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSoundRecorder_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSoundRecorder_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSoundRecorder_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSoundRecorder_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSoundRecorder_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSoundRecorder_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSoundRecorder_1_16_SOData(This,Status)	\
    ( (This)->lpVtbl -> SOData(This,Status) ) 

#define IOPOSSoundRecorder_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSoundRecorder_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSoundRecorder_1_16_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSSoundRecorder_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSoundRecorder_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSoundRecorder_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSoundRecorder_1_16_get_AutoDisable(This,pAutoDisable)	\
    ( (This)->lpVtbl -> get_AutoDisable(This,pAutoDisable) ) 

#define IOPOSSoundRecorder_1_16_put_AutoDisable(This,AutoDisable)	\
    ( (This)->lpVtbl -> put_AutoDisable(This,AutoDisable) ) 

#define IOPOSSoundRecorder_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSoundRecorder_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSoundRecorder_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSoundRecorder_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSoundRecorder_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSoundRecorder_1_16_get_DataCount(This,pDataCount)	\
    ( (This)->lpVtbl -> get_DataCount(This,pDataCount) ) 

#define IOPOSSoundRecorder_1_16_get_DataEventEnabled(This,pDataEventEnabled)	\
    ( (This)->lpVtbl -> get_DataEventEnabled(This,pDataEventEnabled) ) 

#define IOPOSSoundRecorder_1_16_put_DataEventEnabled(This,DataEventEnabled)	\
    ( (This)->lpVtbl -> put_DataEventEnabled(This,DataEventEnabled) ) 

#define IOPOSSoundRecorder_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSoundRecorder_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSoundRecorder_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSoundRecorder_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSoundRecorder_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSoundRecorder_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSoundRecorder_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSoundRecorder_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSoundRecorder_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSoundRecorder_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSoundRecorder_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSoundRecorder_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSoundRecorder_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSoundRecorder_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSoundRecorder_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSoundRecorder_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSoundRecorder_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSoundRecorder_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSoundRecorder_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSoundRecorder_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSoundRecorder_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSoundRecorder_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSoundRecorder_1_16_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSSoundRecorder_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSoundRecorder_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSoundRecorder_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSoundRecorder_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSoundRecorder_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSoundRecorder_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSoundRecorder_1_16_ClearInputProperties(This,pRC)	\
    ( (This)->lpVtbl -> ClearInputProperties(This,pRC) ) 

#define IOPOSSoundRecorder_1_16_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSSoundRecorder_1_16_get_CapChannel(This,pCapChannel)	\
    ( (This)->lpVtbl -> get_CapChannel(This,pCapChannel) ) 

#define IOPOSSoundRecorder_1_16_get_CapRecordingLevel(This,pCapRecordingLevel)	\
    ( (This)->lpVtbl -> get_CapRecordingLevel(This,pCapRecordingLevel) ) 

#define IOPOSSoundRecorder_1_16_get_CapSamplingRate(This,pCapSamplingRate)	\
    ( (This)->lpVtbl -> get_CapSamplingRate(This,pCapSamplingRate) ) 

#define IOPOSSoundRecorder_1_16_get_CapSoundType(This,pCapSoundType)	\
    ( (This)->lpVtbl -> get_CapSoundType(This,pCapSoundType) ) 

#define IOPOSSoundRecorder_1_16_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSSoundRecorder_1_16_get_Channel(This,pChannel)	\
    ( (This)->lpVtbl -> get_Channel(This,pChannel) ) 

#define IOPOSSoundRecorder_1_16_put_Channel(This,Channel)	\
    ( (This)->lpVtbl -> put_Channel(This,Channel) ) 

#define IOPOSSoundRecorder_1_16_get_ChannelList(This,pChannelList)	\
    ( (This)->lpVtbl -> get_ChannelList(This,pChannelList) ) 

#define IOPOSSoundRecorder_1_16_get_RecordingLevel(This,pRecordingLevel)	\
    ( (This)->lpVtbl -> get_RecordingLevel(This,pRecordingLevel) ) 

#define IOPOSSoundRecorder_1_16_put_RecordingLevel(This,RecordingLevel)	\
    ( (This)->lpVtbl -> put_RecordingLevel(This,RecordingLevel) ) 

#define IOPOSSoundRecorder_1_16_get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec)	\
    ( (This)->lpVtbl -> get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec) ) 

#define IOPOSSoundRecorder_1_16_get_SamplingRate(This,pSamplingRate)	\
    ( (This)->lpVtbl -> get_SamplingRate(This,pSamplingRate) ) 

#define IOPOSSoundRecorder_1_16_put_SamplingRate(This,SamplingRate)	\
    ( (This)->lpVtbl -> put_SamplingRate(This,SamplingRate) ) 

#define IOPOSSoundRecorder_1_16_get_SamplingRateList(This,pSamplingRateList)	\
    ( (This)->lpVtbl -> get_SamplingRateList(This,pSamplingRateList) ) 

#define IOPOSSoundRecorder_1_16_get_SoundData(This,pSoundData)	\
    ( (This)->lpVtbl -> get_SoundData(This,pSoundData) ) 

#define IOPOSSoundRecorder_1_16_get_SoundType(This,pSoundType)	\
    ( (This)->lpVtbl -> get_SoundType(This,pSoundType) ) 

#define IOPOSSoundRecorder_1_16_put_SoundType(This,SoundType)	\
    ( (This)->lpVtbl -> put_SoundType(This,SoundType) ) 

#define IOPOSSoundRecorder_1_16_get_SoundTypeList(This,pSoundTypeList)	\
    ( (This)->lpVtbl -> get_SoundTypeList(This,pSoundTypeList) ) 

#define IOPOSSoundRecorder_1_16_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSSoundRecorder_1_16_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSSoundRecorder_1_16_StartRecording(This,FileName,OverWrite,RecordingTime,pRC)	\
    ( (This)->lpVtbl -> StartRecording(This,FileName,OverWrite,RecordingTime,pRC) ) 

#define IOPOSSoundRecorder_1_16_StopRecording(This,pRC)	\
    ( (This)->lpVtbl -> StopRecording(This,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSoundRecorder_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSSoundRecorder_INTERFACE_DEFINED__
#define __IOPOSSoundRecorder_INTERFACE_DEFINED__

/* interface IOPOSSoundRecorder */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSSoundRecorder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91431-B81E-11D2-AB74-0040054C3719")
    IOPOSSoundRecorder : public IOPOSSoundRecorder_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSSoundRecorderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSSoundRecorder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSSoundRecorder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSSoundRecorder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSSoundRecorder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSSoundRecorder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSSoundRecorder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSSoundRecorder * This,
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
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOData )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDisable )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoDisable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDisable )( 
            IOPOSSoundRecorder * This,
            /* [in] */ VARIANT_BOOL AutoDisable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataCount )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pDataCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataEventEnabled )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pDataEventEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataEventEnabled )( 
            IOPOSSoundRecorder * This,
            /* [in] */ VARIANT_BOOL DataEventEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSSoundRecorder * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSSoundRecorder * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSSoundRecorder * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInputProperties )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapAssociatedHardTotalsDevice )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pCapAssociatedHardTotalsDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapChannel )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapChannel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapRecordingLevel )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapRecordingLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSamplingRate )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSamplingRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapSoundType )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ VARIANT_BOOL *pCapSoundType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStorage )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pCapStorage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channel )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pChannel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Channel )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR Channel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelList )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pChannelList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingLevel )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRecordingLevel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RecordingLevel )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long RecordingLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemainingRecordingTimeInSec )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRemainingRecordingTimeInSec);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplingRate )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pSamplingRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SamplingRate )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR SamplingRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplingRateList )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pSamplingRateList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundData )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pSoundData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundType )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pSoundType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SoundType )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR SoundType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoundTypeList )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ BSTR *pSoundTypeList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pStorage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            IOPOSSoundRecorder * This,
            /* [in] */ long Storage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartRecording )( 
            IOPOSSoundRecorder * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL OverWrite,
            /* [in] */ long RecordingTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopRecording )( 
            IOPOSSoundRecorder * This,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSSoundRecorderVtbl;

    interface IOPOSSoundRecorder
    {
        CONST_VTBL struct IOPOSSoundRecorderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSSoundRecorder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSSoundRecorder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSSoundRecorder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSSoundRecorder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSSoundRecorder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSSoundRecorder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSSoundRecorder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSSoundRecorder_SOData(This,Status)	\
    ( (This)->lpVtbl -> SOData(This,Status) ) 

#define IOPOSSoundRecorder_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSSoundRecorder_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSSoundRecorder_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSSoundRecorder_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSSoundRecorder_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSSoundRecorder_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSSoundRecorder_get_AutoDisable(This,pAutoDisable)	\
    ( (This)->lpVtbl -> get_AutoDisable(This,pAutoDisable) ) 

#define IOPOSSoundRecorder_put_AutoDisable(This,AutoDisable)	\
    ( (This)->lpVtbl -> put_AutoDisable(This,AutoDisable) ) 

#define IOPOSSoundRecorder_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSSoundRecorder_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSSoundRecorder_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSSoundRecorder_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSSoundRecorder_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSSoundRecorder_get_DataCount(This,pDataCount)	\
    ( (This)->lpVtbl -> get_DataCount(This,pDataCount) ) 

#define IOPOSSoundRecorder_get_DataEventEnabled(This,pDataEventEnabled)	\
    ( (This)->lpVtbl -> get_DataEventEnabled(This,pDataEventEnabled) ) 

#define IOPOSSoundRecorder_put_DataEventEnabled(This,DataEventEnabled)	\
    ( (This)->lpVtbl -> put_DataEventEnabled(This,DataEventEnabled) ) 

#define IOPOSSoundRecorder_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSSoundRecorder_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSSoundRecorder_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSSoundRecorder_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSSoundRecorder_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSSoundRecorder_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSSoundRecorder_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSSoundRecorder_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSSoundRecorder_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSSoundRecorder_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSSoundRecorder_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSSoundRecorder_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSSoundRecorder_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSSoundRecorder_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSSoundRecorder_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSSoundRecorder_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSSoundRecorder_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSSoundRecorder_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSSoundRecorder_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSSoundRecorder_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSSoundRecorder_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSSoundRecorder_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSSoundRecorder_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSSoundRecorder_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSSoundRecorder_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSSoundRecorder_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSSoundRecorder_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSSoundRecorder_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSSoundRecorder_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSSoundRecorder_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSSoundRecorder_ClearInputProperties(This,pRC)	\
    ( (This)->lpVtbl -> ClearInputProperties(This,pRC) ) 

#define IOPOSSoundRecorder_get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice)	\
    ( (This)->lpVtbl -> get_CapAssociatedHardTotalsDevice(This,pCapAssociatedHardTotalsDevice) ) 

#define IOPOSSoundRecorder_get_CapChannel(This,pCapChannel)	\
    ( (This)->lpVtbl -> get_CapChannel(This,pCapChannel) ) 

#define IOPOSSoundRecorder_get_CapRecordingLevel(This,pCapRecordingLevel)	\
    ( (This)->lpVtbl -> get_CapRecordingLevel(This,pCapRecordingLevel) ) 

#define IOPOSSoundRecorder_get_CapSamplingRate(This,pCapSamplingRate)	\
    ( (This)->lpVtbl -> get_CapSamplingRate(This,pCapSamplingRate) ) 

#define IOPOSSoundRecorder_get_CapSoundType(This,pCapSoundType)	\
    ( (This)->lpVtbl -> get_CapSoundType(This,pCapSoundType) ) 

#define IOPOSSoundRecorder_get_CapStorage(This,pCapStorage)	\
    ( (This)->lpVtbl -> get_CapStorage(This,pCapStorage) ) 

#define IOPOSSoundRecorder_get_Channel(This,pChannel)	\
    ( (This)->lpVtbl -> get_Channel(This,pChannel) ) 

#define IOPOSSoundRecorder_put_Channel(This,Channel)	\
    ( (This)->lpVtbl -> put_Channel(This,Channel) ) 

#define IOPOSSoundRecorder_get_ChannelList(This,pChannelList)	\
    ( (This)->lpVtbl -> get_ChannelList(This,pChannelList) ) 

#define IOPOSSoundRecorder_get_RecordingLevel(This,pRecordingLevel)	\
    ( (This)->lpVtbl -> get_RecordingLevel(This,pRecordingLevel) ) 

#define IOPOSSoundRecorder_put_RecordingLevel(This,RecordingLevel)	\
    ( (This)->lpVtbl -> put_RecordingLevel(This,RecordingLevel) ) 

#define IOPOSSoundRecorder_get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec)	\
    ( (This)->lpVtbl -> get_RemainingRecordingTimeInSec(This,pRemainingRecordingTimeInSec) ) 

#define IOPOSSoundRecorder_get_SamplingRate(This,pSamplingRate)	\
    ( (This)->lpVtbl -> get_SamplingRate(This,pSamplingRate) ) 

#define IOPOSSoundRecorder_put_SamplingRate(This,SamplingRate)	\
    ( (This)->lpVtbl -> put_SamplingRate(This,SamplingRate) ) 

#define IOPOSSoundRecorder_get_SamplingRateList(This,pSamplingRateList)	\
    ( (This)->lpVtbl -> get_SamplingRateList(This,pSamplingRateList) ) 

#define IOPOSSoundRecorder_get_SoundData(This,pSoundData)	\
    ( (This)->lpVtbl -> get_SoundData(This,pSoundData) ) 

#define IOPOSSoundRecorder_get_SoundType(This,pSoundType)	\
    ( (This)->lpVtbl -> get_SoundType(This,pSoundType) ) 

#define IOPOSSoundRecorder_put_SoundType(This,SoundType)	\
    ( (This)->lpVtbl -> put_SoundType(This,SoundType) ) 

#define IOPOSSoundRecorder_get_SoundTypeList(This,pSoundTypeList)	\
    ( (This)->lpVtbl -> get_SoundTypeList(This,pSoundTypeList) ) 

#define IOPOSSoundRecorder_get_Storage(This,pStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,pStorage) ) 

#define IOPOSSoundRecorder_put_Storage(This,Storage)	\
    ( (This)->lpVtbl -> put_Storage(This,Storage) ) 

#define IOPOSSoundRecorder_StartRecording(This,FileName,OverWrite,RecordingTime,pRC)	\
    ( (This)->lpVtbl -> StartRecording(This,FileName,OverWrite,RecordingTime,pRC) ) 

#define IOPOSSoundRecorder_StopRecording(This,pRC)	\
    ( (This)->lpVtbl -> StopRecording(This,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSSoundRecorder_INTERFACE_DEFINED__ */



#ifndef __OposSoundRecorder_CCO_LIBRARY_DEFINED__
#define __OposSoundRecorder_CCO_LIBRARY_DEFINED__

/* library OposSoundRecorder_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposSoundRecorder_CCO;

#ifndef ___IOPOSSoundRecorderEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSSoundRecorderEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSSoundRecorderEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSSoundRecorderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90433-B81E-11D2-AB74-0040054C3719")
    _IOPOSSoundRecorderEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSSoundRecorderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSSoundRecorderEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSSoundRecorderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSSoundRecorderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSSoundRecorderEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSSoundRecorderEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSSoundRecorderEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSSoundRecorderEvents * This,
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
    } _IOPOSSoundRecorderEventsVtbl;

    interface _IOPOSSoundRecorderEvents
    {
        CONST_VTBL struct _IOPOSSoundRecorderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSSoundRecorderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSSoundRecorderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSSoundRecorderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSSoundRecorderEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSSoundRecorderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSSoundRecorderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSSoundRecorderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSSoundRecorderEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSSoundRecorder;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90432-B81E-11D2-AB74-0040054C3719")
OPOSSoundRecorder;
#endif
#endif /* __OposSoundRecorder_CCO_LIBRARY_DEFINED__ */

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


