
// windsetDlg.h : ͷ�ļ�
//���������������
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


// CwindsetDlg �Ի���
void CALLBACK RefreshTimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime );//��ʱ���ص�����
class CwindsetDlg : public CDialogEx
{
// ����
public:
	CwindsetDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WINDSET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	virtual void OnOK();
public:
	//���ܺ���
	void iniDefault();
	bool SetWindowAlpha(HWND hwnd,short alpha);//�ı䴰��͸����
	void MatchWindlonglistbox(void);
	void MatchInfoTree();
	//��ӵı���
	HWND m_winsetHwnd;// Ҫ�ı�Ĵ��ھ��
	long m_wlongGWL_STYLE;//����ԭʼ�Ĵ���long
	long m_wlongGWL_EXSTYLE;
	HMENU m_winsetMenu;//�˵���
	CToolTipCtrl m_tip;
	CPicArcher m_picArcher;
	CSliderCtrl m_sliTra;//͸���Ȼ���
	CColorEdit m_winsetEdit;//����༭��
	CWindlonglistbox  m_winsetGWL_STYLE;//GWL_STYLEѡ���listbox
	CWindInfo  m_winsetInfo;//��ʾ���������Ϣ
	CRect m_winsetRect;//������������С
	short m_winsetTra;// ����͸����

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
