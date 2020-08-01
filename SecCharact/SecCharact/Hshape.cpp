#include "stdafx.h"
#include "Hshape.h"


CHshape::CHshape(void)
{
	Initlize();
}


CHshape::CHshape(double h,double b,double t,double tw):m_dH(h),m_dB(b),m_dT(t),m_dTw(tw)
{

}

CHshape::~CHshape(void)
{
}

void CHshape::Initlize(void)
{
	m_dH  = 0;
	m_dB  = 0;
	m_dT  = 0;
	m_dTw = 0;
}

double CHshape::GetCenCoordXc() const
{
	return 0;
}

double CHshape::GetCenCoordYc() const
{
	return (pow(m_dT,2)+(m_dH-2*m_dT)*m_dTw*m_dH/2+m_dB*m_dT*(m_dH-m_dT/2))/2*m_dB*m_dT+m_dTw*(m_dH-2*m_dT);
}

double CHshape::GetArea() const
{
	return m_dB*m_dH-(m_dB-m_dTw)*(m_dH-2*m_dT);
}

double CHshape::GetMomentInertiaIxx() const
{
	return (m_dB*pow(m_dT,3)/12+m_dB*m_dT*pow((m_dH/2-m_dT/2),2))*2+m_dTw*pow((m_dH-2*m_dT),3)/12;
}

double CHshape::GetMomentInertiaIyy() const
{
	return m_dT*pow(m_dB,3)/6+(m_dH-2*m_dT)*pow(m_dTw,3)/12;
}
