#pragma once
#include "process_thread.h"

// CWindInfo
//此类用于控制显示窗口信息的树形控件
class CWindInfo : public CTreeCtrl
{
	DECLARE_DYNAMIC(CWindInfo)

public:
	CWindInfo();
	void ShowSubTree(HTREEITEM subroot,UINT nCode=TVE_TOGGLE);//折叠或拓展某子树的所有分支
	void _CopyTreeToClipboard(HTREEITEM subroot,char *str,int depth);//用于递归的复制子树值
	long CopyTreeToClipboard(HTREEITEM root,long maxlen);//返回字符串长度
	virtual ~CWindInfo();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuCopy();//复制此项倒剪贴板
	afx_msg void OnMenuCollapseall();//所有节点折叠
	afx_msg void OnMenuExpandall();//所有节点拓展
	afx_msg void OnMenuCopyall();//复制整个树倒剪贴板
	afx_msg void OnMenuRefresh();//刷新树
};



