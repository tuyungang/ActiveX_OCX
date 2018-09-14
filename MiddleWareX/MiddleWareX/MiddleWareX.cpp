// MiddleWareX.cpp : CMiddleWareXApp �� DLL ע���ʵ�֡�

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



// CMiddleWareXApp::InitInstance - DLL ��ʼ��

BOOL CMiddleWareXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CMiddleWareXApp::ExitInstance - DLL ��ֹ

int CMiddleWareXApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}

//����Component Categories�еĳ�ʼ����ȫ�ͽű���ȫ��
HRESULT CreateComponentCategory(CATID catid, WCHAR* catDescription)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister, (void**)&pcr);
	if (FAILED(hr))
		return hr;

	// ȷ��HKCR\Component Categories\{..catid...}��ֵ��ע��
	CATEGORYINFO catinfo;
	catinfo.catid = catid;
	catinfo.lcid = 0x0409; // english
	//size_t len;
	// ȷ����������̫����
	// ֻ���ƿ�ʼ��127���ַ���
	// StringCchLength�ĵڶ���������ʾ������catDescription������ַ�����
	// ������������ʾ�ַ����ĳ���
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
	// ����ַ���������.
	//catinfo.szDescription[len + 1] = '\0';
	catinfo.szDescription[len] = '/0';

	hr = pcr->RegisterCategories(1, &catinfo);
	pcr->Release();
	return hr;
}

//��CLSID�д�����Component Categories�г�ʼ����ȫ�ͽű���ȫ�������Ӧ��implemented Categories��
HRESULT RegisterCLSIDInCategory(REFCLSID clsid, CATID catid)
{
	// ע�����������Ϣ
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

//ע����CLSID�е���Ӧimplemented Categories�һ���ò�������Ϊ�����������Ҳ���õ������
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


// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	//�����ű���ȫ�����䡱���CLSID��
	HRESULT hr = CreateComponentCategory(CATID_SafeForScripting, L"Controls safely scriptable!");
	if (FAILED(hr))
		return hr;

	//������ʼ����ȫ�����䡱���CLSID��
	hr = CreateComponentCategory(CATID_SafeForInitializing, L"Controls safely initializable from persistent data!");
	if (FAILED(hr))
		return hr;

	//���ÿؼ�CLSID�в�����Ľű���ȫ��롰���䡱���еĽű���ȫ���Ӧ
	hr = RegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForScripting);
	if (FAILED(hr))
		return hr;

	//���ÿؼ�CLSID�в�����ĳ�ʼ����ȫ��롰���䡱���еĳ�ʼ����ȫ���Ӧ
	hr = RegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForInitializing);
	if (FAILED(hr))
		return hr;

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	// ɾ���ؼ���ʼ����ȫ���.
	HRESULT hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForInitializing);
	if (FAILED(hr))
		return hr;

	// ɾ���ؼ��ű���ȫ���
	hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForScripting);
	if (FAILED(hr))
		return hr;

	return NOERROR;
}
