// OpenGLCtrlDemo.h: interface for the COpenGLCtrlDemo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLCTRLDEMO_H__6D816270_D911_483B_8DB6_D416A7B37A60__INCLUDED_)
#define AFX_OPENGLCTRLDEMO_H__6D816270_D911_483B_8DB6_D416A7B37A60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Model.h"
#include "Trajectory.h"


typedef CNewArray<CPline,CPline> CListPline;
typedef CNewArray<COLORREF,COLORREF> CListColorPline;

class COpenGLCtrlDemo : public COpenGLCtrl  
{
public:
	void Serialize(CArchive& ar);
	void Stop();
	void Run(const double & dphi=0.5);
	void CreateModel();
	virtual void DrawInOpenGL();
	COpenGLCtrlDemo();
	virtual ~COpenGLCtrlDemo();

	CModel m_Model;
	CTrajectory m_trajectory;

	GL_LIGHT m_glLight;

	BOOL m_showGrid;

protected:
	CListPline m_listPline;
	CListColorPline m_listColorLine;
	double m_lengthAxis;
	COLORREF m_colorAxis;
	COLORREF m_colorGrid;
	double m_scale;

	void CreateGrid();
	void DrawGrid(const int & style=0, const BOOL showValue1=TRUE, const BOOL showValue2=TRUE);

	STRUCT_OBJECTGLLIST m_ModelGrid;

private:
	void CalLengthAxis();
};

#endif // !defined(AFX_OPENGLCTRLDEMO_H__6D816270_D911_483B_8DB6_D416A7B37A60__INCLUDED_)
