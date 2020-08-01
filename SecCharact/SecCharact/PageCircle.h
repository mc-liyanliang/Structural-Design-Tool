#pragma once
#include "afxwin.h"
#include "PageBase.h"


// CPageCircle �Ի���

class CPageCircle : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageCircle)

public:
	CPageCircle(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageCircle();

// �Ի�������
	enum { IDD = IDD_PAGE_CIRCLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_dCircleD;

	afx_msg void OnBnClickedButtonCalCircle();
	afx_msg void OnBnClickedButtonRefreshCircle();
	//void AddPitcure();
	CStatic m_PictureCircle;
};
