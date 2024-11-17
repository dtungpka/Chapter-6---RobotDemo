// Model.h: interface for the CModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL_H__D62B2CF9_8AC2_4D22_B824_D5C0FA244A21__INCLUDED_)
#define AFX_MODEL_H__D62B2CF9_8AC2_4D22_B824_D5C0FA244A21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Element.h"

#define NUM_ELEMENTS	4

class CModel  
{
public:
	void GetMatrixAcceleration(smatrix &m, vectorm &c, const int & idStep);
	void GetMatrixVelocity(smatrix & m, vectorm& c, const int & idStep);
	void Solve();
	void SetModelSize();
	void Reset();
	void RunNext();
	void Serialize(CArchive &ar);
	void Draw();
	void LoadModel(CString sPath, CString sExtent);
	void GetCenter(double & x,double & y,double & z);

	void UpdatePosition();

	CModel();
	virtual ~CModel();

	static void Func(smatrix & a, vectorm & c,const vectorm & x);
	static CModel * m_pModel;

	CElement m_listElement[NUM_ELEMENTS];
	double m_CenterPoint[3];

	CDoubleArray m_trajectory[9];//x,y,z,vx,vy,vz,ax,ay,az

	CDoubleArray m_parameter[NUM_ELEMENTS-1];
	CDoubleArray m_velocity[NUM_ELEMENTS-1];
	CDoubleArray m_acceleration[NUM_ELEMENTS-1];

	int m_idStep;
};

#endif // !defined(AFX_MODEL_H__D62B2CF9_8AC2_4D22_B824_D5C0FA244A21__INCLUDED_)
