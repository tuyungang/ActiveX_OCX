#pragma once

// MiddleWareXPropPage.h : CMiddleWareXPropPage ����ҳ���������


// CMiddleWareXPropPage : �й�ʵ�ֵ���Ϣ������� MiddleWareXPropPage.cpp��

class CMiddleWareXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMiddleWareXPropPage)
	DECLARE_OLECREATE_EX(CMiddleWareXPropPage)

// ���캯��
public:
	CMiddleWareXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MIDDLEWAREX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

