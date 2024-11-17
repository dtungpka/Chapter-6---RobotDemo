
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CNewFrameWnd
{
	
protected: // create from serialization only
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

	void DockControlBarLeftOf(CToolBar* Bar, CToolBar* LeftOf);

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar        m_wndToolBar;
	CToolBar		m_wndToolBarMouse;
	CStatusBar      m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewToolbarMouseDone();
	afx_msg void OnUpdateViewToolbarMouseDone(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

};


