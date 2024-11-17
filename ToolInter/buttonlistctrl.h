#ifndef _LISTBUTTON_CTRL_
#define _LISTBUTTON_CTRL_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// buttonlist.h : header file
//
#include "WinList.h"
/////////////////////////////////////////////////////////////////////////////
// CButtonList window
#ifndef LISTBUTTON_CTRL_EXT_CLASS
#define LISTBUTTON_CTRL_EXT_CLASS TOOLINTER_EXT_CLASS
#endif LISTBUTTON_CTRL_EXT_CLASS

class LISTBUTTON_CTRL_EXT_CLASS CButtonList : public CButton
{
	friend class CWinList;
// Construction
public:
	CButtonList();

protected:
	CWinList* m_pListWindow;
	int m_itemselected;
	CStringArray m_listitem;
	bool m_changed;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonList)
	//}}AFX_VIRTUAL

// Implementation
public:
	CStringArray* GetListItem();
	void DeleteItem(const int & id);
	void DeleteAllItem();
	void SetChanged(const bool & cd=true);
	bool GetChanged();
	void SetItemSelected(const int & id);
	int GetItemSelected();
	int GetItemCount();
	void AddItem(const CString & sItem);
	virtual ~CButtonList();

	// Generated message map functions
protected:
	void UpdateState();
	//{{AFX_MSG(CButtonList)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg void OnButtonClicked();

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif _LISTBUTTON_CTRL_
