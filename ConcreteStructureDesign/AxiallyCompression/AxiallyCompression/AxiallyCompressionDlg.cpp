
// AxiallyCompressionDlg.cpp : ʵ���ļ�
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


// CAxiallyCompressionDlg �Ի���



CAxiallyCompressionDlg::CAxiallyCompressionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAxiallyCompressionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	DDX_Control(pDX, IDC_COMBO_CONCRETE_GRADE, m_ComboComcreteGrade);
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
END_MESSAGE_MAP()


// CAxiallyCompressionDlg ��Ϣ�������

BOOL CAxiallyCompressionDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitComboList();


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAxiallyCompressionDlg::OnPaint()
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
HCURSOR CAxiallyCompressionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAxiallyCompressionDlg::InitComboList()
{
	CTool::InitRebarDiameterComb(m_ComboSpiralStirrupDia);
	CTool::InitSecTypeComb(m_ComboSecType);
}



