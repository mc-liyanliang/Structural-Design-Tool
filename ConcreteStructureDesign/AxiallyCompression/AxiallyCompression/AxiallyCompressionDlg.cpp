
// AxiallyCompressionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AxiallyCompression.h"
#include "AxiallyCompressionDlg.h"
#include "afxdialogex.h"
#include "Tool.h"
#include "AxialCompressionData.h"

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


// CAxiallyCompressionDlg 对话框



CAxiallyCompressionDlg::CAxiallyCompressionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAxiallyCompressionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pData = new CAxialCompressionData;
}

void CAxiallyCompressionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SEC_TYPE, m_ComboSecType);
	DDX_Control(pDX, IDC_EDIT_HEIGHT, m_EditHeight);
	DDX_Control(pDX, IDC_EDIT_WIDTH, m_EditWidth);
	DDX_Control(pDX, IDC_EDIT_LENGTH, m_EditLength);
	DDX_Control(pDX, IDC_EDIT_DIAMETER, m_EditDiameter);
	DDX_Control(pDX, IDC_EDIT_AXIAL_DESIGN_VALUE, m_EditAxialDisignValue);
	DDX_Control(pDX, IDC_EDIT_STABILITY_FACTOR, m_EditStabilityFactor);
	DDX_Control(pDX, IDC_COMBO_CONCRETE_GRADE, m_ComboConcreteGrade);
	DDX_Control(pDX, IDC_COMBO_MAINBAR_GRADE, m_ComboMainbarGrade);
	DDX_Control(pDX, IDC_CHECK_SPIRALRABAR, m_CheckSpiralRebar);
	DDX_Control(pDX, IDC_COMBO_SPIRALREBAR_DIA, m_ComboSpiralStirrupDia);
	DDX_Control(pDX, IDC_EDIT_SPIRAL_STIRRUP_SPACE, m_EditSpiralStirrupSpace);
	DDX_Control(pDX, IDC_COMBO_SPIRALREBAR_GRADE, m_ComboSpiralStirrupGrade);
	DDX_Control(pDX, IDC_EDIT_CORESECTION_DIA, m_EditCoreSecDia);
	DDX_Control(pDX, IDC_EDIT_REBARMAKE, m_EditMainbarMake);
	DDX_Control(pDX, IDC_EDIT_SPIRAL_STIRRUP, m_EditSpiralStrrupMake);
	DDX_Control(pDX, IDC_EDIT_REAL_REBARAREA, m_EditRealMainbarArea);
}

