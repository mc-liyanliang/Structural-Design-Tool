#pragma once
#include "PageBase.h"

// CPageRect �Ի���

class CPageRect : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageRect)

public:
	CPageRect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageRect();

// �Ի�������
	enum { IDD = IDD_PAGE_RECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_dRectH;
	double m_dRectB;
	afx_msg void OnBnClickedButtonCalRect();
	afx_msg void OnBnClickedButtonRefreshRect();
};
