#pragma once
#include "PageBase.h"

// CPageRing 对话框

class CPageRing : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageRing)

public:
	CPageRing(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageRing();

// 对话框数据
	enum { IDD = IDD_PAGE_RING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_dRingD;
	double m_dRingd;

	afx_msg void OnBnClickedRefresh2();
	afx_msg void OnBnClickedButtonRing();
};
