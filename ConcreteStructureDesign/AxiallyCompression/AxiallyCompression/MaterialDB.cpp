#include "stdafx.h"
#include "MaterialDB.h"
#include <wtypes.h>
#include <string.h>


CMaterialDB::CMaterialDB(void)
{

}


CMaterialDB::~CMaterialDB(void)
{
}

CString CMaterialDB::m_arrRebarDia[] = { _T("d4"),  _T("d5"),  _T("d6"),  _T("d8"), _T("d10"), _T("d12"), _T("d14"), _T("d16"), _T("d18"), _T("d20"),  _T("d22"), _T("d25"), _T("d28"), _T("d32"), _T("d36"), _T("d40")};

void CMaterialDB::GetRebarDiaList(CStringArray& arrRebarDia)
{
	arrRebarDia.RemoveAll();
	for(int i=0; i < sizeof(m_arrRebarDia)/sizeof(CString); i++)  
	{
		arrRebarDia.Add(m_arrRebarDia[i]);
	}
}

int CMaterialDB::m_nConcreteGradeCount = 14;
CString CMaterialDB::m_arrConcreteGrade[] ={_T("C15"), _T("C20"), _T("C25"), _T("C30"), _T("C35"), _T("C40"), _T("C45"), _T("C50"), _T("C55"), _T("C60"),  _T("C65"), _T("C70"), _T("C75"), _T("C80")};
double CMaterialDB::m_arrConcreteGrade_fc[] =  {7.2, 9.6, 11.9, 14.3, 16.7, 19.1, 21.1, 23.3, 25.3, 27.5,  29.7, 31.8, 33.8, 35.9};
