// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "SnapshotDlg.h"

#define WM_STARTSNAPSHOT WM_USER+108

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnStart();
	
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnDestroy();
	LRESULT OnUserDefinedMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnHotKey(int nHotKeyID, UINT uModifiers, UINT uVirtKey);
	LRESULT StartCap(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL &bHandled);
protected:
		//soui消息
	EVENT_MAP_BEGIN()
		
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MESSAGE_HANDLER(WM_STARTSNAPSHOT, StartCap)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_DESTROY(OnDestroy)
		MSG_WM_HOTKEY(OnHotKey)		
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	int				m_iHotKeyId;
	bool			m_Captured;
};
