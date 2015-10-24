
// windsetDlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CwindsetDlg 对话框




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
	DDV_MinMaxShort(pDX, m_winsetTra, 0, 255);//数据校验
}

BEGIN_MESSAGE_MAP(CwindsetDlg, CDialogEx)//消息映射
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_HWND, &CwindsetDlg::OnEnChangeEditHandel)
	ON_BN_CLICKED(IDC_RADIO_DEC, &CwindsetDlg::OnBnClickedRadioDec)
	ON_BN_CLICKED(IDC_RADIO_HEX, &CwindsetDlg::OnBnClickedRadioHex)
	ON_MESSAGE(WM_CAPHWND, &CwindsetDlg::OnGetHwnd) //自定义接收鼠标处句柄的消息
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

//功能函数
void CwindsetDlg::iniDefault()
{
	//按钮初始化
	((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->SetCheck(true);
	((CButton *)this->GetDlgItem(IDC_RADIO_DEC))->SetCheck(false);//不加这句会出错，后面貌似会一直调用idc_radio选项
	((CButton *)this->GetDlgItem(IDC_RADIO_MOVEWIND1))->SetCheck(true);
	((CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW))->SetCheck(1);
	//((CButton *)this->GetDlgItem(IDC_BUTTON_ACTIVEWIND))->set
	
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDW)->EnableWindow(false);
	(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDH)->EnableWindow(false);
	m_winsetHwnd=0;

	//句柄编辑框
	m_winsetEdit.SubclassDlgItem(IDC_EDIT_HWND,this);

	//句柄箭头图案
	m_picArcher.SubclassDlgItem(IDC_PICARCHER,this);

	//提示信息初始化
	m_tip.Create(this);
	m_tip.SetTipBkColor(RGB(100,240,100));
	m_tip.SetMaxTipWidth(340);
	for(int i=0;tooltip[i].id!=0 && tooltip[i].value!="";i++)
	{
		m_tip.AddTool(GetDlgItem(tooltip[i].id),tooltip[i].value.data());
	}
	
	//透明度滑条
	m_sliTra.SubclassDlgItem(IDC_SLIDER_TRA,this);
	m_sliTra.SetRange(0,255);
	m_sliTra.SetPos(m_winsetTra);

	//设置刷新定时器
	SetTimer(TIMER_REFRESH,1000,NULL);//为方便在类中操作，不用回调函数了

	//初始化CCheckListBox
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

	//初始化CTreeCtrl
	m_winsetInfo.SubclassDlgItem(IDC_TREE_WINDINFO,this);
	m_winsetInfo.ModifyStyle(0,TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_EDITLABELS  ,0);
	m_winsetInfo.SetBkColor(RGB(170,30,230));
	m_winsetInfo.SetTextColor(RGB(255,255,255));

}
bool  CwindsetDlg::SetWindowAlpha(HWND hwnd,short alpha)
{
	 LONG tLong = GetWindowLong(hwnd,GWL_EXSTYLE);
	 tLong|= WS_EX_LAYERED;//必须加上这一项才行
	 SetWindowLong(hwnd,GWL_EXSTYLE,tLong);
     return ::SetLayeredWindowAttributes(hwnd ,0,alpha,LWA_ALPHA); //同样可以修改其他程序的透明度
}
void CwindsetDlg::MatchWindlonglistbox(void)
{
	long windlong=::GetWindowLong(m_winsetHwnd,GWL_STYLE);
	for(int j=0;windlongbox[j].id!=0 && windlongbox[j].value!="";j++)//清空所选
	{
		m_winsetGWL_STYLE.SetCheck(j,0);
	}
	for(int j=0;windlongbox[j].id!=0 || windlongbox[j].value!="";j++)//完全符合
	{
			if((windlong & windlongbox[j].id)==windlongbox[j].id)
				m_winsetGWL_STYLE.SetCheck(j,1);
	}
	m_winsetGWL_STYLE.RedrawWindow();
		//for(int i=0;i<8*sizeof(long);i++)//当保证都是原子时,没有排序
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
		m_winsetInfo.InsertItem("NULL！");
		return;
	}
	HTREEITEM subroot,tnode,t;
	char tstr[200];
	subroot=m_winsetInfo.InsertItem("基本窗口信息");
		tnode=m_winsetInfo.InsertItem("窗口句柄",subroot);
		{
			sprintf(tstr,"0x%x",m_winsetHwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		tnode=m_winsetInfo.InsertItem("类名",subroot);
		{
			::GetClassName(m_winsetHwnd,tstr,200);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("窗口标题",subroot);
		{
			::GetWindowText(m_winsetHwnd,tstr,200);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("窗口区域",subroot);
		{
			CRect rect;
			::GetWindowRect(m_winsetHwnd, rect);  
			sprintf(tstr,"分辨率:%dX%d",rect.Width(),rect.Height());
			m_winsetInfo.InsertItem(tstr,tnode);
			sprintf(tstr,"范围:(%d,%d)~(%d,%d)",rect.left,rect.top,rect.right,rect.bottom);
			m_winsetInfo.InsertItem(tstr,tnode);
			if(::IsZoomed(m_winsetHwnd)==true) strcpy(tstr,"最大化：ON");
			else strcpy(tstr,"最大化：OFF");
			m_winsetInfo.InsertItem(tstr,tnode);
			if(::IsIconic(m_winsetHwnd)==true) strcpy(tstr,"最小化：ON");
			else strcpy(tstr,"最小化：OFF");
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	subroot=m_winsetInfo.InsertItem("窗口程序信息");
		DWORD dwThreadId,dwProcessId;
		dwThreadId=GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	    t=tnode=m_winsetInfo.InsertItem("PID(进程id)",subroot);
		{
			sprintf(tstr,"0x%08x",dwProcessId);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		DWORD tid[100];
		int count;
		count=TraceAllThreadByPid(dwProcessId,tid);
		sprintf(tstr,"Tid(线程id)：共%d个线程,主线程0x%08x",count,dwThreadId);
		tnode=m_winsetInfo.InsertItem(tstr,subroot);
		{
			for(int i=0;i<count;i++)
			{
				sprintf(tstr,"#%d 0x%08x",i,tid[i]);
				m_winsetInfo.InsertItem(tstr,tnode);
			}
		}
	    tnode=m_winsetInfo.InsertItem("程序路径",subroot);
		{
			GetProcPath(dwProcessId,tstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	subroot=m_winsetInfo.InsertItem("窗口样式");
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
	subroot=m_winsetInfo.InsertItem("相关窗口");
	    tnode=m_winsetInfo.InsertItem("上一窗口",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_HWNDPREV);
			sprintf(tstr,"句柄：0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"标题：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"类：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("下一窗口",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_HWNDNEXT);
			sprintf(tstr,"句柄：0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"标题：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"类：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("父窗口",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetParent(m_winsetHwnd);
			sprintf(tstr,"句柄：0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"标题：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"类：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("所有者窗口",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_OWNER);
			sprintf(tstr,"句柄：0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"标题：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"类：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
	    tnode=m_winsetInfo.InsertItem("第一子窗口",subroot);
		{
			HWND thwnd;
			char ttstr[255];
			thwnd=::GetNextWindow(m_winsetHwnd,GW_CHILD);
			sprintf(tstr,"句柄：0x%08x",thwnd);
			m_winsetInfo.InsertItem(tstr,tnode);
			::SendMessage(m_winsetHwnd, WM_GETTEXT, 255, (LPARAM)ttstr);
			sprintf(tstr,"标题：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
			::GetClassName(m_winsetHwnd,ttstr,200);
			sprintf(tstr,"类：%s",ttstr);
			m_winsetInfo.InsertItem(tstr,tnode);
		}
		m_winsetInfo.ShowSubTree(m_winsetInfo.GetRootItem());
		m_winsetInfo.EnsureVisible(t);
}
// CwindsetDlg 消息处理程序

BOOL CwindsetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, TRUE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	iniDefault();//初始化默认选项
	EnableDebugPriv();//提升权限
	this->SetBackgroundColor(RGB(170,230,255));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CwindsetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CwindsetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CwindsetDlg::OnEnChangeEditHandel()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	char buf[100];
	tEdit->GetWindowText(buf,100);
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16进制
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
	if(IsWindow(m_winsetHwnd))//如果是有效的窗口句柄
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

void CwindsetDlg::OnBnClickedRadioDec()//句柄显示16进制
{
	// TODO: 在此添加控件通知处理程序代码
	char buf[100];
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	sprintf(buf,"%u",m_winsetHwnd);
	tEdit->SetWindowText(buf);
}

void CwindsetDlg::OnBnClickedRadioHex()//句柄显示10进制
{
	// TODO: 在此添加控件通知处理程序代码
	char buf[100];
	CEdit *tEdit=(CEdit *)this->GetDlgItem(IDC_EDIT_HWND);
	sprintf(buf,"%x",m_winsetHwnd);
	tEdit->SetWindowText(buf);
}

LRESULT  CwindsetDlg::OnGetHwnd(WPARAM wParam, LPARAM lParam)//拖动获取句柄后的回调信息函数
{
	m_winsetHwnd=(HWND)wParam;
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16进制
		OnBnClickedRadioHex();
	else OnBnClickedRadioDec();
	return 0;
}


BOOL CwindsetDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_tip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CwindsetDlg::OnEnChangeEditTra()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);//更新数据
	m_sliTra.SetPos(m_winsetTra);
	if(SetWindowAlpha(m_winsetHwnd,m_winsetTra)==false) 
	{
		//MessageBox("fault");
	}
}


void CwindsetDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pScrollBar->m_hWnd==m_sliTra.m_hWnd)
	{
		//实现点哪滚动条就到哪
		CPoint  ptCursor;
		int nMin,nMax,nCurPos;
		CRect rct1,rct2;
		GetCursorPos(&ptCursor);
		m_sliTra.GetRange(nMin, nMax);
		nMin=-10;nMax+=10;
		m_sliTra.ScreenToClient(&ptCursor);
		m_sliTra.GetClientRect(&rct1);
		m_sliTra.GetChannelRect(&rct2);//真实的滚动条
		nCurPos= nMin + (ptCursor.x-(rct2.left+rct1.left ))* (nMax - nMin) /rct2.Width();
		if(nCurPos > nMax) nCurPos = nMax;
			else if(nCurPos < nMin) nCurPos = nMin;
		m_sliTra.SetPos(nCurPos);
		
		//滚动操作
		UpdateData(true);
		m_winsetTra=m_sliTra.GetPos();
		UpdateData(false);
		OnEnChangeEditTra();
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CwindsetDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==TIMER_REFRESH)
	{
		if(m_winsetHwnd==0) return;
		if(IsWindow(m_winsetHwnd))//如果是有效的窗口句柄
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
	// TODO: 在此添加控件通知处理程序代码
	if(((CButton *)this->GetDlgItem(IDC_RADIO_MOVEWIND1))->GetCheck() == true)//默认移动到窗口外
	{
		static int loop=0;
		if(loop==0)
		{
			::GetWindowRect(m_winsetHwnd,&m_winsetRect);
			::SetWindowPos(m_winsetHwnd,HWND_TOP//
							,7000,7100,0,0,
							SWP_NOSIZE);//SWP_NOSIZE忽略dx,dy
			loop=1;
		}
		else
		{
			if(((CButton *)this->GetDlgItem(IDC_CHECK_EXTRASET))->GetCheck() == true)//移动后在调整窗口其他选项
			{
				::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
								,m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOSIZE | SWP_NOACTIVATE);//SWP_NOSIZE忽略dx,dy
				OnBnClickedButtonSetwind();
			}
			else
			{
				::SetFocus(m_winsetHwnd);
				::SetWindowPos(m_winsetHwnd,HWND_TOP,//必须两次调用才行
								m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOACTIVATE |SWP_NOZORDER );
				::SetWindowPos(m_winsetHwnd,HWND_TOP,
								m_winsetRect.top,m_winsetRect.left,m_winsetRect.Width(),m_winsetRect.Height()
								,SWP_NOACTIVATE |SWP_NOZORDER );//SWP_NOZORDER：保持窗口在列表的当前位置（忽略hWndInsertAfter） 
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
		if(((CButton *)this->GetDlgItem(IDC_CHECK_EXTRASET))->GetCheck() == true)//移动后在调整窗口其他选项
		{
			::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
						,i_movex,i_movey,0,0,
						SWP_NOSIZE | SWP_NOACTIVATE);//SWP_NOSIZE忽略dx,dy
			OnBnClickedButtonSetwind();
		}
		else
		{
			::SetWindowPos(m_winsetHwnd,HWND_TOP//
						,i_movex,i_movey,0,0,
						SWP_NOSIZE);//SWP_NOSIZE忽略dx,dy
			OnBnClickedButtonSetwind();
			
		}
	}
}


void CwindsetDlg::OnBnClickedRadioMovewind1()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *tEdit1,*tEdit2;
	tEdit1=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX);
	tEdit2=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY);
	tEdit1->EnableWindow(false);
	tEdit2->EnableWindow(false);
}


void CwindsetDlg::OnBnClickedRadioMovewind2()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *tEdit1,*tEdit2;
	tEdit1=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDX);
	tEdit2=(CEdit *)this->GetDlgItem(IDC_EDIT_MOVEWINDY);
	tEdit1->EnableWindow(true);
	tEdit2->EnableWindow(true);
}


void CwindsetDlg::OnBnClickedButtonHidewind()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetWindowPos(m_winsetHwnd,HWND_BOTTOM//
					,0,0,0,0,
					SWP_NOACTIVATE |SWP_NOSIZE | SWP_NOMOVE | SWP_HIDEWINDOW);//SWP_NOSIZE忽略dx,dy
}


void CwindsetDlg::OnBnClickedButtonShowwind()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetWindowPos(m_winsetHwnd,HWND_BOTTOM,
					0,0,0,0
					,SWP_NOACTIVATE  | SWP_NOSIZE | SWP_NOMOVE |SWP_SHOWWINDOW);//SWP_NOZORDER：保持窗口在列表的当前位置（忽略hWndInsertAfter） 
}


void CwindsetDlg::OnBnClickedButtonActivewind()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetWindowPos(m_winsetHwnd,HWND_TOP,
					0,0,0,0
					, SWP_NOSIZE | SWP_NOMOVE |SWP_SHOWWINDOW);//SWP_NOZORDER：保持窗口在列表的当前位置（忽略hWndInsertAfter） 
}


void CwindsetDlg::OnBnClickedButtonAlwaystop()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetWindowPos(m_winsetHwnd,HWND_TOPMOST//
					,0,0,0,0,
					 SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);//SWP_NOSIZE忽略dx,dy
}


void CwindsetDlg::OnBnClickedButtonAlwaystopoff()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetWindowPos(m_winsetHwnd,HWND_NOTOPMOST,
					0,0,0,0,
					SWP_NOACTIVATE| SWP_NOSIZE | SWP_NOMOVE);//SWP_NOZORDER：保持窗口在列表的当前位置（忽略hWndInsertAfter） 
}


