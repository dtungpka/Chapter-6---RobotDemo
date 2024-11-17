#pragma once
#include "DlgSettingMaterial.h"

class OPENGLSETTING_EXT_CLASS CDlgSettingMaterialMultiObject : public CDlgSettingMaterial
{
	// Construction
public:
	void AddObjectGLlist(STRUCT_OBJECTGLLIST* obj);
	CDlgSettingMaterialMultiObject(CWnd* pParent = NULL);   // standard constructor

	// Dialog Data
		//{{AFX_DATA(CDlgSettingMaterialMultiObject)
	enum { IDD = IDD_DIALOG_SETTING_MATERIAL_MULTIOBJECT };
	CListBox	m_listboxObjects;
	//}}AFX_DATA

protected:
	CArray<STRUCT_OBJECTGLLIST*, STRUCT_OBJECTGLLIST*> m_listobject;
	int m_nCurrentObj;
	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CDlgSettingMaterialMultiObject)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSettingMaterialMultiObject)
	afx_msg void OnSelchangeListObject();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

