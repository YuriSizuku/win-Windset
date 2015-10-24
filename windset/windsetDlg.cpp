
// windsetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "windset.h"
#include "windsetDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#define TIMER_REFRESH 1111

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CwindsetDlg �Ի���




CwindsetDlg::CwindsetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CwindsetDlg::IDD, pParent)
	, m_winsetTra(255)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CwindsetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TRA, m_winsetTra);
	DDV_MinMaxShort(pDX, m_winsetTra, 0, 255);//����У��
}

BEGIN_MESSAGE_MAP(CwindsetDlg, CDialogEx)//��Ϣӳ��
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_HWND, &CwindsetDlg::OnEnChangeEditHandel)
	ON_BN_CLICKED(IDC_RADIO_DEC, &CwindsetDlg::OnBnClickedRadioDec)
	ON_BN_CLICKED(IDC_RADIO_HEX, &CwindsetDlg::OnBnClickedRadioHex)
	ON_MESSAGE(WM_CAPHWND, &CwindsetDlg::OnGetHwnd) //�Զ��������괦�������Ϣ
	ON_EN_CHANGE(IDC_EDIT_TRA, &CwindsetDlg::OnEnChangeEditTra)
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_MOVEWIND, &CwindsetDlg::OnBnClickedButtonMovewind)
	ON_BN_CLICKED(IDC_RADIO_MOVEWIND1, &CwindsetDlg::OnBnClickedRadioMovewind1)
	ON_BN_CLICKED(IDC_RADIO_MOVEWIND2, &CwindsetDlg::OnBnClickedRadioMovewind2)
	ON_BN_CLICKED(IDC_BUTTON_HIDEWIND, &CwindsetDlg::OnBnClickedButtonHidewind)
	ON_BN_CLICKED(IDC_BUTTON_SHOWBOTTOM, &CwindsetDlg::OnBnClickedButtonShowwind)
	ON_BN_CLICKED(IDC_BUTTON_ACTIVEWIND, &CwindsetDlg::OnBnClickedButtonActivewind)
	ON_BN_CLICKED(IDC_BUTTON_ALWAYSTOP, &CwindsetDlg::OnBnClickedButtonAlwaystop)
	ON_BN_CLICKED(IDC_BUTTON_ALWAYSTOPOFF, &CwindsetDlg::OnBnClickedButtonAlwaystopoff)
	ON_BN_CLICKED(IDC_BUTTON_SHOWMINIMIZED, &CwindsetDlg::OnBnClickedButtonShowminimized)
	ON_BN_CLICKED(IDC_BUTTON_SHOWMAXIMIZED, &CwindsetDlg::OnBnClickedButtonShowmaximized)
	ON_BN_CLICKED(IDC_BUTTON_SHOWNORMAL, &CwindsetDlg::OnBnClickedButtonShownormal)
	ON_BN_CLICKED(IDC_BUTTON_CLOSEWIND, &CwindsetDlg::OnBnClickedButtonClosewind)
	ON_BN_CLICKED(IDC_RADIO_CAPTIONON, &CwindsetDlg::OnBnClickedRadioCaptionon)
	ON_BN_CLICKED(IDC_RADIO_CAPTIONOFF, &CwindsetDlg::OnBnClickedRadioCaptionoff)
	ON_BN_CLICKED(IDC_RADIO_MAXMINBOXON, &CwindsetDlg::OnBnClickedRadioMaxminboxon)
	ON_BN_CLICKED(IDC_RADIO_MAXMINBOXOFF, &CwindsetDlg::OnBnClickedRadioMaxminboxoff)
	ON_BN_CLICKED(IDC_RADIO_MENUON, &CwindsetDlg::OnBnClickedRadioMenuon)
	ON_BN_CLICKED(IDC_RADIO_MENUOFF, &CwindsetDlg::OnBnClickedRadioMenuoff)
	ON_BN_CLICKED(IDC_RADIO_SIZECHANGEON, &CwindsetDlg::OnBnClickedRadioSizechangeon)
	ON_BN_CLICKED(IDC_RADIO_SIZECHANGEOFF, &CwindsetDlg::OnBnClickedRadioSizechangeoff)
	ON_BN_CLICKED(IDC_RADIO_BODERON, &CwindsetDlg::OnBnClickedRadioBoderon)
	ON_BN_CLICKED(IDC_RADIO_BODEROFF, &CwindsetDlg::OnBnClickedRadioBoderoff)
	ON_BN_CLICKED(IDC_RADIO_ENABLEWIND, &CwindsetDlg::OnBnClickedRadioEnablewind)
	ON_BN_CLICKED(IDC_RADIO_DISABLEWIND, &CwindsetDlg::OnBnClickedRadioDisablewind)
	ON_BN_CLICKED(IDC_BUTTON_FORSECLOSEWIND, &CwindsetDlg::OnBnClickedButtonForseclosewind)
	ON_BN_CLICKED(IDC_BUTTON_SUSPENDWIND, &CwindsetDlg::OnBnClickedButtonSuspendwind)
	ON_BN_CLICKED(IDC_BUTTON_RESUMEWIND, &CwindsetDlg::OnBnClickedButtonResumewind)
	ON_BN_CLICKED(IDC_CHECK_CHANGESIZE, &CwindsetDlg::OnBnClickedCheckChangesize)
	ON_BN_CLICKED(IDC_CHECK_GWLSTYLE, &CwindsetDlg::OnBnClickedCheckExtraitem)
	ON_BN_CLICKED(IDC_BUTTON_SETWIND, &CwindsetDlg::OnBnClickedButtonSetwind)
	ON_BN_CLICKED(IDC_CHECK_HIDEWINDOW, &CwindsetDlg::OnBnClickedCheckHidewindow)
	ON_BN_CLICKED(IDC_CHECK_ALWAYSTOP, &CwindsetDlg::OnBnClickedCheckAlwaystop)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_TRARECV, &CwindsetDlg::OnBnClickedButtonTrarecv)
	ON_BN_CLICKED(IDC_BUTTON_SELF, &CwindsetDlg::OnBnClickedButtonSelf)
