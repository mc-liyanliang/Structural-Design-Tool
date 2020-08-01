#include "stdafx.h"
#include "Ring.h"


CRing::CRing(void)
{
	Initlize();
}


CRing::CRing(double D,double d):m_dDiameter(D),m_dInnerDiameter(d)
{

}

CRing::~CRing(void)
{
}

void CRing::Initlize(void)
{
	m_dDiameter      = 0;
	m_dInnerDiameter = 0;
}

double CRing::GetCenCoordXc() const
{
	return m_dDiameter/2;
}

double CRing::GetCenCoordYc() const
{
	return m_dDiameter/2;
}

double CRing::GetArea() const
{
	return PI*(pow(m_dDiameter,2)-pow(m_dDiameter-m_dInnerDiameter,2))/4;
}

double CRing::GetMomentInertiaIxx() const
{
	return PI*(pow(m_dDiameter,4)-pow(m_dInnerDiameter,4))/64;
}

double CRing::GetMomentInertiaIyy() const
{
	return PI*(pow(m_dDiameter,4)-pow(m_dInnerDiameter,4))/64;
}
