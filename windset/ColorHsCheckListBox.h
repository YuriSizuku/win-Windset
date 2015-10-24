#pragma once
// CColorHsCheckListBox
//����ʵ��CheckList����ˮƽ�������͸ı������ɫ

//����mask�꣬����ѡ��ı��ĵ���ɫ������,�ı���ɫ�ȣ�
#define CHLB_COLOR_UNSET 0//���ı���ɫ
#define CHLB_COLOR_BK  0x1//������ɫ
#define CHLB_COLOR_TEXT (0x1<<1)//�ı���ɫ�������Ҫע�������
#define CHLB_COLOR_ALL (CHLB_COLOR_BK|CHLB_COLOR_TEXT)//�������ı���ɫ
#define CHLB_COLOR_MODEREVRESE 0x1<<2//��ɫ����
typedef struct CHIBCOLORINFO
{
	COLORREF rgbBk;//������ɫ
	COLORREF rgbText;//�ı���ɫ
	int CrMode;//mask������ѡ��ı��ĵ���ɫ
	DWORD_PTR ptrOther;//��ʱ���ã������պ���չ
	CHIBCOLORINFO(){}
	CHIBCOLORINFO(COLORREF rgbBk,COLORREF rgbText,int CrMode)
	{
		this->rgbBk=rgbBk;
		this->rgbText=rgbText;
		this->CrMode=CrMode;
	}
}CHIBCOLORINFO,*PCHIBCOLORINFO;//ͼ����Ϣ��SetItemData����

class CColorHsCheckListBox : public CCheckListBox
{
	DECLARE_DYNAMIC(CColorHsCheckListBox)

public:
	CColorHsCheckListBox();
	virtual ~CColorHsCheckListBox();


	int m_modeCrSelected;//��ѡ�����ɫmask
	int m_modeCrClicked;//���ʱ����ɫmask
	int m_modeCrDisabled;//�����õ���ɫmask
	COLORREF m_crBk;//Ĭ�ϵı�����ɫ
	COLORREF m_crText;//Ĭ�ϵ��ı���ɫ
	COLORREF m_crClickedBk;//���ʱ�ı���
	COLORREF m_crClickedText;//���ʱ���ı���ɫ
	COLORREF m_crDisabledBk;//������ʱ�ı�����ɫ
	COLORREF m_crDisabledText;//������ʱ���ı���ɫ
	COLORREF m_crSelectedBk;//��ѡʱ�ı�����ɫ
	COLORREF m_crSelectedText;//��ѡ�ǵ��ı���ɫ
	
	//��������ʵ��ֻ�ܹ�����
	int AddString(LPCTSTR lpszItem);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszItem);
	void ResetContent();

	//���ø�����ɫ
	void SetItemColor(int nIndex, COLORREF rgbBK,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetClickColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetSelectedColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetDisabledColor(COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetListBoxColor( COLORREF rgbBk,COLORREF rgbText=0,int CrMode=CHLB_COLOR_BK);
	void SetFontHeight(int height);
	void SetFontWidth(int width);
	void GetFontSize(int *height,int *width);
private:
	int m_nMaxWidth;//��ǰ���ˮƽ����
	CFont m_font;//��ǰ����
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnDestroy();
};