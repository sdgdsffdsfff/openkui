/*
作者： bill
日期： 2011-03-24
功能： Tab控件使用例子
*/

#include "stdafx.h"
#include ".\mainwnd.h"
CMainWnd *g_pMainWnd = NULL;

CMainWnd::CMainWnd(void) : CKuiDialogImpl<CMainWnd>( "IDR_DLG_MAIN" )
{
	g_pMainWnd = this;
}

CMainWnd::~CMainWnd(void)
{
}

LRESULT CMainWnd::OnInitDialog( HWND hDlg, LPARAM lParam )
{
	DWORD dwStyle = WS_CHILD|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_SINGLESEL|LVS_OWNERDRAWFIXED;
        
	if( m_ctlListCtrl.Create( GetRichWnd(),  NULL, NULL, dwStyle, 0, 101 ) )
	{
		DWORD dwExStyle = LVS_EX_FULLROWSELECT;
        dwExStyle |= m_ctlListCtrl.GetExtendedListViewStyle();
		
        m_ctlListCtrl.SetExtendedListViewStyle(dwExStyle);

		m_ctlListCtrl.InsertColumn( 0, _T("标题一"), LVCFMT_LEFT, 100);
		m_ctlListCtrl.InsertColumn( 1, _T("标题二"), LVCFMT_LEFT, 200);
		m_ctlListCtrl.InsertColumn( 2, _T("标题三"), LVCFMT_LEFT, 300);
		

		m_ctlListCtrl.InsertItem( 0, _T("项目一") );
		m_ctlListCtrl.InsertItem( 1, _T("项目二") );
		m_ctlListCtrl.InsertItem( 2, _T("项目三") );

		m_ctlListCtrl.SetItemText( 0, 1, _T("第二列") );
		m_ctlListCtrl.SetItemText( 0, 2, _T("第三列") );
		

		m_ctlListCtrl.Init();
	}

	if( !m_SnakeGame.Create( GetRichWnd(),  NULL, NULL, WS_CHILD, 0, 301 ) )
	{
		CKuiMsgBox::Show( _T("无法初始化游戏") );
	}
	else
		m_SnakeGame.OnInitDialog( m_SnakeGame.m_hWnd, 0 );
	if( !m_ctlWeb.Create( GetViewHWND(), 401, FALSE, RGB(0xFB, 0xFC, 0xFD) ) )
	{
		CKuiMsgBox::Show( _T("无法初始化网页") );
	}
	else
	{
		m_ctlWeb.Show2( _T("http://www.baidu.com/"), _T("about:blank") );
	}
	return TRUE;
}

void CMainWnd::OnDestroy()
{
    PostQuitMessage(0);
}


void CMainWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	::OnKeyDown( nChar, 0 );
}


void CMainWnd::OnBkBtnMax()
{
	if (WS_MAXIMIZE == (GetStyle() & WS_MAXIMIZE))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE | HTCAPTION, 0);
	}
	else
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE | HTCAPTION, 0);
	}
}

void CMainWnd::OnBkBtnMin()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE | HTCAPTION, 0);
}

void CMainWnd::OnBkBtnClose()
{
	DestroyWindow();
}

void CMainWnd::OnStartGame()
{
	SetFocus();
	::OnStartGame( m_SnakeGame.m_hWnd );
}
