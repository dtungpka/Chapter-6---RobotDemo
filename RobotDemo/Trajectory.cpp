// Trajectory.cpp: implementation of the CTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "RobotDemo.h"
#include "Trajectory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrajectory::CTrajectory()
{
	m_dd = 2;//mm
	m_dt = 0.01;//s
	m_x0 = m_y0 = m_z0 = 0;
	CreateDefaultTrajectory();
}

CTrajectory::~CTrajectory()
{
}

void CTrajectory::AddPoint(const double& x, const double& y, const double& z)
{
	m_x.Add(x);
	m_y.Add(y);
	m_z.Add(z);
}
void CTrajectory::InsertPoint(const int& id, const double& x, const double& y, const double& z)
{
	m_x.InsertAt(id, x);
	m_y.InsertAt(id, y);
	m_z.InsertAt(id, z);
}
void CTrajectory::DeletePoint(const int& id)
{
	if (id < 0) return;
	if (id >= m_x.GetSize()) return;
	m_x.RemoveAt(id);
	m_y.RemoveAt(id);
	m_z.RemoveAt(id);
}
void CTrajectory::DeleteAll()
{
	m_x.RemoveAll();
	m_y.RemoveAll();
	m_z.RemoveAll();
}

void CTrajectory::SetPoint(const int& id, const double& x, const double& y, const double& z)
{
	if (id < 0) return;
	if (id >= m_x.GetSize()) return;
	m_x[id] = x;
	m_y[id] = y;
	m_z[id] = z;
}

void CTrajectory::SetPoint0(const double& x0, const double& y0, const double& z0)
{
	m_x0 = x0;
	m_y0 = y0;
	m_z0 = z0;
}

void CTrajectory::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_x0 << m_y0 << m_z0;
	}
	else
	{
		ar >> m_x0 >> m_y0 >> m_z0;
	}
	m_x.Serialize(ar);
	m_y.Serialize(ar);
	m_z.Serialize(ar);
}

void CTrajectory::CreateDefaultTrajectory()
{
	DeleteAll();

	double x, y, z;

	double r = 80;
	double xc = 150, yc = 0, zc = 120;

	int numCycle = 3;
	int numpointpercycle = 2 * PI * r / m_dd;

	double da = 2 * PI / numpointpercycle;
	double hz = 10;

	for (int i = 0; i <= numpointpercycle * numCycle; i++)
	{
		x = xc + r * cos(da * i);
		y = yc + r * sin(da * i);
		z = zc + i * hz / numpointpercycle / numCycle;
		//z = zc;
		AddPoint(x, y, z);
	}

	if (!m_x.GetSize()) return;

	double old_dd = m_dd;
	m_dd = length(point3d(m_x[0], m_y[0], m_z[0]), point3d(m_x[1], m_y[1], m_z[1]));
	m_dt = old_dd * m_dt / m_dd;
}

void CTrajectory::ExportData(CDoubleArray& listX, CDoubleArray& listY, CDoubleArray& listZ,
	CDoubleArray& listVx, CDoubleArray& listVy, CDoubleArray& listVz,
	CDoubleArray& listAx, CDoubleArray& listAy, CDoubleArray& listAz,
	const double& x1, const double& y1, const double& z1,
	const double& x2, const double& y2, const double& z2,
	const double& dd, const double& dt)
{
	double lengthline = length(point3d(x1, y1, z1), point3d(x2, y2, z2));

	double dn = lengthline / dd;
	if (dn < 0.5) return;
	int numpoint = floor(dn);
	if (numpoint <= 0) numpoint = 1;
	double ddx = (x2 - x1) / (double)numpoint;
	double ddy = (y2 - y1) / (double)numpoint;
	double ddz = (z2 - z1) / (double)numpoint;
	double newdt = (lengthline / (double)numpoint) * dt / dd;

	for (int i = 1; i <= numpoint; i++)
	{
		listX.Add(x1 + i * ddx);
		listY.Add(y1 + i * ddy);
		listZ.Add(z1 + i * ddz);
		listVx.Add(ddx / newdt);
		listVy.Add(ddy / newdt);
		listVz.Add(ddz / newdt);
		if (listVx.GetSize() > 1)
		{
			listAx.Add((listVx[listVx.GetSize() - 1] - listVx[listVx.GetSize() - 2]) / newdt);
			listAy.Add((listVy[listVy.GetSize() - 1] - listVy[listVy.GetSize() - 2]) / newdt);
			listAz.Add((listVz[listVz.GetSize() - 1] - listVz[listVz.GetSize() - 2]) / newdt);
		}
		else
		{
			listAx.Add(listVx[listVx.GetSize() - 1] / newdt);
			listAy.Add(listVy[listVy.GetSize() - 1] / newdt);
			listAz.Add(listVz[listVz.GetSize() - 1] / newdt);
		}
	}
}

