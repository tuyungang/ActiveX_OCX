// MiddleWareXCtrl.cpp : CMiddleWareXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "MiddleWareX.h"
#include "MiddleWareXCtrl.h"
#include "MiddleWareXPropPage.h"
#include "afxdialogex.h"

#include <iostream>
#include <map>
#include <string>
#include <atlconv.h>
#include "Util.h"

using namespace std;


//pair<LPCTSTR, LPCTSTR> pairArray[] =
//{
//	make_pair(L"", L"")
//};
pair<char*, char*> pairArray[] =
{
	make_pair((char*)(""), (char*)(""))
};

#pragma data_seg("MYSEC")
//__declspec(dllexport) map<LPCTSTR, LPCTSTR> m_share_data_map(pairArray, pairArray);
//WCHAR *p_key[] = {0};
//WCHAR *p_ualue[] = {0};
map<char*, char*> m_share_data_map(pairArray, pairArray + sizeof(pairArray) / sizeof(pairArray[0]));
static BOOL m_first = FALSE;
long m_index = 0;
CRITICAL_SECTION m_cs_lock = { 0 };
//__declspec(dllexport) map<CString, CString> *m_share_data_map = NULL;
//__declspec(dllexport) CRITICAL_SECTION m_cs_lock = {0};
#pragma data_seg()
#pragma comment(linker,"/SECTION:MYSEC,RWS")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMiddleWareXCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMiddleWareXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CMiddleWareXCtrl, COleControl)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "GetMessage", dispidGetMessage, GetMessage, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "SetMessage", dispidSetMessage, SetMessage, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "BeginWrite", dispidBeginWrite, BeginWrite, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "SaveMessage", dispidSaveMessage, SaveMessage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "LoadMessages", dispidLoadMessages, LoadMessages, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "EncodeMessage", dispidEncodeMessage, EncodeMessage, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "DecodeMessage", dispidDecodeMessage, DecodeMessage, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "BeginRead", dispidBeginRead, BeginRead, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "EndRead", dispidEndRead, EndRead, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMiddleWareXCtrl, "ReleaseShareMem", dispidReleaseShareMem, ReleaseShareMem, VT_I4, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CMiddleWareXCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMiddleWareXCtrl, 1)
	PROPPAGEID(CMiddleWareXPropPage::guid)
END_PROPPAGEIDS(CMiddleWareXCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMiddleWareXCtrl, "MIDDLEWAREX.MiddleWareXCtrl.1",
	0x869c5baf, 0xbe33, 0x4a20, 0x87, 0x96, 0xd9, 0xe0, 0xdb, 0x5b, 0x66, 0x9c)
	

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMiddleWareXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DMiddleWareX = { 0x77A84000, 0xD1CC, 0x4307, { 0x8D, 0x74, 0xE7, 0x5, 0x81, 0xB4, 0xE0, 0xFE } };
const IID IID_DMiddleWareXEvents = { 0x8DBBDB25, 0x9761, 0x4EA8, { 0xB1, 0x4D, 0x1A, 0x33, 0x0, 0xAC, 0xC1, 0x13 } };

// �ؼ�������Ϣ

static const DWORD _dwMiddleWareXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMiddleWareXCtrl, IDS_MIDDLEWAREX, _dwMiddleWareXOleMisc)

// CMiddleWareXCtrl::CMiddleWareXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMiddleWareXCtrl ��ϵͳע�����

BOOL CMiddleWareXCtrl::CMiddleWareXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MIDDLEWAREX,
			IDB_MIDDLEWAREX,
			afxRegApartmentThreading,
			_dwMiddleWareXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMiddleWareXCtrl::CMiddleWareXCtrl - ���캯��

CMiddleWareXCtrl::CMiddleWareXCtrl()
{
	InitializeIIDs(&IID_DMiddleWareX, &IID_DMiddleWareXEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	::InitializeCriticalSection(&m_cs_lock);
}

// CMiddleWareXCtrl::~CMiddleWareXCtrl - ��������

CMiddleWareXCtrl::~CMiddleWareXCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CMiddleWareXCtrl::OnDraw - ��ͼ����

void CMiddleWareXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMiddleWareXCtrl::DoPropExchange - �־���֧��

void CMiddleWareXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CMiddleWareXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMiddleWareXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CMiddleWareXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CMiddleWareXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MIDDLEWAREX);
	dlgAbout.DoModal();
}


// CMiddleWareXCtrl ��Ϣ�������


