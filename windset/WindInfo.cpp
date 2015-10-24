// WindInfo.cpp : 实现文件
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
	_CopyTreeToClipboard(root,str,0);//递归
	long len=strlen(str);
	WCHAR *wstr=new WCHAR[maxlen];
	MByteToWChar(str,wstr,maxlen);
	//CopyToClipboard(str);
	CopyToClipboard2(wstr);//复制到剪贴板上不用宽字节会乱码,之后粘贴到记事本上则是本地编码字符

	//FILE *fp=fopen("d:\\str.txt","wb");
	//long len2=sizeof(str);
	//fwrite(str,sizeof(char),len,fp);
	//fclose(fp);
	//fp=fopen("d:\\wstr.txt","wb");
	//fwrite(wstr,sizeof(WCHAR),len,fp);//直接unicode复制貌似因为没有文件头导致乱码
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



// CWindInfo 消息处理程序

BOOL CWindInfo::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam!=VK_UP && pMsg->wParam!=VK_DOWN)
	{
		SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	}
	return CTreeCtrl::PreTranslateMessage(pMsg);
}


void CWindInfo::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nChar=='C' && GetKeyState(VK_CONTROL)<0)//CTRL+C复制到剪贴板
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
	// TODO: 在此添加命令处理程序代码
	HTREEITEM cur=GetSelectedItem();
	CString s;
	s=GetItemText(cur);
	CopyToClipboard(s.GetBuffer());
}


void CWindInfo::OnMenuCollapseall()
{
	// TODO: 在此添加命令处理程序代码
	ShowSubTree(GetRootItem(),TVE_COLLAPSE);
}


void CWindInfo::OnMenuExpandall()
{
	// TODO: 在此添加命令处理程序代码
	ShowSubTree(GetRootItem(),TVE_EXPAND);
}


void CWindInfo::OnMenuCopyall()
{
	// TODO: 在此添加命令处理程序代码
	CopyTreeToClipboard(GetRootItem(),5000);
}


void CWindInfo::OnMenuRefresh()
{
	// TODO: 在此添加命令处理程序代码
	CwindsetDlg *windlg;
	windlg=(CwindsetDlg *)GetParent();
	windlg->MatchInfoTree();
}