END_MESSAGE_MAP()

//���ܺ���
void CwindsetDlg::iniDefault()
{
	//��ť��ʼ��
	((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->SetCheck(true);
	((CButton *)this->GetDlgItem(IDC_RADIO_DEC))->SetCheck(false);//���������������ò�ƻ�һֱ����idc_radioѡ��
	((CButton *)this->GetDlgItem(IDC_RADIO_MOVEWIND1))->SetCheck(true);
	((CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW))->SetCheck(1);
	//((CButton *)this->GetDlgItem(IDC_BUTTON_ACTIVEWIND))->set
	
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDW)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDH)->EnableWindow(false);
	m_winsetHwnd=0;

	//����༭��
	m_winsetEdit.SubclassDlgItem(IDC_EDIT_HWND,this);

	//�����ͷͼ��
	m_picArcher.SubclassDlgItem(IDC_PICARCHER,this);

	//��ʾ��Ϣ��ʼ��
	m_tip.Create(this);
	m_tip.SetTipBkColor(RGB(100,240,100));
	m_tip.SetMaxTipWidth(340);
	for(int i=0;tooltip[i].id!=0 && tooltip[i].value!="";i++)
	{
		m_tip.AddTool(GetDlgItem(tooltip[i].id),tooltip[i].value.data());
	}
	
	//͸���Ȼ���
	m_sliTra.SubclassDlgItem(IDC_SLIDER_TRA,this);
	m_sliTra.SetRange(0,255);
	m_sliTra.SetPos(m_winsetTra);

	//����ˢ�¶�ʱ��
	SetTimer(TIMER_REFRESH,1000,NULL);//Ϊ���������в��������ûص�������

	//��ʼ��CCheckListBox
	m_winsetGWL_STYLE.SubclassDlgItem(IDC_LIST_EXTRAWIND,this);
	m_winsetGWL_STYLE.SetClickColor(RGB(0,200,255));
	m_winsetGWL_STYLE.SetSelectedColor(RGB(200,255,100));
	m_winsetGWL_STYLE.SetDisabledColor(RGB(230,230,230));
	m_winsetGWL_STYLE.SetFontHeight(10);
	m_winsetGWL_STYLE.SetFontWidth(4);
	for(int i=0;windlongbox[i].id!=0 || windlongbox[i].value!="";i++)
	{
		m_winsetGWL_STYLE.AddString(windlongbox[i].value.data());
	}
	m_winsetGWL_STYLE.EnableWindow(false);

	//��ʼ��CTreeCtrl
	m_winsetInfo.SubclassDlgItem(IDC_TREE_WINDINFO,this);
	m_winsetInfo.ModifyStyle(0,TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_EDITLABELS  ,0);
	m_winsetInfo.SetBkColor(RGB(170,30,230));
	m_winsetInfo.SetTextColor(RGB(255,255,255));

}
bool  CwindsetDlg::SetWindowAlpha(HWND hwnd,short alpha)
{
	 LONG tLong = GetWindowLong(hwnd,GWL_EXSTYLE);
	 tLong|= WS_EX_LAYERED;//���������һ�����
	 SetWindowLong(hwnd,GWL_EXSTYLE,tLong);
     return ::SetLayeredWindowAttributes(hwnd ,0,alpha,LWA_ALPHA); //ͬ�������޸����������͸����
}
void CwindsetDlg::MatchWindlonglistbox(void)
{
	long windlong=::GetWindowLong(m_winsetHwnd,GWL_STYLE);
	for(int j=0;windlongbox[j].id!=0 && windlongbox[j].value!="";j++)//�����ѡ
	{
		m_winsetGWL_STYLE.SetCheck(j,0);
	}
	for(int j=0;windlongbox[j].id!=0 || windlongbox[j].value!="";j++)//��ȫ����
	{
			if((windlong & windlongbox[j].id)==windlongbox[j].id)
				m_winsetGWL_STYLE.SetCheck(j,1);
	}
	m_winsetGWL_STYLE.RedrawWindow();
		//for(int i=0;i<8*sizeof(long);i++)//����֤����ԭ��ʱ,û������
	//{
	//	for(int j=0;windlongbox[j].id!=0 || windlongbox[j].value!="";j++)
	//	{
	//		if((windlong & 0x1<<i) == windlongbox[j].id)
	//			m_winsetGWL_STYLE.SetCheck(j,1);
	//	}
	//}
}
void  CwindsetDlg::MatchInfoTree()
{
 	m_winsetInfo.DeleteAllItems();
	if(!IsWindow(m_winsetHwnd))
	{
		m_winsetInfo.InsertItem("NULL��");
		return;
	}
	HTREEITEM subroot,tnode,t;
	char tstr[200];
	subroot=m_winsetInfo.InsertItem("����������Ϣ");
		tnode=m_winsetInfo.InsertItem("���ھ��",subroot);
		{
			sprintf(tstr,"0x%x",m_winsetHwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		tnode=m_winsetInfo.InsertItem("����",subroot);
		{
			::GetClassName(m_winsetHwnd,tstr,200);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("���ڱ���",subroot);
		{
			::GetWindowText(m_winsetHwnd,tstr,200);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("��������",subroot);
		{
			CRect rect;
			::GetWindowRect(m_winsetHwnd, rect);  
			sprintf(tstr,"�ֱ���:%dX%d",rect.Width(),rect.Height());
			m_winsetInfo.InsertItem(tstr,tnode);
			sprintf(tstr,"��Χ:(%d,%d)~(%d,%d)",rect.left,rect.top,rect.right,rect.bottom);
			m_winsetInfo.InsertItem(tstr,tnode);
			if(::IsZoomed(m_winsetHwnd)==true) strcpy(tstr,"��󻯣�ON");
			else strcpy(tstr,"��󻯣�OFF");
			m_winsetInfo.InsertItem(tstr,tnode);
			if(::IsIconic(m_winsetHwnd)==true) strcpy(tstr,"��С����ON");
			else strcpy(tstr,"��С����OFF");
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	subroot=m_winsetInfo.InsertItem("���ڳ�����Ϣ");
		DWORD dwThreadId,dwProcessId;
		dwThreadId=GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	    t=tnode=m_winsetInfo.InsertItem("PID(����id)",subroot);
		{
			sprintf(tstr,"0x%08x",dwProcessId);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		DWORD tid[100];
		int count;
		count=TraceAllThreadByPid(dwProcessId,tid);
		sprintf(tstr,"Tid(�߳�id)����%d���߳�,���߳�0x%08x",count,dwThreadId);
		tnode=m_winsetInfo.InsertItem(tstr,subroot);
		{
			for(int i=0;i<count;i++)
			{
				sprintf(tstr,"#%d 0x%08x",i,tid[i]);
				m_winsetInfo.InsertItem(tstr,tnode);
			}
		}
	    tnode=m_winsetInfo.InsertItem("����·��",subroot);
		{
			GetProcPath(dwProcessId,tstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	subroot=m_winsetInfo.InsertItem("������ʽ");
		tnode= m_winsetInfo.InsertItem("GWL_STYLE",subroot);
		{
			sprintf(tstr,"0x%08x",m_wlongGWL_STYLE);
			tnode=m_winsetInfo.InsertItem(tstr,tnode);
			for(int i=0;windlongbox[i].id!=0  || windlongbox[i].value!="";i++)
			{
				if((m_wlongGWL_STYLE & windlongbox[i].id)==windlongbox[i].id)
				{
					strcpy(tstr,windlongbox[i].value.data());
					m_winsetInfo.InsertItem(tstr,tnode);
				}
			}
		}
		tnode= m_winsetInfo.InsertItem("GWL_EXSTYLE",subroot);
		{
			sprintf(tstr,"0x%08x",m_wlongGWL_EXSTYLE);
			tnode=m_winsetInfo.InsertItem(tstr,tnode);
			for(int i=0;windEXlongbox[i].id!=0  || windEXlongbox[i].value!="";i++)
			{
				if((m_wlongGWL_EXSTYLE & windEXlongbox[i].id)==windEXlongbox[i].id)
				{
					strcpy(tstr,windEXlongbox[i].value.data());
					m_winsetInfo.InsertItem(tstr,tnode);
				}
			}
		}
	subroot=m_winsetInfo.InsertItem("��ش���");
	    tnode=m_winsetInfo.InsertItem("��һ����",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_HWNDPREV);
			sprintf(tstr,"�����0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"���⣺%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"�ࣺ%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("��һ����",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_HWNDNEXT);
			sprintf(tstr,"�����0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"���⣺%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"�ࣺ%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("������",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetParent(m_winsetHwnd);
			sprintf(tstr,"�����0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"���⣺%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"�ࣺ%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("�����ߴ���",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_OWNER);
			sprintf(tstr,"�����0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"���⣺%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"�ࣺ%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("��һ�Ӵ���",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_CHILD);
			sprintf(tstr,"�����0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"���⣺%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"�ࣺ%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		m_winsetInfo.ShowSubTree(m_winsetInfo.GetRootItem());
		m_winsetInfo.EnsureVisible(t);
}
// CwindsetDlg ��Ϣ�������

BOOL CwindsetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, TRUE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	iniDefault();//��ʼ��Ĭ��ѡ��
	EnableDebugPriv();//����Ȩ��
	this->SetBackgroundColor(RGB(170,230,255));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CwindsetDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CwindsetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CwindsetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CwindsetDlg::OnEnChangeEditHandel()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	char buf[100];
	tEdit->GetWindowText(buf,100);
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16����
	{
		sscanf(buf,"%x",&m_winsetHwnd);
	}
	else
	{
		sscanf(buf,"%u",&m_winsetHwnd);
	}
	
	m_wlongGWL_STYLE=::GetWindowLong(m_winsetHwnd,GWL_STYLE);
	m_wlongGWL_EXSTYLE=::GetWindowLong(m_winsetHwnd,GWL_EXSTYLE);
	MatchInfoTree();
	if(IsWindow(m_winsetHwnd))//�������Ч�Ĵ��ھ��
	{
		m_winsetEdit.SetBkColor(RGB(0,255,0));
		m_winsetMenu=::GetMenu(m_winsetHwnd);
		MatchWindlonglistbox();
	}
	else
	{
		m_winsetEdit.SetBkColor(RGB(255,0,0));
	}
}

void CwindsetDlg::OnBnClickedRadioDec()//�����ʾ16����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[100];
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	sprintf(buf,"%u",m_winsetHwnd);
	tEdit->SetWindowText(buf);
}

void CwindsetDlg::OnBnClickedRadioHex()//�����ʾ10����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[100];
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	sprintf(buf,"%x",m_winsetHwnd);
	tEdit->SetWindowText(buf);
}

LRESULT  CwindsetDlg::OnGetHwnd(WPARAM wParam, LPARAM lParam)//�϶���ȡ�����Ļص���Ϣ����
{
	m_winsetHwnd=(HWND)wParam;
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16����
		OnBnClickedRadioHex();
	else OnBnClickedRadioDec();
	return 0;
}


BOOL CwindsetDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_tip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CwindsetDlg::OnEnChangeEditTra()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);//��������
	m_sliTra.SetPos(m_winsetTra);
	if(SetWindowAlpha(m_winsetHwnd,m_winsetTra)==false) 
	{
		//MessageBox("fault");
	}
}


void CwindsetDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pScrollBar->m_hWnd==m_sliTra.m_hWnd)
	{
		//ʵ�ֵ��Ĺ������͵���
		CPoint  ptCursor;
		int nMin,nMax,nCurPos;
		CRect rct1,rct2;
		GetCursorPos(&ptCursor);
		m_sliTra.GetRange(nMin, nMax);
		nMin=-10;nMax+=10;
		m_sliTra.ScreenToClient(&ptCursor);
		m_sliTra.GetClientRect(&rct1);
		m_sliTra.GetChannelRect(&rct2);//��ʵ�Ĺ�����
		nCurPos= nMin + (ptCursor.x-(rct2.left+rct1.left ))* (nMax - nMin) /rct2.Width();
		if(nCurPos > nMax) nCurPos = nMax;
			else if(nCurPos < nMin) nCurPos = nMin;
		m_sliTra.SetPos(nCurPos);
		
		//��������
		UpdateData(true);
		m_winsetTra=m_sliTra.GetPos();
		UpdateData(false);
		OnEnChangeEditTra();
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CwindsetDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==TIMER_REFRESH)
	{
		if(m_winsetHwnd==0) return;
		if(IsWindow(m_winsetHwnd))//�������Ч�Ĵ��ھ��
		{
			m_winsetEdit.SetBkColor(RGB(0,255,0));
		}
		else
		{
			m_winsetEdit.SetBkColor(RGB(255,0,0));
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CwindsetDlg::OnBnClickedButtonMovewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(((CButton *)this->GetDlgItem(IDC_RADIO_MOVEWIND1))->GetCheck() == true)//Ĭ���ƶ���������
	{
		static int loop=0;
		if(loop==0)
		{
			::GetWindowRect(m_winsetHwnd,&m_winsetRect);
			::SetWindowPos(m_winsetHwnd,HWND_TOP//
							,7000,7100,0,0,
							SWP_NOSIZE);//SWP_NOSIZE����dx,dy
			loop=1;
		}
		else
		{
			if(((CButton *)this->GetDlgItem(IDC_CHECK_EXTRASET))->GetCheck() == true)//�ƶ����ڵ�����������ѡ��
			{
				::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
								,m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOSIZE | SWP_NOACTIVATE);//SWP_NOSIZE����dx,dy
				OnBnClickedButtonSetwind();
			}
			else
			{
				::SetFocus(m_winsetHwnd);
				::SetWindowPos(m_winsetHwnd,HWND_TOP,//�������ε��ò���
								m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOACTIVATE |SWP_NOZORDER );
				::SetWindowPos(m_winsetHwnd,HWND_TOP,
								m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOACTIVATE |SWP_NOZORDER );//SWP_NOZORDER�����ִ������б�ĵ�ǰλ�ã�����hWndInsertAfter�� 
			}
			loop=0;
		}
	}
	else
	{
		int i_movex,i_movey;
		char c_movex[10],c_movey[10];
		((CEdit*)GetDlgItem(IDC_EDIT_MOVEWINDX))->GetWindowText(c_movex,10);
		((CEdit*)GetDlgItem(IDC_EDIT_MOVEWINDY))->GetWindowText(c_movey,10);
		sscanf(c_movex,"%d",&i_movex);
		sscanf(c_movey,"%d",&i_movey);
		if(((CButton *)this->GetDlgItem(IDC_CHECK_EXTRASET))->GetCheck() == true)//�ƶ����ڵ�����������ѡ��
		{
			::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
						,i_movex,i_movey,0,0,
						SWP_NOSIZE | SWP_NOACTIVATE);//SWP_NOSIZE����dx,dy
			OnBnClickedButtonSetwind();
		}
		else
		{
			::SetWindowPos(m_winsetHwnd,HWND_TOP//
						,i_movex,i_movey,0,0,
						SWP_NOSIZE);//SWP_NOSIZE����dx,dy
			OnBnClickedButtonSetwind();
			
		}
	}
}


void CwindsetDlg::OnBnClickedRadioMovewind1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *tEdit1,*tEdit2;
	tEdit1=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX);
	tEdit2=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY);
	tEdit1->EnableWindow(false);
	tEdit2->EnableWindow(false);
}


void CwindsetDlg::OnBnClickedRadioMovewind2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *tEdit1,*tEdit2;
	tEdit1=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX);
	tEdit2=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY);
	tEdit1->EnableWindow(true);
	tEdit2->EnableWindow(true);
}


