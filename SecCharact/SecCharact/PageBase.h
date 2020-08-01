#pragma once
class CPageBase
{
public:
	CPageBase();
	virtual ~CPageBase(void);
public:
	void RefreshData();
public:
	double m_dXc;
	double m_dYc;
	double m_dIxx;
	double m_dIyy;
	double m_dArea;
};

