
// SecCharact.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSecCharactApp:
// �йش����ʵ�֣������ SecCharact.cpp
//

class CSecCharactApp : public CWinApp
{
public:
	CSecCharactApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSecCharactApp theApp;