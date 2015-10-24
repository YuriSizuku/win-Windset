// ColorEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "windset.h"
#include "ColorEdit.h"


// CColorEdit

IMPLEMENT_DYNAMIC(CColorEdit, CEdit)

CColorEdit::CColorEdit():
	m_crText(RGB(0,0,0)),
	m_crBackGnd(RGB(255,255,255))
{

}

CColorEdit::~CColorEdit()
{
}


BEGIN_MESSAGE_MAP(CColorEdit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

void CColorEdit::SetBkColor(COLORREF color)//���ñ�����ɫ
{
	m_crBackGnd=color;
   if (m_brBackGnd.GetSafeHandle()) //�ͷžɵĻ�ˢ
	   m_brBackGnd.DeleteObject();
   m_brBackGnd.CreateSolidBrush(color); //ʹ�����ֱ�����ɫ�����µĻ�ˢ,ʹ�����ֿ򱳾������ֱ���һ��
   Invalidate(TRUE); //redraw
}
void CColorEdit:: SetTextColor(COLORREF color)
{
	m_crText=color;
	Invalidate(TRUE);
}
void CColorEdit::SetTextFont(const LOGFONT &lf)
{
	//�����µ�����,������ΪCEDIT������
	if(m_font.GetSafeHandle())
	{
		m_font.DeleteObject();
	}
	m_font.CreateFontIndirect(&lf);
	CEdit::SetFont(&m_font);
	Invalidate(TRUE);//redraw
}
BOOL CColorEdit::GetTextFont(LOGFONT &lf)
{ 
	if(m_font.GetLogFont(&lf)!=0) return true;
	return FALSE;
}
COLORREF CColorEdit::GetBackColor(){return m_crBackGnd;}//��ȡ��ǰ����ɫ
COLORREF CColorEdit::GetTextColor(){return m_crText;}//��ȡ��ǰ�ı�ɫ
// CColorEdit ��Ϣ�������
HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	
	pDC->SetTextColor(m_crText);///ˢ��ǰ�����ı���ɫ
	pDC->SetBkColor(m_crBackGnd);//ˢ��ǰ�����ı�����
	//���ػ�ˢ,�������������ؼ�����
	return  m_brBackGnd;
}
