#pragma once
#include <vector>
#include <afxstr.h>
#include <afxcoll.h>

struct T_CONCRETE_GRADE
{
private:
	CString m_strConcreteGrade;
	double m_dConcreteGrade_fc;
public:
	CString GetConcreteGrade() const;
	void SetConcreteGrade(const CString& strConcreteGrade);

	double GetConcreteGradeFc() const;
	void SetConcreteGradeFc(const double dConcreteGradeFc);
};

struct T_REBAR_GRADE
{
private:
	CString m_strRebarGrade;
	int m_nRebarFy;
public:
	CString GetRebarGrade() const;
	void SetRebarGrade(const CString& strRebarGrade);

	int GetRebarFy() const;
	void SetRebarFy(const double dRebarFy);
};

class CMaterialDB
{
public:
	CMaterialDB(void);
	~CMaterialDB(void);

public:
	std::vector<T_CONCRETE_GRADE> GetConcreteData() const;
	std::vector<T_REBAR_GRADE> GetRebarData() const;
	std::vector<CString> GetRebarGradeList() const;
	std::vector<CString> GetRebarDiaList() const;
private:
	std::vector<T_CONCRETE_GRADE> m_vctConcreteData;
	std::vector<T_REBAR_GRADE> m_vctRebarData;
	std::vector<CString> m_vctRebarDia;
	std::vector<CString> m_vctRebarGrade;
private:
	void InitConcreteData();	
	void InitRebarGradeList();
	void InitRebarGradeData();
	void InitRebarDiaList();
};