BSTR CMiddleWareXCtrl::GetMessage(LPCTSTR name)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	
	// TODO:  �ڴ���ӵ��ȴ���������
	//int i;
	//for (i = 0; i < m_index; i++) {
	//	/*if (lstrcmp(p_key[i], L"tyg") == 0) {
	//		strResult = p_ualue[i];
	//		break;
	//	}*/
	//	strResult = p_key[1];
	//	break;
	//}

	//FILE *p = NULL;
	map<char*, char*>::iterator it;
	if (m_share_data_map.empty()) {
		strResult = "";
	}
	else {

		int iLen = WideCharToMultiByte(CP_ACP, 0, name, -1, NULL, 0, NULL, NULL);
		char *tu = new char[iLen * sizeof(char) + 1]();
		//memset(tu, 0, iLen * sizeof(char) + 1);
		WideCharToMultiByte(CP_ACP, 0, name, -1, tu, iLen, NULL, NULL);
		
		for (it = m_share_data_map.begin(); it != m_share_data_map.end(); it++) {
			if (strncmp((*it).first, tu, strlen(tu)) == 0) {
				//int iLen = WideCharToMultiByte(CP_UTF8, 0, it->second, -1, NULL, 0, NULL, NULL);
				//char *tu1 = new char[iLen * sizeof(char) + 1]();
				////memset(tu, 0, iLen * sizeof(char) + 1);
				//WideCharToMultiByte(CP_UTF8, 0, name, -1, tu1, iLen, NULL, NULL);

				//int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
				//unsigned short * wszGBK = new unsigned short[len + 1];
				//memset(wszGBK, 0, len * 2 + 2);
				//MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUTF8.c_str(), -1, wszGBK, len);
				//strResult = tu1;
				//strResult = "777";
				if (strcmp((*it).second, "") != 0) {
					strResult = (*it).second;
					//strResult = "aaa";
				}
				else {
					strResult = "";
					//strResult = "bbb";
				}
				break;
			}
		}
	}
	/*p = fopen("E:\\out.txt", "a+");
	for (it = m_share_data_map.begin(); it != m_share_data_map.end(); it++) {
		fwrite(it->first, sizeof(char), strlen(it->first), p);
		fwrite(":", sizeof(char), strlen(":"), p);
		fwrite(it->second, sizeof(char), strlen(it->second), p);

	}
	fclose(p);
	*/
	return strResult.AllocSysString();
}