void CwindsetDlg::OnBnClickedButtonHidewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
					,0,0,0,0,
					SWP_NOACTIVATE |SWP_NOSIZE | SWP_NOMOVE | SWP_HIDEWINDOW);//SWP_NOSIZE����dx,dy
}


void CwindsetDlg::OnBnClickedButtonShowwind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetWindowPos(m_winsetHwnd,HWND_BOTTOM,
					0,0,0,0
					,SWP_NOACTIVATE  | SWP_NOSIZE | SWP_NOMOVE |SWP_SHOWWINDOW);//SWP_NOZORDER�����ִ������б�ĵ�ǰλ�ã�����hWndInsertAfter�� 
}


void CwindsetDlg::OnBnClickedButtonActivewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetWindowPos(m_winsetHwnd,HWND_TOP,
					0,0,0,0
					, SWP_NOSIZE | SWP_NOMOVE |SWP_SHOWWINDOW);//SWP_NOZORDER�����ִ������б�ĵ�ǰλ�ã�����hWndInsertAfter�� 
}


void CwindsetDlg::OnBnClickedButtonAlwaystop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetWindowPos(m_winsetHwnd,HWND_TOPMOST//
					,0,0,0,0,
					 SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);//SWP_NOSIZE����dx,dy
}


void CwindsetDlg::OnBnClickedButtonAlwaystopoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetWindowPos(m_winsetHwnd,HWND_NOTOPMOST,
					0,0,0,0,
					SWP_NOACTIVATE| SWP_NOSIZE | SWP_NOMOVE);//SWP_NOZORDER�����ִ������б�ĵ�ǰλ�ã�����hWndInsertAfter�� 
}


