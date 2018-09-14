#pragma once

// MiddleWareXPropPage.h : CMiddleWareXPropPage 属性页类的声明。


// CMiddleWareXPropPage : 有关实现的信息，请参阅 MiddleWareXPropPage.cpp。

class CMiddleWareXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMiddleWareXPropPage)
	DECLARE_OLECREATE_EX(CMiddleWareXPropPage)

// 构造函数
public:
	CMiddleWareXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MIDDLEWAREX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

