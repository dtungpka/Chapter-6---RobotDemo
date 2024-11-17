// Graph.h: interface for the CGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_)
#define AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef GRAPH_EXT_CLASS
	#define GRAPH_EXT_CLASS TOOLINTER_EXT_CLASS
#endif GRAPH_EXT_CLASS

typedef double (* function)(const double & x);

#ifndef PI
#define PI 3.1415926535897932384626
#endif PI

#define MaxReal		1.6e35
#define MinReal		-1.6e35
#define LocalZero	1.0e-30

void GRAPH_EXT_CLASS DrawGraphFunc(CDC * pdc, const int & xg, const int & yg,
		const double & scalex,const double & scaley,
		const double & xmin,const double & xmax,
		const int & numpoint, function f);
/*Draw graph with function f from origin (xg,yg)
            with scale in x direction scalex
                 scale in y direction scaley
            range to draw from xmin to xmax
            numpoint is number point will be drawn
*/
void GRAPH_EXT_CLASS DrawTable(CDC * pdc,int xgraph1,int ygraph1,
			   int xgraph2,int ygraph2,
			   const int & numx,const int & numy,
			   CString sx,CString sy,
			   const COLORREF & clgrid,const COLORREF & clstring);
/*Draw table grid line, show coordinate grid in a rectangle
 rectangle has coordinate is : (xgraph1,ygraph1) and (xgraph2,ygraph2)
 numx, numy : number to device grid in x and y directions.
 sx, sy : a string will be draw in x and y directions.
 clgrid : color of grid line
 clstring : color of string information.
*/

class GRAPH_EXT_CLASS CPoint2d
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

	friend CPoint2d GRAPH_EXT_CLASS operator+(const CPoint2d & p1,const CPoint2d & p2);
	friend CPoint2d GRAPH_EXT_CLASS operator-(const CPoint2d & p1,const CPoint2d & p2);
};

//Xoay diem p1 quanh diem p0 di 1 goc (degree)
CPoint2d GRAPH_EXT_CLASS RotatePoint(const CPoint2d & p0, const CPoint2d & p1, const double & angle);
//Lay 1 diem tu goc p0 ra 1 doan r lam voi phuong ngang mot goc angle (degree)
CPoint2d GRAPH_EXT_CLASS Polar(const CPoint2d & p,const double & angle,const double & r);

//Tim giao diem cua 2 duong tron (p01,r1) va (p02,r2)
bool GRAPH_EXT_CLASS FindInt2Circle(const CPoint2d & p01,const double & r1,
									const CPoint2d & p02,const double & r2,
									CPoint2d & p1,CPoint2d &p2);
//Tim giao diem cua duong tron (p0,r) voi duong thang (p1,p2)
bool GRAPH_EXT_CLASS FindIntLineCircle(const CPoint2d & p1,const CPoint2d & p2,
								const CPoint2d & p0,const double & r,
								CPoint2d & pi1,CPoint2d &pi2);

//=============================================
//=============================================
//Tim giao diem cua 2 duong thang neu TestInLine=false, 2 doan thang neu TestInLine=true
bool GRAPH_EXT_CLASS FindIntersect(const double & x11,const double & y11,const double & x12,const double & y12,
				   const double & x21,const double & y21,const double & x22,const double & y22,
				   double & x,double & y, const bool & TestInLine=false);
bool GRAPH_EXT_CLASS FindIntersect(const CPoint2d & p1,const CPoint2d & p2,
				   const CPoint2d & p3,const CPoint2d & p4,
				   CPoint2d & p, const bool & TestInLine=false);
//Kiem tra xem 2 doan thang co cat nhau khong
bool GRAPH_EXT_CLASS LineCut(const double & x11,const double & y11,const double & x12,const double & y12,
			 const double & x21,const double & y21,const double & x22,const double & y22);
bool GRAPH_EXT_CLASS LineCut(const CPoint2d & p1,const CPoint2d & p2,
			 const CPoint2d & p3,const CPoint2d & p4);

//Tinh goc giua 2 vector tao boi (p0,p1) va (p0,p2)
double GRAPH_EXT_CLASS Angle(const CPoint2d & p0, const CPoint2d & p1, const CPoint2d & p2);
//Tinh goc giua 2 vector tao boi (p1,p2) voi phuong ngang
double GRAPH_EXT_CLASS Angle(const CPoint2d & p1, const CPoint2d & p2);

//T×m ®iÓm p trªn ®­êng (p1,p2) mµ (p0,p) vu«ng gãc víi (p1,p2)
CPoint2d GRAPH_EXT_CLASS FindPerPoint(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2);
//TÝnh kho¶ng c¸ch tõ mét ®iÓm p0 tíi mét ®­êng th¼ng (p1,p2)
double GRAPH_EXT_CLASS GetDistP2L(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2);

