
// SecCharactDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "PageCircle.h"
#include "PageRing.h"
#include "PageRect.h"
#include "PageH.h"


// CSecCharactDlg 对话框
class CSecCharactDlg : public CDialogEx
{
// 构造
public:
	CSecCharactDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SECCHARACT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl    m_tabCtrl;
	CPageCircle m_PageCircle;
	CPageRing   m_PageRing;
	CPageRect   m_PageRect;
	CPageH      m_PageH;
#define  MAX_DLG_PAGE 5
	CDialog     *m_pDialog[MAX_DLG_PAGE];
	int         m_nCurSelTab;
	afx_msg void OnTcnSelchangeTabSection(NMHDR *pNMHDR, LRESULT *pResult);
};
