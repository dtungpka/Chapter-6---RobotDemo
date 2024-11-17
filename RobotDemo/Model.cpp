// Model.cpp: implementation of the CModel class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "Model.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction for CModel
//////////////////////////////////////////////////////////////////////
CModel* CModel::m_pModel = NULL;

CModel::CModel()
{
	m_pModel = this;

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		m_listElement[i].m_glList.m_glMaterial.SetAmbient((NUM_ELEMENTS - i) * 1.0f / NUM_ELEMENTS, i * 1.0f / NUM_ELEMENTS, (NUM_ELEMENTS - i) * 1.0f / NUM_ELEMENTS, 1);
	}

	m_CenterPoint[0] = m_CenterPoint[1] = m_CenterPoint[2] = 0;
	m_idStep = 0;

	//Kich thuoc cac khau
	SetModelSize();
}

CModel::~CModel()
{
}

void CModel::LoadModel(CString sPath, CString sExtent)
{
	double translateX, translateY, translateZ;
	translateX = translateY = translateZ = 0;

	//Load cac mo hinh tu file *.stl
	CString sfname;
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		sfname.Format("Element%d.", i);
		m_listElement[i].LoadModel(sPath + sfname + sExtent, translateX, translateY, translateZ);
	}

	//Xac dinh toa do diem giua cua toan bo mo hinh
	GetCenter(m_CenterPoint[0], m_CenterPoint[1], m_CenterPoint[2]);

	//Cap nhat cac gia tri xac dinh vi tri cua thanh truyen va con truot
	UpdatePosition();
}

void CModel::GetCenter(double& x, double& y, double& z)
{
	double pointMax3d[3];
	double pointMin3d[3];
	pointMax3d[0] = pointMax3d[1] = pointMax3d[2] = 0;
	pointMin3d[0] = pointMin3d[1] = pointMin3d[2] = 0;

	for (int k = 0; k < 3; k++)
	{
		pointMax3d[k] = m_listElement[0].m_Max[k];
		pointMin3d[k] = m_listElement[0].m_Min[k];

		for (int i = 1; i < NUM_ELEMENTS; i++)
		{
			pointMax3d[k] = max(pointMax3d[k], m_listElement[i].m_Max[k]);
			pointMin3d[k] = min(pointMin3d[k], m_listElement[i].m_Min[k]);
		}
	}
	x = (pointMax3d[0] + pointMin3d[0]) / 2.0;
	y = (pointMax3d[1] + pointMin3d[1]) / 2.0;
	z = (pointMax3d[2] + pointMin3d[2]) / 2.0;
}

void CModel::UpdatePosition()
{
	for (int i = 1; i < NUM_ELEMENTS; i++)
	{
		m_listElement[i].SetPosition(
			m_listElement[i - 1].GetPosEndX(),
			m_listElement[i - 1].GetPosEndY(),
			m_listElement[i - 1].GetPosEndZ());
	}
}

void CModel::Draw()
{
	glTranslated(-m_CenterPoint[0], -m_CenterPoint[1], -m_CenterPoint[2]);

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		m_listElement[i].Draw();
	}

	glLineWidth(4);
	if (m_trajectory[0].GetSize() > 0)
	{
		for (int i = 0; i < m_idStep; i++)
		{
			DrawLine(m_trajectory[0][i], m_trajectory[1][i], m_trajectory[2][i],
				m_trajectory[0][i + 1], m_trajectory[1][i + 1], m_trajectory[2][i + 1], RGB(255, 0, 0));
		}
	}
}

void CModel::Serialize(CArchive& ar)
{
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		m_listElement[i].Serialize(ar);
	}

	if (ar.IsStoring())
	{
		//ar<<m_CurrentGear;
	}
	else
	{
		//ar>>m_CurrentGear;
	}
}

void CModel::RunNext()
{
	if (m_parameter[0].GetSize() <= 0) return;

	m_idStep++;
	if (m_idStep >= m_parameter[0].GetSize())
	{
		m_idStep = 0;
		Sleep(200);
	}

	m_listElement[1].m_Angle[2] = m_parameter[0][m_idStep];
	m_listElement[2].m_Angle[2] = m_parameter[1][m_idStep] + m_parameter[0][m_idStep];
	m_listElement[3].m_Translate[2] = m_parameter[2][m_idStep];
	UpdatePosition();
}