double GRAPH_EXT_CLASS GetDist2P(const CPoint2d & p1,const CPoint2d & p2);
double GRAPH_EXT_CLASS GetDistXY(const double & x1,const double & y1,const double & x2,const double & y2);
BOOL GRAPH_EXT_CLASS ComparePoint(const CPoint2d & p1,const CPoint2d & p2);
BOOL GRAPH_EXT_CLASS PointInLine(const CPoint2d & p,const CPoint2d & p1,const CPoint2d & p2);

#include <afxtempl.h>
class GRAPH_EXT_CLASS CPline : public CArray<CPoint2d,CPoint2d> 
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

class GRAPH_EXT_CLASS CObjectLine
{
public:
	CPline pline;
	short int styleline;//=0 : is e pline; =1 is an ellipse; =2 is a rectangle; =3 is a string
	COLORREF color; //color of object
	int width; //color of object line
	UINT style; //style of object line
	CString string; //used when styleline==3

	CObjectLine()
	{
		styleline = 0;
		color = 0;
		style = 0;
		width = 0;
	};
	CObjectLine(const CObjectLine & pl)
	{
		styleline=pl.styleline;
		color=pl.color;
		style=pl.style;
		width=pl.width;
		string=pl.string;
		for (int k=0;k<pl.pline.GetSize();k++)
			pline.Add(pl.pline[k]);
	};
	~CObjectLine(){};

	CObjectLine & operator=(const CObjectLine & pl)
	{
		styleline=pl.styleline;
		color=pl.color;
		style=pl.style;
		width=pl.width;
		string=pl.string;
		pline.RemoveAll();
		for (int k=0;k<pl.pline.GetSize();k++)
			pline.Add(pl.pline[k]);
		return *this;
	};
};

typedef CArray<CObjectLine,CObjectLine> CObjectPline;
/*
template<class T>
T absT(const T & in)
{
	return (in<0)? -in : in;
}

template<class T>
T FindMax(const CArray<T,T> & xarray)
{
	T max=0;
	if (xarray.GetSize()<=0) return max;
	max=xarray[0];
	for (int i=0;i<xarray.GetSize();i++)
		if (max<xarray[i]) max=xarray[i];
	return max;
}

template<class T>
T FindMin(const CArray<T,T> & xarray)
{
	T max=0;
	if (xarray.GetSize()<=0) return max;
	max=xarray[0];
	for (int i=0;i<xarray.GetSize();i++)
		if (max>xarray[i]) max=xarray[i];
	return max;
}
*/
class GRAPH_EXT_CLASS CGraph  
{
private:
	CObjectPline m_objectpline;

	int x0,y0;
	int x1,y1,x2,y2;
	double xmax,xmin,ymax,ymin;

	COLORREF colortext;
	COLORREF colorgraph;
	COLORREF colorgrid;
	COLORREF colorbound;
	int m_graphwidth;
	int m_gridwidth;
	int m_boundwidth;
	UINT m_linegraphstyle;
	UINT m_linegridstyle;
	UINT m_lineboundstyle;

	bool m_showgridHor;
	bool m_showgridVer;
	bool m_showbound;
	bool m_showlinezero;
	bool m_showstringX;
	bool m_showstringY;

	int numpoint;
	double xcur,ycur;
	double stepgridHor,stepgridVer;
	CDC * pdc;

	void line(const int & x1,const int & x2,const int & y1,const int & y2);
	void SetColorNormal();

public:
	void Erase();
	CGraph();
	CGraph(int xw1,int yw1,int xw2,int yw2);
	CGraph(CDC * pDC,int xw1,int yw1,int xw2,int yw2);
	virtual ~CGraph();

	void SetDC(CDC * pDC){pdc=pDC;};
	CDC* GetDC(){return pdc;};

	CRect SetRect(int xw1,int yw1,int xw2,int yw2);
	CRect SetRect(const CRect & r);
	CRect GetRect(int & xw1,int & yw1,int & xw2,int & yw2);
	CRect GetRect();

	CRect GetRectControl();
	CRect SetRectControl(const CRect & rin);
	CRect SetRectControl(CWnd & win);
	CRect SetRectControl(CWnd * win);

	void SetRangeX(double xminv,double xmaxv);//set range draw with x direction
	void SetRangeY(double yminv,double ymaxv);//set range draw with y direction

