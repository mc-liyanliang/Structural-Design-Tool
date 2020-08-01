#pragma once
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
	static void InitRebarDiameterComb(OUT CComboBox& ComboRebarDia);
	static CString GetSecTypeNameByIndex(UINT enSecType);
	static void InitSecTypeComb(CComboBox& Combo);
};

