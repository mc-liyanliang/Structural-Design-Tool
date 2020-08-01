// PageH.cpp : 实现文件
//

#include "stdafx.h"
#include "SecCharact.h"
#include "PageH.h"
#include "afxdialogex.h"
#include "Hshape.h"


// CPageH 对话框

IMPLEMENT_DYNAMIC(CPageH, CDialogEx)

CPageH::CPageH(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPageH::IDD, pParent)
	, m_dHshapeH(0)
	, m_dHshapeB(0)
	, m_dHshapet(0)
	, m_dHshapetw(0)
{

}

CPageH::~CPageH()
{
}

void CPageH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dHshapeH);
	DDX_Text(pDX, IDC_EDIT2, m_dHshapeB);
	DDX_Text(pDX, IDC_EDIT3, m_dHshapet);
	DDX_Text(pDX, IDC_EDIT4, m_dHshapetw);
	DDX_Text(pDX, IDC_EDIT5, m_dXc);
	DDX_Text(pDX, IDC_EDIT7, m_dYc);
	DDX_Text(pDX, IDC_EDIT8, m_dIxx);
	DDX_Text(pDX, IDC_EDIT9, m_dIyy);
	DDX_Text(pDX, IDC_EDIT10, m_dArea);
}


BEGIN_MESSAGE_MAP(CPageH, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CAL_HSHAPE, &CPageH::OnBnClickedButtonCalHshape)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH_HSHAPE, &CPageH::OnBnClickedButtonRefreshHshape)
END_MESSAGE_MAP()


// CPageH 消息处理程序


void CPageH::OnBnClickedButtonCalHshape()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CHshape hshape(m_dHshapeH,m_dHshapeB,m_dHshapet,m_dHshapetw);
	m_dXc   = hshape.GetCenCoordXc();
	m_dYc   = hshape.GetCenCoordYc();
	m_dIxx  = hshape.GetMomentInertiaIxx();
	m_dIyy  = hshape.GetMomentInertiaIyy();
	m_dArea = hshape.GetArea();
	UpdateData(FALSE);
}


void CPageH::OnBnClickedButtonRefreshHshape()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_dHshapeH    = 0;
	m_dHshapeB    = 0;
	m_dHshapet    = 0;
	m_dHshapetw   = 0;
    RefreshData();
	UpdateData(FALSE);
}
