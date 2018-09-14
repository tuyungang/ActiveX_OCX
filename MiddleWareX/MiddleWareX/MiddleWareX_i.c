

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MiddleWareXLib,0x1C1A40F6,0x7177,0x494A,0xBA,0xFC,0xA3,0xDE,0x6A,0x80,0xE1,0x5A);


MIDL_DEFINE_GUID(IID, DIID__DMiddleWareX,0x77A84000,0xD1CC,0x4307,0x8D,0x74,0xE7,0x05,0x81,0xB4,0xE0,0xFE);


MIDL_DEFINE_GUID(IID, DIID__DMiddleWareXEvents,0x8DBBDB25,0x9761,0x4EA8,0xB1,0x4D,0x1A,0x33,0x00,0xAC,0xC1,0x13);


MIDL_DEFINE_GUID(CLSID, CLSID_MiddleWareX,0x869C5BAF,0xBE33,0x4A20,0x87,0x96,0xD9,0xE0,0xDB,0x5B,0x66,0x9C);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



