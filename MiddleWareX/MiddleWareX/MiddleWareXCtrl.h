#pragma once

// MiddleWareXCtrl.h : CMiddleWareXCtrl ActiveX 控件类的声明。

//#pragma data_seg("MYSEC")
//int app_count = 0;
//#pragma data_seg()
//#pragma comment(linker,"/SECTION:MYSEC,RWS")

// CMiddleWareXCtrl : 有关实现的信息，请参阅 MiddleWareXCtrl.cpp。

class CMiddleWareXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMiddleWareXCtrl)

// 构造函数
public:
	CMiddleWareXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CMiddleWareXCtrl();

	DECLARE_OLECREATE_EX(CMiddleWareXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMiddleWareXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMiddleWareXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMiddleWareXCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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

