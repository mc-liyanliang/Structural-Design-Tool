#include "stdafx.h"
#include "PageBase.h"



CPageBase::CPageBase()	: 
	  m_dXc(0)
	, m_dYc(0)
	, m_dIxx(0)
	, m_dIyy(0)
	, m_dArea(0)
{

}

CPageBase::~CPageBase(void)
{
}

void CPageBase::RefreshData()
{
	m_dXc	= 0;
	m_dYc	= 0;
	m_dIxx	= 0;
	m_dIyy	= 0;
	m_dArea	= 0;
}
