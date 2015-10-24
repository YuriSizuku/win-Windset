#pragma once

// CColorEdit
//����ʵ�ָı�edit������ɫ
class CColorEdit : public CEdit
{
	DECLARE_DYNAMIC(CColorEdit)

public:
	CColorEdit();
	virtual ~CColorEdit();

	void SetBkColor(COLORREF color);//���ñ�����ɫ
	void SetTextColor(COLORREF color);//�����ı���ɫ
	void SetTextFont(const LOGFONT &lf);//��������
	COLORREF GetBackColor();//��ȡ��ǰ����ɫ
	COLORREF GetTextColor();//��ȡ��ǰ�ı�ɫ
	BOOL GetTextFont(LOGFONT &lf);//��ȡ��ǰ����
protected:
	DECLARE_MESSAGE_MAP()
private:
	COLORREF m_crText;//�������ɫ
	COLORREF m_crBackGnd;//����ı�����ɫ
	CFont m_font;//����
	CBrush m_brBackGnd;//�����ı����Ļ�ˢ
public:
	//�ؼ��Լ�����Ϣ���亯��CtlColor,���ƿؼ�֮ǰ����
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);//���ط����ͼ����
};


