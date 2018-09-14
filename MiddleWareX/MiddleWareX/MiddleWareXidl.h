

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Sep 13 23:51:14 2018
 */
/* Compiler settings for MiddleWareX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MiddleWareXidl_h__
#define __MiddleWareXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DMiddleWareX_FWD_DEFINED__
#define ___DMiddleWareX_FWD_DEFINED__
typedef interface _DMiddleWareX _DMiddleWareX;

#endif 	/* ___DMiddleWareX_FWD_DEFINED__ */


#ifndef ___DMiddleWareXEvents_FWD_DEFINED__
#define ___DMiddleWareXEvents_FWD_DEFINED__
typedef interface _DMiddleWareXEvents _DMiddleWareXEvents;

#endif 	/* ___DMiddleWareXEvents_FWD_DEFINED__ */


#ifndef __MiddleWareX_FWD_DEFINED__
#define __MiddleWareX_FWD_DEFINED__

#ifdef __cplusplus
typedef class MiddleWareX MiddleWareX;
#else
typedef struct MiddleWareX MiddleWareX;
#endif /* __cplusplus */

#endif 	/* __MiddleWareX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MiddleWareX_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_MiddleWareX_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MiddleWareX_0000_0000_v0_0_s_ifspec;


#ifndef __MiddleWareXLib_LIBRARY_DEFINED__
#define __MiddleWareXLib_LIBRARY_DEFINED__

/* library MiddleWareXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_MiddleWareXLib;

#ifndef ___DMiddleWareX_DISPINTERFACE_DEFINED__
#define ___DMiddleWareX_DISPINTERFACE_DEFINED__

/* dispinterface _DMiddleWareX */
/* [uuid] */ 


EXTERN_C const IID DIID__DMiddleWareX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("77A84000-D1CC-4307-8D74-E70581B4E0FE")
    _DMiddleWareX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMiddleWareXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMiddleWareX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMiddleWareX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMiddleWareX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMiddleWareX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMiddleWareX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMiddleWareX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMiddleWareX * This,
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
    } _DMiddleWareXVtbl;

    interface _DMiddleWareX
    {
        CONST_VTBL struct _DMiddleWareXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMiddleWareX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMiddleWareX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMiddleWareX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMiddleWareX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMiddleWareX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMiddleWareX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMiddleWareX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMiddleWareX_DISPINTERFACE_DEFINED__ */


#ifndef ___DMiddleWareXEvents_DISPINTERFACE_DEFINED__
#define ___DMiddleWareXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DMiddleWareXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DMiddleWareXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8DBBDB25-9761-4EA8-B14D-1A3300ACC113")
    _DMiddleWareXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMiddleWareXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMiddleWareXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMiddleWareXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMiddleWareXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMiddleWareXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMiddleWareXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMiddleWareXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMiddleWareXEvents * This,
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
    } _DMiddleWareXEventsVtbl;

    interface _DMiddleWareXEvents
    {
        CONST_VTBL struct _DMiddleWareXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMiddleWareXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMiddleWareXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMiddleWareXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMiddleWareXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMiddleWareXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMiddleWareXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMiddleWareXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMiddleWareXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MiddleWareX;

#ifdef __cplusplus

class DECLSPEC_UUID("869C5BAF-BE33-4A20-8796-D9E0DB5B669C")
MiddleWareX;
#endif
#endif /* __MiddleWareXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


