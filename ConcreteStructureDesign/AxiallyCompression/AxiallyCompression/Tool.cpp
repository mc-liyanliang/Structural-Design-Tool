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
	CStringArray arrRebarDia;
	CMaterialDB::GetRebarDiaList(arrRebarDia);
	for (int i = 0; i < arrRebarDia.GetCount(); i++)
	{
		ComboRebarDia.AddString(arrRebarDia.GetAt(i));
	}
	ComboRebarDia.SetCurSel(0);
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
