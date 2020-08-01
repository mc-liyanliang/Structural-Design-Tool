#include "stdafx.h"
#include "AxialCompressionData.h"
#include "Tool.h"


CAxialCompressionData::CAxialCompressionData(void)
{
	Init();
}


CAxialCompressionData::CAxialCompressionData(const CAxialCompressionData& rhs)
{
	*this = rhs;
}

CAxialCompressionData& CAxialCompressionData::operator=(const CAxialCompressionData& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}												  
	m_nSecType			  = rhs.m_nSecType			  ;
	m_dHeight			  = rhs.m_dHeight			  ;
	m_dWidth			  = rhs.m_dWidth			  ;
	m_dLength			  = rhs.m_dLength			  ;
	m_dDiameter			  = rhs.m_dDiameter			  ;
	m_dAxialDesignValue	  = rhs.m_dAxialDesignValue	  ;
	m_dStabilityFactor	  = rhs.m_dStabilityFactor	  ;
	m_strConcreteGrade	  = rhs.m_strConcreteGrade	  ;
	m_strMainbarGrade	  = rhs.m_strMainbarGrade	  ;
	m_bSpiralStirrup	  = rhs.m_bSpiralStirrup	  ;
	m_strSpiralStirrupDia	  = rhs.m_strSpiralStirrupDia	  ;
	m_dSpiralStirrupSpace  = rhs.m_dSpiralStirrupSpace  ;
	m_strSpiralStirrupGrade = rhs.m_strSpiralStirrupGrade ;
	m_dCoreSecDiameter	  = rhs.m_dCoreSecDiameter	  ;
	return *this;
}

CAxialCompressionData::~CAxialCompressionData(void)
{
}

void CAxialCompressionData::Init()
{
	m_nSecType = CTool::en_Rect;
	m_dHeight = 450.0;
	m_dWidth = 450.0;
	m_dLength = 62000.0;
	m_dDiameter = 450.0;
	m_dAxialDesignValue = 24000.0;
	m_dStabilityFactor = 1.0;
	m_strConcreteGrade = _T("C25");
	m_strMainbarGrade = _T("HRB400");
	m_bSpiralStirrup  = FALSE;
	m_strSpiralStirrupDia = _T("d20");
	m_dSpiralStirrupSpace = 60.0;
	m_strSpiralStirrupGrade = _T("HRB335");
	m_dCoreSecDiameter = 440.0;
}

void CAxialCompressionData::SetSecType(const UINT enSecType)
{
	m_nSecType = enSecType;
}

UINT CAxialCompressionData::GetSecType() const
{
	return m_nSecType;
}

void CAxialCompressionData::SetHeight(const double dHeight)
{
	m_dHeight = dHeight;
}

double CAxialCompressionData::GetHeight() const
{
	return m_dHeight;
}

void CAxialCompressionData::SetWidth(const double dWidth)
{
	m_dWidth = dWidth;
}

double CAxialCompressionData::GetWidth() const
{
	return m_dWidth;
}

void CAxialCompressionData::SetLength(const double dLength)
{
	m_dLength = dLength;
}

double CAxialCompressionData::GetLength() const
{
	return m_dLength;
}

void CAxialCompressionData::SetDiameter(const double dDiameter)
{
	m_dDiameter = dDiameter;
}

double CAxialCompressionData::GetDiameter() const
{
	return m_dDiameter;
}

void CAxialCompressionData::SetAxialDesignValue(const double dAxialDesignValue)
{
	m_dAxialDesignValue = dAxialDesignValue;
}

double CAxialCompressionData::GetAxialDesignValue() const
{
	return m_dAxialDesignValue;
}

void CAxialCompressionData::SetStabilityFactor(const double dStabilityFactor)
{
	m_dStabilityFactor = dStabilityFactor;
}

double CAxialCompressionData::GetStabilityFactor() const
{
	return m_dStabilityFactor;
}

void CAxialCompressionData::SetConcreteGrade(const CString& strConcreteGrade)
{
	m_strConcreteGrade = strConcreteGrade;
}

CString CAxialCompressionData::GetConcreteGrade() const
{
	return m_strConcreteGrade;
}

void CAxialCompressionData::SetMainbarGrade(const CString& strMainbarGrade)
{
	m_strMainbarGrade = strMainbarGrade;
}

CString CAxialCompressionData::GetMainbarGrade() const
{
	return m_strMainbarGrade;
}

void CAxialCompressionData::SetSpiralStirrup(BOOL bSpiralStirrup)
{
	m_bSpiralStirrup = bSpiralStirrup;
}

BOOL CAxialCompressionData::GetSpiralStirrup() const
{
	return m_bSpiralStirrup;
}

void CAxialCompressionData::SetSpiralStirrupDia(const CString& strSpiralStirrupDia)
{
	m_strSpiralStirrupDia = strSpiralStirrupDia;
}

CString CAxialCompressionData::GetSpiralStirrupDia() const
{
	return m_strSpiralStirrupDia;
}

void CAxialCompressionData::SetSpiralStirrupSpace(const double dSpiralStirrupSpace)
{
	m_dSpiralStirrupSpace = dSpiralStirrupSpace;
}

double CAxialCompressionData::GetSpiralStirrupSpacae() const
{
	return m_dSpiralStirrupSpace;
}

void CAxialCompressionData::SetSpiralStirrupGrade(const CString& strSpiralStirrupGrade)
{
	m_strSpiralStirrupGrade = strSpiralStirrupGrade;
}

CString CAxialCompressionData::GetSpiralStirrupGrade() const
{
	return m_strSpiralStirrupGrade;
}

void CAxialCompressionData::SetCoreSecDiameter(const double dCoreSecDiameter)
{
	m_dCoreSecDiameter = dCoreSecDiameter;
}

double CAxialCompressionData::GetCoreSecDiameter() const
{
	return m_dCoreSecDiameter;
}
