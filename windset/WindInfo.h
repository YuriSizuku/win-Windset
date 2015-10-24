#pragma once
#include "process_thread.h"

// CWindInfo
//�������ڿ�����ʾ������Ϣ�����οؼ�
class CWindInfo : public CTreeCtrl
{
	DECLARE_DYNAMIC(CWindInfo)

public:
	CWindInfo();
	void ShowSubTree(HTREEITEM subroot,UINT nCode=TVE_TOGGLE);//�۵�����չĳ���������з�֧
	void _CopyTreeToClipboard(HTREEITEM subroot,char *str,int depth);//���ڵݹ�ĸ�������ֵ
	long CopyTreeToClipboard(HTREEITEM root,long maxlen);//�����ַ�������
	virtual ~CWindInfo();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuCopy();//���ƴ��������
	afx_msg void OnMenuCollapseall();//���нڵ��۵�
	afx_msg void OnMenuExpandall();//���нڵ���չ
	afx_msg void OnMenuCopyall();//������������������
	afx_msg void OnMenuRefresh();//ˢ����
};



