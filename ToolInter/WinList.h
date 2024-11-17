#ifndef _WINLIST_CTRL_
#define _WINLIST_CTRL_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WinList.h : header file
//
//#include "newlist.h"
/////////////////////////////////////////////////////////////////////////////
// CWinList window
#ifndef LISTBUTTON_CTRL_EXT_CLASS
#define LISTBUTTON_CTRL_EXT_CLASS TOOLINTER_EXT_CLASS
#endif LISTBUTTON_CTRL_EXT_CLASS

class CButtonList;

class LISTBUTTON_CTRL_EXT_CLASS CNewList : public CListBox
{
	friend class CWinList;	
// Construction
public:
	CNewList();
	CWinList * m_WndParent;
	CFont m_font;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNewList)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class LISTBUTTON_CTRL_EXT_CLASS CWinList : public CWnd
{
	friend class CButtonList;	
	friend class CNewList;
// Construction
public:
	CButtonList* m_pParentBtn;
	CWinList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinList)
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateSizeAndPosition();
	CNewList m_listbox;
	virtual ~CWinList();

	// Generated message map functions
protected:
	void HideDropDown(const bool & update=true);
	//{{AFX_MSG(CWinList)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG
	afx_msg void OnKillfocusListBox();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif _WINLIST_CTRL_