	COLORREF SetColorGrid(const COLORREF & color){COLORREF oldcolor=colorgrid;colorgrid=color;return oldcolor;};
	COLORREF SetColorBound(const COLORREF & color){COLORREF oldcolor=colorbound;colorbound=color;return oldcolor;};
	COLORREF SetColorText(const COLORREF & color){COLORREF oldcolor=colortext;colortext=color;return oldcolor;};
	COLORREF SetColorGraph(const COLORREF & color){COLORREF oldcolor=colorgraph;colorgraph=color;return oldcolor;};
	int SetGraphWidth(const int & w){int temp=m_graphwidth;m_graphwidth=w;return w;};
	int SetGridWidth(const int & w){int temp=m_gridwidth;m_gridwidth=w;return w;};
	int SetBoundWidth(const int & w){int temp=m_boundwidth;m_boundwidth=w;return w;};
	UINT SetGraphStyle(const UINT & w){UINT temp=m_linegraphstyle;m_linegraphstyle=w;return w;};
	UINT SetGridStyle(const UINT & w){UINT temp=m_linegridstyle;m_linegridstyle=w;return w;};
	UINT SetBoundStyle(const UINT & w){UINT temp=m_lineboundstyle;m_lineboundstyle=w;return w;};

	void SetNumpoint(const int & npoint){numpoint=npoint;if (numpoint<0) numpoint=-numpoint;};

	COLORREF GetColorGrid(){return colorgrid;};
	COLORREF GetColorBound(){return colorbound;};
	COLORREF GetColorText(){return colortext;};
	COLORREF GetColorGraph(){return colorgraph;};
	int GetGraphWidth(){return m_graphwidth;};
	int GetGridWidth(){return m_gridwidth;};
	int GetBoundWidth(){return m_boundwidth;};
	UINT GetGraphStyle(){return m_linegraphstyle;};
	UINT GetGridStyle(){return m_linegridstyle;};
	UINT GetBoundStyle(){return m_lineboundstyle;};

	bool GetShowGridHor(){return m_showgridHor;};
	bool GetShowGridVer(){return m_showgridVer;};
	bool GetShowBound(){return m_showbound;};
	bool GetShowLineZero(){return m_showlinezero;};
	bool GetShowStringX(){return m_showstringX;};
	bool GetShowStringY(){return m_showstringY;};

	bool SetShowGridHor(const bool & show){bool temp=m_showgridHor;m_showgridHor=show;return show;};
	bool SetShowGridVer(const bool & show){bool temp=m_showgridVer;m_showgridVer=show;return show;};
	bool SetShowBound(const bool & show){bool temp=m_showbound;m_showbound=show;return show;};
	bool SetShowLineZero(const bool & show){bool temp=m_showlinezero;m_showlinezero=show;return show;};
	bool SetShowStringX(const bool & show){bool temp=m_showstringX;m_showstringX=show;return show;};
	bool SetShowStringY(const bool & show){bool temp=m_showstringY;m_showstringY=show;return show;};

	int  Top(){return y1;};
	int  Bottom(){return y2;};
	int  Left(){return x1;};
	int  Right(){return x2;};

	double  GetXmin(){return xmin;};
	double  GetXmax(){return xmax;};
	double  GetYmin(){return ymin;};
	double  GetYmax(){return ymax;};

	double  GetCurrentX(){return xcur;};
	double  GetCurrentY(){return ycur;};

	void GetOrigin(int & x,int & y){x=x0;y=y0;};//Get origin coordinates (0,0) on graph
	CPoint GetOrigin(){return CPoint(x0,y0);};//Get origin coordinates (0,0) on graph
	double GetX0(){return x0;};
	double GetY0(){return y0;};

	double  ScaleX();//get scale to draw in X direction
	double  ScaleY();//get scale to draw in Y direction

	void SetScaleXY(const double & scale);//dat ti le cua truc Y theo truc X
	void SetScaleYX(const double & scale);//dat ti le cua truc X theo truc Y

	void DrawBackGround(const COLORREF & color,const bool & bound=false);//Draw table grid
	void DrawTable();//Draw table grid
	void DrawFunc(function f);//draw graph with function f
	void DrawFunc(function f,double xminv, double xmaxv);//draw graph with function f and range in x of it
	void DrawFuncPolar(function f,double start, double end);//draw graph with function f and range in x of it
	void DrawPline(const CPline & pline);
	void DrawPline(double * x, double * y, const int & nump);
	void DrawLine(double x1v,double y1v,double x2v,double y2v);
	void DrawLine(const CPoint2d & p1,const CPoint2d & p2);
	void MoveTo(double x,double y);
	void LineTo(double x,double y);
	void MoveTo(const CPoint2d & p);
	void LineTo(const CPoint2d & p);

	void Circle(const CPoint2d & p,const double & rad);
	void Circle(const double & x,const double & y,const double & rad);

	void Ellipse(const CPoint2d & p,const double & radx,const double & rady);
	void Ellipse(const double & x,const double & y,const double & radx,const double & rady);

