#pragma once
#include "afxwin.h"
#include "PageBase.h"


// CPageCircle 对话框

class CPageCircle : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageCircle)

public:
	CPageCircle(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageCircle();

// 对话框数据
	enum { IDD = IDD_PAGE_CIRCLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_dCircleD;

	afx_msg void OnBnClickedButtonCalCircle();
	afx_msg void OnBnClickedButtonRefreshCircle();
	//void AddPitcure();
	CStatic m_PictureCircle;
};
