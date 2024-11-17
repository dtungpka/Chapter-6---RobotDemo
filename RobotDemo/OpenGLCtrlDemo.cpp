// OpenGLCtrlDemo.cpp: implementation of the COpenGLCtrlDemo class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "RobotDemo.h"
#include "OpenGLCtrlDemo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//#define SUBDIRECTORY_MODEL_FILE "stl-Binary\\"
//#define EXTENT_MODEL_FILE "stl"

#define SUBDIRECTORY_MODEL_FILE "STL-files\\"
#define EXTENT_MODEL_FILE "stl"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COpenGLCtrlDemo::COpenGLCtrlDemo()
{
	m_lengthAxis = 2000;
	m_colorAxis = RGB(255, 255, 255);
	m_colorGrid = RGB(0, 0, 255);
	m_scale = 1;

	m_glLight.SetStyleDefault(1);
	m_glLight.Default();

	m_glLight.constant_atten = 1.8f;
	m_glLight.linear_atten = 0.0f;
	m_glLight.quad_atten = 0.0f;

	double m_l = 1000;
	m_glLight.SetPosition((float)m_l / 40.0f, (float)m_l / 40.0f, (float)m_l / 40.0f, 1.0f);
	m_glLight.Position[3] = 1.0f;

	m_showGrid = TRUE;
}

COpenGLCtrlDemo::~COpenGLCtrlDemo()
{
}

void COpenGLCtrlDemo::DrawInOpenGL()
{
	if (GetCreateMode3D())
	{
		glClearColor(0.15f, 0.15f, 0.15f, 0.4f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//Dat tham so thuc hien viec pha tron
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_NORMALIZE);

		m_glLight.Enable();
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);//Khong Ap dung anh sang cho ca 2 mat
		m_glLight.SetUpLight();

		glPushMatrix();
		glScalef(1.0 / m_scale, 1.0 / m_scale, 1.0 / m_scale);

		//Add your draw code here
		m_Model.Draw();
		m_trajectory.Draw();
		if (m_showGrid) m_ModelGrid.Draw();
		glPopMatrix();

		//============

		//Draw Coordinates
		float oldPos3 = m_glLight.Position[3];
		m_glLight.Position[3] = 0;
		m_glLight.SetUpLight();
		m_glLight.Position[3] = oldPos3;

		if (!m_showGrid) DrawCoordinate3D(2, 0.05, RGB(150, 250, 55), false);//dat he truc tai goc

		GLdouble xp, yp, zp;
		CPoint pcoord; CRect rclient;
		GetClientRect(rclient);
		pcoord = CPoint(rclient.left + 40, rclient.bottom - 40);
		Project2Real(pcoord, 0.5, xp, yp, zp);
		glTranslatef(xp, yp, zp);
		DrawCoordinate3D(0.01, 0.0005, RGB(150, 50, 55), false);//dat he truc o goc Duoi-Trai man hinh
	}
	else
	{
		//Ve cac duong can ve tren do thi
		glPushMatrix();
		glScalef(1.0 / m_scale, 1.0 / m_scale, 1.0 / m_scale);
		glLineWidth(1);
		for (int i = 0; i < m_listPline.GetSize(); i++)
		{
			COLORREF color = RGB(255, 255, 255);
			if (i < m_listColorLine.GetSize()) color = m_listColorLine[i];
			DrawPline(m_listPline[i], color);
		}
		DrawGrid();
		glPopMatrix();
	}
}

