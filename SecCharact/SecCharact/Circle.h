#pragma once
#include "base.h"
class CCircle :
	public CBase
{
public:
	CCircle(void);
	CCircle(double d);
	virtual ~CCircle(void);
public:
	void Initlize(void);
	double GetCenCoordXc() const;
	double GetCenCoordYc() const;
	double GetArea() const;
	double GetMomentInertiaIxx() const;
	double GetMomentInertiaIyy() const;
private:
	double m_dDiameter;
};

