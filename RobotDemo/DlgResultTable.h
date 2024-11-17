#pragma once
#include "afxdialogex.h"


// CDlgResultTable dialog
class CDlgResultTable : public CDialog
{
	DECLARE_DYNAMIC(CDlgResultTable)

	// Construction
public:
	void SetDataToGrid();
	CDlgResultTable(CWnd* pParent = NULL);   // standard constructor

	// Dialog Data
	//{{AFX_DATA(CDlgSelectElement)
	enum { IDD = IDD_DIALOG_RESULT_TABLE };
	//}}AFX_DATA
	CGridCtrl m_GridView;

	CModel* m_pModel;

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CDlgResultTable)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgResultTable)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void OnGridCopy();
	DECLARE_MESSAGE_MAP()
};