

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for DeviceMonitor.idl:
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

#ifndef __DeviceMonitor_h__
#define __DeviceMonitor_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOPOSDeviceMonitor_1_16_FWD_DEFINED__
#define __IOPOSDeviceMonitor_1_16_FWD_DEFINED__
typedef interface IOPOSDeviceMonitor_1_16 IOPOSDeviceMonitor_1_16;

#endif 	/* __IOPOSDeviceMonitor_1_16_FWD_DEFINED__ */


#ifndef __IOPOSDeviceMonitor_FWD_DEFINED__
#define __IOPOSDeviceMonitor_FWD_DEFINED__
typedef interface IOPOSDeviceMonitor IOPOSDeviceMonitor;

#endif 	/* __IOPOSDeviceMonitor_FWD_DEFINED__ */


#ifndef ___IOPOSDeviceMonitorEvents_FWD_DEFINED__
#define ___IOPOSDeviceMonitorEvents_FWD_DEFINED__
typedef interface _IOPOSDeviceMonitorEvents _IOPOSDeviceMonitorEvents;

#endif 	/* ___IOPOSDeviceMonitorEvents_FWD_DEFINED__ */


#ifndef __OPOSDeviceMonitor_FWD_DEFINED__
#define __OPOSDeviceMonitor_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPOSDeviceMonitor OPOSDeviceMonitor;
#else
typedef struct OPOSDeviceMonitor OPOSDeviceMonitor;
#endif /* __cplusplus */

#endif 	/* __OPOSDeviceMonitor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOPOSDeviceMonitor_1_16_INTERFACE_DEFINED__
#define __IOPOSDeviceMonitor_1_16_INTERFACE_DEFINED__

