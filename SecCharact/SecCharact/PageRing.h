#pragma once
#include "PageBase.h"

// CPageRing �Ի���

class CPageRing : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageRing)

public:
	CPageRing(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageRing();

// �Ի�������
	enum { IDD = IDD_PAGE_RING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_dRingD;
	double m_dRingd;

	afx_msg void OnBnClickedRefresh2();
	afx_msg void OnBnClickedButtonRing();
};
