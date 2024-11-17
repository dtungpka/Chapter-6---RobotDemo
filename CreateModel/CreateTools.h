// CreateModel.h: interface for the CCreateModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CREATEMODEL_H__9FABF96C_FE8E_4637_AD5E_C51EFB8485E8__INCLUDED_)
#define AFX_CREATEMODEL_H__9FABF96C_FE8E_4637_AD5E_C51EFB8485E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef CREATETOOLS_EXT_CLASS
	#define CREATETOOLS_EXT_CLASS CREATEMODEL_EXT_CLASS
#endif CREATETOOLS_EXT_CLASS

void CREATETOOLS_EXT_CLASS glNewListNew(int &gllist, const int &range=1, const GLenum & mode = GL_COMPILE);

void CREATETOOLS_EXT_CLASS SetNormalByFace(const bool & byFace=true);
bool CREATETOOLS_EXT_CLASS GetNormalByFace();
void CREATETOOLS_EXT_CLASS SetPointOrg(const double & x,const double & y,const double & z);
void CREATETOOLS_EXT_CLASS SetPointOrgX(const double & x);
void CREATETOOLS_EXT_CLASS SetPointOrgY(const double & y);
void CREATETOOLS_EXT_CLASS SetPointOrgZ(const double & z);
void CREATETOOLS_EXT_CLASS GetPointOrg(double & x,double & y,double & z);
double CREATETOOLS_EXT_CLASS GetPointOrgX();
double CREATETOOLS_EXT_CLASS GetPointOrgY();
double CREATETOOLS_EXT_CLASS GetPointOrgZ();

void CREATETOOLS_EXT_CLASS Set_glNormal3f(const double &x, const double &y, const double &z);
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS EnablePolygonSmooth();
void CREATETOOLS_EXT_CLASS DisablePolygonSmooth();
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS DrawLine(const CPoint2d &p1, const CPoint2d &p2, const COLORREF & color);
void CREATETOOLS_EXT_CLASS DrawLine(const float &x1, const float &y1, const float &z1, const float &x2, const float &y2, const float &z2, const COLORREF & color);
void CREATETOOLS_EXT_CLASS DrawPline(const CPline &pline, const COLORREF & color);
//=================================================
//=================================================
CPline CREATETOOLS_EXT_CLASS MovePline(CPline *pline, const CPoint2d &pb, const CPoint2d &pe);
CPline CREATETOOLS_EXT_CLASS RotatePline(CPline *pline, const CPoint2d & p0, const double &phi);
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS CalSetNormal(const CPoint2d &p1,const double & z1, const CPoint2d &p2,const double & z2, const CPoint2d &p3,const double & z3);
void CREATETOOLS_EXT_CLASS CalSetNormal(const double &x1,const double & y1,const double & z1, 
					   const double &x2,const double & y2,const double & z2, 
					   const double &x3,const double & y3,const double & z3);
//=================================================
//=================================================
CPline CREATETOOLS_EXT_CLASS GetPlineCircle(const CPoint2d & pCenter,const double r, const bool & ccw=true,const int & numpoint=100, const BOOL & closepline=FALSE);
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS RevolvePline(const CPoint2d & pCenter, const CPline & pline, const int & direct, const int & numstep=100);
//direct : la huong quay = 0  : duong tam quay di qua diem pCenter va // voi truc x
//direct : la huong quay = 1  : duong tam quay di qua diem pCenter va // voi truc y
//direct : la huong quay = 2  : duong tam quay di qua diem pCenter va // voi truc z
void CREATETOOLS_EXT_CLASS ExtrudePline(const CPoint2d & pCenter,const CPline & pline, const double & h, const bool & fillhead=true, const bool & inout=true);
void CREATETOOLS_EXT_CLASS ExtrudePline(const CPoint2d & pCenter,const CPline & pline, const double & h,const double & r_inout, const bool & fillhead=true);
double CREATETOOLS_EXT_CLASS ExtrudePline(const CPoint2d & pCenter,const CPline & pline, const double & beta, const double & r, const double & h, const double & r_inout, const bool & right = true, const bool & fillhead=true, const int & numsteph=20);
//=================================================
void CREATETOOLS_EXT_CLASS RevolvePlineNew(const CPoint2d & pCenter, const CPline & pline, const int & direct, const int & numstep=100);
//direct : la huong quay = 0  : duong tam quay di qua diem pCenter va // voi truc x
//direct : la huong quay = 1  : duong tam quay di qua diem pCenter va // voi truc y
//direct : la huong quay = 2  : duong tam quay di qua diem pCenter va // voi truc z
void CREATETOOLS_EXT_CLASS ExtrudePlineNew(const CPoint2d & pCenter,const CPline & pline, const double & h, const bool & fillhead=true, const bool & inout=true);
void CREATETOOLS_EXT_CLASS ExtrudePlineNew(const CPoint2d & pCenter,const CPline & pline, const double & h,const double & r_inout, const bool & fillhead=true);
double CREATETOOLS_EXT_CLASS ExtrudePlineNew(const CPoint2d & pCenter,const CPline & pline, const double & beta, const double & r, const double & h, const double & r_inout, const bool & right = true, const bool & fillhead=true, const int & numsteph=20);
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS Cylinder(const CPoint2d & pCenter,const double & r, const double & h, const bool & fillhead=true,const int & numpoint=100);
void CREATETOOLS_EXT_CLASS Cylinder(const CPoint2d & pCenter,const double & r, const double & h,const double & r_inout, const bool & fillhead=true,const int & numpoint=100);
void CREATETOOLS_EXT_CLASS Cylinder2Face(const CPoint2d & pCenter,const double & rout,const double & rin, const double & h,const int & numpoint=100);
//=================================================
void CREATETOOLS_EXT_CLASS CylinderNew(const CPoint2d & pCenter,const double & r, const double & h, const bool & fillhead=true,const int & numpoint=100);
void CREATETOOLS_EXT_CLASS CylinderNew(const CPoint2d & pCenter,const double & r, const double & h,const double & r_inout, const bool & fillhead=true,const int & numpoint=100);
void CREATETOOLS_EXT_CLASS Cylinder2FaceNew(const CPoint2d & pCenter,const double & rout,const double & rin, const double & h,const int & numpoint=100);
//=================================================
//=================================================
void CREATETOOLS_EXT_CLASS DrawTriangles(
										 const double &x1, const double &y1, const double &z1,
										 const double &xn1, const double &yn1, const double &zn1,
										 const double &x2, const double &y2, const double &z2,
										 const double &xn2, const double &yn2, const double &zn2,
										 const double &x3, const double &y3, const double &z3,
										 const double &xn3, const double &yn3, const double &zn3,
										 const int &nor=0
										 );
void CREATETOOLS_EXT_CLASS DrawTriangle(const CPoint2d &p1,const CPoint2d &p2,const CPoint2d &p3,
				  const double &z, const double & normal, 
				  const bool & zaxis=false);
void CREATETOOLS_EXT_CLASS DrawTriangles(
					   const double &x1, const double &y1, const double &z1,
					   const double &x2, const double &y2, const double &z2,
					   const double &x3, const double &y3, const double &z3,
					   const int &nor=0);
void CREATETOOLS_EXT_CLASS DrawQuads(
					   const double &x1, const double &y1, const double &z1,
					   const double &xn1, const double &yn1, const double &zn1,
					   const double &x2, const double &y2, const double &z2,
					   const double &xn2, const double &yn2, const double &zn2,
					   const double &x3, const double &y3, const double &z3,
					   const double &xn3, const double &yn3, const double &zn3,
					   const double &x4, const double &y4, const double &z4,
					   const double &xn4, const double &yn4, const double &zn4,
					   const int &nor=0
					   );
void CREATETOOLS_EXT_CLASS DrawQuads(
						 const double &x1, const double &y1, const double &z1,
						 const double &x2, const double &y2, const double &z2,
						 const double &x3, const double &y3, const double &z3,
						 const double &x4, const double &y4, const double &z4,
						 const int &nor=0);
//================================================
//=================================================
typedef struct CREATETOOLS_EXT_CLASS STRUCT_TRIANGLES
{
	int m_listId[3][2];
					// 0 : chua chi so xac dinh dinh do thuoc duong nao
					// 1 : chua chi so dinh cua tam giac
	STRUCT_TRIANGLES();
	STRUCT_TRIANGLES(
		const int & idl1,const int & idp1,
		const int & idl2,const int & idp2,
		const int & idl3,const int & idp3);
	STRUCT_TRIANGLES(const STRUCT_TRIANGLES & sta);
	STRUCT_TRIANGLES& operator=(const STRUCT_TRIANGLES & sta);

	void SetIdPoint(
		const int & idl1,const int & idp1,
		const int & idl2,const int & idp2,
		const int & idl3,const int & idp3);
	void Copy(const STRUCT_TRIANGLES & sta);
	bool HaveLine(
		const int & idl1,const int & idp1,
		const int & idl2,const int & idp2);
	bool HavePoint(const int & idl,const int & idp);
	bool IsSamePoint(const int & idl,const int & idp,const int & idtria);
}struct_triangles;
//=================================================
//=================================================
class CREATETOOLS_EXT_CLASS CRegionGL
{
public:
	CRegionGL();
	CRegionGL(const CRegionGL & region);
	CRegionGL(const CPline & pline);
	~CRegionGL();