void CwindsetDlg::OnBnClickedButtonShowminimized()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::ShowWindow(m_winsetHwnd,SW_SHOWMINIMIZED);
}


void CwindsetDlg::OnBnClickedButtonShowmaximized()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::ShowWindow(m_winsetHwnd,SW_SHOWMAXIMIZED);
}


void CwindsetDlg::OnBnClickedButtonShownormal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::ShowWindow(m_winsetHwnd,SW_SHOWNORMAL);
}


void CwindsetDlg::OnBnClickedButtonWindstyle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int loop=0;

}


void CwindsetDlg::OnBnClickedButtonClosewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	::SendMessage(m_winsetHwnd,WM_CLOSE,0,0);//WM_DESTROY�������
}


void CwindsetDlg::OnBnClickedRadioCaptionon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,0,WS_CAPTION,SWP_FRAMECHANGED);//�ӳ�����
}


void CwindsetDlg::OnBnClickedRadioCaptionoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,WS_CAPTION,0,SWP_FRAMECHANGED);//ȥ������
}


void CwindsetDlg::OnBnClickedRadioMaxminboxon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,0,WS_SYSMENU,SWP_FRAMECHANGED);//ȥ����󻯡���С��֮���
}


void CwindsetDlg::OnBnClickedRadioMaxminboxoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,WS_SYSMENU,0,SWP_FRAMECHANGED);//������󻯡���С��֮���
}


