
// AxiallyCompression.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAxiallyCompressionApp:
// �йش����ʵ�֣������ AxiallyCompression.cpp
//

class CAxiallyCompressionApp : public CWinApp
{
public:
	CAxiallyCompressionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAxiallyCompressionApp theApp;