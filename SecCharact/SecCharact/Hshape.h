#pragma once
#include "base.h"
class CHshape :
	public CBase
{
public:
	CHshape(void);
	CHshape(double h,double b,double t,double tw);
	virtual ~CHshape(void);
public:
	void Initlize(void);

	double GetCenCoordXc() const;
	double GetCenCoordYc() const;
	double GetArea() const;
	double GetMomentInertiaIxx() const;
	double GetMomentInertiaIyy() const;
private:
	double m_dH;
	double m_dB;
	double m_dT;
	double m_dTw;
};

