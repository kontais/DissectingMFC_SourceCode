// MFCexp5_1_2.h : main header file for the MFCEXP5_1_2 application
//

#if !defined(AFX_MFCEXP5_1_2_H__2F0D6282_E2BF_4120_95CB_8FD7F04409FC__INCLUDED_)
#define AFX_MFCEXP5_1_2_H__2F0D6282_E2BF_4120_95CB_8FD7F04409FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_2App:
// See MFCexp5_1_2.cpp for the implementation of this class
//

class CMFCexp5_1_2App : public CWinApp
{
public:
	CMFCexp5_1_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp5_1_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCexp5_1_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP5_1_2_H__2F0D6282_E2BF_4120_95CB_8FD7F04409FC__INCLUDED_)
