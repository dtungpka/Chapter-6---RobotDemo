#if !defined(AFX_OPENGLCTRL_H__6D4A7090_6688_411E_8285_9A1D2444332B__INCLUDED_)
#define AFX_OPENGLCTRL_H__6D4A7090_6688_411E_8285_9A1D2444332B__INCLUDED_

//OpenGL control
//Version : 2.0
//Created by Vu Le Huy - 27/11/2004

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// openglctrl.h : header file

#ifndef OPENGL_EXT_CLASS
#define OPENGL_EXT_CLASS
#endif OPENGL_EXT_CLASS


//-------------------------------------------------------------------------
//	Draw Base Shapes
//-------------------------------------------------------------------------
void OPENGL_EXT_CLASS DrawCircle(const double & r, const int & numpoint=20);
void OPENGL_EXT_CLASS DrawCylinder(const double & r1,const double & r2,const double & h, const int & numpoint=20);
void OPENGL_EXT_CLASS DrawCylinder(const double & r,const double & h, const int & numpoint=20);
void OPENGL_EXT_CLASS DrawSphere(const double & r, const int & numpoint=20);

//-------------------------------------------------------------------------
//	Class for Vector 3f
//-------------------------------------------------------------------------
#include <math.h>
class OPENGL_EXT_CLASS Vec3f
{
public:
    float x, y, z;
	
    Vec3f (void) {x=0;y=0;z=0;};
    Vec3f (const float X, const float Y, const float Z) 
	{ x=X; y=Y; z=Z; };
    Vec3f (const Vec3f& v) 
	{ x=v.x; y=v.y; z=v.z; };
    Vec3f (float v[3])
	{ x=v[0]; y=v[1]; z=v[2]; };
    void Set (const float X, const float Y, const float Z)
	{ x=X; y=Y; z=Z; };
    void Set (float v[3])
	{ x=v[0]; y=v[1]; z=v[2]; };
	
    Vec3f& operator = (const Vec3f& A)            // ASSIGNMENT (=)
	{ x=A.x; y=A.y; z=A.z; 
	return(*this);  };
    Vec3f operator + (const Vec3f& A) const       // ADDITION (+)
	{ Vec3f Sum(x+A.x, y+A.y, z+A.z); 
	return(Sum); };
    Vec3f operator - (const Vec3f& A) const       // SUBTRACTION (-)
	{ Vec3f Diff(x-A.x, y-A.y, z-A.z);
	return(Diff); };
    float operator * (const Vec3f& A) const       // DOT-PRODUCT (*)
	{ float DotProd = x*A.x+y*A.y+z*A.z; 
	return(DotProd); };
    Vec3f operator / (const Vec3f& A) const       // CROSS-PRODUCT (/)
	{ Vec3f CrossProd(y*A.z-z*A.y, z*A.x-x*A.z, x*A.y-y*A.x);
	return(CrossProd); };
    Vec3f operator * (const float s) const        // MULTIPLY BY SCALAR (*)
	{ Vec3f Scaled(x*s, y*s, z*s); 
	return(Scaled); };
    Vec3f operator / (const float s) const        // DIVIDE BY SCALAR (/)
	{ Vec3f Scaled(x/s, y/s, z/s);
	return(Scaled); };
	
    void operator += (const Vec3f A)              // ACCUMULATED VECTOR ADDITION (+=)
	{ x+=A.x; y+=A.y; z+=A.z; };
    void operator -= (const Vec3f A)              // ACCUMULATED VECTOR SUBTRACTION (+=)
	{ x-=A.x; y-=A.y; z-=A.z; };
    void operator *= (const float s)              // ACCUMULATED SCALAR MULT (*=)
	{ x*=s; y*=s; z*=s; };
    void operator /= (const float s)              // ACCUMULATED SCALAR DIV (/=)
	{ x/=s; y/=s; z/=s; };
    Vec3f operator - (void) const                 // NEGATION (-)
	{ Vec3f Negated(-x, -y, -z);
	return(Negated); };
	
