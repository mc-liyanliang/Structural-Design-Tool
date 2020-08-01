#pragma once
#include <vector>
class CMaterialDB
{
public:
	CMaterialDB(void);
	~CMaterialDB(void);
	struct T_CONCRETE_GRADE
	{
		CString m_strConcreteGrade;
		double m_dConcreteGrade_fc;
	};
	CArray<T_CONCRETE_GRADE, T_CONCRETE_GRADE&> m_ConcreteData;
public:
	static CString m_arrRebarDia[];
	static void GetRebarDiaList(CStringArray& arrRebarDia);

	static int m_nConcreteGradeCount;
	static CString m_arrConcreteGrade[];
	static double m_arrConcreteGrade_fc[];
	
};

