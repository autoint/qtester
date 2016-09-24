// Admin_Tool.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAdmin_ToolApp:
// See Admin_Tool.cpp for the implementation of this class
//

class CAdmin_ToolApp : public CWinApp
{
public:
	CAdmin_ToolApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAdmin_ToolApp theApp;