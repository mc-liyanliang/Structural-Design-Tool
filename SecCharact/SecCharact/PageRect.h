#pragma once
#include "PageBase.h"

// CPageRect 对话框

class CPageRect : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageRect)

public:
	CPageRect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageRect();

// 对话框数据
	enum { IDD = IDD_PAGE_RECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_dRectH;
	double m_dRectB;
	afx_msg void OnBnClickedButtonCalRect();
	afx_msg void OnBnClickedButtonRefreshRect();
};