void CwindsetDlg::OnBnClickedRadioMenuon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetMenu(m_winsetHwnd,m_winsetMenu);
}


void CwindsetDlg::OnBnClickedRadioMenuoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SetMenu(m_winsetHwnd,NULL);
}


void CwindsetDlg::OnBnClickedRadioSizechangeon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,0,WS_SIZEBOX ,0);//��ֹ���ı��С
}


void CwindsetDlg::OnBnClickedRadioSizechangeoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,WS_SIZEBOX ,0,0);//��ֹ���ı��С
}


void CwindsetDlg::OnBnClickedRadioBoderon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,0,WS_BORDER,SWP_FRAMECHANGED);
}


void CwindsetDlg::OnBnClickedRadioBoderoff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,WS_BORDER,0,SWP_FRAMECHANGED);
}


void CwindsetDlg::OnBnClickedRadioEnablewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,WS_DISABLED,0,0);
}


void CwindsetDlg::OnBnClickedRadioDisablewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ModifyStyle(m_winsetHwnd,0,WS_DISABLED,0);
}


void CwindsetDlg::OnBnClickedButtonForseclosewind()//ǿ�ƽ�������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DWORD dwThreadId,dwProcessId;
	HANDLE hProcess;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	hProcess = OpenProcess(PROCESS_TERMINATE,FALSE,dwProcessId);
	if(hProcess==NULL) return;
	TerminateProcess(hProcess,NULL);
}


