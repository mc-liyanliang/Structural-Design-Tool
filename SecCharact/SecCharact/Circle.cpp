#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(void)
{
	Initlize();
}

void CCircle::Initlize(void)
{
	m_dDiameter = 0;
}

CCircle::CCircle(double d):m_dDiameter(d)
{
	
}

CCircle::~CCircle(void)
{
}

double CCircle::GetCenCoordXc() const
{
	return m_dDiameter/2;
}

double CCircle::GetCenCoordYc() const
{
	return m_dDiameter/2;
}

double CCircle::GetArea() const
{
	return PI*pow(m_dDiameter, 2)/4;
}

double CCircle::GetMomentInertiaIxx() const
{
	return PI*pow(m_dDiameter, 4)/64;
}

double CCircle::GetMomentInertiaIyy() const
{
	return PI*pow(m_dDiameter, 4)/64;
}
