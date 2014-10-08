// card.h : main header file for the CARD application
//

#if !defined(AFX_CARD_H__32255B03_F56F_4DAB_85B2_48D119B0559F__INCLUDED_)
#define AFX_CARD_H__32255B03_F56F_4DAB_85B2_48D119B0559F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCardApp:
// See card.cpp for the implementation of this class
//

class CCardApp : public CWinApp
{
public:
	CCardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCardApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARD_H__32255B03_F56F_4DAB_85B2_48D119B0559F__INCLUDED_)
