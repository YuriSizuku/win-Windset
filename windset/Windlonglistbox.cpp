// Windlonglistbox.cpp : 实现文件
//

#include "stdafx.h"
#include "windset.h"
#include "Windlonglistbox.h"
#include "windsetDlg.h"//头文件互相包含会有问题，要在cpp文件中
class CwindsetDlg;
// CWindlonglistbox

IMPLEMENT_DYNAMIC(CWindlonglistbox, CColorHsCheckListBox)

CWindlonglistbox::CWindlonglistbox()
{

}

CWindlonglistbox::~CWindlonglistbox()
{
}


BEGIN_MESSAGE_MAP(CWindlonglistbox, CColorHsCheckListBox)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_VSCROLL()
	ON_COMMAND(ID_MENU_COPYCURSEL, &CWindlonglistbox::OnMenuCopycursel)
	ON_COMMAND(ID_MENU_ADDSURSEL, &CWindlonglistbox::OnMenuAddsursel)
	ON_COMMAND(ID_MENU_CALCURSEL, &CWindlonglistbox::OnMenuCalcursel)
	ON_COMMAND(ID_MENU_REFRESH, &CWindlonglistbox::OnMenuRefresh)
	ON_COMMAND(ID_MENU_USECHECKED, &CWindlonglistbox::OnMenuUsechecked)
	ON_COMMAND(ID_MENU_CLEAR, &CWindlonglistbox::OnMenuClear)
	ON_COMMAND(ID_MENU_ALLCHECKED, &CWindlonglistbox::OnMenuAllchecked)
	ON_COMMAND(ID_MENU_RECV, &CWindlonglistbox::OnMenuRecv)
END_MESSAGE_MAP()



// CWindlonglistbox 消息处理程序




void CWindlonglistbox::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACKMOUSEEVENT csTME;
	csTME.cbSize = sizeof (csTME);
	csTME.dwFlags = TME_LEAVE|TME_HOVER;
	csTME.hwndTrack = m_hWnd ;// 指定要 追踪 的窗口 
	csTME.dwHoverTime = 500;  // 鼠标在按钮上停留超过 ms ，才认为状态为 HOVER
	::_TrackMouseEvent (&csTME); // 开启 Windows 的 WM_MOUSELEAVE ， WM_MOUSEHOVER 事件支持 
	if(m_bIsMouseOver)
	{
		//::InvalidateRect(0,&m_rtText,true);//用次虽然可清除GetDesktopWindow画的，但闪烁(重画所有区域)
		m_bIsMouseOver=false;
		::RedrawWindow(0,&m_rtText,NULL,RDW_ERASE |RDW_INVALIDATE );
	}
	CColorHsCheckListBox::OnMouseMove(nFlags, point);
}


void CWindlonglistbox::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_bIsMouseOver=true;

	//这可以做提示信息用，但此处比较小，会画到外面，还是不弄了；之后还不容易清除，闪烁
	//这个功能决定不做了。。。
	//CColorHsCheckListBox::OnMouseHover(nFlags, point);
	//CPoint winpoi;
	//GetCursorPos(&winpoi);
	//m_rtText.top=winpoi.y;
	//m_rtText.left=winpoi.x;
	//char *buf="123j21kjkjsk232323232";
	//
	//CSize ts;
	//CDC *pDC=GetDesktopWindow()->GetDC();
	//ts=pDC->GetTextExtent(buf);
	//m_rtText.bottom=m_rtText.top+ts.cy;
	//m_rtText.right=m_rtText.left+ts.cx;
	////pDC->SetTextColor(RGB(255,0,0));
	//pDC->SetBkColor(RGB(255,0,0));
	//pDC->TextOut(m_rtText.left,m_rtText.top,buf);
}


void CWindlonglistbox::OnMouseLeave()//移出次控件的客户区时调用
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bIsMouseOver=false;
	CColorHsCheckListBox::OnMouseLeave();
}


void CWindlonglistbox::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu rmenu,*pMenu;
	rmenu.LoadMenu(IDR_MENU_WINDLONGR);
	pMenu=rmenu.GetSubMenu(0);

	CPoint pt;
    GetCursorPos(&pt);
	pMenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this);
	rmenu.DestroyMenu();
	
	CColorHsCheckListBox::OnRButtonDown(nFlags, point);
}


