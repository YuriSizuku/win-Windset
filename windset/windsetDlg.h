
// windsetDlg.h : 头文件
//整个程序的主界面
#include "PicArcher.h"
#include "ColorEdit.h"
#include "Windlonglistbox.h"
#include "WindInfo.h"
#include "process_thread.h"
#include "value.h"

class CWinlonglistbox;
//
extern ValueIdMap tooltip[100];
extern ValueIdMap windlongbox[100];
extern ValueIdMap windEXlongbox[100];
#pragma once


// CwindsetDlg 对话框
void CALLBACK RefreshTimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime );//定时器回调函数
class CwindsetDlg : public CDialogEx
{
// 构造
public:
	CwindsetDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WINDSET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	virtual void OnOK();
public:
	//功能函数
	void iniDefault();
	bool SetWindowAlpha(HWND hwnd,short alpha);//改变窗口透明度
	void MatchWindlonglistbox(void);
	void MatchInfoTree();
	//添加的变量
	HWND m_winsetHwnd;// 要改变的窗口句柄
	long m_wlongGWL_STYLE;//保存原始的窗口long
	long m_wlongGWL_EXSTYLE;
	HMENU m_winsetMenu;//菜单栏
	CToolTipCtrl m_tip;
	CPicArcher m_picArcher;
	CSliderCtrl m_sliTra;//透明度滑条
	CColorEdit m_winsetEdit;//句柄编辑框
	CWindlonglistbox  m_winsetGWL_STYLE;//GWL_STYLE选项的listbox
	CWindInfo  m_winsetInfo;//显示句柄窗口信息
	CRect m_winsetRect;//句柄窗口区域大小
	short m_winsetTra;// 窗口透明度

	afx_msg void OnEnChangeEditHandel();
	afx_msg void OnBnClickedRadioDec();
	afx_msg void OnBnClickedRadioHex();
	afx_msg LRESULT OnGetHwnd(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEditTra();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonMovewind();
	afx_msg void OnBnClickedRadioMovewind1();
	afx_msg void OnBnClickedRadioMovewind2();
	afx_msg void OnBnClickedButtonHidewind();
	afx_msg void OnBnClickedButtonShowwind();
	afx_msg void OnBnClickedButtonActivewind();
	afx_msg void OnBnClickedButtonAlwaystop();
	afx_msg void OnBnClickedButtonAlwaystopoff();
	afx_msg void OnBnClickedButtonShowminimized();
	afx_msg void OnBnClickedButtonShowmaximized();
	afx_msg void OnBnClickedButtonShownormal();
	afx_msg void OnBnClickedButtonWindstyle();
	afx_msg void OnBnClickedButtonClosewind();
	afx_msg void OnBnClickedRadioCaptionon();
	afx_msg void OnBnClickedRadioCaptionoff();
	afx_msg void OnBnClickedRadioMaxminboxon();
	afx_msg void OnBnClickedRadioMaxminboxoff();
	afx_msg void OnBnClickedRadioMenuon();
	afx_msg void OnBnClickedRadioMenuoff();
	afx_msg void OnBnClickedRadioSizechangeon();
	afx_msg void OnBnClickedRadioSizechangeoff();
	afx_msg void OnBnClickedRadioBoderon();
	afx_msg void OnBnClickedRadioBoderoff();
	afx_msg void OnBnClickedRadioEnablewind();
	afx_msg void OnBnClickedRadioDisablewind();
	afx_msg void OnBnClickedButtonForseclosewind();
	afx_msg void OnBnClickedButtonSuspendwind();
	afx_msg void OnBnClickedButtonResumewind();
	afx_msg void OnBnClickedCheckChangesize();
	afx_msg void OnBnClickedCheckExtraitem();
	afx_msg void OnBnClickedButtonSetwind();
	afx_msg void OnBnClickedCheckHidewindow();
	afx_msg void OnBnClickedCheckAlwaystop();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButtonTrarecv();
	afx_msg void OnBnClickedButtonSelf();
};
