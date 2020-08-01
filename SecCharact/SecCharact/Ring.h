#pragma once
#include "base.h"
class CRing :
	public CBase
{
public:
	CRing(void);
	CRing(double d,double t);
	virtual ~CRing(void);
public:
	void Initlize(void);

	double GetCenCoordXc() const;
	double GetCenCoordYc() const;
	double GetArea() const;
	double GetMomentInertiaIxx() const;
	double GetMomentInertiaIyy() const;
private:
	double m_dDiameter;
	double m_dInnerDiameter;
};

