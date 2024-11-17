// DlgGraphTrajectory.cpp : implementation file
//

#include "pch.h"
#include "RobotDemo.h"
#include "DlgGraphTrajectory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGraphTrajectory dialog


CDlgGraphTrajectory::CDlgGraphTrajectory(CWnd* pParent /*=NULL*/)
	: CDlgGraphs(pParent)
{
	//{{AFX_DATA_INIT(CDlgGraphTrajectory)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pModel=NULL;
}


void CDlgGraphTrajectory::DoDataExchange(CDataExchange* pDX)
{
	CDlgGraphs::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGraphTrajectory)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGraphTrajectory, CDlgGraphs)
	//{{AFX_MSG_MAP(CDlgGraphTrajectory)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGraphTrajectory message handlers

void CDlgGraphTrajectory::SetDataForGraph()
{
	if (m_pModel==NULL) return;
	
	m_pl1.RemoveAll();
	m_pl2.RemoveAll();
	m_pl3.RemoveAll();
	
	CDoubleArray * pData1=&m_pModel->m_trajectory[0];
	CDoubleArray * pData2=&m_pModel->m_trajectory[1];
	CDoubleArray * pData3=&m_pModel->m_trajectory[2];
	
	switch (m_cbStyleView.GetCurSel())
	{
		case 1:
			pData1=&m_pModel->m_trajectory[3];
			pData2=&m_pModel->m_trajectory[4];
			pData3=&m_pModel->m_trajectory[5];
			m_str1="Vx [mm/s]";
			m_str2="Vy [mm/s]";
			m_str3="Vz [mm/s]";
			break;
		case 2:
			pData1=&m_pModel->m_trajectory[6];
			pData2=&m_pModel->m_trajectory[7];
			pData3=&m_pModel->m_trajectory[8];
			m_str1="ax [mm/s^2]";
			m_str2="ay [mm/s^2]";
			m_str3="az [mm/s^2]";
			break;
		default:
			pData1=&m_pModel->m_trajectory[0];
			pData2=&m_pModel->m_trajectory[1];
			pData3=&m_pModel->m_trajectory[2];
			m_str1="x [mm]";
			m_str2="y [mm]";
			m_str3="z [mm]";
			break;
	}	

	if (pData1->GetSize()<=0) return;
	
	for (int i=0;i<m_pModel->m_parameter[0].GetSize();i++)
	{
		m_pl1.Add(CPoint2d(i,pData1->GetAt(i)));
		m_pl2.Add(CPoint2d(i,pData2->GetAt(i)));
		m_pl3.Add(CPoint2d(i,pData3->GetAt(i)));
	}
	
	CDoubleArray max,min;
	max.Add((double)FindMax(*pData1));
	max.Add((double)FindMax(*pData2));
	max.Add((double)FindMax(*pData3));
	
	min.Add((double)FindMin(*pData1));
	min.Add((double)FindMin(*pData2));
	min.Add((double)FindMin(*pData3));
	
	m_ymin=floor(FindMin(min));
	m_ymax=ceil(FindMax(max));
	m_xmin=0;
	m_xmax=m_pModel->m_parameter[0].GetSize();	
}
