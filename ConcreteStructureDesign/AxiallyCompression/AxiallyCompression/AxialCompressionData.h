#pragma once
class CAxialCompressionData
{
public:
	CAxialCompressionData(void);
	CAxialCompressionData(const CAxialCompressionData& rhs);
	CAxialCompressionData& operator=(const CAxialCompressionData& rhs);
	~CAxialCompressionData(void);
public:
	void SetSecType(const UINT enSecType);
	UINT GetSecType() const;

	void SetHeight(const double dHeight);
	double GetHeight() const;

	void SetWidth(const double dWidth);
	double GetWidth() const;

	void SetLength(const double dLength);
	double GetLength() const;

	void SetDiameter(const double dDiameter);
	double GetDiameter() const;

	void SetAxialDesignValue(const double dAxialDesignValue);
	double GetAxialDesignValue() const;

	void SetStabilityFactor(const double dStabilityFactor);
	double GetStabilityFactor() const;

	void SetConcreteGrade(const CString& strConcreteGrade);
	CString GetConcreteGrade() const;

	void SetMainbarGrade(const CString& strMainbarGrade);
	CString GetMainbarGrade() const;

	void SetSpiralStirrup(BOOL bSpiralStirrup);
	BOOL GetSpiralStirrup() const;

	void SetSpiralStirrupDia(const CString& strSpiralStirrupDia);
	CString GetSpiralStirrupDia() const;

	void SetSpiralStirrupSpace(const double dSpiralStirrupSpace);
	double GetSpiralStirrupSpacae() const;

	void SetSpiralStirrupGrade(const CString& strSpiralStirrupGrade);
	CString GetSpiralStirrupGrade() const;

	void SetCoreSecDiameter(const double dCoreSecDiameter);
	double GetCoreSecDiameter() const;
private:
	UINT    m_nSecType;
	double  m_dHeight;
	double  m_dWidth;
	double  m_dLength;
	double  m_dDiameter;
	double  m_dAxialDesignValue;
	double  m_dStabilityFactor;
	CString m_strConcreteGrade;
	CString m_strMainbarGrade;
	BOOL    m_bSpiralStirrup;
	CString m_strSpiralStirrupDia;
	double  m_dSpiralStirrupSpace;
	CString m_strSpiralStirrupGrade;
	double  m_dCoreSecDiameter;
public:
	void Init();
};