void COpenGLCtrlDemo::DrawGrid(const int& style, const BOOL showValue1, const BOOL showValue2)
{
	glPushMatrix();

	CString s1("X"), s2("Y");
	if (style == 1)
	{
		s1 = "Y"; s2 = "Z";
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 1, 0, 0);
	}
	else
		if (style == 2)
		{
			s1 = "Z"; s2 = "X";
			glRotatef(-90, 0, 0, 1);
			glRotatef(-90, 0, 1, 0);
		}

	//Ve he truc toa do
	CString s;
	int num = 10;
	int dd = MakeRound(m_lengthAxis / num, 1);
	double aStep = dd;
	glLineWidth(1);
	//ve truc hoanh
	if (showValue1) PrintString(m_lengthAxis + dd / 1.5, 0, 0, s1, m_colorAxis);
	DrawLine(CPoint2d(-m_lengthAxis, 0), CPoint2d(m_lengthAxis, 0), m_colorAxis);
	//ve truc tung
	if (showValue2) PrintString(0, m_lengthAxis + dd / 2.0, 0, s2, m_colorAxis);
	DrawLine(CPoint2d(0, -m_lengthAxis), CPoint2d(0, m_lengthAxis), m_colorAxis);
	//ve cac duong luoi va danh so tren cac truc
	glLineWidth(1);
	if (showValue1 && showValue2) PrintString(dd / aStep, dd / aStep, 0, "0", m_colorAxis);
	for (int i = -num; i <= num; i++)
	{
		if (i == 0) continue;
		int pos = i * dd; s.Format("%d", pos);
		//danh so tren truc x
		DrawLine(CPoint2d(pos, dd / aStep), CPoint2d(pos, -dd / aStep), m_colorAxis);
		if (showValue1) PrintString(pos, dd / 10.0, 0, s, m_colorAxis);
		//danh so tren truc y
		DrawLine(CPoint2d(dd / aStep, pos), CPoint2d(-dd / aStep, pos), m_colorAxis);
		if (showValue2) PrintString(dd / aStep, pos, 0, s, m_colorAxis);

		////ve cac duong luoi
		//DrawLine(CPoint2d(pos,-m_lengthAxis),CPoint2d(pos,m_lengthAxis),m_colorGrid);
		//DrawLine(CPoint2d(-m_lengthAxis,pos),CPoint2d(m_lengthAxis,pos),m_colorGrid);
	}
	glPopMatrix();
}

void COpenGLCtrlDemo::CreateGrid()
{
	CalLengthAxis();

	wglMakeCurrent(GetDC()->m_hDC, GetHGLRC());

	m_ModelGrid.BeginNewList();
	if (GetCreateMode3D())
		DrawGrid(0, FALSE, FALSE);
	DrawGrid(1, TRUE, FALSE);
	DrawGrid(2, TRUE, TRUE);
	m_ModelGrid.EndNewList();

	wglMakeCurrent(NULL, NULL);
}

void COpenGLCtrlDemo::CreateModel()
{
	SetAngleView(45, 0, 0);

	CreateGrid();
	if (m_Model.m_listElement[0].m_glList.m_gllist == 0)
	{
		extern CRobotDemoApp theApp;
		this->MakeCurrent();
		m_Model.LoadModel(theApp.m_sAppLocation + SUBDIRECTORY_MODEL_FILE, EXTENT_MODEL_FILE);
		m_trajectory.SetPoint0(m_Model.m_listElement[NUM_ELEMENTS - 1].GetPosEndX(),
			m_Model.m_listElement[NUM_ELEMENTS - 1].GetPosEndY(),
			m_Model.m_listElement[NUM_ELEMENTS - 1].GetPosEndZ());
		m_trajectory.CreateDrawList();
		m_trajectory.ExportData(m_Model.m_trajectory[0], m_Model.m_trajectory[1], m_Model.m_trajectory[2],
			m_Model.m_trajectory[3], m_Model.m_trajectory[4], m_Model.m_trajectory[5],
			m_Model.m_trajectory[6], m_Model.m_trajectory[7], m_Model.m_trajectory[8]);
		m_Model.Solve();
		this->MakeNotCurrent();
	}
}

void COpenGLCtrlDemo::CalLengthAxis()
{
	double dMaxLength = m_lengthAxis;
	int mul = (int)(dMaxLength / 5.0);
	int valRound = 5;
	m_lengthAxis = MakeRound(dMaxLength / 2.0, valRound);
	if (m_lengthAxis <= dMaxLength / 2.0 - valRound / 2.0) m_lengthAxis += valRound;
	if (m_lengthAxis <= LocalZero) m_lengthAxis = valRound;
	m_scale = m_lengthAxis / valRound / 2.0;
}

void COpenGLCtrlDemo::Run(const double& dphi)
{
	m_Model.RunNext();
	Invalidate(FALSE);
}

void COpenGLCtrlDemo::Stop()
{
	m_Model.Reset();
	Invalidate(FALSE);
}

void COpenGLCtrlDemo::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_showGrid;
	}
	else
	{
		ar >> m_showGrid;
	}
	m_glLight.Serialize(ar);
	m_Model.Serialize(ar);
	m_trajectory.Serialize(ar);
}