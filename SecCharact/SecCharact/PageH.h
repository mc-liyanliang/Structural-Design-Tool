#pragma once
#include "PageBase.h"

// CPageH �Ի���

class CPageH : public CDialogEx,public CPageBase
{
	DECLARE_DYNAMIC(CPageH)

public:
	CPageH(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPageH();

// �Ի�������
	enum { IDD = IDD_PAGE_H };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_dHshapeH;
	double m_dHshapeB;
	double m_dHshapet;
	double m_dHshapetw;
	afx_msg void OnBnClickedButtonCalHshape();
	afx_msg void OnBnClickedButtonRefreshHshape();
};