void CTrajectory::ExportData(CDoubleArray& listX, CDoubleArray& listY, CDoubleArray& listZ,
	CDoubleArray& listVx, CDoubleArray& listVy, CDoubleArray& listVz,
	CDoubleArray& listAx, CDoubleArray& listAy, CDoubleArray& listAz)
{
	listX.RemoveAll();
	listY.RemoveAll();
	listZ.RemoveAll();
	listVx.RemoveAll();
	listVy.RemoveAll();
	listVz.RemoveAll();
	listAx.RemoveAll();
	listAy.RemoveAll();
	listAz.RemoveAll();

	if (m_x.GetSize() < 1) return;

	listX.Add(m_x0);
	listY.Add(m_y0);
	listZ.Add(m_z0);
	listVx.Add(0);
	listVy.Add(0);
	listVz.Add(0);
	listAx.Add(0);
	listAy.Add(0);
	listAz.Add(0);

	ExportData(listX, listY, listZ, listVx, listVy, listVz, listAx, listAy, listAz, m_x0, m_y0, m_z0, m_x[0], m_y[0], m_z[0], 2 * m_dd, m_dt);

	for (int i = 0; i < m_x.GetSize() - 1; i++)
	{
		ExportData(listX, listY, listZ, listVx, listVy, listVz, listAx, listAy, listAz, m_x[i], m_y[i], m_z[i], m_x[i + 1], m_y[i + 1], m_z[i + 1], m_dd, m_dt);
	}

	ExportData(listX, listY, listZ, listVx, listVy, listVz, listAx, listAy, listAz, m_x[m_x.GetSize() - 1], m_y[m_x.GetSize() - 1], m_z[m_x.GetSize() - 1], m_x0, m_y0, m_z0, 2 * m_dd, m_dt);

	listX.RemoveAt(listX.GetSize() - 1);
	listY.RemoveAt(listY.GetSize() - 1);
	listZ.RemoveAt(listZ.GetSize() - 1);
	listVx.RemoveAt(listVx.GetSize() - 1);
	listVy.RemoveAt(listVy.GetSize() - 1);
	listVz.RemoveAt(listVz.GetSize() - 1);
	listAx.RemoveAt(listAx.GetSize() - 1);
	listAy.RemoveAt(listAy.GetSize() - 1);
	listAz.RemoveAt(listAz.GetSize() - 1);
}

void CTrajectory::Draw()
{
	glPushMatrix();
	m_glList.Draw();
	glPopMatrix();
}

void CTrajectory::CreateDrawList()
{
	m_glList.BeginNewList();

	glLineWidth(2);
	if (m_x.GetSize() > 0)
	{
		DrawLine(m_x0, m_y0, m_z0, m_x[0], m_y[0], m_z[0], RGB(255, 255, 0));
		for (int i = 0; i < m_x.GetSize() - 1; i++)
		{
			DrawLine(m_x[i], m_y[i], m_z[i], m_x[i + 1], m_y[i + 1], m_z[i + 1], RGB(255, 255, 0));
		}
		DrawLine(m_x0, m_y0, m_z0, m_x[m_x.GetSize() - 1], m_y[m_x.GetSize() - 1], m_z[m_x.GetSize() - 1], RGB(255, 255, 0));
	}

	m_glList.EndNewList();
}

void CTrajectory::Set_dd(const double& dd)
{
	m_dd = dd;
}
void CTrajectory::Set_dt(const double& dt)
{
	m_dt = dt;
}

double CTrajectory::Get_dd()
{
	return m_dd;
}
double CTrajectory::Get_dt()
{
	return m_dt;
}

double CTrajectory::GetVelocity()
{
	return m_dd / m_dt;
}

int CTrajectory::LoadTrajectory(const CString& sfname)
{
	DeleteAll();

	if (sfname.IsEmpty()) return -2;//file name is not supported

	CStdioFile file;
	if (!file.Open(sfname, CFile::modeRead | CFile::typeText)) return -1;

	CString sRead;
	float x, y, z;
	while (file.ReadString(sRead))
	{
		if (sRead.IsEmpty()) break;
		sscanf_s(sRead, "%f%f%f", &x, &y, &z);
		AddPoint(x, y, z);
	}
	file.Close();

	if (m_x.GetSize() > 1)
	{
		double old_dd = m_dd;
		m_dd = length(point3d(m_x[0], m_y[0], m_z[0]), point3d(m_x[1], m_y[1], m_z[1]));
		m_dt = old_dd * m_dt / m_dd;
	}

	return 0;
}