BEGIN_MESSAGE_MAP(CAxiallyCompressionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CAxiallyCompressionDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CAxiallyCompressionDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// CAxiallyCompressionDlg 消息处理程序

BOOL CAxiallyCompressionDlg::OnInitDialog()
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
	InitComboList();
	Data2Dlg();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAxiallyCompressionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAxiallyCompressionDlg::OnPaint()
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
HCURSOR CAxiallyCompressionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAxiallyCompressionDlg::InitComboList()
{
	m_Tool.InitSecTypeComb(m_ComboSecType);

	m_Tool.InitConcreteGradeComb(m_ComboConcreteGrade);

	m_Tool.InitRebarDiameterComb(m_ComboSpiralStirrupDia);

	m_Tool.InitRebarGradeComb(m_ComboMainbarGrade);
	m_Tool.InitRebarGradeComb(m_ComboSpiralStirrupGrade);
}

void CAxiallyCompressionDlg::Data2Dlg()
{
	m_ComboSecType.SetCurSel(m_pData->GetSecType());

	CString str;
	str.Format(_T("%.0f"), m_pData->GetHeight());
	m_EditHeight.SetWindowText(str);

	str.Format(_T("%.0f"), m_pData->GetWidth());
	m_EditWidth.SetWindowText(str);

	str.Format(_T("%.0f"), m_pData->GetLength());
	m_EditLength.SetWindowText(str);

	str.Format(_T("%.0f"), m_pData->GetDiameter());
	m_EditDiameter.SetWindowText(str);

	str.Format(_T("%.0f"), m_pData->GetAxialDesignValue());
	m_EditAxialDisignValue.SetWindowText(str);

	str.Format(_T("%.1f"), m_pData->GetStabilityFactor());
	m_EditStabilityFactor.SetWindowText(str);

	m_ComboConcreteGrade.SetCurSel(m_Tool.GetComboIndexByStr(m_ComboConcreteGrade, m_pData->GetConcreteGrade()));

    m_ComboMainbarGrade.SetCurSel(m_Tool.GetComboIndexByStr(m_ComboMainbarGrade, m_pData->GetMainbarGrade()));

	m_CheckSpiralRebar.SetCheck(m_pData->bSpiralStirrup());

	m_ComboSpiralStirrupDia.SetCurSel(m_Tool.GetComboIndexByStr(m_ComboSpiralStirrupDia, m_pData->GetSpiralStirrupDia()));

	str.Format(_T("%.0f"), m_pData->GetSpiralStirrupSpace());
	m_EditSpiralStirrupSpace.SetWindowText(str);

	m_ComboSpiralStirrupGrade.SetCurSel(m_Tool.GetComboIndexByStr(m_ComboSpiralStirrupGrade, m_pData->GetSpiralStirrupGrade()));

	str.Format(_T("%.0f"), m_pData->GetCoreSecDiameter());
	m_EditCoreSecDia.SetWindowText(str);

	UpdateData(FALSE);
}

BOOL CAxiallyCompressionDlg::Dlg2Data()
{
	UpdateData(TRUE);

	m_pData->SetSecType(m_ComboSecType.GetCurSel());

	CString str;
	m_EditHeight.GetWindowText(str);
	m_pData->SetHeight(_ttof(str));

	m_EditWidth.GetWindowText(str);
	m_pData->SetWidth(_ttof(str));

	m_EditLength.GetWindowText(str);
	m_pData->SetLength(_ttof(str));

	m_EditDiameter.GetWindowText(str);
	m_pData->SetDiameter(_ttof(str));

	m_EditAxialDisignValue.GetWindowText(str);
	m_pData->SetAxialDesignValue(_ttof(str));

	m_EditStabilityFactor.GetWindowText(str);
	m_pData->SetStabilityFactor(_ttof(str));

	m_ComboConcreteGrade.GetLBText(m_ComboConcreteGrade.GetCurSel(), str);
	m_pData->SetConcreteGrade(str);

	m_ComboMainbarGrade.GetLBText(m_ComboMainbarGrade.GetCurSel(), str);
	m_pData->SetMainbarGrade(str);
	
	m_pData->SetbSpiralStirrup(m_CheckSpiralRebar.GetCheck());

	m_ComboSpiralStirrupDia.GetLBText(m_ComboSpiralStirrupDia.GetCurSel(), str);
	m_pData->SetSpiralStirrupDia(str);

	m_EditSpiralStirrupSpace.GetWindowText(str);
	m_pData->SetSpiralStirrupSpace(_ttof(str));

	m_ComboSpiralStirrupGrade.GetLBText(m_ComboSpiralStirrupGrade.GetCurSel(), str);
	m_pData->SetConcreteGrade(str);

	m_EditCoreSecDia.GetWindowText(str);
	m_pData->SetCoreSecDiameter(_ttof(str));

	return TRUE;
}

void CAxiallyCompressionDlg::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类
	CDialogEx::PostNcDestroy();
	if (m_pData != nullptr)
	{
		delete m_pData;
		m_pData = nullptr;
	}
}


void CAxiallyCompressionDlg::OnBnClickedButtonCalculate()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg2Data();
	double dConcreteFc = m_Tool.GetConcreteFcByGrade(m_pData->GetConcreteGrade());
	int nRebarFy = m_Tool.GetRebarFyByGrade(m_pData->GetMainbarGrade());
	double dRebarArea = (m_pData->GetAxialDesignValue() * 1000.0 - 0.9 * m_pData->GetStabilityFactor() * dConcreteFc * m_pData->GetHeight() * m_pData->GetWidth()) / (0.9 * m_pData->GetStabilityFactor() * nRebarFy);
}


void CAxiallyCompressionDlg::OnBnClickedButtonReset()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pData->Init();
	Data2Dlg();
}
