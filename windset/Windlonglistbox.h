#pragma once //�������֮���α�������
#include "ColorHsCheckListBox.h"
#include "process_thread.h"
#include "value.h"

// CWindlonglistbox
//����ʵ�ֿ���GW_STYLE��listbox
class CWindlonglistbox : public CColorHsCheckListBox
{
	DECLARE_DYNAMIC(CWindlonglistbox)

public:
	CWindlonglistbox();
	virtual ~CWindlonglistbox();
private:
	//BOOL _bMouseTrack;//������������һ�μ���һ�δ��¼�
	bool m_bIsMouseOver;//�˴��˱�������
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
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);//��Ӧ�˵��¼�
	afx_msg void OnMenuCopycursel();
	afx_msg void OnMenuAddsursel();
	afx_msg void OnMenuCalcursel();
	
	afx_msg void OnMenuRefresh();
	afx_msg void OnMenuUsechecked();
	afx_msg void OnMenuClear();
	afx_msg void OnMenuAllchecked();
	afx_msg void OnMenuRecv();
};


