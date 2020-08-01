// PageRing.cpp : 实现文件
//

#include "stdafx.h"
#include "SecCharact.h"
#include "PageRing.h"
#include "afxdialogex.h"
#include "Ring.h"


// CPageRing 对话框

IMPLEMENT_DYNAMIC(CPageRing, CDialogEx)

CPageRing::CPageRing(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPageRing::IDD, pParent)
	, m_dRingD(0)
	, m_dRingd(0)
{

}

CPageRing::~CPageRing()
{
}

void CPageRing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dRingD);
	DDX_Text(pDX, IDC_EDIT2, m_dRingd);
	DDX_Text(pDX, IDC_EDIT3, m_dXc);
	DDX_Text(pDX, IDC_EDIT4, m_dYc);
	DDX_Text(pDX, IDC_EDIT5, m_dIxx);
	DDX_Text(pDX, IDC_EDIT7, m_dIyy);
	DDX_Text(pDX, IDC_EDIT8, m_dArea);
}


BEGIN_MESSAGE_MAP(CPageRing, CDialogEx)
	ON_BN_CLICKED(IDC_REFRESH2, &CPageRing::OnBnClickedRefresh2)
	ON_BN_CLICKED(IDC_BUTTON_RING, &CPageRing::OnBnClickedButtonRing)
END_MESSAGE_MAP()


// CPageRing 消息处理程序


void CPageRing::OnBnClickedRefresh2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_dRingD    =0;
	m_dRingd    =0;
    RefreshData();
	UpdateData(FALSE);
}


void CPageRing::OnBnClickedButtonRing()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
 	CRing ring(m_dRingD,m_dRingd);
	m_dXc   = ring.GetCenCoordXc();
	m_dYc   = ring.GetCenCoordYc();
	m_dIxx  = ring.GetMomentInertiaIxx();
	m_dIyy  = ring.GetMomentInertiaIyy();
	m_dArea = ring.GetArea();
	UpdateData(FALSE);
}
