#include "stdafx.h"
#include "Tool.h"
#include "MaterialDB.h"


CTool::CTool(void)
{
}


CTool::~CTool(void)
{
}


void CTool::InitRebarDiameterComb(OUT CComboBox& ComboRebarDia)
{
	ComboRebarDia.ResetContent();
	std::vector<CString> vctRebarDiaList = material.GetRebarDiaList();
	for (size_t i = 0; i < vctRebarDiaList.size(); i++)
	{
		ComboRebarDia.AddString(vctRebarDiaList[i]);
	}
	ComboRebarDia.SetCurSel(0);
}

void CTool::InitRebarGradeComb(OUT CComboBox& ComboRebarGrade)
{
	ComboRebarGrade.ResetContent();
	std::vector<CString> vctRebarGradeList = material.GetRebarGradeList();
	for (size_t i = 0; i < vctRebarGradeList.size(); i++)
	{
		ComboRebarGrade.AddString(vctRebarGradeList[i]);
	}
	ComboRebarGrade.SetCurSel(0);
}


void CTool::InitConcreteGradeComb(OUT CComboBox& ComboRebarDia)
{
	ComboRebarDia.ResetContent();
	std::vector<T_CONCRETE_GRADE> vctConcreteData = material.GetConcreteData();
	for (size_t i = 0; i < vctConcreteData.size(); i++)
	{
		const T_CONCRETE_GRADE& gradeData = vctConcreteData[i];
		ComboRebarDia.AddString(gradeData.GetConcreteGrade());
	}
	ComboRebarDia.SetCurSel(0);
}

double CTool::GetConcreteFcByGrade(const CString& strConcreteGrade)
{
	std::vector<T_CONCRETE_GRADE> vctConcreteData = material.GetConcreteData();
	for (size_t i = 0; i < vctConcreteData.size(); i++)
	{
		const T_CONCRETE_GRADE& gradeData = vctConcreteData[i];
		if (strConcreteGrade.Compare(gradeData.GetConcreteGrade()) == 0)
		{
			return gradeData.GetConcreteGradeFc();
		}
	}

	ASSERT(0);
	return 0;
}

int CTool::GetRebarFyByGrade(const CString& strRebarGrade)
{
	std::vector<T_REBAR_GRADE> vctRebarData = material.GetRebarData();
	for (size_t i = 0; i < vctRebarData.size(); i++)
	{
		const T_REBAR_GRADE& rebarData = vctRebarData[i];
		if (strRebarGrade.Compare(rebarData.GetRebarGrade()) == 0)
		{
			return rebarData.GetRebarFy();
		}
	}

	ASSERT(0);
	return 0;
}

CString CTool::GetSecTypeNameByIndex(UINT enSecType)
{
	CString str = _T("¾ØÐÎ");
	if (enSecType == en_Rect)
	{
		str = _T("¾ØÐÎ");
	}
	else if(enSecType == en_Circle)
	{
		str = _T("Ô²ÐÎ");
	}
	else
	{
		ASSERT(0);
	}
	return str;
}

void CTool::InitSecTypeComb(CComboBox& Combo)
{
	Combo.ResetContent();
	Combo.AddString(GetSecTypeNameByIndex(en_Rect));
	Combo.AddString(GetSecTypeNameByIndex(en_Circle));
	Combo.SetCurSel(0);
}

int CTool::GetComboIndexByStr(IN const CComboBox &Comb,IN const CString& str)
{
	CString strTmp;
	for (int nIndex = 0; nIndex < Comb.GetCount() ;nIndex++)
	{
		Comb.GetLBText(nIndex,strTmp);

		if (str == strTmp)
		{
			return nIndex;
		}
	}
	ASSERT(0);
	return 0;
}