BOOL CWindlonglistbox::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam!=VK_UP && pMsg->wParam!=VK_DOWN)
	{
		SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	}	
	return CColorHsCheckListBox::PreTranslateMessage(pMsg);
}


void CWindlonglistbox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)//处理回车键，但是要PreTranslateMessage处理
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if(nChar==VK_RETURN )
	{
		int cursel=GetCurSel();
		if(GetCheck(cursel)!=0)
			SetCheck(cursel,0);
		else SetCheck(cursel,1);
	}
	if(nChar=='C' && GetKeyState(VK_CONTROL)<0)//CTRL+C复制到剪贴板
	{
		OnMenuCopycursel();
	}
	CColorHsCheckListBox::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CWindlonglistbox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CColorHsCheckListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CWindlonglistbox::OnCommand(WPARAM wParam, LPARAM lParam)//wparam为id
{
	// TODO: 在此添加专用代码和/或调用基类
	if(wParam==ID_MENU_COPYCURSEL)//先经过OnCommad再到各自的回调函数
	{

	}
	return CColorHsCheckListBox::OnCommand(wParam, lParam);
}


void CWindlonglistbox::OnMenuCopycursel()//复制此项
{
	// TODO: 在此添加命令处理程序代码
	int cursel=GetCurSel();
	CString s;
	GetText(cursel,s);
	if(s=="") return;
	CopyToClipboard(s.GetBuffer());
}


void CWindlonglistbox::OnMenuAddsursel()//添加此项
{
	// TODO: 在此添加命令处理程序代码
	long winlong;
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	winlong=::GetWindowLong(winhwnd,GWL_STYLE);
	winlong |= windlongbox[GetCurSel()].id;
	::SetWindowLong(winhwnd,GWL_STYLE,winlong);
	::SetWindowPos(winhwnd,HWND_BOTTOM,0,0,0,0,
						SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED |SWP_NOOWNERZORDER);//目的是刷新窗口
	OnMenuRefresh();
}


void CWindlonglistbox::OnMenuCalcursel()//取消此项
{
	// TODO: 在此添加命令处理程序代码
	long winlong;
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	winlong=::GetWindowLong(winhwnd,GWL_STYLE);
	long id=windlongbox[GetCurSel()].id;
	winlong &= ~windlongbox[GetCurSel()].id;//。。。~才是取反标识，!不是取反
	::SetWindowLong(winhwnd,GWL_STYLE,winlong);
	::SetWindowPos(winhwnd,HWND_TOP,0,0,0,0,
						SWP_NOSIZE | SWP_NOMOVE  |SWP_FRAMECHANGED );//目的是刷新窗口
	OnMenuRefresh();
}


void CWindlonglistbox::OnMenuRefresh()//刷新
{
	// TODO: 在此添加命令处理程序代码
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	windlg->MatchWindlonglistbox();
}


void CWindlonglistbox::OnMenuUsechecked()//应用已选
{
	// TODO: 在此添加命令处理程序代码
		long windlong=0;
		HWND winhwnd;
		CwindsetDlg *windlg;
		windlg=(CwindsetDlg *)GetParent();
		winhwnd=windlg->m_winsetHwnd;
		for(int i=0;windlongbox[i].id!=0 || windlongbox[i].value!="";i++)
		{
			if(GetCheck(i)!=0) windlong |=windlongbox[i].id;
		}
		::SetWindowLong(winhwnd,GWL_STYLE,windlong);
		::SetWindowPos(winhwnd,HWND_TOP,0,0,0,0,
						SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//目的是刷新窗口
		OnMenuRefresh();
}


void CWindlonglistbox::OnMenuClear()//清空
{
	// TODO: 在此添加命令处理程序代码
	for(int j=0;j<GetCount();j++)
	{
		SetCheck(j,0);
	}
	RedrawWindow();
}


void CWindlonglistbox::OnMenuAllchecked()//全选
{
	// TODO: 在此添加命令处理程序代码
	for(int j=0;j<GetCount();j++)
	{
		SetCheck(j,1);
	}
	RedrawWindow();
}


void CWindlonglistbox::OnMenuRecv()
{
	// TODO: 在此添加命令处理程序代码
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	::SetWindowLong(winhwnd,GWL_STYLE,windlg->m_wlongGWL_STYLE);
	::SetWindowPos(winhwnd,HWND_TOP,0,0,0,0,
				SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//目的是刷新窗口
	OnMenuRefresh();
}
