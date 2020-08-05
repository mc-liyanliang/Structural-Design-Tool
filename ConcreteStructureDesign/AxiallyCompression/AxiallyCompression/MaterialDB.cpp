#include "stdafx.h"
#include "MaterialDB.h"
#include <wtypes.h>
#include <string.h>


CMaterialDB::CMaterialDB(void)
{
	InitRebarDiaList();
	InitConcreteData();
	InitRebarGradeList();
	InitRebarGradeData();
}


CMaterialDB::~CMaterialDB(void)
{
}


void CMaterialDB::InitRebarDiaList()
{
	const int rebarDiaCount = 16;
	CString arrRebarDia[rebarDiaCount] = { _T("d4"),  _T("d5"),  _T("d6"),  _T("d8"), _T("d10"), _T("d12"), _T("d14"), _T("d16"), _T("d18"), _T("d20"),  _T("d22"), _T("d25"), _T("d28"), _T("d32"), _T("d36"), _T("d40")};

	for(int i=0; i < rebarDiaCount; i++)  
	{
		m_vctRebarDia.push_back(arrRebarDia[i]);
	}
}

void CMaterialDB::InitConcreteData()
{
	const int nConcreteGradeCount = 14;
	CString arrConcreteGrade[nConcreteGradeCount] ={_T("C15"), _T("C20"), _T("C25"), _T("C30"), _T("C35"), _T("C40"), _T("C45"), _T("C50"), _T("C55"), _T("C60"),  _T("C65"), _T("C70"), _T("C75"), _T("C80")};
	double arrConcreteGrade_fc[nConcreteGradeCount] =  {7.2, 9.6, 11.9, 14.3, 16.7, 19.1, 21.1, 23.3, 25.3, 27.5,  29.7, 31.8, 33.8, 35.9};
	
	for (int i = 0; i < nConcreteGradeCount; ++i)
	{
		T_CONCRETE_GRADE tConcreteData;
		tConcreteData.SetConcreteGrade(arrConcreteGrade[i]);
		tConcreteData.SetConcreteGradeFc(arrConcreteGrade_fc[i]);
		m_vctConcreteData.push_back(tConcreteData);
	}
}

void CMaterialDB::InitRebarGradeList()
{
	const int rebarGradeCount = 14;
	CString arrRebarGrade[rebarGradeCount] = { _T("HPB300"), _T("HRB335"), _T("HRBF335"), _T("HRB400"), _T("HRBF400"), _T("RRB400"), _T("HRB500"), _T("HRBF500")};

	for(int i=0; i < rebarGradeCount; i++)  
	{
		m_vctRebarGrade.push_back(arrRebarGrade[i]);
	}
}

void CMaterialDB::InitRebarGradeData()
{
	const int rebarGradeCount = 8;
	CString arrRebarGrade[rebarGradeCount] = { _T("HPB300"), _T("HRB335"), _T("HRBF335"), _T("HRB400"), _T("HRBF400"), _T("RRB400"), _T("HRB500"), _T("HRBF500")};
	int arrRebarFy[rebarGradeCount] = { 270, 300, 300, 360, 360, 360, 435, 435};
	for (int i = 0; i < rebarGradeCount; ++i)
	{
		T_REBAR_GRADE tRebarData;
		tRebarData.SetRebarGrade(arrRebarGrade[i]);
		tRebarData.SetRebarFy(arrRebarFy[i]);
		m_vctRebarData.push_back(tRebarData);
	}
}

std::vector<CString> CMaterialDB::GetRebarDiaList() const
{
	return m_vctRebarDia;
}

std::vector<T_CONCRETE_GRADE> CMaterialDB::GetConcreteData() const
{
	return m_vctConcreteData;
}

std::vector<T_REBAR_GRADE> CMaterialDB::GetRebarData() const
{
	return m_vctRebarData;
}

std::vector<CString> CMaterialDB::GetRebarGradeList() const
{
	return m_vctRebarGrade;
}

//////////////////////////////////////////////////////////////////////////
//             struct T_CONCRETE_GRADE
//////////////////////////////////////////////////////////////////////////
CString T_CONCRETE_GRADE::GetConcreteGrade() const
{
	return m_strConcreteGrade;
}

void T_CONCRETE_GRADE::SetConcreteGrade(const CString& strConcreteGrade)
{
	m_strConcreteGrade = strConcreteGrade;
}

double T_CONCRETE_GRADE::GetConcreteGradeFc() const
{
	return m_dConcreteGrade_fc;
}

void T_CONCRETE_GRADE::SetConcreteGradeFc(const double dConcreteGradeFc)
{
	m_dConcreteGrade_fc = dConcreteGradeFc;
}


//////////////////////////////////////////////////////////////////////////
//             struct T_REBAR_GRADE
//////////////////////////////////////////////////////////////////////////
CString T_REBAR_GRADE::GetRebarGrade() const
{
	return m_strRebarGrade;
}

void T_REBAR_GRADE::SetRebarGrade(const CString& strRebarGrade)
{
	m_strRebarGrade = strRebarGrade;
}

int T_REBAR_GRADE::GetRebarFy() const
{
	return m_nRebarFy;
}

void T_REBAR_GRADE::SetRebarFy(const double dRebarFy)
{
	m_nRebarFy = dRebarFy;
}
