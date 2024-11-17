#pragma once
#include <afxwin.h>

/*
class CDlgSettingLight :
    public CDialog
{
};
*/

class OPENGLSETTING_EXT_CLASS CDlgSettingLight : public CDialog
{
	// Construction
public:
	void SetData(GL_LIGHT& light, COpenGLCtrl* pOpenGLCtrl = NULL);
	void SetOpenGLCtrl(COpenGLCtrl* pOpenGLCtrl);
	void GetLight(GL_LIGHT& light);
	void SetLight(GL_LIGHT& light);
	CDlgSettingLight(CWnd* pParent = NULL);   // standard constructor

protected:
	GL_LIGHT m_oldLight;
	GL_LIGHT* m_pglLight;
	COpenGLCtrl* m_pOpenGLCtrl;

	// Dialog Data
	//{{AFX_DATA(CDlgSettingLight)
	enum { IDD = IDD_DIALOG_SETTING_LIGHT };
	BOOL	m_position_w;
	float	m_attenuation_constant;
	float	m_attenuation_linear;
	float	m_attenuation_quadratic;
	float	m_position_x;
	float	m_position_y;
	float	m_position_z;
	float		m_spot_cutoff;
	float		m_spot_exponent;
	float	m_spot_direction_x;
	float	m_spot_direction_y;
	float	m_spot_direction_z;
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
	//}}AFX_DATA


	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSettingLight)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	void InitSlider();
	void SetSlider(const UINT& nID, const int& cursel, const int& min, const int& max, const int& numtick);

	// Generated message map functions
	//{{AFX_MSG(CDlgSettingLight)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnApply();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDefault();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeEditAttenuationConstant();
	afx_msg void OnChangeEditAttenuationLinear();
	afx_msg void OnChangeEditAttenuationQuadratic();
	afx_msg void OnChangeEditPositionX();
	afx_msg void OnChangeEditPositionY();
	afx_msg void OnChangeEditPositionZ();
	afx_msg void OnChangeEditSpotCutoff();
	afx_msg void OnChangeEditSpotDirectionX();
	afx_msg void OnChangeEditSpotDirectionY();
	afx_msg void OnChangeEditSpotDirectionZ();
	afx_msg void OnChangeEditSpotExponent();
	afx_msg void OnCheckPositionW();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