/* interface IOPOSDeviceMonitor_1_16 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSDeviceMonitor_1_16;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB90381-B81E-11D2-AB74-0040054C3719")
    IOPOSDeviceMonitor_1_16 : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceData( 
            /* [retval][out] */ BSTR *pDeviceData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceList( 
            /* [retval][out] */ BSTR *pDeviceList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MonitoringDeviceList( 
            /* [retval][out] */ BSTR *pMonitoringDeviceList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMonitoringDevice( 
            /* [in] */ BSTR DeviceID,
            /* [in] */ long MonitoringMode,
            /* [in] */ long Boundary,
            /* [in] */ long SubBoundary,
            /* [in] */ long IntervalTime,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearMonitoringDevice( 
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteMonitoringDevice( 
            /* [in] */ BSTR DeviceID,
            /* [retval][out] */ long *pRC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeviceValue( 
            /* [in] */ BSTR DeviceID,
            /* [out] */ long *pValue,
            /* [retval][out] */ long *pRC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSDeviceMonitor_1_16Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSDeviceMonitor_1_16 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSDeviceMonitor_1_16 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSDeviceMonitor_1_16 * This,
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
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDisable )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoDisable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDisable )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ VARIANT_BOOL AutoDisable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataCount )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pDataCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataEventEnabled )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDataEventEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataEventEnabled )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ VARIANT_BOOL DataEventEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInputProperties )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceData )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceList )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pDeviceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MonitoringDeviceList )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ BSTR *pMonitoringDeviceList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMonitoringDevice )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR DeviceID,
            /* [in] */ long MonitoringMode,
            /* [in] */ long Boundary,
            /* [in] */ long SubBoundary,
            /* [in] */ long IntervalTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearMonitoringDevice )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteMonitoringDevice )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR DeviceID,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceValue )( 
            IOPOSDeviceMonitor_1_16 * This,
            /* [in] */ BSTR DeviceID,
            /* [out] */ long *pValue,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSDeviceMonitor_1_16Vtbl;

    interface IOPOSDeviceMonitor_1_16
    {
        CONST_VTBL struct IOPOSDeviceMonitor_1_16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSDeviceMonitor_1_16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSDeviceMonitor_1_16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSDeviceMonitor_1_16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSDeviceMonitor_1_16_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSDeviceMonitor_1_16_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSDeviceMonitor_1_16_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSDeviceMonitor_1_16_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSDeviceMonitor_1_16_SOData(This,Status)	\
    ( (This)->lpVtbl -> SOData(This,Status) ) 

#define IOPOSDeviceMonitor_1_16_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSDeviceMonitor_1_16_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSDeviceMonitor_1_16_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSDeviceMonitor_1_16_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSDeviceMonitor_1_16_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSDeviceMonitor_1_16_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSDeviceMonitor_1_16_get_AutoDisable(This,pAutoDisable)	\
    ( (This)->lpVtbl -> get_AutoDisable(This,pAutoDisable) ) 

#define IOPOSDeviceMonitor_1_16_put_AutoDisable(This,AutoDisable)	\
    ( (This)->lpVtbl -> put_AutoDisable(This,AutoDisable) ) 

#define IOPOSDeviceMonitor_1_16_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSDeviceMonitor_1_16_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSDeviceMonitor_1_16_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSDeviceMonitor_1_16_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSDeviceMonitor_1_16_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSDeviceMonitor_1_16_get_DataCount(This,pDataCount)	\
    ( (This)->lpVtbl -> get_DataCount(This,pDataCount) ) 

#define IOPOSDeviceMonitor_1_16_get_DataEventEnabled(This,pDataEventEnabled)	\
    ( (This)->lpVtbl -> get_DataEventEnabled(This,pDataEventEnabled) ) 

#define IOPOSDeviceMonitor_1_16_put_DataEventEnabled(This,DataEventEnabled)	\
    ( (This)->lpVtbl -> put_DataEventEnabled(This,DataEventEnabled) ) 

#define IOPOSDeviceMonitor_1_16_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSDeviceMonitor_1_16_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSDeviceMonitor_1_16_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSDeviceMonitor_1_16_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSDeviceMonitor_1_16_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSDeviceMonitor_1_16_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSDeviceMonitor_1_16_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSDeviceMonitor_1_16_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSDeviceMonitor_1_16_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSDeviceMonitor_1_16_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSDeviceMonitor_1_16_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSDeviceMonitor_1_16_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSDeviceMonitor_1_16_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSDeviceMonitor_1_16_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSDeviceMonitor_1_16_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSDeviceMonitor_1_16_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSDeviceMonitor_1_16_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSDeviceMonitor_1_16_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSDeviceMonitor_1_16_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSDeviceMonitor_1_16_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSDeviceMonitor_1_16_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSDeviceMonitor_1_16_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSDeviceMonitor_1_16_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSDeviceMonitor_1_16_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_1_16_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_1_16_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_1_16_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSDeviceMonitor_1_16_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ClearInputProperties(This,pRC)	\
    ( (This)->lpVtbl -> ClearInputProperties(This,pRC) ) 

#define IOPOSDeviceMonitor_1_16_get_DeviceData(This,pDeviceData)	\
    ( (This)->lpVtbl -> get_DeviceData(This,pDeviceData) ) 

#define IOPOSDeviceMonitor_1_16_get_DeviceList(This,pDeviceList)	\
    ( (This)->lpVtbl -> get_DeviceList(This,pDeviceList) ) 

#define IOPOSDeviceMonitor_1_16_get_MonitoringDeviceList(This,pMonitoringDeviceList)	\
    ( (This)->lpVtbl -> get_MonitoringDeviceList(This,pMonitoringDeviceList) ) 

#define IOPOSDeviceMonitor_1_16_AddMonitoringDevice(This,DeviceID,MonitoringMode,Boundary,SubBoundary,IntervalTime,pRC)	\
    ( (This)->lpVtbl -> AddMonitoringDevice(This,DeviceID,MonitoringMode,Boundary,SubBoundary,IntervalTime,pRC) ) 

#define IOPOSDeviceMonitor_1_16_ClearMonitoringDevice(This,pRC)	\
    ( (This)->lpVtbl -> ClearMonitoringDevice(This,pRC) ) 

#define IOPOSDeviceMonitor_1_16_DeleteMonitoringDevice(This,DeviceID,pRC)	\
    ( (This)->lpVtbl -> DeleteMonitoringDevice(This,DeviceID,pRC) ) 

#define IOPOSDeviceMonitor_1_16_GetDeviceValue(This,DeviceID,pValue,pRC)	\
    ( (This)->lpVtbl -> GetDeviceValue(This,DeviceID,pValue,pRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSDeviceMonitor_1_16_INTERFACE_DEFINED__ */


#ifndef __IOPOSDeviceMonitor_INTERFACE_DEFINED__
#define __IOPOSDeviceMonitor_INTERFACE_DEFINED__

/* interface IOPOSDeviceMonitor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOPOSDeviceMonitor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCB91381-B81E-11D2-AB74-0040054C3719")
    IOPOSDeviceMonitor : public IOPOSDeviceMonitor_1_16
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOPOSDeviceMonitorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOPOSDeviceMonitor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOPOSDeviceMonitor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOPOSDeviceMonitor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOPOSDeviceMonitor * This,
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
            IOPOSDeviceMonitor * This,
            /* [in] */ long Status);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SODirectIO )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long EventNumber,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOError )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long ResultCode,
            /* [in] */ long ResultCodeExtended,
            /* [in] */ long ErrorLocus,
            /* [out][in] */ long *pErrorResponse);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOOutputCompleteDummy )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long OutputID);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOStatusUpdate )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long Data);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SOProcessID )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pProcessID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OpenResult )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pOpenResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDisable )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoDisable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDisable )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ VARIANT_BOOL AutoDisable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BinaryConversion )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pBinaryConversion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BinaryConversion )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long BinaryConversion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapPowerReporting )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pCapPowerReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHealthText )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pCheckHealthText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Claimed )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pClaimed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataCount )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pDataCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataEventEnabled )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pDataEventEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataEventEnabled )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ VARIANT_BOOL DataEventEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceEnabled )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pDeviceEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceEnabled )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ VARIANT_BOOL DeviceEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreezeEvents )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pFreezeEvents);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreezeEvents )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ VARIANT_BOOL FreezeEvents);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerNotify )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pPowerNotify);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PowerNotify )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long PowerNotify);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PowerState )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pPowerState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCode )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pResultCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultCodeExtended )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pResultCodeExtended);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectDescription )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pControlObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlObjectVersion )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pControlObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectDescription )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pServiceObjectDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceObjectVersion )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pServiceObjectVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceDescription )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pDeviceDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapStatisticsReporting )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pCapStatisticsReporting);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateStatistics )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateStatistics);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapCompareFirmwareVersion )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pCapCompareFirmwareVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CapUpdateFirmware )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ VARIANT_BOOL *pCapUpdateFirmware);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckHealth )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long Level,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClaimDevice )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long Timeout,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInput )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DirectIO )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ long Command,
            /* [out][in] */ long *pData,
            /* [out][in] */ BSTR *pString,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR DeviceName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStatistics )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveStatistics )( 
            IOPOSDeviceMonitor * This,
            /* [out][in] */ BSTR *pStatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateStatistics )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR StatisticsBuffer,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompareFirmwareVersion )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [out] */ long *pResult,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateFirmware )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR FirmwareFileName,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearInputProperties )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceData )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pDeviceData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceList )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pDeviceList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MonitoringDeviceList )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ BSTR *pMonitoringDeviceList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMonitoringDevice )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR DeviceID,
            /* [in] */ long MonitoringMode,
            /* [in] */ long Boundary,
            /* [in] */ long SubBoundary,
            /* [in] */ long IntervalTime,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearMonitoringDevice )( 
            IOPOSDeviceMonitor * This,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteMonitoringDevice )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR DeviceID,
            /* [retval][out] */ long *pRC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceValue )( 
            IOPOSDeviceMonitor * This,
            /* [in] */ BSTR DeviceID,
            /* [out] */ long *pValue,
            /* [retval][out] */ long *pRC);
        
        END_INTERFACE
    } IOPOSDeviceMonitorVtbl;

    interface IOPOSDeviceMonitor
    {
        CONST_VTBL struct IOPOSDeviceMonitorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPOSDeviceMonitor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOPOSDeviceMonitor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOPOSDeviceMonitor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOPOSDeviceMonitor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOPOSDeviceMonitor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOPOSDeviceMonitor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOPOSDeviceMonitor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOPOSDeviceMonitor_SOData(This,Status)	\
    ( (This)->lpVtbl -> SOData(This,Status) ) 

#define IOPOSDeviceMonitor_SODirectIO(This,EventNumber,pData,pString)	\
    ( (This)->lpVtbl -> SODirectIO(This,EventNumber,pData,pString) ) 

#define IOPOSDeviceMonitor_SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse)	\
    ( (This)->lpVtbl -> SOError(This,ResultCode,ResultCodeExtended,ErrorLocus,pErrorResponse) ) 

#define IOPOSDeviceMonitor_SOOutputCompleteDummy(This,OutputID)	\
    ( (This)->lpVtbl -> SOOutputCompleteDummy(This,OutputID) ) 

#define IOPOSDeviceMonitor_SOStatusUpdate(This,Data)	\
    ( (This)->lpVtbl -> SOStatusUpdate(This,Data) ) 

#define IOPOSDeviceMonitor_SOProcessID(This,pProcessID)	\
    ( (This)->lpVtbl -> SOProcessID(This,pProcessID) ) 

#define IOPOSDeviceMonitor_get_OpenResult(This,pOpenResult)	\
    ( (This)->lpVtbl -> get_OpenResult(This,pOpenResult) ) 

#define IOPOSDeviceMonitor_get_AutoDisable(This,pAutoDisable)	\
    ( (This)->lpVtbl -> get_AutoDisable(This,pAutoDisable) ) 

#define IOPOSDeviceMonitor_put_AutoDisable(This,AutoDisable)	\
    ( (This)->lpVtbl -> put_AutoDisable(This,AutoDisable) ) 

#define IOPOSDeviceMonitor_get_BinaryConversion(This,pBinaryConversion)	\
    ( (This)->lpVtbl -> get_BinaryConversion(This,pBinaryConversion) ) 

#define IOPOSDeviceMonitor_put_BinaryConversion(This,BinaryConversion)	\
    ( (This)->lpVtbl -> put_BinaryConversion(This,BinaryConversion) ) 

#define IOPOSDeviceMonitor_get_CapPowerReporting(This,pCapPowerReporting)	\
    ( (This)->lpVtbl -> get_CapPowerReporting(This,pCapPowerReporting) ) 

#define IOPOSDeviceMonitor_get_CheckHealthText(This,pCheckHealthText)	\
    ( (This)->lpVtbl -> get_CheckHealthText(This,pCheckHealthText) ) 

#define IOPOSDeviceMonitor_get_Claimed(This,pClaimed)	\
    ( (This)->lpVtbl -> get_Claimed(This,pClaimed) ) 

#define IOPOSDeviceMonitor_get_DataCount(This,pDataCount)	\
    ( (This)->lpVtbl -> get_DataCount(This,pDataCount) ) 

#define IOPOSDeviceMonitor_get_DataEventEnabled(This,pDataEventEnabled)	\
    ( (This)->lpVtbl -> get_DataEventEnabled(This,pDataEventEnabled) ) 

#define IOPOSDeviceMonitor_put_DataEventEnabled(This,DataEventEnabled)	\
    ( (This)->lpVtbl -> put_DataEventEnabled(This,DataEventEnabled) ) 

#define IOPOSDeviceMonitor_get_DeviceEnabled(This,pDeviceEnabled)	\
    ( (This)->lpVtbl -> get_DeviceEnabled(This,pDeviceEnabled) ) 

#define IOPOSDeviceMonitor_put_DeviceEnabled(This,DeviceEnabled)	\
    ( (This)->lpVtbl -> put_DeviceEnabled(This,DeviceEnabled) ) 

#define IOPOSDeviceMonitor_get_FreezeEvents(This,pFreezeEvents)	\
    ( (This)->lpVtbl -> get_FreezeEvents(This,pFreezeEvents) ) 

#define IOPOSDeviceMonitor_put_FreezeEvents(This,FreezeEvents)	\
    ( (This)->lpVtbl -> put_FreezeEvents(This,FreezeEvents) ) 

#define IOPOSDeviceMonitor_get_PowerNotify(This,pPowerNotify)	\
    ( (This)->lpVtbl -> get_PowerNotify(This,pPowerNotify) ) 

#define IOPOSDeviceMonitor_put_PowerNotify(This,PowerNotify)	\
    ( (This)->lpVtbl -> put_PowerNotify(This,PowerNotify) ) 

#define IOPOSDeviceMonitor_get_PowerState(This,pPowerState)	\
    ( (This)->lpVtbl -> get_PowerState(This,pPowerState) ) 

#define IOPOSDeviceMonitor_get_ResultCode(This,pResultCode)	\
    ( (This)->lpVtbl -> get_ResultCode(This,pResultCode) ) 

#define IOPOSDeviceMonitor_get_ResultCodeExtended(This,pResultCodeExtended)	\
    ( (This)->lpVtbl -> get_ResultCodeExtended(This,pResultCodeExtended) ) 

#define IOPOSDeviceMonitor_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IOPOSDeviceMonitor_get_ControlObjectDescription(This,pControlObjectDescription)	\
    ( (This)->lpVtbl -> get_ControlObjectDescription(This,pControlObjectDescription) ) 

#define IOPOSDeviceMonitor_get_ControlObjectVersion(This,pControlObjectVersion)	\
    ( (This)->lpVtbl -> get_ControlObjectVersion(This,pControlObjectVersion) ) 

#define IOPOSDeviceMonitor_get_ServiceObjectDescription(This,pServiceObjectDescription)	\
    ( (This)->lpVtbl -> get_ServiceObjectDescription(This,pServiceObjectDescription) ) 

#define IOPOSDeviceMonitor_get_ServiceObjectVersion(This,pServiceObjectVersion)	\
    ( (This)->lpVtbl -> get_ServiceObjectVersion(This,pServiceObjectVersion) ) 

#define IOPOSDeviceMonitor_get_DeviceDescription(This,pDeviceDescription)	\
    ( (This)->lpVtbl -> get_DeviceDescription(This,pDeviceDescription) ) 

#define IOPOSDeviceMonitor_get_DeviceName(This,pDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pDeviceName) ) 

#define IOPOSDeviceMonitor_get_CapStatisticsReporting(This,pCapStatisticsReporting)	\
    ( (This)->lpVtbl -> get_CapStatisticsReporting(This,pCapStatisticsReporting) ) 

#define IOPOSDeviceMonitor_get_CapUpdateStatistics(This,pCapUpdateStatistics)	\
    ( (This)->lpVtbl -> get_CapUpdateStatistics(This,pCapUpdateStatistics) ) 

#define IOPOSDeviceMonitor_get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion)	\
    ( (This)->lpVtbl -> get_CapCompareFirmwareVersion(This,pCapCompareFirmwareVersion) ) 

#define IOPOSDeviceMonitor_get_CapUpdateFirmware(This,pCapUpdateFirmware)	\
    ( (This)->lpVtbl -> get_CapUpdateFirmware(This,pCapUpdateFirmware) ) 

#define IOPOSDeviceMonitor_CheckHealth(This,Level,pRC)	\
    ( (This)->lpVtbl -> CheckHealth(This,Level,pRC) ) 

#define IOPOSDeviceMonitor_ClaimDevice(This,Timeout,pRC)	\
    ( (This)->lpVtbl -> ClaimDevice(This,Timeout,pRC) ) 

#define IOPOSDeviceMonitor_ClearInput(This,pRC)	\
    ( (This)->lpVtbl -> ClearInput(This,pRC) ) 

#define IOPOSDeviceMonitor_Close(This,pRC)	\
    ( (This)->lpVtbl -> Close(This,pRC) ) 

#define IOPOSDeviceMonitor_DirectIO(This,Command,pData,pString,pRC)	\
    ( (This)->lpVtbl -> DirectIO(This,Command,pData,pString,pRC) ) 

#define IOPOSDeviceMonitor_Open(This,DeviceName,pRC)	\
    ( (This)->lpVtbl -> Open(This,DeviceName,pRC) ) 

#define IOPOSDeviceMonitor_ReleaseDevice(This,pRC)	\
    ( (This)->lpVtbl -> ReleaseDevice(This,pRC) ) 

#define IOPOSDeviceMonitor_ResetStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> ResetStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_RetrieveStatistics(This,pStatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> RetrieveStatistics(This,pStatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_UpdateStatistics(This,StatisticsBuffer,pRC)	\
    ( (This)->lpVtbl -> UpdateStatistics(This,StatisticsBuffer,pRC) ) 

#define IOPOSDeviceMonitor_CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC)	\
    ( (This)->lpVtbl -> CompareFirmwareVersion(This,FirmwareFileName,pResult,pRC) ) 

#define IOPOSDeviceMonitor_UpdateFirmware(This,FirmwareFileName,pRC)	\
    ( (This)->lpVtbl -> UpdateFirmware(This,FirmwareFileName,pRC) ) 

#define IOPOSDeviceMonitor_ClearInputProperties(This,pRC)	\
    ( (This)->lpVtbl -> ClearInputProperties(This,pRC) ) 

#define IOPOSDeviceMonitor_get_DeviceData(This,pDeviceData)	\
    ( (This)->lpVtbl -> get_DeviceData(This,pDeviceData) ) 

#define IOPOSDeviceMonitor_get_DeviceList(This,pDeviceList)	\
    ( (This)->lpVtbl -> get_DeviceList(This,pDeviceList) ) 

#define IOPOSDeviceMonitor_get_MonitoringDeviceList(This,pMonitoringDeviceList)	\
    ( (This)->lpVtbl -> get_MonitoringDeviceList(This,pMonitoringDeviceList) ) 

#define IOPOSDeviceMonitor_AddMonitoringDevice(This,DeviceID,MonitoringMode,Boundary,SubBoundary,IntervalTime,pRC)	\
    ( (This)->lpVtbl -> AddMonitoringDevice(This,DeviceID,MonitoringMode,Boundary,SubBoundary,IntervalTime,pRC) ) 

#define IOPOSDeviceMonitor_ClearMonitoringDevice(This,pRC)	\
    ( (This)->lpVtbl -> ClearMonitoringDevice(This,pRC) ) 

#define IOPOSDeviceMonitor_DeleteMonitoringDevice(This,DeviceID,pRC)	\
    ( (This)->lpVtbl -> DeleteMonitoringDevice(This,DeviceID,pRC) ) 

#define IOPOSDeviceMonitor_GetDeviceValue(This,DeviceID,pValue,pRC)	\
    ( (This)->lpVtbl -> GetDeviceValue(This,DeviceID,pValue,pRC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOPOSDeviceMonitor_INTERFACE_DEFINED__ */



#ifndef __OposDeviceMonitor_CCO_LIBRARY_DEFINED__
#define __OposDeviceMonitor_CCO_LIBRARY_DEFINED__

/* library OposDeviceMonitor_CCO */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OposDeviceMonitor_CCO;

#ifndef ___IOPOSDeviceMonitorEvents_DISPINTERFACE_DEFINED__
#define ___IOPOSDeviceMonitorEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOPOSDeviceMonitorEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOPOSDeviceMonitorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB90383-B81E-11D2-AB74-0040054C3719")
    _IOPOSDeviceMonitorEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOPOSDeviceMonitorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOPOSDeviceMonitorEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOPOSDeviceMonitorEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOPOSDeviceMonitorEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOPOSDeviceMonitorEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOPOSDeviceMonitorEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOPOSDeviceMonitorEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOPOSDeviceMonitorEvents * This,
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
    } _IOPOSDeviceMonitorEventsVtbl;

    interface _IOPOSDeviceMonitorEvents
    {
        CONST_VTBL struct _IOPOSDeviceMonitorEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOPOSDeviceMonitorEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOPOSDeviceMonitorEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOPOSDeviceMonitorEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOPOSDeviceMonitorEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOPOSDeviceMonitorEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOPOSDeviceMonitorEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOPOSDeviceMonitorEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOPOSDeviceMonitorEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPOSDeviceMonitor;

#ifdef __cplusplus

class DECLSPEC_UUID("CCB90382-B81E-11D2-AB74-0040054C3719")
OPOSDeviceMonitor;
#endif
#endif /* __OposDeviceMonitor_CCO_LIBRARY_DEFINED__ */

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


