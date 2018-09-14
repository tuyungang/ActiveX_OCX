// MiddleWareXPropPage.cpp : CMiddleWareXPropPage 属性页类的实现。

#include "stdafx.h"
#include "MiddleWareX.h"
#include "MiddleWareXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMiddleWareXPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CMiddleWareXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMiddleWareXPropPage, "MIDDLEWAREX.MiddleWareXPropPage.1",
	0xfccf290d, 0x8eb, 0x43ac, 0x92, 0x82, 0xd6, 0x68, 0xd9, 0x71, 0x5e, 0xc)

// CMiddleWareXPropPage::CMiddleWareXPropPageFactory::UpdateRegistry -
// 添加或移除 CMiddleWareXPropPage 的系统注册表项

BOOL CMiddleWareXPropPage::CMiddleWareXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MIDDLEWAREX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMiddleWareXPropPage::CMiddleWareXPropPage - 构造函数

CMiddleWareXPropPage::CMiddleWareXPropPage() :
	COlePropertyPage(IDD, IDS_MIDDLEWAREX_PPG_CAPTION)
{
}

// CMiddleWareXPropPage::DoDataExchange - 在页和属性间移动数据

void CMiddleWareXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMiddleWareXPropPage 消息处理程序