void CwindsetDlg::OnBnClickedButtonShowminimized()
{
	// TODO: 在此添加控件通知处理程序代码
	::ShowWindow(m_winsetHwnd,SW_SHOWMINIMIZED);
}


void CwindsetDlg::OnBnClickedButtonShowmaximized()
{
	// TODO: 在此添加控件通知处理程序代码
	::ShowWindow(m_winsetHwnd,SW_SHOWMAXIMIZED);
}


void CwindsetDlg::OnBnClickedButtonShownormal()
{
	// TODO: 在此添加控件通知处理程序代码
	::ShowWindow(m_winsetHwnd,SW_SHOWNORMAL);
}


void CwindsetDlg::OnBnClickedButtonWindstyle()
{
	// TODO: 在此添加控件通知处理程序代码
	static int loop=0;

}


void CwindsetDlg::OnBnClickedButtonClosewind()
{
	// TODO: 在此添加控件通知处理程序代码

	::SendMessage(m_winsetHwnd,WM_CLOSE,0,0);//WM_DESTROY会出问题
}


void CwindsetDlg::OnBnClickedRadioCaptionon()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,0,WS_CAPTION,SWP_FRAMECHANGED);//加除标题
}


void CwindsetDlg::OnBnClickedRadioCaptionoff()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,WS_CAPTION,0,SWP_FRAMECHANGED);//去除标题
}


