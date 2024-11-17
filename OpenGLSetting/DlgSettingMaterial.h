#pragma once
#include <afxwin.h>


class OPENGLSETTING_EXT_CLASS CDlgSettingMaterial : public CDialog
{
	// Construction
public:

	CDlgSettingMaterial(CWnd* pParent = NULL);   // standard constructor
	CDlgSettingMaterial(int id, CWnd* pParent = NULL);   // standard constructor

	void GetMaterial(GL_MATERIAL& material);
	void SetMaterial(GL_MATERIAL& material);
	void SetShowObject(BOOL* showobject);
	void SetOpenGLCtrl(COpenGLCtrl* pOpenGLCtrl);
	void SetData(GL_MATERIAL& material, BOOL* showobject = NULL, COpenGLCtrl* pOpenGLCtrl = NULL);

protected:
	GL_MATERIAL m_oldMaterial;
	BOOL m_oldShowObject;
	GL_MATERIAL* m_pglMaterial;
	COpenGLCtrl* m_pOpenGLCtrl;
	BOOL* m_pShowObject;

	// Dialog Data
		//{{AFX_DATA(CDlgSettingMaterial)
	enum { IDD = IDD_DIALOG_SETTING_MATERIAL };
	CButton	m_HideObject;
	CButton	m_UseGLBend;
	int		m_ambient_alfa;
	int		m_ambient_blue;
	int		m_ambient_green;
	int		m_ambient_red;
	int		m_diffuse_alfa;
	int		m_diffuse_blue;
	int		m_diffuse_green;
	int		m_diffuse_red;
	int		m_specular_alfa;
	int		m_specular_blue;
	int		m_specular_green;
	int		m_specular_red;
	int		m_emitted_alfa;
	int		m_emitted_blue;
	int		m_emitted_green;
	int		m_emitted_red;
	int	m_shininess;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSettingMaterial)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitSlider();
	void SetSlider(const UINT& nID, const int& cursel, const int& min, const int& max, const int& numtick);

	// Generated message map functions
	//{{AFX_MSG(CDlgSettingMaterial)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDefault();
	afx_msg void OnApply();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCheckHideObject();
	afx_msg void OnCheckUseGlBend();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