BSTR CMiddleWareXCtrl::SetMessage(LPCTSTR name, LPCTSTR ualue)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
	//strResult = ualue;
	//strResult.GetLength();
	//int i;
	//if (m_index == 0) {
	//	p_key[m_index] = new WCHAR[lstrlen(name) + 1]();
	//	p_ualue[m_index] = new WCHAR[lstrlen(ualue) + 1]();
	//	wmemcpy(p_key[m_index], name, lstrlen(name));
	//	wmemcpy(p_ualue[m_index], ualue, lstrlen(ualue));
	//	//strResult = p_ualue[m_index];
	//	m_index++;
	//}
	//else {
	//	for (i = 0; i < m_index; i++) {
	//		if (lstrcmp(p_key[i], name) == 0) {
	//			/*delete [](p_key + i);
	//			delete [](p_ualue + i);*/
	//			p_key[i] = new WCHAR[lstrlen(name) + 1]();
	//			p_ualue[i] = new WCHAR[lstrlen(ualue) + 1]();
	//			wmemcpy(p_key[i], name, lstrlen(name));
	//			wmemcpy(p_ualue[i], ualue, lstrlen(ualue));
	//			//strResult = p_ualue[i];
	//			break;
	//		}
	//	}
	//	if (i >= m_index) {
	//		p_key[m_index] = new WCHAR[lstrlen(name) + 1]();
	//		p_ualue[m_index] = new WCHAR[lstrlen(ualue) + 1]();
	//		wmemcpy(p_key[m_index], name, lstrlen(name));
	//		wmemcpy(p_ualue[m_index], ualue, lstrlen(ualue));
	//		//strResult = p_ualue[m_index];
	//		m_index++;
	//	}
	//}

	//for (i = 0; i < m_index; i++) {
	//	if (lstrcmp(p_key[i], name) == 0) {
	//		strResult = p_key[i];
	//		break;
	//	}
	//}
	char *tu_name;
	char *tu_ualue;

	int name_iLen = WideCharToMultiByte(CP_ACP, 0, name, -1, NULL, 0, NULL, NULL);
	tu_name = new char[name_iLen * sizeof(char)]();
	WideCharToMultiByte(CP_ACP, 0, name, -1, tu_name, name_iLen, NULL, NULL);

	char *p_name = new char[strlen(tu_name) * sizeof(char) + 1]();
	memcpy(p_name, tu_name, strlen(tu_name));
	delete[]tu_name;

	char *p_ualue;
	strResult = ualue;
	//if (lstrcmp(ualue, L"") != 0) {
	if (strResult.Compare(_T("")) != 0) {
		int ualue_iLen = WideCharToMultiByte(CP_ACP, 0, ualue, -1, NULL, 0, NULL, NULL);
		//int ualue_iLen = WideCharToMultiByte(CP_UTF8, 0, ualue, -1, NULL, 0, NULL, NULL);
		tu_ualue = new char[ualue_iLen * sizeof(char)]();
		WideCharToMultiByte(CP_ACP, 0, ualue, -1, tu_ualue, ualue_iLen, NULL, NULL);

		p_ualue = new char[strlen(tu_ualue) * sizeof(char) + 1]();
		memcpy(p_ualue, tu_ualue, strlen(tu_ualue));
		delete[]tu_ualue;
	}

	map<char*, char*>::iterator it;	

	if (!m_first) {
		m_share_data_map.clear();
		m_first = TRUE;
	}
	
	if (m_share_data_map.empty()) {
		//strResult = ualue;
		if (strResult.Compare(_T("")) != 0) {
		//if (lstrcmp(ualue, L"") != 0) {
			m_share_data_map.insert(map<char*, char*>::value_type(p_name, p_ualue));
			strResult = "111";
		}
		else {
			m_share_data_map.insert(map<char*, char*>::value_type(p_name, ""));
			strResult = "555";
		}
		//strResult = "555";
		
	} 
	else {
		//it = m_share_data_map.find("areaCode");
		//if (it != m_share_data_map.end()) {
		//	strResult = "666";
		//	/*free(it->first);
		//	free(it->second);
		//	m_share_data_map.erase(it);
		//	m_share_data_map.insert(map<char*, char*>::value_type(tu_name, tu_ualue));*/
		//}
		//else {
		//	m_share_data_map.insert(map<char*, char*>::value_type(p_name, p_ualue));
		//	//strResult = "888";
		//}

		for (it = m_share_data_map.begin(); it != m_share_data_map.end(); it++) {
			if (strncmp((*it).first, p_name, strlen(p_name)) == 0) {
				//strResult = "999";
				delete []it->first;
				if (strcmp((*it).second, "") != 0)
					delete []it->second;
				m_share_data_map.erase(it);
				if (strResult.Compare(_T("")) != 0) {
					m_share_data_map.insert(map<char*, char*>::value_type(p_name, p_ualue));
					strResult = p_ualue;
				} 
				else {
					m_share_data_map.insert(map<char*, char*>::value_type(p_name, ""));
					strResult = "888";
				}
				break;
			}
		}
		if (it == m_share_data_map.end()) {
			//strResult = "988";
			//if (lstrcmp(ualue, L"") != 0) {
			if (strResult.Compare(_T("")) != 0) {
				m_share_data_map.insert(map<char*, char*>::value_type(p_name, p_ualue));
				strResult = "444";
			}
			else {
				m_share_data_map.insert(map<char*, char*>::value_type(p_name, ""));
				strResult = "666";
			}

		}
		
	}

	return strResult.AllocSysString();
}


void CMiddleWareXCtrl::BeginWrite()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

	::EnterCriticalSection(&m_cs_lock);
}


void CMiddleWareXCtrl::SaveMessage()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	::LeaveCriticalSection(&m_cs_lock);
}


LONG CMiddleWareXCtrl::LoadMessages()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

	return m_index;

	//return 0;
}


BSTR CMiddleWareXCtrl::EncodeMessage(LPCTSTR src)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
	CString data_cstring = src;
	std::wstring ws(data_cstring);
	std::string data_string;
	data_string.assign(ws.begin(), ws.end());
	string encoded = Encrypto_base64(reinterpret_cast<const unsigned char*>(data_string.c_str()), data_string.length());
	strResult = encoded.c_str();

	return strResult.AllocSysString();
}


BSTR CMiddleWareXCtrl::DecodeMessage(LPCTSTR src)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
	CString data_cstring = src;
	std::wstring ws(data_cstring);
	std::string data_string;
	data_string.assign(ws.begin(), ws.end());
	std::string decoded = Decrypto_base64(data_string);
	strResult = decoded.c_str();

	return strResult.AllocSysString();
}


void CMiddleWareXCtrl::BeginRead()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	::EnterCriticalSection(&m_cs_lock);
}


void CMiddleWareXCtrl::EndRead()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	::LeaveCriticalSection(&m_cs_lock);
}




LONG CMiddleWareXCtrl::ReleaseShareMem()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	/*int i;
	if (m_index == 0) {

	}
	else {		
		for (i = 0; i < m_index; i++) {
			delete [](p_key+i);
			delete [](p_ualue+i);
		}

		m_index = 0;
	}*/

	if (m_share_data_map.empty()) {
	} else {
		map<char*, char*>::iterator it = m_share_data_map.begin();
		while (it != m_share_data_map.end()) {
			delete []it->first;
			if (strcmp((*it).second, "") != 0)
				delete []it->second;
			it++;
		}
		m_share_data_map.clear();
	}

	return 0;
}