	void CircleFill(const CPoint2d & p,const double & rad,const COLORREF & color);
	void CircleFill(const double & x,const double & y,const double & rad,const COLORREF & color);
	void EllipseFill(const CPoint2d & p,const double & radx,const double & rady,const COLORREF & color);
	void EllipseFill(const double & x,const double & y,const double & radx,const double & rady,const COLORREF & color);

	void CircleByDC(const CPoint2d & p,const double & rad);
	void CircleByDC(const double & x,const double & y,const double & rad);
	void EllipseByDC(const CPoint2d & p,const double & radx,const double & rady);
	void EllipseByDC(const double & x,const double & y,const double & radx,const double & rady);

	void DrawVector(const CPoint2d &p1, const double & value, const double & angle, const double & larraw=1, const double & anglearrow = 15);
	void DrawVector(const CPoint2d & p1, const CPoint2d & p2, const double & larraw = 1, const double & anglearrow = 15);
	
	void Rectangle(const CPoint2d & p1,const CPoint2d & p2);
	void Rectangle(const double & x1,const double & y1,const double & x2,const double & y2);

	void DrawTextWithColor(const double & x,const double & y,const CString & str,const COLORREF & color,const UINT & just=TA_BOTTOM|TA_LEFT);
	void DrawText(const double & x,const double & y,const CString & str,const UINT & just=TA_BOTTOM|TA_LEFT);
	void DrawTextWithColor(const CString & str,const COLORREF & color,const UINT & just=TA_BOTTOM|TA_LEFT);
	void DrawText(const CString & str,const UINT & just=TA_BOTTOM|TA_LEFT);
	void DrawTextWithColor(const CPoint2d & p,const CString & str,const COLORREF & color,const UINT & just=TA_BOTTOM|TA_LEFT);
	void DrawText(const CPoint2d & p,const CString & str,const UINT & just=TA_BOTTOM|TA_LEFT);

	int  XScreen();
	int  YScreen();

	void Real2Screen(double xr,double yr,int & xscr,int & yscr);
	void Screen2Real(int xscr,int yscr,double & xr,double & yr);
	CPoint2d Real2Screen(const CPoint2d & p);
	CPoint2d Screen2Real(const CPoint2d & p);

	void SetStepgridHor(double step){stepgridHor=step;};//{set value greater than zero to not auto calculate step of grid}
	void SetStepgridVer(double step){stepgridVer=step;};//{set to zero to auto calculate step of grid}
	double  GetStepgridHor();
	double  GetStepgridVer();

	int AddFunc(function f);//draw graph with function f
	int AddFunc(function f,double xminv, double xmaxv);//draw graph with function f and range in x of it
	int AddFuncPolar(function f,double start, double end);
	int AddPline(const CPline & pline);
	int AddPline(double * x, double * y, const int & nump);
	int AddLine(const double & x1v,const double & y1v,const double & x2v,const double & y2v);
	int AddLine(const CPoint2d & p1,const CPoint2d & p2);
	int AddCircle(const CPoint2d & p,const double & rad);
	int AddCircle(const double & x,const double & y,const double & rad);
	int AddEllipse(const CPoint2d & p,const double & radx,const double & rady);
	int AddEllipse(const double & x,const double & y,const double & radx,const double & rady);
	int AddRectangle(const CPoint2d & p1,const CPoint2d & p2);
	int AddRectangle(const double & x1v,const double & y1v,const double & x2v,const double & y2v);
	int AddTextWithColor(const double & x,const double & y,const CString & str,const COLORREF & color,const UINT & just=TA_BOTTOM|TA_LEFT);
	int AddText(const double & x,const double & y,const CString & str,const UINT & just=TA_BOTTOM|TA_LEFT);
	int AddTextWithColor(const CPoint2d & p,const CString & str,const COLORREF & color,const UINT & just=TA_BOTTOM|TA_LEFT);
	int AddText(const CPoint2d & p,const CString & str,const UINT & just=TA_BOTTOM|TA_LEFT);

	void RemoveObject(const int & id);
	void RemoveAllObject();
	CObjectPline *GetObjectPline();
	CObjectLine	*GetObject(const int & id);
	COLORREF  GetColorObject(const int & id);
	CPline * GetDataObject(const int & id);

	CObjectLine	SetObject(const int & id,const CObjectLine & obj);
	COLORREF  SetColorObject(const int & id,const COLORREF & color);
	CPline			SetDataObject(const int & id,const CPline & pl);
	CPline			SetDataObject(const int & id,double * x, double * y, const int & nump);

	int GetNumberObject(){return m_objectpline.GetSize();};

	void	DrawObject(const int & id);
	void	DrawAllObject();

	void	MoveObjectTo(const int & id,const double & x,const double & y);
	void	MoveObjectTrans(const int & id,const double & x,const double & y);
};

#endif // !defined(AFX_GRAPH_H__B1458A55_A2F9_11D7_96E9_A8406B344772__INCLUDED_)