void CwindsetDlg::OnBnClickedRadioMaxminboxon()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,0,WS_SYSMENU,SWP_FRAMECHANGED);//去掉最大化、最小化之类的
}


void CwindsetDlg::OnBnClickedRadioMaxminboxoff()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,WS_SYSMENU,0,SWP_FRAMECHANGED);//加上最大化、最小化之类的
}


void CwindsetDlg::OnBnClickedRadioMenuon()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetMenu(m_winsetHwnd,m_winsetMenu);
}


void CwindsetDlg::OnBnClickedRadioMenuoff()
{
	// TODO: 在此添加控件通知处理程序代码
	::SetMenu(m_winsetHwnd,NULL);
}


void CwindsetDlg::OnBnClickedRadioSizechangeon()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,0,WS_SIZEBOX ,0);//禁止鼠标改变大小
}


void CwindsetDlg::OnBnClickedRadioSizechangeoff()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,WS_SIZEBOX ,0,0);//禁止鼠标改变大小
}


void CwindsetDlg::OnBnClickedRadioBoderon()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,0,WS_BORDER,SWP_FRAMECHANGED);
}


void CwindsetDlg::OnBnClickedRadioBoderoff()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,WS_BORDER,0,SWP_FRAMECHANGED);
}


void CwindsetDlg::OnBnClickedRadioEnablewind()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,WS_DISABLED,0,0);
}


