// DlgResultTable.cpp : implementation file
//

#include "pch.h"
#include "RobotDemo.h"
#include "afxdialogex.h"
#include "DlgResultTable.h"


// CDlgResultTable dialog
#define ID_GRID_COPY 2000

IMPLEMENT_DYNAMIC(CDlgResultTable, CDialog)

CDlgResultTable::CDlgResultTable(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgResultTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgResultTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pModel = NULL;
}


void CDlgResultTable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgResultTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_STATIC_GRID, m_GridView);
}


BEGIN_MESSAGE_MAP(CDlgResultTable, CDialog)
	//{{AFX_MSG_MAP(CDlgResultTable)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_GRID_COPY, OnGridCopy)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgResultTable message handlers

void CDlgResultTable::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	CRect r;
	GetClientRect(&r);
	if (!r.PtInRect(point)) return;

	if (!m_GridView.m_hWnd) return;

	m_GridView.GetWindowRect(r);
	CNewMenu ContextMenu;

	VERIFY(ContextMenu.CreatePopupMenu());

	ContextMenu.AppendMenu(MF_STRING, ID_GRID_COPY, (LPCTSTR)"&Copy");
	ContextMenu.LoadToolBar(IDR_MAINFRAME);
	if (r.PtInRect(point)) ContextMenu.TrackPopupMenu(
		TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CDlgResultTable::OnGridCopy()
{
	// TODO: Add your command handler code here
	if (!m_GridView.m_hWnd) return;
	m_GridView.OnEditCopy();
}



void CDlgResultTable::SetDataToGrid()
{
	if ((m_pModel == NULL) || (m_pModel->m_trajectory[0].GetSize() <= 0)) return;

	m_GridView.DeleteAllItems();

	m_GridView.SetFixedRowCount(1);
	m_GridView.SetFixedColumnCount(1);

	m_GridView.SetRowCount(m_pModel->m_trajectory[0].GetSize() + 1);
	m_GridView.SetColumnCount(1 + 9 + (NUM_ELEMENTS - 1) * 3);

	m_GridView.SetItemText(0, 1, "X (mm)");
	m_GridView.SetItemText(0, 2, "Y (mm)");
	m_GridView.SetItemText(0, 3, "Z (mm)");
	m_GridView.SetItemText(0, 4, "vx (mm/s)");
	m_GridView.SetItemText(0, 5, "vy (mm/s)");
	m_GridView.SetItemText(0, 6, "vz (mm/s)");
	m_GridView.SetItemText(0, 7, "ax (mm/s^2)");
	m_GridView.SetItemText(0, 8, "ay (mm/s^2)");
	m_GridView.SetItemText(0, 9, "az (mm/s^2)");


	CString sTemp;

	for (int i = 0; i < NUM_ELEMENTS - 1; i++)
	{
		sTemp.Format("parameter %d", i + 1);
		m_GridView.SetItemText(0, 9 + i + 1, sTemp);

		sTemp.Format("velocity %d", i + 1);
		m_GridView.SetItemText(0, 9 + i + (NUM_ELEMENTS - 1) + 1, sTemp);

		sTemp.Format("accelerator %d", i + 1);
		m_GridView.SetItemText(0, 9 + i + 2 * (NUM_ELEMENTS - 1) + 1, sTemp);
	}

	for (int i = 0; i < m_pModel->m_trajectory[0].GetSize(); i++)
	{
		sTemp.Format("%d", i + 1);
		m_GridView.SetItemText(i + 1, 0, sTemp);

		for (int j = 0; j < 9; j++)
		{
			sTemp.Format("%f", m_pModel->m_trajectory[j][i]);
			m_GridView.SetItemText(i + 1, j + 1, sTemp);
		}

		if (i < m_pModel->m_parameter[0].GetSize())
			for (int j = 0; j < 3; j++)
			{
				sTemp.Format("%f", m_pModel->m_parameter[j][i]);
				m_GridView.SetItemText(i + 1, j + 9 + 1, sTemp);

				sTemp.Format("%f", m_pModel->m_velocity[j][i]);
				m_GridView.SetItemText(i + 1, j + 9 + (NUM_ELEMENTS - 1) + 1, sTemp);

				sTemp.Format("%f", m_pModel->m_acceleration[j][i]);
				m_GridView.SetItemText(i + 1, j + 9 + 2 * (NUM_ELEMENTS - 1) + 1, sTemp);
			}
	}
}

BOOL CDlgResultTable::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	SetDataToGrid();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

