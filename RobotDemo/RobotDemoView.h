
// RobotDemoView.h : interface of the CRobotDemoView class
//

#pragma once


class CRobotDemoView : public CView
{
protected: // create from serialization only
	CRobotDemoView() noexcept;
	DECLARE_DYNCREATE(CRobotDemoView)

// Attributes
public:
	CRobotDemoDoc* GetDocument() const;
	COpenGLCtrlDemo* GetOpenGLCtrlDemo();

	int m_stateDemo;

	CGraph m_graph;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRobotDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDemoRun();
	afx_msg void OnDemoStop();
	afx_msg void OnDemoPause();
#ifndef _WIN64
	afx_msg void OnTimer(UINT nIDEvent);
#else
	afx_msg void OnTimer(UINT_PTR nIDEvent);
#endif _WIN64
	afx_msg void OnUpdateDemoPause(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDemoRun(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDemoStop(CCmdUI* pCmdUI);
	afx_msg void OnViewGrid();
	afx_msg void OnUpdateViewGrid(CCmdUI* pCmdUI);
	afx_msg void OnMouseNothing();
	afx_msg void OnUpdateMouseNothing(CCmdUI* pCmdUI);
	afx_msg void OnMousePan();
	afx_msg void OnUpdateMousePan(CCmdUI* pCmdUI);
	afx_msg void OnMouseRotate();
	afx_msg void OnUpdateMouseRotate(CCmdUI* pCmdUI);
	afx_msg void OnMouseZoom();
	afx_msg void OnUpdateMouseZoom(CCmdUI* pCmdUI);
	afx_msg void OnMouseRotateAround();
	afx_msg void OnUpdateMouseRotateAround(CCmdUI* pCmdUI);
	afx_msg void OnDemoGraphResult();
	afx_msg void OnDemoGraphTrajectory();
	afx_msg void OnDemoResultTable();
	afx_msg void OnSettingLight();
	afx_msg void OnSettingMaterialElements();
	afx_msg void OnDemoResolve();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotDemoView.cpp
inline CRobotDemoDoc* CRobotDemoView::GetDocument() const
   { return reinterpret_cast<CRobotDemoDoc*>(m_pDocument); }
#endif

