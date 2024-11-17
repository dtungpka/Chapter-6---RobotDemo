// Graph.h: interface for the CGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_)
#define AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef CREATEDATA_EXT_CLASS
	#define CREATEDATA_EXT_CLASS CREATEMODEL_EXT_CLASS
#endif CREATEDATA_EXT_CLASS

typedef double (* function)(const double & x);

#ifndef PI
#define PI 3.1415926535897932384626
#endif PI

#ifndef MaxReal
	#define MaxReal		1.6e25
#endif MaxReal
#ifndef MinReal
	#define MinReal		-1.6e25
#endif MinReal
#ifndef LocalZero
	#define LocalZero	1.0e-20
#endif LocalZero

class CREATEDATA_EXT_CLASS CPoint2d 
{
public:
	double x,y;

	CPoint2d(){x=0;y=0;};
	CPoint2d(const CPoint2d & p){x=p.x;y=p.y;};
	CPoint2d(const CPoint & p){x=p.x;y=p.y;};
	CPoint2d(const double & xv,const double & yv){x=xv;y=yv;};
	~CPoint2d(){};

	void SetPoint(const CPoint2d & p){x=p.x;y=p.y;};
	void SetXY(const double & xv,const double & yv){x=xv;y=yv;};
	void SetX(const double & xv){x=xv;};
	void SetY(const double & yv){y=yv;};

	CPoint2d & operator=(const CPoint2d & p);
	CPoint2d & operator=(const CPoint & p);
	operator CPoint();
	double & operator[](const int & i);

	bool operator==(const CPoint & p);
	bool operator!=(const CPoint & p);

	friend CPoint2d CREATEDATA_EXT_CLASS operator+(const CPoint2d & p1,const CPoint2d & p2);
	friend CPoint2d CREATEDATA_EXT_CLASS operator-(const CPoint2d & p1,const CPoint2d & p2);
};

//lay diem trung diem cua mot doan thang
CPoint2d CREATEDATA_EXT_CLASS MiddlePoint(const CPoint2d & p1,const CPoint2d & p2);
//lay doi xung diem p0 qua duong thang p1p2
CPoint2d CREATEDATA_EXT_CLASS MirrorPoint(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2);

//Xoay diem p1 quanh diem p0 di 1 goc (degree)
CPoint2d CREATEDATA_EXT_CLASS RotatePoint(const CPoint2d & p0, const CPoint2d & p1, const double & angle);
//Lay 1 diem tu goc p0 ra 1 doan r lam voi phuong ngang mot goc angle (degree)
CPoint2d CREATEDATA_EXT_CLASS Polar(const CPoint2d & p,const double & angle,const double & r);

//Tim giao diem cua 2 duong tron (p01,r1) va (p02,r2)
bool CREATEDATA_EXT_CLASS FindInt2Circle(const CPoint2d & p01,const double & r1,
									const CPoint2d & p02,const double & r2,
									CPoint2d & p1,CPoint2d &p2);
//Tim giao diem cua duong tron (p0,r) voi duong thang (p1,p2)
bool CREATEDATA_EXT_CLASS FindIntLineCircle(const CPoint2d & p1,const CPoint2d & p2,
								const CPoint2d & p0,const double & r,
								CPoint2d & pi1,CPoint2d &pi2);

//=============================================
//=============================================
//Tim giao diem cua 2 duong thang neu TestInLine=false, 2 doan thang neu TestInLine=true
//gia tri tra ve :
//	= -1 : neu co giao diem nhung khong nam giua 2 doan thang (khi TestInLine=true)
//	= 0  : 2 duong song song, khong cat nhau
//	= 1  : co  giao diem
//	= 2  : 2 duong trung nhau
int CREATEDATA_EXT_CLASS FindIntersect(const double & x11,const double & y11,const double & x12,const double & y12,
				   const double & x21,const double & y21,const double & x22,const double & y22,
				   double & x,double & y, const bool & TestInLine=false);
int CREATEDATA_EXT_CLASS FindIntersect(const CPoint2d & p1,const CPoint2d & p2,
				   const CPoint2d & p3,const CPoint2d & p4,
				   CPoint2d & p, const bool & TestInLine=false);
//Kiem tra xem 2 doan thang co cat nhau khong
bool CREATEDATA_EXT_CLASS LineCut(const double & x11,const double & y11,const double & x12,const double & y12,
			 const double & x21,const double & y21,const double & x22,const double & y22);
