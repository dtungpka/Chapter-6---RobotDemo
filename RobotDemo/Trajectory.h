// Trajectory.h: interface for the CTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAJECTORY_H__ED59C828_48A8_4014_9EA4_98F80A08FCF9__INCLUDED_)
#define AFX_TRAJECTORY_H__ED59C828_48A8_4014_9EA4_98F80A08FCF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTrajectory  
{
public:
	int LoadTrajectory(const CString & sfname);
	void CreateDrawList();
	void Draw();
	void ExportData(CDoubleArray & listX, CDoubleArray & listY, CDoubleArray & listZ, 
					CDoubleArray &listVx, CDoubleArray &listVy, CDoubleArray &listVz,
					CDoubleArray &listAx, CDoubleArray &listAy, CDoubleArray &listAz);
	void CreateDefaultTrajectory();
	void Serialize(CArchive &ar);
	CTrajectory();
	virtual ~CTrajectory();

	void AddPoint(const double & x, const double & y, const double & z);
	void InsertPoint(const int & id,const double & x, const double & y, const double & z);
	void DeletePoint(const int & id);
	void DeleteAll();

	void SetPoint(const int & id,const double & x, const double & y, const double & z);

	void SetPoint0(const double & x0, const double & y0, const double & z0);

	void Set_dd(const double & dd);
	void Set_dt(const double & dt);

	double Get_dd();
	double Get_dt();
	double GetVelocity();

protected:
	void ExportData(CDoubleArray &listX, CDoubleArray &listY, CDoubleArray &listZ, 
			CDoubleArray &listVx, CDoubleArray &listVy, CDoubleArray &listVz,
			CDoubleArray &listAx, CDoubleArray &listAy, CDoubleArray &listAz,
			const double & x1, const double & y1, const double & z1, 
			const double & x2, const double & y2, const double & z2, const double & dd, const double & dt);
	STRUCT_OBJECTGLLIST m_glList;

	double m_dd;//do dai quang duong moi lan di chuyen
	double m_dt;//thoi gian moi lan di chuyen

	double m_x0,m_y0,m_z0;//toa do diem bat dau cua qua trinh hoat dong

	CDoubleArray m_x;
	CDoubleArray m_y;
	CDoubleArray m_z;
};

#endif // !defined(AFX_TRAJECTORY_H__ED59C828_48A8_4014_9EA4_98F80A08FCF9__INCLUDED_)
