
// SecCharactDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "PageCircle.h"
#include "PageRing.h"
#include "PageRect.h"
#include "PageH.h"


// CSecCharactDlg �Ի���
class CSecCharactDlg : public CDialogEx
{
// ����
public:
	CSecCharactDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SECCHARACT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
