// DlgGraphs.cpp : implementation file
//

#include "pch.h"
#include "RobotDemo.h"
#include "afxdialogex.h"
#include "DlgGraphs.h"


// CDlgGraphs dialog

IMPLEMENT_DYNAMIC(CDlgGraphs, CDialog)

CDlgGraphs::CDlgGraphs(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGraphs::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGraphs)
	//}}AFX_DATA_INIT

	m_pModel = NULL;
	m_pTrajectory = NULL;
}


void CDlgGraphs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGraphs)
	DDX_Control(pDX, IDC_COMBO_SHOW_MIN, m_cShowMin);
	DDX_Control(pDX, IDC_COMBO_SHOW_MAX, m_cShowMax);
	DDX_Control(pDX, IDC_COMBO_STYLE_VIEW, m_cbStyleView);
	DDX_Control(pDX, IDC_STATIC_GRAPH, m_Static_Graph);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGraphs, CDialog)
	//{{AFX_MSG_MAP(CDlgGraphs)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_STYLE_VIEW, OnSelchangeComboStyleView)
	ON_CBN_SELCHANGE(IDC_COMBO_SHOW_MAX, OnSelchangeComboShowMax)
	ON_CBN_SELCHANGE(IDC_COMBO_SHOW_MIN, OnSelchangeComboShowMin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGraphs message handlers

void CDlgGraphs::SetDataForGraph()
{
	if (m_pModel == NULL) return;

	m_pl1.RemoveAll();
	m_pl2.RemoveAll();
	m_pl3.RemoveAll();

	CDoubleArray* pData1 = &m_pModel->m_parameter[0];
	CDoubleArray* pData2 = &m_pModel->m_parameter[1];
	CDoubleArray* pData3 = &m_pModel->m_parameter[2];

	switch (m_cbStyleView.GetCurSel())
	{
	case 1:
		pData1 = &m_pModel->m_velocity[0];
		pData2 = &m_pModel->m_velocity[1];
		pData3 = &m_pModel->m_velocity[2];
		m_str1 = "w(Phi1) [deg/s]";
		m_str2 = "w(Phi2) [deg/s]";
		m_str3 = "v(l3) [mm/s]";
		break;
	case 2:
		pData1 = &m_pModel->m_acceleration[0];
		pData2 = &m_pModel->m_acceleration[1];
		pData3 = &m_pModel->m_acceleration[2];
		m_str1 = "a(Phi1) [deg/s^2]";
		m_str2 = "a(Phi2) [deg/s^2]";
		m_str3 = "a(l3) [mm/s^2]";
		break;
	default:
		pData1 = &m_pModel->m_parameter[0];
		pData2 = &m_pModel->m_parameter[1];
		pData3 = &m_pModel->m_parameter[2];
		m_str1 = "Phi1 [deg]";
		m_str2 = "Phi2 [deg]";
		m_str3 = "l3 [mm]";
		break;
	}

	if (pData1->GetSize() <= 0) return;

	double dt = m_pTrajectory->Get_dt();
	for (int i = 0; i < m_pModel->m_parameter[0].GetSize(); i++)
	{
		m_pl1.Add(CPoint2d(i * dt, pData1->GetAt(i)));
		m_pl2.Add(CPoint2d(i * dt, pData2->GetAt(i)));
		m_pl3.Add(CPoint2d(i * dt, pData3->GetAt(i)));
	}

	CDoubleArray max, min;
	max.Add((double)FindMax(*pData1));
	max.Add((double)FindMax(*pData2));
	max.Add((double)FindMax(*pData3));

	min.Add((double)FindMin(*pData1));
	min.Add((double)FindMin(*pData2));
	min.Add((double)FindMin(*pData3));

	m_ymin = floor(FindMin(min));
	m_ymax = ceil(FindMax(max));
	m_xmin = 0;
	m_xmax = m_pModel->m_parameter[0].GetSize() * dt;
}

void CDlgGraphs::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	m_graph.SetRectControl(m_Static_Graph);

	m_graph.DrawBackGround(RGB(255, 255, 255));

	//---------------------------------

	double ymax = m_ymax, ymin = m_ymin;
	CString s;
	if ((m_cShowMin.m_hWnd) && (m_cShowMin.GetCurSel() >= 0))
	{
		m_cShowMin.GetLBText(m_cShowMin.GetCurSel(), s);
		ymin = atoi(s);
	}
	if ((m_cShowMax.m_hWnd) && (m_cShowMax.GetCurSel() >= 0))
	{
		m_cShowMax.GetLBText(m_cShowMax.GetCurSel(), s);
		ymax = atoi(s);
	}
	if (ymax < ymin)
	{
		double ytemp = ymin;
		ymin = ymax;
		ymax = ytemp;
	}

	m_graph.SetRangeX(m_xmin, m_xmax);
	m_graph.SetRangeY(ymin, ymax);
	//m_graph.SetStepgridHor(0.1);

	m_graph.SetShowBound(true);
	m_graph.SetShowLineZero(false);
	m_graph.SetGridStyle(PS_DOT);


	m_graph.DrawTable();

	m_graph.SetColorGraph(RGB(255, 0, 0));
	m_graph.MoveTo(m_graph.GetXmax(), m_graph.GetYmin());
	m_graph.DrawText("t (s)", TA_TOP | TA_RIGHT);

	m_graph.SetColorGraph(RGB(255, 0, 0));
	if (m_pl1.GetSize() > 0)
	{
		m_graph.MoveTo(m_pl1[0]); m_graph.DrawText(" " + m_str1, TA_BOTTOM | TA_LEFT);
		m_graph.MoveTo(m_pl1[m_pl1.GetSize() / 2]); m_graph.DrawText(m_str1, TA_BOTTOM | TA_CENTER);
		m_graph.DrawPline(m_pl1); m_graph.DrawText(m_str1 + "  ", TA_BOTTOM | TA_RIGHT);
	}


	//m_graph.SetColorGraph(RGB(255,0,200));
	m_graph.SetColorGraph(RGB(125, 0, 125));
	if (m_pl2.GetSize() > 0)
	{
		m_graph.MoveTo(m_pl2[0]); m_graph.DrawText(" " + m_str2, TA_BOTTOM | TA_LEFT);
		m_graph.MoveTo(m_pl2[m_pl2.GetSize() / 2]); m_graph.DrawText(m_str2, TA_BOTTOM | TA_CENTER);
		m_graph.DrawPline(m_pl2); m_graph.DrawText(m_str2 + "  ", TA_BOTTOM | TA_RIGHT);
	}

	m_graph.SetColorGraph(RGB(0, 0, 255));
	if (m_pl3.GetSize() > 0)
	{
		m_graph.MoveTo(m_pl3[0]); m_graph.DrawText(" " + m_str3, TA_BOTTOM | TA_LEFT);
		m_graph.MoveTo(m_pl3[m_pl3.GetSize() / 2]); m_graph.DrawText(m_str3, TA_BOTTOM | TA_CENTER);
		m_graph.DrawPline(m_pl3);	m_graph.DrawText(m_str3 + "  ", TA_BOTTOM | TA_RIGHT);
	}
}

BOOL CDlgGraphs::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_cbStyleView.SetCurSel(0);
	m_pModel->Solve();
	SetDataToItems();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgGraphs::OnSelchangeComboStyleView()
{
	// TODO: Add your control notification handler code here
	SetDataToItems();
	Invalidate(FALSE);
}

void CDlgGraphs::SetDataToItems()
{
	SetDataForGraph();
	SetDataComboBox();
}

void CDlgGraphs::SetDataComboBox()
{
	m_cShowMin.ResetContent();
	m_cShowMax.ResetContent();

	double ymax = m_ymax, ymin = m_ymin;
	double yrange = ymax - ymin;

	int stepoc = (int)floor(log10(yrange));

	CString s;
	double ystep;

	s.Format("%0.0f", ymin);
	m_cShowMin.AddString(s);
	m_cShowMax.AddString(s);
	for (int i = -10; i <= 10; i++)
	{
		if (i == 0)
		{
			for (int j = -9; j <= 9; j++)
			{
				if ((m_cbStyleView.GetCurSel() == 2) && (j == 0))
				{
					for (int k = -9; k <= 9; k++)
					{
						ystep = k * pow(10, stepoc - 2);
						if ((ystep > ymin) && (ystep < ymax))
						{
							s.Format("%0.1f", ystep);
							m_cShowMin.AddString(s);
							m_cShowMax.AddString(s);
						}
					}
				}
				else
				{
					ystep = j * pow(10, stepoc - 1);
					if ((ystep > ymin) && (ystep < ymax))
					{
						s.Format("%0.1f", ystep);
						m_cShowMin.AddString(s);
						m_cShowMax.AddString(s);
					}
				}
			}
		}
		else
		{
			ystep = i * pow(10, stepoc);
			if ((ystep > ymin) && (ystep < ymax))
			{
				s.Format("%0.1f", ystep);
				m_cShowMin.AddString(s);
				m_cShowMax.AddString(s);
			}
		}
	}
	s.Format("%0.1f", ymax);
	m_cShowMin.AddString(s);
	m_cShowMax.AddString(s);

	m_cShowMin.SetCurSel(0);
	m_cShowMax.SetCurSel(m_cShowMax.GetCount() - 1);
}

void CDlgGraphs::OnSelchangeComboShowMax()
{
	// TODO: Add your control notification handler code here
	Invalidate(FALSE);
}

void CDlgGraphs::OnSelchangeComboShowMin()
{
	// TODO: Add your control notification handler code here
	Invalidate(FALSE);
}
