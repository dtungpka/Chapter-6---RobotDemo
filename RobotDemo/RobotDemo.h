
// RobotDemo.h : main header file for the RobotDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRobotDemoApp:
// See RobotDemo.cpp for the implementation of this class
//

class CRobotDemoApp : public CWinApp
{
public:
	CRobotDemoApp() noexcept;

	CString m_sAppLocation;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRobotDemoApp theApp;
