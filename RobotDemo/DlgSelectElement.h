#pragma once
#include "afxdialogex.h"


// CDlgSelectElement dialog
class CDlgSelectElement : public CDialog
{
	DECLARE_DYNAMIC(CDlgSelectElement)
	// Construction
public:
	virtual void OnOK();
	CDlgSelectElement(CWnd* pParent = NULL);   // standard constructor

	// Dialog Data
		//{{AFX_DATA(CDlgSelectElement)
	enum { IDD = IDD_DIALOG_SELECT_ELEMENT };
	CComboBox	m_cSelectElement;
	//}}AFX_DATA

	COpenGLCtrlDemo* m_pOpenGLCtrlDemo;

	int m_SelectedElement;

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CDlgSelectElement)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelectElement)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboSelectElement();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