void CwindsetDlg::OnBnClickedButtonSuspendwind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!IsWindow(m_winsetHwnd)) return;
	DWORD dwThreadId,dwProcessId;
	HANDLE hProcess;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	SuspendTask(dwProcessId);
}


void CwindsetDlg::OnBnClickedButtonResumewind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!IsWindow(m_winsetHwnd)) return;
	DWORD dwThreadId,dwProcessId;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	ResumeTask(dwProcessId);
}


void CwindsetDlg::OnBnClickedCheckChangesize()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_CHANGESIZE))->GetCheck()!=0 )
	{
		(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDW)->EnableWindow(true);
		(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDH)->EnableWindow(true);
	}
	else
	{
		(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDW)->EnableWindow(false);
		(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDH)->EnableWindow(false);	
	}
}


void CwindsetDlg::OnBnClickedCheckExtraitem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_GWLSTYLE))->GetCheck()!=0 )
	{
		m_winsetGWL_STYLE.EnableWindow(true);
	}
	else
	{
		m_winsetGWL_STYLE.EnableWindow(false);
	}
}

void CwindsetDlg::OnBnClickedButtonSetwind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CButton *pButton;

	//�ı�ߴ�
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_CHANGESIZE))->GetCheck() == 1 )
	{
		int i_movew,i_moveh;
		char c_movew[10],c_moveh[10];
		((CEdit*)GetDlgItem(IDC_EDIT_MOVEWINDW))->GetWindowText(c_movew,10);
		((CEdit*)GetDlgItem(IDC_EDIT_MOVEWINDH))->GetWindowText(c_moveh,10);
		sscanf(c_movew,"%d",&i_movew);
		sscanf(c_moveh,"%d",&i_moveh);
		::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
						,0,0,i_movew,i_moveh,
						SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);//SWP_NOMOVE����x,y
	}

	//���ô��ڷ��
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_GWLSTYLE))->GetCheck() == 1 )
	{
		long windlong=0;
		for(int i=0;windlongbox[i].id!=0 || windlongbox[i].value!="";i++)
		{
			if(m_winsetGWL_STYLE.GetCheck(i)!=0) windlong |=windlongbox[i].id;
		}
		::SetWindowLong(m_winsetHwnd,GWL_STYLE,windlong);
		::SetWindowPos(m_winsetHwnd,HWND_BOTTOM,0,0,0,0,
						SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//Ŀ����ˢ�´���
	}

	//���ش���
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_HIDEWINDOW))->GetCheck() == 1 ) 
	{
		::ShowWindow(m_winsetHwnd,SW_HIDE);
		return;
	}
	else
	{
		OnBnClickedButtonShowwind();
	}

	//�����
	pButton=(CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW);
	if( pButton->GetCheck() == 1 && pButton->IsWindowEnabled()) 
	{
		OnBnClickedButtonActivewind();
	}
	else
	{
		
	}

	//ʼ���ö�
	pButton=(CButton *)this->GetDlgItem(IDC_CHECK_ALWAYSTOP);
	if( pButton->GetCheck() == 1 && pButton->IsWindowEnabled() ) 
	{
		OnBnClickedButtonAlwaystop();
		return;
	}
	else
	{
		OnBnClickedButtonAlwaystopoff();
	}

	//�ŵ��ײ�
	pButton=(CButton *)this->GetDlgItem(IDC_CHECK_BOTTOM);
	if( pButton->GetCheck() == 1 && pButton->IsWindowEnabled() ) 
	{
		OnBnClickedButtonShowwind();
	}
	else
	{
		//::ShowWindow(m_winsetHwnd,SW_SHOW);
			::SetWindowPos(m_winsetHwnd,HWND_TOP,
					0,0,0,0
					,SWP_NOACTIVATE  | SWP_NOSIZE | SWP_NOMOVE |SWP_NOOWNERZORDER);//SWP_NOZORDER�����ִ������б�ĵ�ǰλ�ã�����hWndInsertAfter)

	}
}

void CwindsetDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();//����ʹ�ð��س��������˳�
}

void CwindsetDlg::OnBnClickedCheckHidewindow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(((CButton *)this->GetDlgItem(IDC_CHECK_HIDEWINDOW))->GetCheck() == 1)
	{
		((CButton *)this->GetDlgItem(IDC_CHECK_ALWAYSTOP))->EnableWindow(false);
		((CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW))->EnableWindow(false);
		((CButton *)this->GetDlgItem(IDC_CHECK_BOTTOM))->EnableWindow(false);
	}
	else
	{
		((CButton *)this->GetDlgItem(IDC_CHECK_ALWAYSTOP))->EnableWindow(true);
		((CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW))->EnableWindow(true);
		((CButton *)this->GetDlgItem(IDC_CHECK_BOTTOM))->EnableWindow(true);
	}
}


void CwindsetDlg::OnBnClickedCheckAlwaystop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(((CButton *)this->GetDlgItem(IDC_CHECK_ALWAYSTOP))->GetCheck() == 1)
	{
		((CButton *)this->GetDlgItem(IDC_CHECK_BOTTOM))->EnableWindow(false);
	}
	else
	{
		((CButton *)this->GetDlgItem(IDC_CHECK_BOTTOM))->EnableWindow(true);
	}
}


BOOL CwindsetDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CwindsetDlg::OnBnClickedButtonTrarecv()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetWindowLong(m_winsetHwnd,GWL_EXSTYLE,m_wlongGWL_EXSTYLE);
}

void CwindsetDlg::OnBnClickedButtonSelf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_winsetHwnd=this->GetSafeHwnd();
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16����
		OnBnClickedRadioHex();
	else OnBnClickedRadioDec();
	OnEnChangeEditHandel();
	CAboutDlg c;
	c.DoModal();
}
