// WindInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "windset.h"
#include "WindInfo.h"
#include "windsetDlg.h"
// CWindInfo

IMPLEMENT_DYNAMIC(CWindInfo, CTreeCtrl)

CWindInfo::CWindInfo()
{

}
void CWindInfo::ShowSubTree(HTREEITEM subroot,UINT nCode)
{
	while(subroot)
	{
		Expand(subroot,nCode);
		HTREEITEM childnode;
		childnode=GetChildItem(subroot);
		if(childnode!=NULL)
		{
			ShowSubTree(childnode,nCode);
		}
		subroot=GetNextSiblingItem(subroot);
	}
}
long CWindInfo::CopyTreeToClipboard(HTREEITEM root,long maxlen)
{
	char *str=new char[maxlen];
	memset(str,0,maxlen);
	_CopyTreeToClipboard(root,str,0);//�ݹ�
	long len=strlen(str);
	WCHAR *wstr=new WCHAR[maxlen];
	MByteToWChar(str,wstr,maxlen);
	//CopyToClipboard(str);
	CopyToClipboard2(wstr);//���Ƶ��������ϲ��ÿ��ֽڻ�����,֮��ճ�������±������Ǳ��ر����ַ�

	//FILE *fp=fopen("d:\\str.txt","wb");
	//long len2=sizeof(str);
	//fwrite(str,sizeof(char),len,fp);
	//fclose(fp);
	//fp=fopen("d:\\wstr.txt","wb");
	//fwrite(wstr,sizeof(WCHAR),len,fp);//ֱ��unicode����ò����Ϊû���ļ�ͷ��������
	//fclose(fp);
	
	delete[] str;
	delete[] wstr;
	return len;
}
void CWindInfo::_CopyTreeToClipboard(HTREEITEM subroot,char *str,int depth)
{
	char ept[100];
	memset(ept,' ',depth*2);ept[depth*2]=0;
	HTREEITEM next=subroot;
	HTREEITEM child;
	while(next!=NULL)
	{
		child=GetChildItem(next);
		strcat(str,ept);strcat(str,GetItemText(next));strcat(str,"\r\n");
		if(child!=NULL)
		{
			strcat(str,ept);strcat(str,"{\r\n");
			_CopyTreeToClipboard(child,str,depth+1);
		}
		if(child!=NULL) 
		{
			strcat(str,ept);strcat(str,"}\r\n");
		}
		next=GetNextSiblingItem(next);
	}
}
CWindInfo::~CWindInfo()
{
}


BEGIN_MESSAGE_MAP(CWindInfo, CTreeCtrl)
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENU_COPY, &CWindInfo::OnMenuCopy)
	ON_COMMAND(ID_Menu_COLLAPSEALL, &CWindInfo::OnMenuCollapseall)
	ON_COMMAND(ID_MENU_EXPANDALL, &CWindInfo::OnMenuExpandall)
	ON_COMMAND(ID_MENU_COPYALL, &CWindInfo::OnMenuCopyall)
	ON_COMMAND(ID_MENU_REFRESH, &CWindInfo::OnMenuRefresh)
END_MESSAGE_MAP()



// CWindInfo ��Ϣ�������

BOOL CWindInfo::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam!=VK_UP && pMsg->wParam!=VK_DOWN)
	{
		SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	}
	return CTreeCtrl::PreTranslateMessage(pMsg);
}


void CWindInfo::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu rmenu,*pMenu;
	rmenu.LoadMenu(IDR_MENU_WINDINFO);
	pMenu=rmenu.GetSubMenu(0);

	CPoint pt;
    GetCursorPos(&pt);
	pMenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this);
	rmenu.DestroyMenu();
	CTreeCtrl::OnRButtonDown(nFlags, point);
}


void CWindInfo::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nChar=='C' && GetKeyState(VK_CONTROL)<0)//CTRL+C���Ƶ�������
	{
		OnMenuCopy();
	}
	if(nChar==VK_RETURN )
	{
		HTREEITEM node=GetSelectedItem();
		Expand(node,TVE_TOGGLE);
	}
	CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CWindInfo::OnMenuCopy()
{
	// TODO: �ڴ���������������
	HTREEITEM cur=GetSelectedItem();
	CString s;
	s=GetItemText(cur);
	CopyToClipboard(s.GetBuffer());
}


void CWindInfo::OnMenuCollapseall()
{
	// TODO: �ڴ���������������
	ShowSubTree(GetRootItem(),TVE_COLLAPSE);
}


void CWindInfo::OnMenuExpandall()
{
	// TODO: �ڴ���������������
	ShowSubTree(GetRootItem(),TVE_EXPAND);
}


void CWindInfo::OnMenuCopyall()
{
	// TODO: �ڴ���������������
	CopyTreeToClipboard(GetRootItem(),5000);
}


void CWindInfo::OnMenuRefresh()
{
	// TODO: �ڴ���������������
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	windlg->MatchInfoTree();
}
