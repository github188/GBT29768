
// Tag.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "AuthTag.h"

// CTagApp:
// �йش����ʵ�֣������ Tag.cpp
//

class CTagApp : public CWinApp
{
public:
	CTagApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTagApp theApp;
extern HWND hParentWnd;
extern AuthTag authtag;