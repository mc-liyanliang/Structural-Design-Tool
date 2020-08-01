#pragma once
#define _USE_MATH_DEFINES
#include<math.h>
#define PI M_PI     //3.141592653589793
#include <math.h>
class CBase
{
public:
	CBase(void);
	virtual ~CBase(void);
public:
	virtual void Initlize(void)=0;

	virtual double GetCenCoordXc() const=0;
	virtual double GetCenCoordYc() const=0;
	virtual double GetArea() const=0;
	virtual double GetMomentInertiaIxx() const=0;
	virtual double GetMomentInertiaIyy() const=0;
};

