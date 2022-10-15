
// ZCalc.h : main header file for the ZCalc application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CZCalcApp:
// See ZCalc.cpp for the implementation of this class
//

class CZCalcApp : public CWinApp
{
public:
	CZCalcApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZCalcApp theApp;