void CwindsetDlg::OnBnClickedRadioDisablewind()
{
	// TODO: 在此添加控件通知处理程序代码
	ModifyStyle(m_winsetHwnd,0,WS_DISABLED,0);
}


void CwindsetDlg::OnBnClickedButtonForseclosewind()//强制结束进程
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD dwThreadId,dwProcessId;
	HANDLE hProcess;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	hProcess = OpenProcess(PROCESS_TERMINATE,FALSE,dwProcessId);
	if(hProcess==NULL) return;
	TerminateProcess(hProcess,NULL);
}


void CwindsetDlg::OnBnClickedButtonSuspendwind()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!IsWindow(m_winsetHwnd)) return;
	DWORD dwThreadId,dwProcessId;
	HANDLE hProcess;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	SuspendTask(dwProcessId);
}


void CwindsetDlg::OnBnClickedButtonResumewind()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!IsWindow(m_winsetHwnd)) return;
	DWORD dwThreadId,dwProcessId;
	dwThreadId = GetWindowThreadProcessId(m_winsetHwnd,&dwProcessId);
	ResumeTask(dwProcessId);
}


void CwindsetDlg::OnBnClickedCheckChangesize()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CButton *pButton;

	//改变尺寸
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
						SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);//SWP_NOMOVE忽略x,y
	}

	//设置窗口风格
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_GWLSTYLE))->GetCheck() == 1 )
	{
		long windlong=0;
		for(int i=0;windlongbox[i].id!=0 || windlongbox[i].value!="";i++)
		{
			if(m_winsetGWL_STYLE.GetCheck(i)!=0) windlong |=windlongbox[i].id;
		}
		::SetWindowLong(m_winsetHwnd,GWL_STYLE,windlong);
		::SetWindowPos(m_winsetHwnd,HWND_BOTTOM,0,0,0,0,
						SWP_NOACTIVATE|SWP_NOSIZE | SWP_NOMOVE |SWP_NOZORDER |SWP_FRAMECHANGED );//目的是刷新窗口
	}

	//隐藏窗口
	if( ((CButton *)this->GetDlgItem(IDC_CHECK_HIDEWINDOW))->GetCheck() == 1 ) 
	{
		::ShowWindow(m_winsetHwnd,SW_HIDE);
		return;
	}
	else
	{
		OnBnClickedButtonShowwind();
	}

	//激活窗口
	pButton=(CButton *)this->GetDlgItem(IDC_CHECK_ACTIVEWINDOW);
	if( pButton->GetCheck() == 1 && pButton->IsWindowEnabled()) 
	{
		OnBnClickedButtonActivewind();
	}
	else
	{
		
	}

	//始终置顶
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

	//放到底层
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
					,SWP_NOACTIVATE  | SWP_NOSIZE | SWP_NOMOVE |SWP_NOOWNERZORDER);//SWP_NOZORDER：保持窗口在列表的当前位置（忽略hWndInsertAfter)

	}
}

void CwindsetDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();//屏蔽使得按回车键不会退出
}

void CwindsetDlg::OnBnClickedCheckHidewindow()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CwindsetDlg::OnBnClickedButtonTrarecv()
{

	// TODO: 在此添加控件通知处理程序代码
	SetWindowLong(m_winsetHwnd,GWL_EXSTYLE,m_wlongGWL_EXSTYLE);
}

void CwindsetDlg::OnBnClickedButtonSelf()
{
	// TODO: 在此添加控件通知处理程序代码
	m_winsetHwnd=this->GetSafeHwnd();
	if( ((CButton *)this->GetDlgItem(IDC_RADIO_HEX))->GetCheck() == true)//16进制
		OnBnClickedRadioHex();
	else OnBnClickedRadioDec();
	OnEnChangeEditHandel();
	CAboutDlg c;
	c.DoModal();
}
