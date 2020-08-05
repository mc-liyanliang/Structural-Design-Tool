#pragma once
#include "MaterialDB.h"
class CTool
{
public:
	CTool(void);
	~CTool(void);
public:
	enum EN_SEC_TYPE
	{
		en_Rect,
		en_Circle,
	};
public:
	void InitRebarDiameterComb(OUT CComboBox& ComboRebarDia);
	void InitRebarGradeComb(OUT CComboBox& ComboRebarGrade);
	void InitConcreteGradeComb(OUT CComboBox& ComboRebarDia);
	double GetConcreteFcByGrade(const CString& strConcreteGrade);
	int GetRebarFyByGrade(const CString& strRebarGrade);
	CString GetSecTypeNameByIndex(UINT enSecType);
	void InitSecTypeComb(CComboBox& Combo);
	int GetComboIndexByStr(IN const CComboBox &Comb,IN const CString& str);
private:
	CMaterialDB material;
};

