// MiddleWareXPropPage.cpp : CMiddleWareXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "MiddleWareX.h"
#include "MiddleWareXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMiddleWareXPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMiddleWareXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMiddleWareXPropPage, "MIDDLEWAREX.MiddleWareXPropPage.1",
	0xfccf290d, 0x8eb, 0x43ac, 0x92, 0x82, 0xd6, 0x68, 0xd9, 0x71, 0x5e, 0xc)

// CMiddleWareXPropPage::CMiddleWareXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMiddleWareXPropPage ��ϵͳע�����

BOOL CMiddleWareXPropPage::CMiddleWareXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MIDDLEWAREX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMiddleWareXPropPage::CMiddleWareXPropPage - ���캯��

CMiddleWareXPropPage::CMiddleWareXPropPage() :
	COlePropertyPage(IDD, IDS_MIDDLEWAREX_PPG_CAPTION)
{
}

// CMiddleWareXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMiddleWareXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMiddleWareXPropPage ��Ϣ�������
