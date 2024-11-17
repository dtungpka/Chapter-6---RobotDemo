
// RobotDemoView.cpp : implementation of the CRobotDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RobotDemo.h"
#endif

#include "RobotDemoDoc.h"
#include "RobotDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ID_TIMER_DEMO	100
#define TIME_DELAY_STEP	10

// CRobotDemoView

IMPLEMENT_DYNCREATE(CRobotDemoView, CView)

BEGIN_MESSAGE_MAP(CRobotDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(IDM_DEMO_RUN, OnDemoRun)
	ON_COMMAND(IDM_DEMO_STOP, OnDemoStop)
	ON_COMMAND(IDM_DEMO_PAUSE, OnDemoPause)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(IDM_DEMO_PAUSE, OnUpdateDemoPause)
	ON_UPDATE_COMMAND_UI(IDM_DEMO_RUN, OnUpdateDemoRun)
	ON_UPDATE_COMMAND_UI(IDM_DEMO_STOP, OnUpdateDemoStop)
	ON_COMMAND(IDM_VIEW_GRID, OnViewGrid)
	ON_UPDATE_COMMAND_UI(IDM_VIEW_GRID, OnUpdateViewGrid)
	ON_COMMAND(IDM_MOUSE_NOTHING, OnMouseNothing)
	ON_UPDATE_COMMAND_UI(IDM_MOUSE_NOTHING, OnUpdateMouseNothing)
	ON_COMMAND(IDM_MOUSE_PAN, OnMousePan)
	ON_UPDATE_COMMAND_UI(IDM_MOUSE_PAN, OnUpdateMousePan)
	ON_COMMAND(IDM_MOUSE_ROTATE, OnMouseRotate)
	ON_UPDATE_COMMAND_UI(IDM_MOUSE_ROTATE, OnUpdateMouseRotate)
	ON_COMMAND(IDM_MOUSE_ZOOM, OnMouseZoom)
	ON_UPDATE_COMMAND_UI(IDM_MOUSE_ZOOM, OnUpdateMouseZoom)
	ON_COMMAND(IDM_MOUSE_ROTATE_AROUND, OnMouseRotateAround)
	ON_UPDATE_COMMAND_UI(IDM_MOUSE_ROTATE_AROUND, OnUpdateMouseRotateAround)
	ON_COMMAND(IDM_DEMO_GRAPH_RESULT, OnDemoGraphResult)
	ON_COMMAND(IDM_DEMO_GRAPH_TRAJECTORY, OnDemoGraphTrajectory)
	ON_COMMAND(IDM_DEMO_RESULT_TABLE, OnDemoResultTable)
	ON_COMMAND(IDM_SETTING_LIGHT, OnSettingLight)
	ON_COMMAND(IDM_SETTING_MATERIAL_ELEMENTS, OnSettingMaterialElements)
END_MESSAGE_MAP()

// CRobotDemoView construction/destruction

CRobotDemoView::CRobotDemoView() noexcept
{
	// TODO: add construction code here

}

CRobotDemoView::~CRobotDemoView()
{
}

BOOL CRobotDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRobotDemoView drawing

void CRobotDemoView::OnDraw(CDC* /*pDC*/)
{
	CRobotDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRobotDemoView printing

BOOL CRobotDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRobotDemoView diagnostics

#ifdef _DEBUG
void CRobotDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotDemoDoc* CRobotDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotDemoDoc)));
	return (CRobotDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRobotDemoView message handlers
COpenGLCtrlDemo* CRobotDemoView::GetOpenGLCtrlDemo()
{
	return &GetDocument()->m_DemoModel;
}


int CRobotDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	COpenGLCtrlDemo* pDemoModel = GetOpenGLCtrlDemo();
	if (!pDemoModel->m_hWnd)
	{
		CRect rect;
		GetClientRect(rect);
		pDemoModel->Create(rect, this, 100);
		//pDemoModel->SetFunctionDrawOpenGL(DrawOPenGL);
		//pDemoModel->SetFunctionDrawDC(DrawDC);

		pDemoModel->SetScaleWithClient();
		pDemoModel->SetMouseStyleDone(CMouseEvent::MOUSE_ROTATE);
		pDemoModel->CreateModel();
		pDemoModel->OnViewTop();

		pDemoModel->SetAngleView(-60, 0, -135);
	}
	return 0;
}

void CRobotDemoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (GetOpenGLCtrlDemo()->GetSafeHwnd())
	{
		CRect rect;
		GetClientRect(rect);
		GetOpenGLCtrlDemo()->MoveWindow(rect);
	}
}

void CRobotDemoView::OnDemoRun()
{
	// TODO: Add your command handler code here
	//SetTimer(ID_TIMER_DEMO,TIME_DELAY_STEP,0);
	COpenGLCtrlDemo* pOpenGL = GetOpenGLCtrlDemo();
	int timedelay = int(pOpenGL->m_trajectory.Get_dt() * 1000.0);
	SetTimer(ID_TIMER_DEMO, timedelay, 0);
	m_stateDemo = 1;
}

void CRobotDemoView::OnDemoStop()
{
	// TODO: Add your command handler code here
	KillTimer(ID_TIMER_DEMO);
	GetDocument()->m_DemoModel.Stop();
	m_stateDemo = 0;
}

void CRobotDemoView::OnDemoPause()
{
	// TODO: Add your command handler code here
	KillTimer(ID_TIMER_DEMO);
	m_stateDemo = 2;
}

//void CRobotDemoView::OnTimer(UINT nIDEvent)
#ifndef _WIN64
void CRobotDemoView::OnTimer(UINT nIDEvent)
#else
void CRobotDemoView::OnTimer(UINT_PTR nIDEvent)
#endif _WIN64
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == ID_TIMER_DEMO)
		GetDocument()->m_DemoModel.Run();
	CView::OnTimer(nIDEvent);
}

void CRobotDemoView::OnUpdateDemoPause(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_stateDemo == 2);
	pCmdUI->Enable(m_stateDemo == 1);
}

void CRobotDemoView::OnUpdateDemoRun(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_stateDemo == 1);
	pCmdUI->Enable(m_stateDemo != 1);
}

void CRobotDemoView::OnUpdateDemoStop(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_stateDemo != 0);
	pCmdUI->SetCheck(m_stateDemo == 0);
}

void CRobotDemoView::OnViewGrid()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.m_showGrid = !GetDocument()->m_DemoModel.m_showGrid;
	GetDocument()->m_DemoModel.Invalidate(FALSE);
}

void CRobotDemoView::OnUpdateViewGrid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.m_showGrid);
}

void CRobotDemoView::OnMouseNothing()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.SetMouseStyleDone(CMouseEvent::MOUSE_NOTHING);
}

void CRobotDemoView::OnUpdateMouseNothing(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.GetMouseStyleDone() == CMouseEvent::MOUSE_NOTHING);
}

void CRobotDemoView::OnMousePan()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.SetMouseStyleDone(CMouseEvent::MOUSE_PAN);
}

void CRobotDemoView::OnUpdateMousePan(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.GetMouseStyleDone() == CMouseEvent::MOUSE_PAN);
}

void CRobotDemoView::OnMouseRotate()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.SetMouseStyleDone(CMouseEvent::MOUSE_ROTATE);
}

void CRobotDemoView::OnUpdateMouseRotate(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.GetMouseStyleDone() == CMouseEvent::MOUSE_ROTATE);
}

void CRobotDemoView::OnMouseZoom()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.SetMouseStyleDone(CMouseEvent::MOUSE_ZOOM);
}

void CRobotDemoView::OnUpdateMouseZoom(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.GetMouseStyleDone() == CMouseEvent::MOUSE_ZOOM);
}

void CRobotDemoView::OnMouseRotateAround()
{
	// TODO: Add your command handler code here
	GetDocument()->m_DemoModel.SetMouseStyleDone(CMouseEvent::MOUSE_ROTATE_AROUND);
}

void CRobotDemoView::OnUpdateMouseRotateAround(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->m_DemoModel.GetMouseStyleDone() == CMouseEvent::MOUSE_ROTATE_AROUND);
}


#include "DlgGraphs.h"
void CRobotDemoView::OnDemoGraphResult()
{
	// TODO: Add your command handler code here
	CDlgGraphs	dlg;
	dlg.m_pModel = &GetOpenGLCtrlDemo()->m_Model;
	dlg.m_pTrajectory = &GetOpenGLCtrlDemo()->m_trajectory;
	dlg.DoModal();
}

#include "DlgGraphTrajectory.h"
void CRobotDemoView::OnDemoGraphTrajectory()
{
	// TODO: Add your command handler code here
	CDlgGraphTrajectory	dlg;
	dlg.m_pModel = &GetOpenGLCtrlDemo()->m_Model;
	dlg.m_pTrajectory = &GetOpenGLCtrlDemo()->m_trajectory;
	dlg.DoModal();
}

#include "DlgResultTable.h"
void CRobotDemoView::OnDemoResultTable()
{
	// TODO: Add your command handler code here
	CDlgResultTable	dlg;
	dlg.m_pModel = &GetDocument()->m_DemoModel.m_Model;
	dlg.DoModal();
}

void CRobotDemoView::OnSettingLight()
{
	// TODO: Add your command handler code here
	int oldState = m_stateDemo;
	if (oldState == 1) OnDemoPause();

	CDlgSettingLight dlg;
	dlg.SetData(GetOpenGLCtrlDemo()->m_glLight, GetOpenGLCtrlDemo());
	dlg.DoModal();

	if (oldState == 1) OnDemoRun();
}

#include "DlgSelectElement.h"

void CRobotDemoView::OnSettingMaterialElements()
{
	// TODO: Add your command handler code here
	CDlgSelectElement dlgElement;
	dlgElement.m_pOpenGLCtrlDemo = GetOpenGLCtrlDemo();

	if (dlgElement.DoModal() == IDOK)
	{
		int oldState = m_stateDemo;
		if (oldState == 1) OnDemoPause();

		STRUCT_OBJECTGLLIST* m_pModelElement = &(GetOpenGLCtrlDemo()->m_Model.m_listElement[dlgElement.m_SelectedElement].m_glList);
		CDlgSettingMaterial dlg;
		dlg.SetData(m_pModelElement->m_glMaterial, NULL, GetOpenGLCtrlDemo());
		if (dlg.DoModal() == IDOK)
		{
			GetOpenGLCtrlDemo()->Invalidate(FALSE);
		}

		if (oldState == 1) OnDemoRun();
	}

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		dlgElement.m_pOpenGLCtrlDemo->m_Model.m_listElement[i].m_drawBound = FALSE;
	}
}

void CRobotDemoView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	/*
	COpenGLCtrlDemo* pDemoModel = GetOpenGLCtrlDemo();
	CString sfname;
	sfname = GetDocument()->GetPathName();
	if (pDemoModel->m_hWnd)
	{
		if ((pDemoModel->m_trajectory.LoadTrajectory(sfname) == 0))//||(sfname.IsEmpty()))
		{
			//if (sfname.IsEmpty()) pDemoModel->m_trajectory.CreateDefaultTrajectory();

			pDemoModel->MakeCurrent();

			pDemoModel->m_Model.Reset();
			pDemoModel->m_trajectory.CreateDrawList();
			pDemoModel->m_trajectory.ExportData(pDemoModel->m_Model.m_trajectory[0], pDemoModel->m_Model.m_trajectory[1], pDemoModel->m_Model.m_trajectory[2],
				pDemoModel->m_Model.m_trajectory[3], pDemoModel->m_Model.m_trajectory[4], pDemoModel->m_Model.m_trajectory[5],
				pDemoModel->m_Model.m_trajectory[6], pDemoModel->m_Model.m_trajectory[7], pDemoModel->m_Model.m_trajectory[8]);
			pDemoModel->Invalidate();

			pDemoModel->m_Model.Solve();

			pDemoModel->MakeNotCurrent();

		}
	}
	*/
}

void CRobotDemoView::OnDemoResolve()
{
	// TODO: Add your command handler code here
	COpenGLCtrlDemo* pDemoModel = GetOpenGLCtrlDemo();
	pDemoModel->m_Model.Reset();
	pDemoModel->m_trajectory.ExportData(pDemoModel->m_Model.m_trajectory[0], pDemoModel->m_Model.m_trajectory[1], pDemoModel->m_Model.m_trajectory[2],
		pDemoModel->m_Model.m_trajectory[3], pDemoModel->m_Model.m_trajectory[4], pDemoModel->m_Model.m_trajectory[5],
		pDemoModel->m_Model.m_trajectory[6], pDemoModel->m_Model.m_trajectory[7], pDemoModel->m_Model.m_trajectory[8]);
	pDemoModel->m_Model.Solve();
}