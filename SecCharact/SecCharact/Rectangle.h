#pragma once
#include "base.h"
class CRectangle :
	public CBase
{
public:
	CRectangle(void);
	CRectangle(double h,double b);
	virtual ~CRectangle(void);
public:
	void Initlize(void);

	double GetCenCoordXc() const;
	double GetCenCoordYc() const;
	double GetArea() const;
	double GetMomentInertiaIxx() const;
	double GetMomentInertiaIyy() const;
private:
	double m_dB;
	double m_dH;
};

