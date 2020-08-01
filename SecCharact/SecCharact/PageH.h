#pragma once
#include "PageBase.h"

// CPageH 对话框

class CPageH : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageH)

public:
	CPageH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPageH();

// 对话框数据
	enum { IDD = IDD_PAGE_H };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_dHshapeH;
	double m_dHshapeB;
	double m_dHshapet;
	double m_dHshapetw;
	afx_msg void OnBnClickedButtonCalHshape();
	afx_msg void OnBnClickedButtonRefreshHshape();
};
