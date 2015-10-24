// ColorHsCheckListBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ColorHsCheckListBox.h"


// CColorHsCheckListBox

IMPLEMENT_DYNAMIC(CColorHsCheckListBox, CCheckListBox)

CColorHsCheckListBox::CColorHsCheckListBox():
m_nMaxWidth(0)
,m_modeCrSelected(0)
,m_modeCrClicked(CHLB_COLOR_MODEREVRESE |CHLB_COLOR_ALL)
,m_modeCrDisabled(CHLB_COLOR_TEXT)
,m_crBk(::GetSysColor(COLOR_WINDOW))
,m_crText(::GetSysColor(COLOR_WINDOWTEXT ))
,m_crClickedBk(::GetSysColor(COLOR_HIGHLIGHT ))
,m_crClickedText(::GetSysColor(COLOR_HIGHLIGHTTEXT ))
,m_crSelectedBk(m_crBk)
,m_crSelectedText(m_crText)
,m_crDisabledBk(m_crBk)
,m_crDisabledText(::GetSysColor(COLOR_GRAYTEXT))
{

}

CColorHsCheckListBox::~CColorHsCheckListBox()
{

}


BEGIN_MESSAGE_MAP(CColorHsCheckListBox, CCheckListBox)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

//���غ���
int CColorHsCheckListBox::InsertString(int nIndex, LPCTSTR lpszItem)
{
	int nRet = CCheckListBox::InsertString(nIndex,lpszItem);
	SIZE sSize; 
	CClientDC myDC(this);
	CFont* pListBoxFont = GetFont(); 
	if(pListBoxFont != NULL) 
	{ 
		CFont* pOldFont=myDC.SelectObject(pListBoxFont);
		GetTextExtentPoint32(myDC.m_hDC, 
						lpszItem, strlen(lpszItem), &sSize);//��ȡ�����С
		m_nMaxWidth = max(m_nMaxWidth, (int)sSize.cx); 
		SetHorizontalExtent(m_nMaxWidth+17);
		myDC.SelectObject(pOldFont);
	}

	return nRet;
}
int CColorHsCheckListBox::AddString(LPCTSTR lpszItem)
{
	int nRet = CCheckListBox::AddString(lpszItem);

	SIZE sSize; 
	CClientDC myDC(this);
	CFont* pListBoxFont = GetFont(); 
	if(pListBoxFont != NULL) 
	{ 
		CFont* pOldFont=myDC.SelectObject(pListBoxFont);
		GetTextExtentPoint32(myDC.m_hDC, 
						lpszItem, strlen(lpszItem), &sSize);//��ȡ�����С
		m_nMaxWidth = max(m_nMaxWidth, (int)sSize.cx); 
		SetHorizontalExtent(m_nMaxWidth+17);//17Ϊcheckbox��С
		myDC.SelectObject(pOldFont);
	}
	return nRet; 
}
int CColorHsCheckListBox::DeleteString(UINT nIndex)
{
	PCHIBCOLORINFO pcrinfo;
	pcrinfo=(PCHIBCOLORINFO)CCheckListBox::GetItemData(nIndex);
	if(pcrinfo!=NULL) delete pcrinfo;
	int nRet = CCheckListBox::DeleteString(nIndex);

	SIZE sSize; 
	CClientDC myDC(this);
	CFont* pListBoxFont = GetFont(); 
	char *buf;
	int count=GetCount();
	if(pListBoxFont != NULL) 
	{ 
		m_nMaxWidth=0;
		for(int i=0;i<this->GetCount();i++)
		{		
			buf=new char[GetTextLen(i)+1];
			GetText(i,buf);
			CFont* pOldFont=myDC.SelectObject(pListBoxFont);
			GetTextExtentPoint32(myDC.m_hDC, 
						         buf, strlen(buf), &sSize);//��ȡ�����С
			m_nMaxWidth = max(m_nMaxWidth, (int)sSize.cx); 
			myDC.SelectObject(pOldFont);
			delete  [] buf;
		}

	}

	SetHorizontalExtent(m_nMaxWidth+17 );
	return nRet;
}
void CColorHsCheckListBox::ResetContent()
{
	PCHIBCOLORINFO pcrinfo;
	for(int i=0;i<GetCount();i++)
	{
		pcrinfo=(PCHIBCOLORINFO)CCheckListBox::GetItemData(i);
		if(pcrinfo!=NULL) delete pcrinfo;
	}
	CCheckListBox::ResetContent();
	m_nMaxWidth = 0; 
	SetHorizontalExtent(0); 
}

