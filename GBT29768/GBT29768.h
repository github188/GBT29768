
// GBT29768.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Auth.h"

// CGBT29768App:
// �йش����ʵ�֣������ GBT29768.cpp
//

class CGBT29768App : public CWinApp
{
public:
	CGBT29768App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGBT29768App theApp;
extern Auth auth;
extern HWND hParentWnd;