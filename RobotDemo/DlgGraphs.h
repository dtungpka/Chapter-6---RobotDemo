#pragma once
#include "afxdialogex.h"

#include "Model.h"
#include "Trajectory.h"

// CDlgGraphs dialog
class CDlgGraphs : public CDialog
{
	DECLARE_DYNAMIC(CDlgGraphs)

	// Construction
public:
	void SetDataComboBox();
	void SetDataToItems();
	virtual void SetDataForGraph();
	CDlgGraphs(CWnd* pParent = NULL);   // standard constructor

	// Dialog Data
		//{{AFX_DATA(CDlgGraphs)
	enum { IDD = IDD_DIALOG_GRAPH };
	CComboBox	m_cShowMin;
	CComboBox	m_cShowMax;
	CComboBox	m_cbStyleView;
	CStatic	m_Static_Graph;
	//}}AFX_DATA

	CGraph m_graph;

	CPline m_pl1, m_pl2, m_pl3;
	CString m_str1, m_str2, m_str3;

	double m_xmax, m_xmin, m_ymax, m_ymin;

	CModel* m_pModel;
	CTrajectory* m_pTrajectory;

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CDlgGraphs)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGraphs)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboStyleView();
	afx_msg void OnSelchangeComboShowMax();
	afx_msg void OnSelchangeComboShowMin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