//������ɫ����
void CColorHsCheckListBox::SetItemColor(int nIndex, COLORREF rgbBk,COLORREF rgbText,int CrMode)
{
	
	PCHIBCOLORINFO pcrinfo;
	pcrinfo=(PCHIBCOLORINFO)CCheckListBox::GetItemData(nIndex);
	if(pcrinfo==NULL)
	{
		pcrinfo=new CHIBCOLORINFO(rgbBk,rgbText,CrMode);
		SetItemData(nIndex,(DWORD_PTR)pcrinfo);
	}
	else
	{
		pcrinfo->rgbBk=rgbBk;
		pcrinfo->rgbText=rgbText;
		pcrinfo->CrMode=CrMode;
	}
	RedrawWindow();
}
void CColorHsCheckListBox::SetClickColor(COLORREF rgbBk,COLORREF rgbText,int CrMode)
{
	m_crClickedBk=rgbBk;
	m_crClickedText=rgbText;
	m_modeCrClicked=CrMode;
	RedrawWindow();
}
void CColorHsCheckListBox::SetSelectedColor(COLORREF rgbBk,COLORREF rgbText,int CrMode)
{
	m_crSelectedBk=rgbBk;
	m_crSelectedText=rgbText;
	m_modeCrSelected=CrMode;
	RedrawWindow();
}
void CColorHsCheckListBox::SetDisabledColor(COLORREF rgbBk,COLORREF rgbText,int CrMode)
{
	m_crDisabledBk=rgbBk;
	m_crDisabledText=rgbText;
	m_modeCrDisabled=CrMode;
	RedrawWindow();
}
void CColorHsCheckListBox::SetListBoxColor( COLORREF rgbBk,COLORREF rgbText,int CrMode)
{
	if(CrMode & CHLB_COLOR_BK) m_crBk=rgbBk;
	if(CrMode & CHLB_COLOR_TEXT) m_crText=rgbText;
	RedrawWindow();
}
//�������庯��
void CColorHsCheckListBox::SetFontHeight(int height)
{
	CFont* ptf=GetFont(); // �õ�ԭ��������   
	LOGFONT lf;   
	ptf->GetLogFont(&lf);   
	lf.lfHeight = height; // �ı�����߶�
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&lf);  
	SetFont(&m_font); // ����������  
}
void CColorHsCheckListBox::SetFontWidth(int width)
{
	CFont* ptf=GetFont(); // �õ�ԭ��������   
	LOGFONT lf;   
	ptf->GetLogFont(&lf);   
	lf.lfWidth=width; // �ı�������
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&lf);  
	SetFont(&m_font); // ����������  
}
void CColorHsCheckListBox::GetFontSize(int *height,int *width)
{
	CFont* ptf=GetFont(); // �õ�ԭ��������   
	LOGFONT lf;   
	ptf->GetLogFont(&lf);
	*height=lf.lfHeight;
	*width=lf.lfWidth;
}

