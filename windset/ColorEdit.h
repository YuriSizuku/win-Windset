#pragma once

// CColorEdit
//此类实现改变edit背景颜色
class CColorEdit : public CEdit
{
	DECLARE_DYNAMIC(CColorEdit)

public:
	CColorEdit();
	virtual ~CColorEdit();

	void SetBkColor(COLORREF color);//设置背景颜色
	void SetTextColor(COLORREF color);//设置文本颜色
	void SetTextFont(const LOGFONT &lf);//设置字体
	COLORREF GetBackColor();//获取当前背景色
	COLORREF GetTextColor();//获取当前文本色
	BOOL GetTextFont(LOGFONT &lf);//获取当前字体
protected:
	DECLARE_MESSAGE_MAP()
private:
	COLORREF m_crText;//字体的颜色
	COLORREF m_crBackGnd;//字体的背景颜色
	CFont m_font;//字体
	CBrush m_brBackGnd;//整个文本区的画刷
public:
	//控件自己的消息反射函数CtlColor,绘制控件之前调用
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);//重载反射绘图函数
};


