#ifndef _NEWTABCTRL_
#define _NEWTABCTRL_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewTabCtrl.h : header file
//
//created by Vu Le Huy, 2/9/2004
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CNewTabCtrl window
#include <afxtempl.h>
#include "XPTabCtrl.h"
#define PARENT_OF_NEWTABCTRL CTabCtrl //CXPTabCtrl
//#define USE_PARENT_HAVE_ONSELCHANGE
class TOOLINTER_EXT_CLASS CNewTabCtrl : public PARENT_OF_NEWTABCTRL
{
// Construction
public:
	CNewTabCtrl();

	int SetCurSel(int nItem);
// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetEnableTabItem(const int & idItem, const bool enable=true);
	virtual bool GetEnableTabItem(const int &idItem);
	void Redraw();
	void InsertTabPage(int index,CWnd *pCtrlInTab, LPCTSTR title, int nImg=0);
	void ChangeTabPage(int iIndex, CWnd *pNewTab, LPTSTR lpszCaption, int iImage=0);
	void DeleteTab(int iIndex);
	void ResetSizeAllItem();
	BOOL DeleteAllItems();
	BOOL DeleteItem(int nItem);

	CWnd* GetItemPageCtrl(int id);
	void SetPosTabOnBottom(BOOL posbt=true);
	void SetPosTabOnRight(BOOL posrt=true);

	void AddTabPage(CWnd * pCtrlInTab, LPCTSTR title, int nImg=0);
	void AddTabPageByListBox(CListBox * pCtrlInTab, LPCTSTR title, int nImg=0);
	void AddTabPageByEdit(CEdit * pCtrlInTab, LPCTSTR title, int nImg=0);
	void AddTabPageByTreeCtrl(CTreeCtrl * pCtrlInTab, LPCTSTR title, int nImg=0);
	void AddTabPageByDialog(CDialog * pCtrlInTab, UINT nIDdlg, LPCTSTR title, int nImg=0);

	BOOL SetImage(UINT nBitmapID, int cx, int nGrow, COLORREF crMask=RGB(255,255,255));
	virtual ~CNewTabCtrl();

	virtual COLORREF GetTextColor(int idItem);

protected:
	//virtual void DrawTabItem(CDC* pDC, int ixItem, const CRect& rcItemC, UINT uiFlags);

	// Generated message map functions
	//{{AFX_MSG(CNewTabCtrl)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	CImageList m_ImgList;
	CArray<CWnd*,CWnd*> m_listWnd;
	CArray<bool,bool> m_listTabEnable;
	int m_iSelectedTab;

	DECLARE_MESSAGE_MAP()
private:
	void SetAttTab(CWnd * pCtrlInTab,const int & id);
};

/////////////////////////////////////////////////////////////////////////////

#endif _NEWTABCTRL_