// CColorHsCheckListBox ��Ϣ�������
void CColorHsCheckListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	//TODO:  ������Ĵ����Ի���ָ����
	if ((int)lpDIS->itemID < 0)
		return; 
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	COLORREF tcrText;
	COLORREF tcrBk;
	PCHIBCOLORINFO pcrinfo;
	//ȷ���������ı�Ӧ��Ϊʲô��ɫ
	tcrText=m_crText;
	tcrBk=m_crBk;
	pcrinfo=(PCHIBCOLORINFO)lpDIS->itemData;
	if(pcrinfo!=NULL && pcrinfo->CrMode!=0)//�����Զ�����ɫ
	{
		if(pcrinfo->CrMode & CHLB_COLOR_BK) tcrBk=pcrinfo->rgbBk;
		if(pcrinfo->CrMode & CHLB_COLOR_TEXT) tcrText=pcrinfo->rgbText;
	}
	if(GetCheck(lpDIS->itemID))//��ѡ�е���ɫ
	{
		if(m_modeCrSelected & CHLB_COLOR_MODEREVRESE)//��ɫ
		{
			if(m_modeCrSelected & CHLB_COLOR_BK) 
				tcrBk=RGB(255-GetRValue(tcrBk),255-GetGValue(tcrBk),255-GetBValue(tcrBk));
			if(m_modeCrSelected & CHLB_COLOR_TEXT)  
				tcrText=RGB(255-GetRValue(tcrText),255-GetGValue(tcrText),255-GetBValue(tcrText));
		}
		else if(m_modeCrSelected != CHLB_COLOR_UNSET)//�Զ�����ɫ
		{
			if(m_modeCrSelected & CHLB_COLOR_BK) tcrBk=m_crSelectedBk;
			if(m_modeCrSelected & CHLB_COLOR_TEXT)  tcrText=m_crSelectedText;
		}
	}
	if (lpDIS->itemState & ODS_SELECTED)//���������ɫ
	{
		if(m_modeCrClicked & CHLB_COLOR_MODEREVRESE)//��ɫ
		{
			if(m_modeCrClicked & CHLB_COLOR_BK) 
				tcrBk=RGB(255-GetRValue(tcrBk),255-GetGValue(tcrBk),255-GetBValue(tcrBk));
			if(m_modeCrClicked & CHLB_COLOR_TEXT)  
				tcrText=RGB(255-GetRValue(tcrText),255-GetGValue(tcrText),255-GetBValue(tcrText));
		}
		else if(m_modeCrClicked != CHLB_COLOR_UNSET)//�Զ�����ɫ
		{
			if(m_modeCrClicked & CHLB_COLOR_BK) tcrBk=m_crClickedBk;
			if(m_modeCrClicked & CHLB_COLOR_TEXT)  tcrText=m_crClickedText;
		}
	}
	if(lpDIS->itemState &  ODS_DISABLED || !this->IsEnabled(lpDIS->itemID))//����ʱ����ɫ
	{
		if(m_modeCrDisabled & CHLB_COLOR_MODEREVRESE)//��ɫ
		{
			if(m_modeCrDisabled & CHLB_COLOR_BK) 
				tcrBk=RGB(255-GetRValue(tcrBk),255-GetGValue(tcrBk),255-GetBValue(tcrBk));
			if(m_modeCrDisabled & CHLB_COLOR_TEXT)  
				tcrText=RGB(255-GetRValue(tcrText),255-GetGValue(tcrText),255-GetBValue(tcrText));
		}
		else if(m_modeCrDisabled != CHLB_COLOR_UNSET)//�Զ�����ɫ
		{
			if(m_modeCrDisabled & CHLB_COLOR_BK) tcrBk=m_crDisabledBk;
			if(m_modeCrDisabled & CHLB_COLOR_TEXT)  tcrText=m_crDisabledText;
		}
	}

	//���ñ������ı���ɫ
	CBrush brush(tcrBk);
	CString sText;
	UINT nFormat = DT_LEFT | DT_SINGLELINE | DT_VCENTER;
	int nBkMode;
	COLORREF crOldText;
	crOldText=pDC->SetTextColor(tcrText); 
	nBkMode=pDC->SetBkMode(TRANSPARENT);//ʹ���ֲ��ֱ���͸��
	GetText(lpDIS->itemID, sText);
	pDC->DrawFocusRect(&lpDIS->rcItem); 
	pDC->FillRect(&lpDIS->rcItem, &brush);
	//pDC->DrawText(sText, -1, &(lpDIS->rcItem), nFormat | DT_CALCRECT);//��������������
	pDC->DrawText(sText, -1, &(lpDIS->rcItem), nFormat);
	pDC->SetTextColor(crOldText); //һ��Ҫ�����ԭ���������ֽ�������
	pDC->SetBkMode(nBkMode);
}


void CColorHsCheckListBox::OnDestroy()
{
	PCHIBCOLORINFO pcrinfo;
	for(int i=0;i<GetCount();i++)
	{
		pcrinfo=(PCHIBCOLORINFO)CCheckListBox::GetItemData(i);
		if(pcrinfo!=NULL) delete pcrinfo;
	}
	CCheckListBox::OnDestroy();
	// TODO: �ڴ˴������Ϣ����������
}
