/*
作者： b2b160
日期： 2011-03-07
功能： IM登陆窗口界面例子
*/

#pragma once
#include "stdafx.h"
class CMainWnd : public CKuiDialogImpl<CMainWnd>
	, public CWHRoundRectFrameHelper<CMainWnd>
{
public:
	CMainWnd(void);
	virtual ~CMainWnd(void);
	LRESULT OnInitDialog( HWND hDlg, LPARAM lParam );
	void OnDestroy();

	void OnBkBtnClose();
    void OnBkBtnMax();
    void OnBkBtnMin();
	void OnAdd();
	void OnDec();
	void OnNotify( UINT nID, LPCSTR pClassName );

	void OnTimer(UINT_PTR nIDEvent);   // 动画定时器

	KUI_NOTIFY_MAP(IDC_RICHVIEW_WIN)
        KUI_NOTIFY_ID_COMMAND(60001, OnBkBtnClose)
        KUI_NOTIFY_ID_COMMAND(60002, OnBkBtnMax)
        KUI_NOTIFY_ID_COMMAND(60003, OnBkBtnMin)
		KUI_NOTIFY_ID_COMMAND(9, OnAdd)
		KUI_NOTIFY_ID_COMMAND(10, OnDec)
		KUI_NOTIFY_COMMAND( OnNotify )
        //KUI_NOTIFY_TAB_SELCHANGE(IDC_TAB_MAIN, OnBkTabMainSelChange)
    KUI_NOTIFY_MAP_END()

	BEGIN_MSG_MAP_EX(CMainWnd)
		MSG_KUI_NOTIFY(IDC_RICHVIEW_WIN)
		CHAIN_MSG_MAP(CKuiDialogImpl<CMainWnd>)
		CHAIN_MSG_MAP(CWHRoundRectFrameHelper<CMainWnd>)

		MSG_WM_TIMER(OnTimer)

		MSG_WM_INITDIALOG(OnInitDialog)
		//MSG_WM_SYSCOMMAND(OnSysCommand)
		MSG_WM_DESTROY(OnDestroy)
		
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
protected:
	int					m_nCurProgress;
	CEdit				m_ctlUserName;
	CEdit				m_ctlUserPass;
};
