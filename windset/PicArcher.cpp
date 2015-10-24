// PicArcher.cpp : 实现文件
//

#include "stdafx.h"
#include "windset.h"
#include "PicArcher.h"
bool IsCapture=false;
HWND hwnd_before=0;
int sWidth = GetSystemMetrics(SM_CXSCREEN);  
int sHeight = GetSystemMetrics(SM_CYSCREEN);  
// CPicArcher

IMPLEMENT_DYNAMIC(CPicArcher, CStatic)

CPicArcher::CPicArcher()
{
	//this->SetTimer(TIMER_CAPTURE,100,TimerCaptureProc);
	//this->SetTimer(TIMER_CAPTURE,500,TimerCaptureProc);
}

CPicArcher::~CPicArcher()
{
}


BEGIN_MESSAGE_MAP(CPicArcher, CStatic)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
// CPicArcher 消息处理程序
void CPicArcher::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPoint winsetPoi;//目标窗口点
	HWND winsetHwnd;//目标窗口句柄
	IsCapture=false;
	ReleaseCapture();
	
	//清理绘图
	RECT rc;
	HWND DeskHwnd = ::GetDesktopWindow();    //取得桌面句柄
	HDC DeskDC = ::GetWindowDC(DeskHwnd);     //取得桌面设备场景
	int oldRop2 = SetROP2(DeskDC,R2_NOTXORPEN);
	HPEN newPen = ::CreatePen(PS_SOLID, 3, 0);    //建立新画笔,载入DeskDC
	HGDIOBJ oldPen = ::SelectObject(DeskDC, newPen);
	::GetWindowRect(hwnd_before, &rc);      //获得窗口矩形
	if(rc.left<0) rc.left=0;
	if(rc.top<0) rc.top=0;
	if(rc.right>sWidth) rc.right=sWidth;
	if(rc.bottom>sHeight) rc.bottom=sHeight;
	::Rectangle(DeskDC, rc.left, rc.top, rc.right, rc.bottom);
	hwnd_before=0;
	::SetROP2(DeskDC, oldRop2);
    ::SelectObject( DeskDC, oldPen);
    ::DeleteObject(newPen);
    ::ReleaseDC( DeskHwnd, DeskDC);
	
	GetCursorPos(&winsetPoi);
	winsetHwnd=::WindowFromPoint(winsetPoi);
	::PostMessage(GetParent()->m_hWnd,WM_CAPHWND,(WPARAM)winsetHwnd,0);
	
	HICON hicon2 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE (IDI_ICON2)); 
	this->SetIcon(hicon2);
	this->GetParent()->ShowWindow(SW_SHOW);
	CStatic::OnLButtonUp(nFlags, point);
}

void CPicArcher::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->GetParent()->ShowWindow(SW_HIDE);
	SetCapture();
	Sleep(300);//若没隐藏立刻绘图会引起错误
	IsCapture=true;

	HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE (IDC_CURSOR1));
	::SetCursor(hc);
	HICON hicon2 = LoadIcon(AfxGetApp()->m_hInstance, NULL); 
	this->SetIcon(hicon2);
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CPicArcher::OnMouseMove(UINT nFlags, CPoint point)//移动鼠标的时候绘制窗口矩形范围
{
	if(nFlags!=MK_LBUTTON) return;
	if(IsCapture==false && hwnd_before==0) return;
	POINT pnt;
    RECT rc;
	::GetCursorPos(&pnt);                //取得鼠标坐标
	
	HWND hwnd_current = ::WindowFromPoint(pnt) ;    //取得鼠标指针处窗口句柄
	if(hwnd_before==hwnd_current && IsCapture!=0) return;
	
	HWND DeskHwnd = ::GetDesktopWindow();    //取得桌面句柄
	HDC DeskDC = ::GetWindowDC(DeskHwnd);     //取得桌面设备场景
	int oldRop2 = SetROP2(DeskDC,R2_NOTXORPEN);
	HPEN newPen = ::CreatePen(PS_SOLID, 3, 0);    //建立新画笔,载入DeskDC
	HGDIOBJ oldPen = ::SelectObject(DeskDC, newPen);
	
	if(IsCapture==true && hwnd_before==0)
	{
		::GetWindowRect(hwnd_current, &rc);      //获得窗口矩形
		if(rc.left<0) rc.left=0;
		if(rc.top<0) rc.top=0;
		if(rc.right>sWidth) rc.right=sWidth;
		if(rc.bottom>sHeight) rc.bottom=sHeight;
		::Rectangle(DeskDC, rc.left, rc.top, rc.right, rc.bottom);
		hwnd_before=hwnd_current;
	}
	else if(IsCapture==true && hwnd_before!=0)
	{
		::GetWindowRect(hwnd_before, &rc);      //获得窗口矩形
		if(rc.left<0) rc.left=0;
		if(rc.top<0) rc.top=0;
		if(rc.right>sWidth) rc.right=sWidth;
		if(rc.bottom>sHeight) rc.bottom=sHeight;
		::Rectangle(DeskDC, rc.left, rc.top, rc.right, rc.bottom);
		::GetWindowRect(hwnd_current, &rc);  
		if(rc.left<0) rc.left=0;
		if(rc.top<0) rc.top=0;
		if(rc.right>sWidth) rc.right=sWidth;
		if(rc.bottom>sHeight) rc.bottom=sHeight;
		::Rectangle(DeskDC, rc.left, rc.top, rc.right, rc.bottom);
		hwnd_before=hwnd_current;
	}
    ::SetROP2(DeskDC, oldRop2);
    ::SelectObject( DeskDC, oldPen);
    ::DeleteObject(newPen);
    ::ReleaseDC( DeskHwnd, DeskDC);
    DeskDC = NULL;
}
