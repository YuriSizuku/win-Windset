// Windlonglistbox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "windset.h"
#include "Windlonglistbox.h"
#include "windsetDlg.h"//ͷ�ļ���������������⣬Ҫ��cpp�ļ���
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



// CWindlonglistbox ��Ϣ�������




void CWindlonglistbox::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACKMOUSEEVENT csTME;
	csTME.cbSize = sizeof (csTME);
	csTME.dwFlags = TME_LEAVE|TME_HOVER;
	csTME.hwndTrack = m_hWnd ;// ָ��Ҫ ׷�� �Ĵ��� 
	csTME.dwHoverTime = 500;  // ����ڰ�ť��ͣ������ ms ������Ϊ״̬Ϊ HOVER
	::_TrackMouseEvent (&csTME); // ���� Windows �� WM_MOUSELEAVE �� WM_MOUSEHOVER �¼�֧�� 
	if(m_bIsMouseOver)
	{
		//::InvalidateRect(0,&m_rtText,true);//�ô���Ȼ�����GetDesktopWindow���ģ�����˸(�ػ���������)
		m_bIsMouseOver=false;
		::RedrawWindow(0,&m_rtText,NULL,RDW_ERASE |RDW_INVALIDATE );
	}
	CColorHsCheckListBox::OnMouseMove(nFlags, point);
}


void CWindlonglistbox::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_bIsMouseOver=true;

	//���������ʾ��Ϣ�ã����˴��Ƚ�С���ử�����棬���ǲ�Ū�ˣ�֮�󻹲������������˸
	//������ܾ��������ˡ�����
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


void CWindlonglistbox::OnMouseLeave()//�Ƴ��οؼ��Ŀͻ���ʱ����
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bIsMouseOver=false;
	CColorHsCheckListBox::OnMouseLeave();
}


void CWindlonglistbox::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam!=VK_UP && pMsg->wParam!=VK_DOWN)
	{
		SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	}	
	return CColorHsCheckListBox::PreTranslateMessage(pMsg);
}


void CWindlonglistbox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)//����س���������ҪPreTranslateMessage����
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if(nChar==VK_RETURN )
	{
		int cursel=GetCurSel();
		if(GetCheck(cursel)!=0)
			SetCheck(cursel,0);
		else SetCheck(cursel,1);
	}
	if(nChar=='C' && GetKeyState(VK_CONTROL)<0)//CTRL+C���Ƶ�������
	{
		OnMenuCopycursel();
	}
	CColorHsCheckListBox::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CWindlonglistbox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CColorHsCheckListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CWindlonglistbox::OnCommand(WPARAM wParam, LPARAM lParam)//wparamΪid
{
	// TODO: �ڴ����ר�ô����/����û���
	if(wParam==ID_MENU_COPYCURSEL)//�Ⱦ���OnCommad�ٵ����ԵĻص�����
	{

	}
	return CColorHsCheckListBox::OnCommand(wParam, lParam);
}


void CWindlonglistbox::OnMenuCopycursel()//���ƴ���
{
	// TODO: �ڴ���������������
	int cursel=GetCurSel();
	CString s;
	GetText(cursel,s);
	if(s=="") return;
	CopyToClipboard(s.GetBuffer());
}


void CWindlonglistbox::OnMenuAddsursel()//��Ӵ���
{
	// TODO: �ڴ���������������
	long winlong;
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	winlong=::GetWindowLong(winhwnd,GWL_STYLE);
	winlong |= windlongbox[GetCurSel()].id;
	::SetWindowLong(winhwnd,GWL_STYLE,winlong);
	::SetWindowPos(winhwnd,HWND_BOTTOM,0,0,0,0,
						SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED |SWP_NOOWNERZORDER);//Ŀ����ˢ�´���
	OnMenuRefresh();
}


void CWindlonglistbox::OnMenuCalcursel()//ȡ������
{
	// TODO: �ڴ���������������
	long winlong;
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	winlong=::GetWindowLong(winhwnd,GWL_STYLE);
	long id=windlongbox[GetCurSel()].id;
	winlong &= ~windlongbox[GetCurSel()].id;//������~����ȡ����ʶ��!����ȡ��
	::SetWindowLong(winhwnd,GWL_STYLE,winlong);
	::SetWindowPos(winhwnd,HWND_TOP,0,0,0,0,
						SWP_NOSIZE | SWP_NOMOVE  |SWP_FRAMECHANGED );//Ŀ����ˢ�´���
	OnMenuRefresh();
}


void CWindlonglistbox::OnMenuRefresh()//ˢ��
{
	// TODO: �ڴ���������������
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	windlg->MatchWindlonglistbox();
}


void CWindlonglistbox::OnMenuUsechecked()//Ӧ����ѡ
{
	// TODO: �ڴ���������������
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
						SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//Ŀ����ˢ�´���
		OnMenuRefresh();
}


void CWindlonglistbox::OnMenuClear()//���
{
	// TODO: �ڴ���������������
	for(int j=0;j<GetCount();j++)
	{
		SetCheck(j,0);
	}
	RedrawWindow();
}


void CWindlonglistbox::OnMenuAllchecked()//ȫѡ
{
	// TODO: �ڴ���������������
	for(int j=0;j<GetCount();j++)
	{
		SetCheck(j,1);
	}
	RedrawWindow();
}


void CWindlonglistbox::OnMenuRecv()
{
	// TODO: �ڴ���������������
	HWND winhwnd;
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	winhwnd=windlg->m_winsetHwnd;
	::SetWindowLong(winhwnd,GWL_STYLE,windlg->m_wlongGWL_STYLE);
	::SetWindowPos(winhwnd,HWND_TOP,0,0,0,0,
				SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//Ŀ����ˢ�´���
	OnMenuRefresh();
}