	CRegionGL & operator=(const CRegionGL & region);
	CRegionGL & operator=(const CPline & pline);
	void Copy(const CRegionGL & region);
	void Copy(const CPline & pline);

	int GetNumBound();
	CPline * GetPointerBound(const int & id);
	CPline GetBound(const int & id);
/*
	CRegionGL operator+(const CRegionGL & region);
	CRegionGL operator+(const CPline & pline);
	CRegionGL operator-(const CRegionGL & region);
	CRegionGL operator-(const CPline & pline);
	CRegionGL & operator+=(const CRegionGL & region);
	CRegionGL & operator+=(const CPline & pline);
	CRegionGL & operator-=(const CRegionGL & region);
	CRegionGL & operator-=(const CPline & pline);
*/
	bool AddBound(const CPline & pline);
	bool SubBound(const CPline & pline);

	bool AddBound(const CRegionGL & region);
	bool SubBound(const CRegionGL & region);

	CRegionGL Union(const CRegionGL & region);
	CRegionGL Subtract(const CRegionGL & region);
	CRegionGL Intersect(const CRegionGL & region);

	void Draw(const double &z=0, const double & normal=1,const bool & zaxis=false);
	bool WriteListTriangleToFile(const CString &fname);

private:	
	int m_znormal;
	CNewArray<CPline,CPline> m_listPline;//chua danh sach cac duong bien
	//duong dau tien se la duong bao ngoai
	//cac duong ve sau la duong bao trong
	CNewArray<STRUCT_TRIANGLES,STRUCT_TRIANGLES> m_listTriangles;

	void Cal_Normal();
	double Get_znormal(const int & idl1,const int & idp1,
								const int & idl2,const int & idp2,
								const int & idl3,const int & idp3);
	CPoint2d GetPointInBound(const int & idl,const int & idp);
	CPoint2d GetPointInTriangle(const int & idtria,const int & ida);
	CPoint2d GetPointInTriangle(const STRUCT_TRIANGLES & tria,const int & ida);
	bool LineCutTriangle(const int & idl1,const int & idp1,const int & idl2,const int & idp2);
	bool LineCutBound(const int & idl1,const int & idp1,const int & idl2,const int & idp2);
	bool FindPointNearest(const int & idl1,const int & idp1,
									const int & idl2,const int & idp2,
									int & idl, int & idp);
	bool CreateTriangle(const int & idl1,const int & idp1,
								 const int & idl2,const int & idp2);
public :
	bool IsCCW();
	void SetCCW(const bool & ccw=true);//dat huong theo nguoc chieu kim dong ho la duong
	void CreateListTriangle();
	void RemoveListTriangle();
	bool IsCreatedListTriangle();

	void RemoveAll();
};

void CREATETOOLS_EXT_CLASS RevolveRegion(const CPoint2d & pCenter, CRegionGL & region, const int & direct, const int & numstep=100);
//direct : la huong quay = 0  : duong tam quay di qua diem pCenter va // voi truc x
//direct : la huong quay = 1  : duong tam quay di qua diem pCenter va // voi truc y
//direct : la huong quay = 2  : duong tam quay di qua diem pCenter va // voi truc z
void CREATETOOLS_EXT_CLASS ExtrudeRegion(CRegionGL & region, const double & h,const bool & showout=true,const bool & showin=true);

void CREATETOOLS_EXT_CLASS RevolveRegionNew(const CPoint2d & pCenter, CRegionGL & region, const int & direct, const int & numstep=100);
//direct : la huong quay = 0  : duong tam quay di qua diem pCenter va // voi truc x
//direct : la huong quay = 1  : duong tam quay di qua diem pCenter va // voi truc y
//direct : la huong quay = 2  : duong tam quay di qua diem pCenter va // voi truc z
void CREATETOOLS_EXT_CLASS ExtrudeRegionNew(CRegionGL & region, const double & h,const bool & showout=true,const bool & showin=true);
#endif // !defined(AFX_CREATEMODEL_H__9FABF96C_FE8E_4637_AD5E_C51EFB8485E8__INCLUDED_)
