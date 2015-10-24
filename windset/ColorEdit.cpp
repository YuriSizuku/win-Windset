// ColorEdit.cpp : 实现文件
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

void CColorEdit::SetBkColor(COLORREF color)//设置背景颜色
{
	m_crBackGnd=color;
   if (m_brBackGnd.GetSafeHandle()) //释放旧的画刷
	   m_brBackGnd.DeleteObject();
   m_brBackGnd.CreateSolidBrush(color); //使用文字背景颜色创建新的画刷,使得文字框背景和文字背景一致
   Invalidate(TRUE); //redraw
}
void CColorEdit:: SetTextColor(COLORREF color)
{
	m_crText=color;
	Invalidate(TRUE);
}
void CColorEdit::SetTextFont(const LOGFONT &lf)
{
	//创建新的字体,并设置为CEDIT的字体
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
COLORREF CColorEdit::GetBackColor(){return m_crBackGnd;}//获取当前背景色
COLORREF CColorEdit::GetTextColor(){return m_crText;}//获取当前文本色
// CColorEdit 消息处理程序
HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	
	pDC->SetTextColor(m_crText);///刷新前更改文本颜色
	pDC->SetBkColor(m_crBackGnd);//刷新前更改文本背景
	//返回画刷,用来绘制整个控件背景
	return  m_brBackGnd;
}
