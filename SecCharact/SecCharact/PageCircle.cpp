// PageCircle.cpp : 实现文件
//

#include "stdafx.h"
#include "SecCharact.h"
#include "PageCircle.h"
#include "afxdialogex.h"
#include "Circle.h"


// CPageCircle 对话框

IMPLEMENT_DYNAMIC(CPageCircle, CDialogEx)

CPageCircle::CPageCircle(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPageCircle::IDD, pParent)
	, m_dCircleD(0)
{

}

CPageCircle::~CPageCircle()
{
}

void CPageCircle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CIRCLED, m_dCircleD);
	DDX_Text(pDX, IDC_EDIT_CIRCLEXC, m_dXc);
	DDX_Text(pDX, IDC_EDIT_CIRCLEYC, m_dYc);
	DDX_Text(pDX, IDC_EDIT_CIRCLEIXX, m_dIxx);
	DDX_Text(pDX, IDC_EDIT_CIRCLEIYY, m_dIyy);
	DDX_Text(pDX, IDC_EDIT_CIRCLEAREA, m_dArea);
	DDX_Control(pDX, IDC_STATIC_PICTURE_CIRCLE, m_PictureCircle);
}


BEGIN_MESSAGE_MAP(CPageCircle, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPageCircle::OnBnClickedButtonCalCircle)
	ON_BN_CLICKED(IDC_BUTTON2, &CPageCircle::OnBnClickedButtonRefreshCircle)
END_MESSAGE_MAP()


// CPageCircle 消息处理程序


void CPageCircle::OnBnClickedButtonCalCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); 
	CCircle circle(m_dCircleD);
	m_dXc   = circle.GetCenCoordXc();
	m_dYc   = circle.GetCenCoordYc();
	m_dArea = circle.GetArea();
	m_dIxx  = circle.GetMomentInertiaIxx();
	m_dIyy  = circle.GetMomentInertiaIyy();
	UpdateData(FALSE); 
}


void CPageCircle::OnBnClickedButtonRefreshCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); 
	m_dCircleD    = 0;
	RefreshData();
	UpdateData(FALSE); 
}
/*
void CPageCircle::AddPitcure()
{
	CBitmap bitmap;  
	//加载指定位图资源 Bmp图片ID  
	bitmap.LoadBitmap(IDB_BITMAP1);    
	//获取对话框上的句柄 图片控件ID  
	CStatic *p=(CStatic *)GetDlgItem(IDC_STATIC_PICTURE_CIRCLE);    
	//设置静态控件窗口风格为位图居中显示   
	p->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);   
	//将图片设置到Picture控件上  
	p->SetBitmap(bitmap);   

	BITMAP bmpInfo; 
	bitmap.GetBitmap(&bmpInfo); 
	CDC dcMemory; 
	CDC* pDC=GetDlgItem(IDC_STATIC_PICTURE_CIRCLE)->GetDC(); 
	dcMemory.CreateCompatibleDC(pDC); 
	CBitmap* pOldBitmap = dcMemory.SelectObject(&bitmap); 
	CRect rect; 
	m_PictureCircle.GetClientRect(&rect);
	int nX = rect.left + (rect.Width() - bmpInfo.bmWidth) / 2; 
	int nY = rect.top + (rect.Height() - bmpInfo.bmHeight) / 2; 
	//pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);  
	pDC->SetStretchBltMode(COLORONCOLOR); 
	pDC->StretchBlt(0, 0,rect.Width()+700,rect.Height()+700,&dcMemory,0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,SRCCOPY); 
	dcMemory.SelectObject(pOldBitmap); 
	ReleaseDC(pDC); 
}
*/
