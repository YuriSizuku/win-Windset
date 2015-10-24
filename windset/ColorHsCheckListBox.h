#pragma once
// CColorHsCheckListBox
//此类实现CheckList智能水平滚动条和改变各种颜色

//各种mask宏，用于选择改变哪的颜色（背景,文本颜色等）
#define CHLB_COLOR_UNSET 0//不改变颜色
#define CHLB_COLOR_BK  0x1//背景颜色
#define CHLB_COLOR_TEXT (0x1<<1)//文本颜色，宏操作要注意加括号
#define CHLB_COLOR_ALL (CHLB_COLOR_BK|CHLB_COLOR_TEXT)//背景和文本颜色
#define CHLB_COLOR_MODEREVRESE 0x1<<2//颜色反向
typedef struct CHIBCOLORINFO
{
	COLORREF rgbBk;//背景颜色
	COLORREF rgbText;//文本颜色
	int CrMode;//mask，用于选择改变哪的颜色
	DWORD_PTR ptrOther;//暂时无用，便于日后拓展
	CHIBCOLORINFO(){}
	CHIBCOLORINFO(COLORREF rgbBk,COLORREF rgbText,int CrMode)
	{
		this->rgbBk=rgbBk;
		this->rgbText=rgbText;
		this->CrMode=CrMode;
	}
}CHIBCOLORINFO,*PCHIBCOLORINFO;//图像信息，SetItemData中用

class CColorHsCheckListBox : public CCheckListBox
{
	DECLARE_DYNAMIC(CColorHsCheckListBox)

public:
	CColorHsCheckListBox();
	virtual ~CColorHsCheckListBox();


	int m_modeCrSelected;//被选择的颜色mask
	int m_modeCrClicked;//点击时的颜色mask
	int m_modeCrDisabled;//不可用的颜色mask
	COLORREF m_crBk;//默认的背景颜色
	COLORREF m_crText;//默认的文本颜色
	COLORREF m_crClickedBk;//点击时的背景
	COLORREF m_crClickedText;//点击时的文本颜色
	COLORREF m_crDisabledBk;//不可用时的背景颜色
	COLORREF m_crDisabledText;//不可用时的文本颜色
	COLORREF m_crSelectedBk;//被选时的背景颜色
	COLORREF m_crSelectedText;//被选是的文本颜色
	
	//重载类以实现只能滚动条
	int AddString(LPCTSTR lpszItem);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszItem);
	void ResetContent();

	//设置各种颜色
	void SetItemColor(int nIndex, COLORREF rgbBK,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetClickColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetSelectedColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetDisabledColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetListBoxColor( COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetFontHeight(int height);
	void SetFontWidth(int width);
	void GetFontSize(int *height,int *width);
private:
	int m_nMaxWidth;//当前最大水平长度
	CFont m_font;//当前字体
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnDestroy();
};