    float operator [] (const int i) const         // ALLOWS VECTOR ACCESS AS AN ARRAY.
	{ return( (i==0)?x:((i==1)?y:z) ); };
    float & operator [] (const int i)
	{ return( (i==0)?x:((i==1)?y:z) ); };
	
    float Length (void) const                     // LENGTH OF VECTOR
	{ return ((float)sqrt((double)(x*x+y*y+z*z))); };
    float LengthSqr (void) const                  // LENGTH OF VECTOR (SQUARED)
	{ return (x*x+y*y+z*z); };
    void Normalize (void)                         // NORMALIZE VECTOR
	{ float L = Length();                       // CALCULATE LENGTH
	if (L>0) { x/=L; y/=L; z/=L; } };         // DIV COMPONENTS BY LENGTH
	
    void Print()
	{ printf("(%.3f, %.3f, %.3f)\n",x, y, z); }
	
    Vec3f multComponents (const Vec3f& A) const
	{ return Vec3f (x*A.x, y*A.y, z*A.z); }
};

/////////////////////////////////////////////////////////////////////////////
// COpenGLCtrl window
/////////////////////////////////////////////////////////////////////////////

class COpenGLCtrl;

/////////////////////////////////////////////////////////////////////////////
// COpenGLCtrl window

#define OPENGLCTRL_CLASSNAME    _T("MFCOpenGLCtrl")  // Window class name
class COpenGLCtrl;

void /*AFXAPI*/ DDX_OpenGLControl(CDataExchange* pDX, int nIDC, COpenGLCtrl& rControl);

// Handy functions
#define IsSHIFTpressed() ( (GetKeyState(VK_SHIFT) & (1 << (sizeof(SHORT)*8-1))) != 0   )
#define IsCTRLpressed()  ( (GetKeyState(VK_CONTROL) & (1 << (sizeof(SHORT)*8-1))) != 0 )
//================================
void OPENGL_EXT_CLASS CalcNormal12f(double p10,double p11,double p12,
				   double p20,double p21,double p22,
				   double p30,double p31,double p32, 
				   double &n0,double &n1,double &n2);
