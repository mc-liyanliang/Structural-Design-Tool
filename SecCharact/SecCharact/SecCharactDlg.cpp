
// SecCharactDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SecCharact.h"
#include "SecCharactDlg.h"
#include "afxdialogex.h"
#include "PageCircle.h"
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


// CSecCharactDlg �Ի���



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


// CSecCharactDlg ��Ϣ�������

BOOL CSecCharactDlg::OnInitDialog()
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
	m_tabCtrl.InsertItem(0,_T("Բ��"));
	m_tabCtrl.InsertItem(1,_T("����"));
	m_tabCtrl.InsertItem(2,_T("����"));
	m_tabCtrl.InsertItem(3,_T("H��"));

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

	//��ʾ��ʼҳ��
	m_pDialog[0]->ShowWindow(SW_SHOW);
	m_pDialog[1]->ShowWindow(SW_HIDE);
	m_pDialog[2]->ShowWindow(SW_HIDE);
	m_pDialog[3]->ShowWindow(SW_HIDE);

	//���浱ǰѡ��
	m_nCurSelTab = 0;

	
	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSecCharactDlg::OnPaint()
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

	//UpdateWindow();
	//CPageCircle PageCircle;
	//PageCircle.AddPitcure();
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSecCharactDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSecCharactDlg::OnTcnSelchangeTabSection(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pDialog[m_nCurSelTab]->ShowWindow(SW_HIDE);
	m_nCurSelTab = m_tabCtrl.GetCurSel();
	if(m_pDialog[m_nCurSelTab])
	{
		m_pDialog[m_nCurSelTab]->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}
