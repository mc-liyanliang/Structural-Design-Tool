
// AxiallyCompressionDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Tool.h"

class CAxialCompressionData;
// CAxiallyCompressionDlg 对话框
class CAxiallyCompressionDlg : public CDialogEx
{
// 构造
public:
	CAxiallyCompressionDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_AXIALLYCOMPRESSION_DIALOG };

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
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonReset();
private:
	void InitComboList();
	void Data2Dlg();
	BOOL Dlg2Data();
private:
	CTool m_Tool;
	CAxialCompressionData* m_pData;
private:
	CComboBox m_ComboSecType;
	CEdit m_EditHeight;
	CEdit m_EditWidth;
	CEdit m_EditLength;
	CEdit m_EditDiameter;
	CEdit m_EditAxialDisignValue;
	CEdit m_EditStabilityFactor;
	CComboBox m_ComboConcreteGrade;
	CComboBox m_ComboMainbarGrade;
	CButton m_CheckSpiralRebar;
	CComboBox m_ComboSpiralStirrupDia;
	CEdit m_EditSpiralStirrupSpace;
	CComboBox m_ComboSpiralStirrupGrade;
	CEdit m_EditCoreSecDia;
	CEdit m_EditMainbarMake;
	CEdit m_EditSpiralStrrupMake;
	CEdit m_EditRealMainbarArea;
	virtual void PostNcDestroy();
};
