// cardDlg.h : header file
//

#if !defined(AFX_CARDDLG_H__C9C24038_DEF9_4CC4_B675_824506EFA7E5__INCLUDED_)
#define AFX_CARDDLG_H__C9C24038_DEF9_4CC4_B675_824506EFA7E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCardDlg dialog

class CCardDlg : public CDialog
{
// Construction
public:
	CCardDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCardDlg)
	enum { IDD = IDD_CARD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE icdev ;
	char tempwrite[255]; 
	int money ; 
	int st ; 
	// Generated message map functions
	//{{AFX_MSG(CCardDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDDLG_H__C9C24038_DEF9_4CC4_B675_824506EFA7E5__INCLUDED_)
