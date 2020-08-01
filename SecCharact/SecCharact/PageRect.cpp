// PageRect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SecCharact.h"
#include "PageRect.h"
#include "afxdialogex.h"
#include "Rectangle.h"


// CPageRect �Ի���

IMPLEMENT_DYNAMIC(CPageRect, CDialogEx)

CPageRect::CPageRect(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPageRect::IDD, pParent)
	, m_dRectH(0)
	, m_dRectB(0)
{

}

CPageRect::~CPageRect()
{
}

void CPageRect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dRectH);
	DDX_Text(pDX, IDC_EDIT2, m_dRectB);
	DDX_Text(pDX, IDC_EDIT4, m_dXc);
	DDX_Text(pDX, IDC_EDIT5, m_dYc);
	DDX_Text(pDX, IDC_EDIT9, m_dIxx);
	DDX_Text(pDX, IDC_EDIT10, m_dIyy);
	DDX_Text(pDX, IDC_EDIT7, m_dArea);
}


BEGIN_MESSAGE_MAP(CPageRect, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CAL_RECT, &CPageRect::OnBnClickedButtonCalRect)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH_RECT, &CPageRect::OnBnClickedButtonRefreshRect)
END_MESSAGE_MAP()


// CPageRect ��Ϣ�������


void CPageRect::OnBnClickedButtonCalRect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CRectangle rectangle(m_dRectH,m_dRectB);
	m_dXc   = rectangle.GetCenCoordXc();
	m_dYc   = rectangle.GetCenCoordYc();
	m_dIxx  = rectangle.GetMomentInertiaIxx();
	m_dIyy  = rectangle.GetMomentInertiaIyy();
	m_dArea = rectangle.GetArea();
	UpdateData(FALSE);
}


void CPageRect::OnBnClickedButtonRefreshRect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_dRectH		=	0;
	m_dRectB		=	0;
    RefreshData();
	UpdateData(FALSE);
}
