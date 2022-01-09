
// TXT.h : main header file for the TXTManager application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTXTApp:
// See TXT.cpp for the implementation of this class
//

class CTXTApp : public CWinApp
{
public:
	CTXTApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTXTApp theApp;
