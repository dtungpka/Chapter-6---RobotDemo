// DlgSelectElement.cpp : implementation file
//

#include "pch.h"
#include "RobotDemo.h"
#include "afxdialogex.h"
#include "DlgSelectElement.h"

#include "Model.h"

// CDlgSelectElement dialog

IMPLEMENT_DYNAMIC(CDlgSelectElement, CDialog)


CDlgSelectElement::CDlgSelectElement(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSelectElement::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelectElement)
	//}}AFX_DATA_INIT

	m_pOpenGLCtrlDemo = NULL;
	m_SelectedElement = 0;
}


void CDlgSelectElement::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelectElement)
	DDX_Control(pDX, IDC_COMBO_SELECT_ELEMENT, m_cSelectElement);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelectElement, CDialog)
	//{{AFX_MSG_MAP(CDlgSelectElement)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_ELEMENT, OnSelchangeComboSelectElement)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectElement message handlers

BOOL CDlgSelectElement::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	CString s;
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		s.Format("Element %d", i + 1);
		m_cSelectElement.AddString(s);
	}
	m_cSelectElement.SetCurSel(0);
	OnSelchangeComboSelectElement();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSelectElement::OnSelchangeComboSelectElement()
{
	// TODO: Add your control notification handler code here
	m_SelectedElement = m_cSelectElement.GetCurSel();

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		m_pOpenGLCtrlDemo->m_Model.m_listElement[i].m_drawBound = FALSE;
	}
	m_pOpenGLCtrlDemo->m_Model.m_listElement[m_SelectedElement].m_drawBound = TRUE;
	m_pOpenGLCtrlDemo->Invalidate(FALSE);
}

void CDlgSelectElement::OnOK()
{
	m_SelectedElement = m_cSelectElement.GetCurSel();
	CDialog::OnOK();
}

