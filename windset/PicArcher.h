#pragma once
// CPicArcher
//����Ϊʵ�ְ����϶�Ч��
class CPicArcher : public CStatic
{
	DECLARE_DYNAMIC(CPicArcher)

public:
	CPicArcher();
	virtual ~CPicArcher();
	CWnd m_rectwind;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};