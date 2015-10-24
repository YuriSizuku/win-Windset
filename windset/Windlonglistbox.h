#pragma once //不加这个之后多次编译会出错
#include "ColorHsCheckListBox.h"
#include "process_thread.h"
#include "value.h"

// CWindlonglistbox
//此类实现控制GW_STYLE的listbox
class CWindlonglistbox : public CColorHsCheckListBox
{
	DECLARE_DYNAMIC(CWindlonglistbox)

public:
	CWindlonglistbox();
	virtual ~CWindlonglistbox();
private:
	//BOOL _bMouseTrack;//作用是鼠标进入一次激发一次此事件
	bool m_bIsMouseOver;//此处此变量无用
	CRect m_rtText;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);//响应菜单事件
	afx_msg void OnMenuCopycursel();
	afx_msg void OnMenuAddsursel();
	afx_msg void OnMenuCalcursel();
	
	afx_msg void OnMenuRefresh();
	afx_msg void OnMenuUsechecked();
	afx_msg void OnMenuClear();
	afx_msg void OnMenuAllchecked();
	afx_msg void OnMenuRecv();
};