bool CREATEDATA_EXT_CLASS LineCut(const CPoint2d & p1,const CPoint2d & p2,
			 const CPoint2d & p3,const CPoint2d & p4);

//Tinh goc giua 2 vector tao boi (p0,p1) va (p0,p2)
double CREATEDATA_EXT_CLASS Angle(const CPoint2d & p0, const CPoint2d & p1, const CPoint2d & p2);
//Tinh goc giua 2 vector tao boi (p1,p2) voi phuong ngang
double CREATEDATA_EXT_CLASS Angle(const CPoint2d & p1, const CPoint2d & p2);

//T×m ®iÓm p trªn ®­êng (p1,p2) mµ (p0,p) vu«ng gãc víi (p1,p2)
CPoint2d CREATEDATA_EXT_CLASS FindPerPoint(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2);
//TÝnh kho¶ng c¸ch tõ mét ®iÓm p0 tíi mét ®­êng th¼ng (p1,p2)
double CREATEDATA_EXT_CLASS GetDistP2L(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2);

double CREATEDATA_EXT_CLASS GetDist2P(const CPoint2d & p1,const CPoint2d & p2);
double CREATEDATA_EXT_CLASS GetDistXY(const double & x1,const double & y1,const double & x2,const double & y2);
BOOL CREATEDATA_EXT_CLASS ComparePoint(const CPoint2d & p1,const CPoint2d & p2);
BOOL CREATEDATA_EXT_CLASS PointInLine(const CPoint2d & p,const CPoint2d & p1,const CPoint2d & p2);

#include <afxtempl.h>
class CREATEDATA_EXT_CLASS CPline : public CArray<CPoint2d,CPoint2d> 
{
public:
	CPline(){RemoveAll();};
	CPline(const CPline & pl)
	{
		RemoveAll();
		for (int k=0;k<pl.GetSize();k++)
			Add(pl[k]);
	};
	CPline & operator=(const CPline & pl)
	{
		RemoveAll();
		for (int k=0;k<pl.GetSize();k++)
			Add(pl[k]);
		return *this;
	};
	/*
	void Add(const double & x,const double & y)
	{
		Add(CPoint2d(x,y));
	}
	*/
	void	MoveObjectTo(const double & x,const double & y)
	{
		CPoint2d p0=GetAt(0);
		for (int i=0;i<GetSize();i++)
		{
			CPoint2d p=GetAt(i);
			p.x=x+(p.x-p0.x);p.y=y+(p.y-p0.y);
			SetAt(i,p);
		}
	};
	void	MoveObjectTrans(const double & x,const double & y)
	{
		for (int i=0;i<GetSize();i++)
		{
			CPoint2d p=GetAt(i);
			p.x+=x;p.y+=y;SetAt(i,p);
		}
	};
	double GetDistFromPoint(const CPoint2d & p)
	{
		if (GetSize()<1) return MaxReal;
		if (GetSize()==1) return GetDist2P(GetAt(0),p);

		double d1=GetDist2P(p,GetAt(0)),d2;
		int pos1=0;
		for (int i=1;i<GetSize();i++)
			if (GetDist2P(p,GetAt(i))<d1) {d1=GetDist2P(p,GetAt(i));pos1=i;}
		int pos0=pos1-1,pos2=pos1+1;
		if (pos2>=GetSize()) pos2=-1;

		if (pos0>=0) 
		{
			CPoint2d per=FindPerPoint(p,GetAt(pos0),GetAt(pos1));
			if (!PointInLine(per ,GetAt(pos0),GetAt(pos1)))	
					 d1=GetDist2P(p,per);
			else	d1=GetDist2P(p,GetAt(pos1));
		}
		else d1=GetDist2P(p,GetAt(pos1));
		if (pos2>=0) 
		{
			CPoint2d per=FindPerPoint(p,GetAt(pos1),GetAt(pos2));
			if (!PointInLine(per ,GetAt(pos1),GetAt(pos2)))	
					 d2=GetDist2P(p,per);
			else	d2=GetDist2P(p,GetAt(pos1));
		}
		else d2=GetDist2P(p,GetAt(pos1));
		

		double dist=GetDist2P(p,GetAt(pos1));
		if (dist>d1) dist=d1;
		if (dist>d2) dist=d2;

		return dist;
	}
};

#endif // !defined(AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_)
