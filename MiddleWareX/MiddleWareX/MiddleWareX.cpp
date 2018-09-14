// MiddleWareX.cpp : CMiddleWareXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "MiddleWareX.h"
#include "ComCat.h"
#include "strsafe.h"
#include "ObjSafe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMiddleWareXApp theApp;

const GUID CDECL _tlid = { 0x1C1A40F6, 0x7177, 0x494A, { 0xBA, 0xFC, 0xA3, 0xDE, 0x6A, 0x80, 0xE1, 0x5A } };
const GUID CDECL CLSID_SafeItem = { 0x869c5baf, 0xbe33, 0x4a20, 0x87, 0x96, 0xd9, 0xe0, 0xdb, 0x5b, 0x66, 0x9c };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMiddleWareXApp::InitInstance - DLL 初始化

BOOL CMiddleWareXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMiddleWareXApp::ExitInstance - DLL 终止

int CMiddleWareXApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}

//创建Component Categories中的初始化安全和脚本安全项
HRESULT CreateComponentCategory(CATID catid, WCHAR* catDescription)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister, (void**)&pcr);
	if (FAILED(hr))
		return hr;

	// 确认HKCR\Component Categories\{..catid...}键值被注册
	CATEGORYINFO catinfo;
	catinfo.catid = catid;
	catinfo.lcid = 0x0409; // english
	//size_t len;
	// 确认描述不是太长。
	// 只复制开始的127个字符。
	// StringCchLength的第二个参数表示被读入catDescription的最大字符数。
	// 第三个参数表示字符串的长度
	//hr = StringCchLength(catDescription, STRSAFE_MAX_CCH, &len);
	int len = wcslen(catDescription);
	if (SUCCEEDED(hr))
	{
		if (len>127)
		{
			len = 127;
		}
	}
	else
	{
		// TODO: Write an error handler;
	}

	wcsncpy(catinfo.szDescription, catDescription, len);
	//hr = StringCchCopy(catinfo.szDescription, len + 1, catDescription);
	// 添加字符串结束符.
	//catinfo.szDescription[len + 1] = '\0';
	catinfo.szDescription[len] = '/0';

	hr = pcr->RegisterCategories(1, &catinfo);
	pcr->Release();
	return hr;
}

//在CLSID中创建与Component Categories中初始化安全和脚本安全项中相对应的implemented Categories项
HRESULT RegisterCLSIDInCategory(REFCLSID clsid, CATID catid)
{
	// 注册组件分类信息
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister, (void**)&pcr);

	if (SUCCEEDED(hr))
	{
		CATID rgcatid[1];
		rgcatid[0] = catid;
		hr = pcr->RegisterClassImplCategories(clsid, 1, rgcatid);
	}

	if (pcr != NULL)
		pcr->Release();

	return hr;

}

//注销与CLSID中的相应implemented Categories项，一般用不到，因为其它程序可能也会用到这此项
HRESULT UnRegisterCLSIDInCategory(REFCLSID clsid, CATID catid)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister, (void**)&pcr);

	if (SUCCEEDED(hr))
	{
		CATID rgcatid[1];
		rgcatid[0] = catid;
		hr = pcr->UnRegisterClassImplCategories(clsid, 1, rgcatid);
	}

	if (pcr != NULL)
		pcr->Release();
	return hr;
}


// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	//创建脚本安全“补充”项，非CLSID中
	HRESULT hr = CreateComponentCategory(CATID_SafeForScripting, L"Controls safely scriptable!");
	if (FAILED(hr))
		return hr;

	//创建初始化安全“补充”项，非CLSID中
	hr = CreateComponentCategory(CATID_SafeForInitializing, L"Controls safely initializable from persistent data!");
	if (FAILED(hr))
		return hr;

	//设置控件CLSID中补充项的脚本安全项，与“补充”项中的脚本安全项对应
	hr = RegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForScripting);
	if (FAILED(hr))
		return hr;

	//设置控件CLSID中补充项的初始化安全项，与“补充”项中的初始化安全项对应
	hr = RegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForInitializing);
	if (FAILED(hr))
		return hr;

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	// 删除控件初始化安全入口.
	HRESULT hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForInitializing);
	if (FAILED(hr))
		return hr;

	// 删除控件脚本安全入口
	hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForScripting);
	if (FAILED(hr))
		return hr;

	return NOERROR;
}