void CModel::Reset()
{
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		m_listElement[i].Reset();
	}
	SetModelSize();
	UpdatePosition();
	m_idStep = 0;
}

void CModel::SetModelSize()
{
	m_listElement[0].m_l = 215;
	m_listElement[0].m_theta = 90;
	m_listElement[1].m_l = 140;
	m_listElement[2].m_l = 90;
	m_listElement[3].m_l = 0;
	m_listElement[3].m_theta = -90;
}

void CModel::Func(smatrix& a, vectorm& c, const vectorm& x)
{
	a.SetSize(NUM_ELEMENTS - 1);
	c.SetSize(NUM_ELEMENTS - 1);

	double currentX = m_pModel->m_trajectory[0][m_pModel->m_idStep];
	double currentY = m_pModel->m_trajectory[1][m_pModel->m_idStep];
	double currentZ = m_pModel->m_trajectory[2][m_pModel->m_idStep];

	double l0 = m_pModel->m_listElement[0].m_l;
	double l1 = m_pModel->m_listElement[1].m_l;
	double l2 = m_pModel->m_listElement[2].m_l;
	double l3 = x(2);

	double c1 = cos(x(0));//phi1 = x(0)
	double s1 = sin(x(0));
	double c2 = cos(x(1));//phi2 = x(1)
	double s2 = sin(x(1));

	double c12 = cos(x(0) + x(1));
	double s12 = sin(x(0) + x(1));

	a(0, 0) = -l2 * s12 - l1 * s1;
	a(0, 1) = -l2 * s12;
	a(0, 2) = 0;
	a(1, 0) = l2 * c12 + l1 * c1;
	a(1, 1) = l2 * c12;
	a(1, 2) = 0;
	a(2, 0) = 0;
	a(2, 1) = 0;
	a(2, 2) = -1.0;

	c(0) = l2 * c12 + l1 * c1 - currentX;
	c(1) = l2 * s12 + l1 * s1 - currentY;
	c(2) = -l3 + l0 - currentZ;
}

void CModel::GetMatrixVelocity(smatrix& m, vectorm& c, const int& idStep)
{
	m.SetSize(NUM_ELEMENTS - 1);
	c.SetSize(NUM_ELEMENTS - 1);

	if (m_parameter[0].GetSize() <= 0) return;

	double scaleDegRad = 180.0 / PI;

	double c1 = cos(m_parameter[0][idStep] / scaleDegRad);//phi1
	double s1 = sin(m_parameter[0][idStep] / scaleDegRad);
	double c2 = cos(m_parameter[1][idStep] / scaleDegRad);//phi2
	double s2 = sin(m_parameter[1][idStep] / scaleDegRad);

	double l0 = m_pModel->m_listElement[0].m_l;
	double l1 = m_pModel->m_listElement[1].m_l;
	double l2 = m_pModel->m_listElement[2].m_l;
	double l3 = m_parameter[2][idStep];

	double c12 = cos((m_parameter[0][idStep] + m_parameter[1][idStep]) / scaleDegRad);
	double s12 = sin((m_parameter[0][idStep] + m_parameter[1][idStep]) / scaleDegRad);

	m(0, 0) = -l2 * s12 - l1 * s1;
	m(0, 1) = -l2 * s12;
	m(0, 2) = 0;
	m(1, 0) = l2 * c12 + l1 * c1;
	m(1, 1) = l2 * c12;
	m(1, 2) = 0;
	m(2, 0) = 0;
	m(2, 1) = 0;
	m(2, 2) = -1.0;

	c[0] = m_trajectory[3][idStep];
	c[1] = m_trajectory[4][idStep];
	c[2] = m_trajectory[5][idStep];
}

