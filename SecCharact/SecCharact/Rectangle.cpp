#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(void)
{
	Initlize();
}


CRectangle::CRectangle(double h,double b):m_dH(h),m_dB(b)
{

}

CRectangle::~CRectangle(void)
{
}

void CRectangle::Initlize(void)
{
	m_dB = 0;
	m_dH = 0;
}

double CRectangle::GetCenCoordXc() const
{
	return m_dB/2;
}

double CRectangle::GetCenCoordYc() const
{
	return m_dH/2;
}

double CRectangle::GetArea() const
{
	return m_dH*m_dB;
}

double CRectangle::GetMomentInertiaIxx() const
{
	return m_dB*pow(m_dH,3)/12;
}

double CRectangle::GetMomentInertiaIyy() const
{
	return m_dH*pow(m_dB,3)/12;
}