//================================
#define RED			0.5
#define GREEN		0.0
#define BLUE		0.5
//================================
//================================
typedef void (*FunctionDrawOpenGLCtrl)(COpenGLCtrl *);
//================================
//================================
typedef GLfloat GLfloat4f[4];
typedef struct OPENGL_EXT_CLASS GL_MATERIAL
{
public:
	static int styledefault;

	UINT FaceApply;
	GLfloat4f Diffuse;
	GLfloat4f Ambient;
	GLfloat4f Specular;
	GLfloat4f Emission;
	GLfloat Shininess;
	bool UseGLBend;

	GL_MATERIAL()
	{
		FaceApply=GL_FRONT_AND_BACK;
		//GL_FRONT,GL_BACK
		Default();
	}
	static int GetStyleDefault();
	static void SetStyleDefault(int style);
	void Default();
	void Copy(const GL_MATERIAL & ma);
	void SetUpMaterial();
	void SetAmbient(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetDiffuse(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetAmbientByColor(const COLORREF & color,const double & a3);
	void SetSpecular(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetEmission(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);

	void Serialize(CArchive& ar);
	void AfxWrite(const CString & docname,const CString & itname);
	void AfxGet(const CString & docname,const CString & itname);
}gl_material;
//================================
typedef struct OPENGL_EXT_CLASS GL_LIGHT
{
public:
	static int styledefault;

	UINT ID_LIGHT;
	GLfloat4f Ambient;
	GLfloat4f Diffuse;
	GLfloat4f Specular;
	GLfloat4f Position;
	GLfloat4f SpotDirection;
	GLfloat	SpotCutOff;
	GLfloat	SpotExponent;
	GLfloat constant_atten,quad_atten,linear_atten;
	GL_LIGHT()
	{
		ID_LIGHT=GL_LIGHT0;
		Default();
	}
	static int GetStyleDefault();
	static void SetStyleDefault(int style);
	void Default();
	void Copy(const GL_LIGHT & ma);
	void SetUpLight(const bool & notmove=true);
	void SetAmbient(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetDiffuse(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetSpecular(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetPosition(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);
	void SetSpotDirection(const GLfloat & a0,const GLfloat & a1,const GLfloat & a2,const GLfloat & a3);

	void Serialize(CArchive& ar);
	void AfxWrite(const CString & docname,const CString & itname);
	void AfxGet(const CString & docname,const CString & itname);

	static void Enable();
	static void Disable();
}gl_light;

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//	struct STRUCT_OBJECTGLLIST for drawing by glList
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------

typedef struct OPENGL_EXT_CLASS STRUCT_OBJECTGLLIST
{
	GL_MATERIAL	 m_glMaterial;
	int m_gllist;
	UINT  m_modeshowFront;
	UINT  m_modeshowBack;
	BOOL m_show;
	char m_name[256];
	Vec3f m_Max,m_Min;
	
	STRUCT_OBJECTGLLIST();
	double GetCenterX();
	double GetCenterY();
	double GetCenterZ();
	double GetSizeX();
	double GetSizeY();
	double GetSizeZ();
	
	void BeginNewList();
	void EndNewList();
	void DrawBound(const COLORREF & color);
	void Draw();

	void SetName(const CString & sname);
	CString GetName();
}struct_objectgllist;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Texture
/*/
class OPENGL_EXT_CLASS CTexture 
{
public: 
	//CTexture();
	CTexture(char *sfilename=NULL);
	~CTexture();
	void setTexture();
	void setTexFile(CString sfilename);

	void SetTexEnv(const int & texenv){m_modeTexEnv=texenv;}
	int GetTexEnv(){return m_modeTexEnv;}
protected : 
    //char *texFileName;
    AUX_RGBImageRec *image;
	int first_time;
	int m_modeTexEnv;
};
//*/
//================================
//================================
// CMouseEvent
class OPENGL_EXT_CLASS CMouseEvent
{
protected:
	bool m_left_down;
	bool m_mid_down;
	CPoint m_OldPosMouse,m_click_pt;
	COpenGLCtrl * m_pOpenGLCtrl;
	UINT m_styledone;//=0 : do nothing
								//=1 : pan
								//=2 : zoom
								//=3 : rotate
	HCURSOR m_lhCursor_pan[2];
	HCURSOR m_lhCursor_zoom[2];
	HCURSOR m_lhCursor_rotate[2];
	HCURSOR m_lhCursor_rotateAround[2];
	HCURSOR m_lhCursor_Normal;
	HCURSOR m_lhCursor;
public :
	enum
	{
		MOUSE_NOTHING=0,//  0
		MOUSE_PAN,//  1
		MOUSE_ZOOM,//  2
		MOUSE_ROTATE,//  3
		MOUSE_ROTATE_AROUND,//  4
	};

	CMouseEvent();
	~CMouseEvent();

	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMButtonUp(UINT nFlags, CPoint point);

	void SetOpenGLCtrl(COpenGLCtrl * pCtrl){m_pOpenGLCtrl=pCtrl;}
	void SetMouseStyleDone(const UINT & sty){m_styledone=sty;}
	UINT  GetMouseStyleDone(){return m_styledone;}

	void SetCursorNormal(const UINT & ID_=0);
	void SetCursorPan(const UINT & ID_Up,const UINT & ID_Down);
	void SetCursorZoom(const UINT & ID_Up,const UINT & ID_Down);
	void SetCursorRotate(const UINT & ID_Up,const UINT & ID_Down);
	void SetCursorRotateAround(const UINT & ID_Up,const UINT & ID_Down);

	void SetCursorNormal(const HCURSOR & ID_=NULL);
	void SetCursorPan(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL);
	void SetCursorZoom(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL);
	void SetCursorRotate(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL);
	void SetCursorRotateAround(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL);

private:
	void SetCursorWindow(CPoint point);

	void PanOnLButtonDown(UINT nFlags, CPoint point);
	void PanOnMButtonDown(UINT nFlags, CPoint point);
	void PanOnMouseMove(UINT nFlags, CPoint point);
	BOOL PanOnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void PanOnLButtonUp(UINT nFlags, CPoint point);
	void PanOnMButtonUp(UINT nFlags, CPoint point);

	void ZoomOnLButtonDown(UINT nFlags, CPoint point);
	void ZoomOnMButtonDown(UINT nFlags, CPoint point);
	void ZoomOnMouseMove(UINT nFlags, CPoint point);
	BOOL ZoomOnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void ZoomOnLButtonUp(UINT nFlags, CPoint point);
	void ZoomOnMButtonUp(UINT nFlags, CPoint point);

	void RotateOnLButtonDown(UINT nFlags, CPoint point);
	void RotateOnMButtonDown(UINT nFlags, CPoint point);
	void RotateOnMouseMove(UINT nFlags, CPoint point);
	BOOL RotateOnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void RotateOnLButtonUp(UINT nFlags, CPoint point);
	void RotateOnMButtonUp(UINT nFlags, CPoint point);

	void RotateAroundOnLButtonDown(UINT nFlags, CPoint point);
	void RotateAroundOnMButtonDown(UINT nFlags, CPoint point);
	void RotateAroundOnMouseMove(UINT nFlags, CPoint point);
	BOOL RotateAroundOnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void RotateAroundOnLButtonUp(UINT nFlags, CPoint point);
	void RotateAroundOnMButtonUp(UINT nFlags, CPoint point);
};
//================================
//================================
typedef GLfloat GLMatrix[16];
#ifndef PARENT_OPENGL_CONTROL
	//#define PARENT_OPENGL_CONTROL CView
	#define PARENT_OPENGL_CONTROL CWnd
#endif PARENT_OPENGL_CONTROL
//================================
void OPENGL_EXT_CLASS LoadCursorOpenGL(COpenGLCtrl *pOpenGL);
class OPENGL_EXT_CLASS COpenGLCtrl : public PARENT_OPENGL_CONTROL
{
// Construction
	DECLARE_DYNCREATE(COpenGLCtrl)
	friend class CMouseEvent;

public:
	COpenGLCtrl(const bool & mode3D=true);

	void SetCreateMode3D(const bool & mode3D=true){m_creatmode3d=mode3D;}
	bool GetCreateMode3D(){return m_creatmode3d;}

	BOOL Create(const RECT& rect, CWnd* parent, UINT nID,
                DWORD dwStyle = WS_CHILD |WS_TABSTOP | WS_VISIBLE);
	BOOL CreateEx(const RECT& rect, CWnd* pParentWnd, UINT nID, 
				DWORD dwStyle=WS_CHILD |WS_TABSTOP | WS_VISIBLE,
				DWORD dwStyleEx=WS_EX_CLIENTEDGE);
	BOOL CreateFromStatic( UINT nID, CWnd* pParent );

	virtual void  OnDraw(CDC* pDC);

// Attributes
public:
	void SetBkColor(const COLORREF & cl){m_bkColor=cl;}
	COLORREF GetBkColor() {return m_bkColor;}

	void SetFunctionDrawOpenGL(FunctionDrawOpenGLCtrl f){m_functiondrawOpenGL=f;}
	FunctionDrawOpenGLCtrl GetFunctionDrawOpenGL(){return m_functiondrawOpenGL;}

	void SetFunctionDrawDC(FunctionDrawOpenGLCtrl f){m_functiondrawDC=f;}
	FunctionDrawOpenGLCtrl GetFunctionDrawDC(){return m_functiondrawDC;}

	void SetNearPlane(const GLfloat & dplane){m_fNearPlane=dplane;}
	GLfloat GetNearPlane(){return m_fNearPlane;}

	void SetFarPlane(const GLfloat & dplane){m_fFarPlane=dplane;}
	GLfloat GetFarPlane(){return m_fFarPlane;}

	void SetAnglePerPlane(const GLfloat & alg){m_fAnglePer=alg;}
	GLfloat GetAnglePerPlane(){return m_fAnglePer;}

	void SetMouseStyleDone(const UINT &style){m_MouseEvent.SetMouseStyleDone(style);}
	UINT GetMouseStyleDone(){return m_MouseEvent.GetMouseStyleDone();}

	void SetCursorNormal(const UINT & ID_=0){m_MouseEvent.SetCursorNormal(ID_);}
	void SetCursorPan(const UINT & ID_Up,const UINT & ID_Down){m_MouseEvent.SetCursorPan(ID_Up,ID_Down);}
	void SetCursorZoom(const UINT & ID_Up,const UINT & ID_Down){m_MouseEvent.SetCursorZoom(ID_Up,ID_Down);}
	void SetCursorRotate(const UINT & ID_Up,const UINT & ID_Down){m_MouseEvent.SetCursorRotate(ID_Up,ID_Down);}
	void SetCursorRotateAround(const UINT & ID_Up,const UINT & ID_Down){m_MouseEvent.SetCursorRotateAround(ID_Up,ID_Down);}

	void SetCursorNormal(const HCURSOR & ID_=NULL){m_MouseEvent.SetCursorNormal(ID_);}
	void SetCursorPan(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL){m_MouseEvent.SetCursorPan(ID_Up,ID_Down);}
	void SetCursorZoom(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL){m_MouseEvent.SetCursorZoom(ID_Up,ID_Down);}
	void SetCursorRotate(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL){m_MouseEvent.SetCursorRotate(ID_Up,ID_Down);}
	void SetCursorRotateAround(const HCURSOR & ID_Up,const HCURSOR & ID_Down=NULL){m_MouseEvent.SetCursorRotateAround(ID_Up,ID_Down);}

	void SetScaleWithClient(const bool & scl=true){m_scalewithclient=scl;}
	bool GetScaleWithClient(){ return m_scalewithclient;}

	void SetTransValueSystem(const double & d){m_Transval=d;}
	void SetRotateValueSystem(const double & d){m_Rotaval=d;}
	void SetScaleValueSystem(const double & d){m_Scaleval=d;}

	double GetTransValueSystem(){return m_Transval;}
	double GetRotateValueSystem(){return m_Rotaval;}
	double GetScaleValueSystem(){return m_Scaleval;}

	void SetPanScaleValue(const double & d){m_PanScaleValue=d;}
	void SetZoomScaleValue(const double & d){m_ZoomScaleValue=d;}
	void SetRotateScaleValue(const double & d){m_RotateScaleValue=d;}

	double GetPanScaleValue(){return m_PanScaleValue;}
	double GetZoomScaleValue(){return m_ZoomScaleValue;}
	double GetRotateScaleValue(){return m_RotateScaleValue;}

	void SetPosXValueSystem(const double & d){m_ddx=d;}
	void SetPosYValueSystem(const double & d){m_ddy=d;}
	void SetPosZValueSystem(const double & d){m_ddz=d;}

	double GetPosXValueSystem(){return m_ddx;}
	double GetPosYValueSystem(){return m_ddy;}
	double GetPosZValueSystem(){return m_ddz;}

	virtual void OnRotateDecX();
	virtual void OnRotateDecY();
	virtual void OnRotateDecZ();
	virtual void OnRotateIncX();
	virtual void OnRotateIncY();
	virtual void OnRotateIncZ();

	virtual void OnTranslateDecX();
	virtual void OnTranslateDecY();
	virtual void OnTranslateIncX();
	virtual void OnTranslateIncY();

	virtual void OnZoomIn();
	virtual void OnZoomOut();

	void MakeFont();
	void PrintString(const char* str);
	void PrintString(const char* str, COLORREF & color);
	void PrintString(const float & x, const float & y, const float & z, const char* str, COLORREF & color);

	void DrawCoordinate3D(const double & laxist,const double & raxist,const COLORREF & color,const bool & autocall=true);
	void DrawCoordinate(const double & laxist,const COLORREF & color);

	void MakeCurrent();
	void MakeNotCurrent();

protected:
	bool m_creatmode3d;
	bool m_scalewithclient;
	FunctionDrawOpenGLCtrl m_functiondrawOpenGL;
	FunctionDrawOpenGLCtrl m_functiondrawDC;

	HGLRC m_hRC;
	HPALETTE m_hPalette;
	COLORREF m_bkColor;

	CPalette	m_CurrentPalette;
	CPalette	*m_pOldPalette;

	/*
	double m_dex,m_dey,m_dez;
	double m_dnx,m_dny,m_dnz;
	double m_dux,m_duy,m_duz;
	*/
	GLfloat m_fNearPlane,m_fFarPlane,m_fAnglePer;

	GLMatrix m_matrixsystem;
	//Translate variables
	double m_ddx,m_ddy,m_ddz;
	//Translate value
	double m_Transval;
	//Rotate value
	double m_Rotaval;
	//Scale value
	double m_Scaleval;

	//pan scale value
	double m_PanScaleValue;
	//zoom scale value
	double m_ZoomScaleValue;
	//Rotate scale value
	double m_RotateScaleValue;

	BOOL RegisterWindowClass();
	void ResetScrollBars();

	void SetupLogicalPalette();
	void CreateRGBPalette(CDC *pCDC);
	unsigned char ComponentFromIndex(int i, UINT nbits, UINT shift);
	void CopyToClipBoard(CWnd *pWnd);

	void Draw(CDC* pDC);

private:
	CMouseEvent m_MouseEvent;
	bool m_focus,m_drawforcus;
	bool m_isbusy;
	GLuint m_FontListBase;
	BOOL m_bGotFont;
// Operations
public:
	void SetDrawForcusLine(const bool & draw=true){m_drawforcus=draw;}
	bool GetDrawForcusLine(){return m_drawforcus;}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void DrawInDC(CDC * pDC);
	virtual void DrawInOpenGL();
	bool ProjectCurrent2Window(const GLdouble & x,const GLdouble & y,const GLdouble & z,
								 CPoint & pScreen);
	bool Project2Window(const GLdouble & x,const GLdouble & y,const GLdouble & z,
								 CPoint & pScreen);
	bool Project2Real(CPoint & pScreen,const double & winz,
								 GLdouble &x, GLdouble &y, GLdouble &z);
	void SetAngleView(const double & ax,const double & ay,const double & az);
	void RotateX(const double & angle);
	void RotateY(const double & angle);
	void RotateZ(const double & angle);

	HGLRC GetHGLRC();
	int CreateOpenGL();
	virtual ~COpenGLCtrl();

	void CopyToClipBoard();

	// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseNothing();
	afx_msg void OnUpdateMouseNothing(CCmdUI* pCmdUI);
	afx_msg void OnMousePan();
	afx_msg void OnUpdateMousePan(CCmdUI* pCmdUI);
	afx_msg void OnMouseRotate();
	afx_msg void OnUpdateMouseRotate(CCmdUI* pCmdUI);
	afx_msg void OnMouseRotateAround();
	afx_msg void OnUpdateMouseRotateAround(CCmdUI* pCmdUI);
	afx_msg void OnMouseZoom();
	afx_msg void OnUpdateMouseZoom(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
public:
	virtual afx_msg void OnViewFront();
	virtual afx_msg void OnViewBack();
	virtual afx_msg void OnViewLeft();
	virtual afx_msg void OnViewRight();
	virtual afx_msg void OnViewTop();
	virtual afx_msg void OnViewBottom();
	virtual afx_msg void OnViewAxis();
	virtual afx_msg void OnResetOriginal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLCTRL_H__6D4A7090_6688_411E_8285_9A1D2444332B__INCLUDED_)
