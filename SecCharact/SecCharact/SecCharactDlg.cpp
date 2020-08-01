
// SecCharactDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SecCharact.h"
#include "SecCharactDlg.h"
#include "afxdialogex.h"
#include "PageCircle.h"
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


// CSecCharactDlg 对话框



CSecCharactDlg::CSecCharactDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecCharactDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSecCharactDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SECTION, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CSecCharactDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SECTION, &CSecCharactDlg::OnTcnSelchangeTabSection)
END_MESSAGE_MAP()


// CSecCharactDlg 消息处理程序

BOOL CSecCharactDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tabCtrl.InsertItem(0,_T("圆形"));
	m_tabCtrl.InsertItem(1,_T("环形"));
	m_tabCtrl.InsertItem(2,_T("矩形"));
	m_tabCtrl.InsertItem(3,_T("H形"));

	m_tabCtrl.SetPadding(19);
	m_tabCtrl.SetMinTabWidth(50);
	m_tabCtrl.SetItemSize(CSize(50,25));

	m_PageCircle.Create(IDD_PAGE_CIRCLE,&m_tabCtrl);
	m_PageRing.Create(IDD_PAGE_RING,&m_tabCtrl);
	m_PageRect.Create(IDD_PAGE_RECT,&m_tabCtrl);
	m_PageH.Create(IDD_PAGE_H,&m_tabCtrl);

	CRect rc;
	m_tabCtrl.GetClientRect(rc);
	rc.top += 25;

	m_PageCircle.MoveWindow(&rc);
	m_PageRing.MoveWindow(&rc);
	m_PageRect.MoveWindow(&rc);
	m_PageH.MoveWindow(&rc);

	m_pDialog[0]=&m_PageCircle;
	m_pDialog[1]=&m_PageRing;
	m_pDialog[2]=&m_PageRect;
	m_pDialog[3]=&m_PageH;

	//显示初始页面
	m_pDialog[0]->ShowWindow(SW_SHOW);
	m_pDialog[1]->ShowWindow(SW_HIDE);
	m_pDialog[2]->ShowWindow(SW_HIDE);
	m_pDialog[3]->ShowWindow(SW_HIDE);

	//保存当前选择
	m_nCurSelTab = 0;

	
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSecCharactDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSecCharactDlg::OnPaint()
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

	//UpdateWindow();
	//CPageCircle PageCircle;
	//PageCircle.AddPitcure();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSecCharactDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSecCharactDlg::OnTcnSelchangeTabSection(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDialog[m_nCurSelTab]->ShowWindow(SW_HIDE);
	m_nCurSelTab = m_tabCtrl.GetCurSel();
	if(m_pDialog[m_nCurSelTab])
	{
		m_pDialog[m_nCurSelTab]->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}
