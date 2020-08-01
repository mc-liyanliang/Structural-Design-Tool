
// AxiallyCompressionDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CAxiallyCompressionDlg �Ի���
class CAxiallyCompressionDlg : public CDialogEx
{
// ����
public:
	CAxiallyCompressionDlg(CWnd* pParent = NULL);	// ��׼���캯��
private:
	CComboBox m_ComboSecType;
	CEdit m_EditHeight;
	CEdit m_EditWidth;
	CEdit m_EditLength;
	CEdit m_EditDiameter;
	CEdit m_EditAxialDisignValue;
	CEdit m_EditStabilityFactor;
	CComboBox m_ComboComcreteGrade;
	CComboBox m_ComboMainbarGrade;
	CButton m_CheckSpiralRebar;
	CComboBox m_ComboSpiralStirrupDia;
	CEdit m_EditSpiralStirrupSpace;
	CComboBox m_ComboSpiralStirrupGrade;
	CEdit m_EditCoreSecDia;
	CEdit m_EditMainbarMake;
	CEdit m_EditSpiralStrrupMake;
	CEdit m_EditRealMainbarArea;
// �Ի�������
	enum { IDD = IDD_AXIALLYCOMPRESSION_DIALOG };

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
private:
	void InitComboList();

};