void CModel::GetMatrixAcceleration(smatrix& m, vectorm& c, const int& idStep)
{
	m.SetSize(NUM_ELEMENTS - 1);
	c.SetSize(NUM_ELEMENTS - 1);

	if (m_parameter[0].GetSize() <= 0) return;

	double scaleDegRad = 180.0 / PI;

	double c1 = cos(m_parameter[0][idStep] / scaleDegRad);//phi1
	double s1 = sin(m_parameter[0][idStep] / scaleDegRad);
	double c2 = cos(m_parameter[1][idStep] / scaleDegRad);//phi2
	double s2 = sin(m_parameter[1][idStep] / scaleDegRad);

	double c12 = cos((m_parameter[0][idStep] + m_parameter[1][idStep]) / scaleDegRad);
	double s12 = sin((m_parameter[0][idStep] + m_parameter[1][idStep]) / scaleDegRad);

	double l0 = m_pModel->m_listElement[0].m_l;
	double l1 = m_pModel->m_listElement[1].m_l;
	double l2 = m_pModel->m_listElement[2].m_l;
	double l3 = m_parameter[2][idStep];

	double v1 = m_pModel->m_velocity[0][m_velocity[0].GetSize() - 1] / scaleDegRad;
	double v2 = m_pModel->m_velocity[1][m_velocity[1].GetSize() - 1] / scaleDegRad;
	double v3 = m_pModel->m_velocity[2][m_velocity[2].GetSize() - 1];

	m(0, 0) = -l2 * s12 - l1 * s1;
	m(0, 1) = -l2 * s12;
	m(0, 2) = 0;
	m(1, 0) = l2 * c12 + l1 * c1;
	m(1, 1) = l2 * c12;
	m(1, 2) = 0;
	m(2, 0) = 0;
	m(2, 1) = 0;
	m(2, 2) = -1.0;

	c[0] = (l2 * c12 + l1 * c1) * v1 * v1 + 2 * l2 * c12 * v1 * v2 + l2 * c12 * v2 * v2 + m_trajectory[6][idStep];
	c[1] = (l2 * s12 + l1 * s1) * v1 * v1 + 2 * l2 * s12 * v1 * v2 + l2 * s12 * v2 * v2 + m_trajectory[7][idStep];
	c[2] = m_trajectory[8][idStep];
}

void CModel::Solve()
{
	int preIdStep = m_idStep;
	Reset();

	for (int i = 0; i < NUM_ELEMENTS - 1; i++)
	{
		m_parameter[i].RemoveAll();
		m_velocity[i].RemoveAll();
		m_acceleration[i].RemoveAll();
	}

	double eps = 0.00001;
	int maxloop = 200;
	vectorm x(3);
	vectorm vt(3);
	vectorm at(3);

	double scaleDegRad = 180.0 / PI;
	x[0] = (m_listElement[1].m_Angle[2] - 0.1) / scaleDegRad;
	x[1] = (m_listElement[2].m_Angle[2] + 0.1) / scaleDegRad;
	x[2] = m_listElement[3].m_Translate[2] - 0.1;

	m_pModel = this;
	smatrix ma;
	vectorm vb;
	for (int i = 0; i < m_trajectory[0].GetSize(); i++)//vong lap thuc hien giai cac bai toan tren toan bo quy dao
	{
		m_idStep = i;

		//Giai bai toan vi tri
		if (Newton_Raphson(x, Func, eps, maxloop) == 0)
		{
			x(0) = NormalAngleRad(x(0));
			x(1) = NormalAngleRad(x(1));
			if (x(0) > PI) x(0) -= 2 * PI;
			if (x(1) > PI) x(1) -= 2 * PI;
			m_parameter[0].Add(x(0) * scaleDegRad);
			m_parameter[1].Add(x(1) * scaleDegRad);
			m_parameter[2].Add(m_listElement[3].m_l - x[2]);
		}
		//Giai bai toan van toc
		GetMatrixVelocity(ma, vb, i);
		if (Gauss_Jordan(ma, vb, vt) == 0)
		{
			m_velocity[0].Add(vt(0) * scaleDegRad);
			m_velocity[1].Add(vt(1) * scaleDegRad);
			m_velocity[2].Add(vt(2));
		}

		//Giai bai toan gia toc
		GetMatrixAcceleration(ma, vb, i);
		if (Gauss_Jordan(ma, vb, at) == 0)
		{
			m_acceleration[0].Add(at(0) * scaleDegRad);
			m_acceleration[1].Add(at(1) * scaleDegRad);
			m_acceleration[2].Add(at(2));
		}
	}
	m_idStep = preIdStep;
}