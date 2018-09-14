#pragma once

// MiddleWareXCtrl.h : CMiddleWareXCtrl ActiveX �ؼ����������

//#pragma data_seg("MYSEC")
//int app_count = 0;
//#pragma data_seg()
//#pragma comment(linker,"/SECTION:MYSEC,RWS")

// CMiddleWareXCtrl : �й�ʵ�ֵ���Ϣ������� MiddleWareXCtrl.cpp��

class CMiddleWareXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMiddleWareXCtrl)

// ���캯��
public:
	CMiddleWareXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CMiddleWareXCtrl();

	DECLARE_OLECREATE_EX(CMiddleWareXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMiddleWareXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMiddleWareXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMiddleWareXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidReleaseShareMem = 10L,
		dispidEndRead = 9L,
		dispidBeginRead = 8L,
		dispidDecodeMessage = 7L,
		dispidEncodeMessage = 6L,
		dispidLoadMessages = 5L,
		dispidSaveMessage = 4L,
		dispidBeginWrite = 3L,
		dispidSetMessage = 2L,
		dispidGetMessage = 1L
	};
protected:
	BSTR GetMessage(LPCTSTR name);
	BSTR SetMessage(LPCTSTR name, LPCTSTR ualue);
	void BeginWrite();
	void SaveMessage();
	LONG LoadMessages();
	BSTR EncodeMessage(LPCTSTR src);
	BSTR DecodeMessage(LPCTSTR src);
	void BeginRead();
	void EndRead();

	LONG ReleaseShareMem();
};

