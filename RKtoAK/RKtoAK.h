
// RKtoAK.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRKtoAKApp:
// �йش����ʵ�֣������ RKtoAK.cpp
//

class CRKtoAKApp : public CWinApp
{
public:
	CRKtoAKApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRKtoAKApp theApp;