// Graph.cpp: implementation of the CGraph class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "Graph.h"
#include "math.h"
//#include "MathLib.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const int PostextHorX=5,PostextHorY=10;
const int PostextVerX=-10,PostextVerY=-6;
//===========================================================

void Text(CDC* pDC, double value, int xCoord, int yCoord,COLORREF textcolor)
{
	CString str;str.Format(TEXT("%0.1f"), value);
	CSize Extent = pDC->GetTextExtent(str);
	CRect txtRect(xCoord-Extent.cx, yCoord, xCoord, yCoord+Extent.cy);

	COLORREF color=pDC->SetTextColor(textcolor);
	int oldmode=pDC->SetBkMode(TRANSPARENT);

	pDC->DrawText(str, &txtRect, DT_VCENTER|DT_RIGHT);

	pDC->SetTextColor(color);
	pDC->SetBkMode(oldmode);
}
void Text(CDC* pDC, CString str, int xCoord, int yCoord,COLORREF textcolor)
{
	CSize Extent = pDC->GetTextExtent(str);
	CRect txtRect(xCoord-Extent.cx, yCoord, xCoord, yCoord+Extent.cy);

	COLORREF color=pDC->SetTextColor(textcolor);
	int oldmode=pDC->SetBkMode(TRANSPARENT);

	pDC->DrawText(str, &txtRect, DT_VCENTER|DT_RIGHT);

	pDC->SetTextColor(color);
	pDC->SetBkMode(oldmode);
}
//---
CString GetNumStr(CString & sv)
{
	sv.TrimLeft();sv.TrimRight();
	CString stg;
	if (sv=="")	return CString();
	int i=1;stg="";
	while ((i<=sv.GetLength())&&(sv[i]!=' '))
	{
		stg+=sv[i];
		i++;
	}
	sv=sv.Right(sv.GetLength()-i+1);
	sv.TrimLeft();sv.TrimRight();
	return stg;
}

//=============================================================

void DrawGraphFunc(CDC * pdc, const int & xg, const int & yg,
		const double & scalex,const double & scaley,
		const double & xmin,const double & xmax,
		const int & numpoint, function f)
{
	double dx,x,y;

	dx=(xmax-xmin)/numpoint;
	x=xmin;
	y=f(x);
	x=xg+(x-xmin)*scalex;
	y=yg-y*scaley;
	pdc->MoveTo(CPoint((int)x,(int)y));
	for (int i=1;i<=numpoint;i++)
	{
		x=xmin+i*dx;
		y=f(x);
		x=xg+(x-xmin)*scalex;
		y=yg-y*scaley;
		pdc->LineTo(CPoint((int)x,(int)y));
	}
}
//---------
void DrawTable(CDC * pdc,int xgraph1,int ygraph1,
			   int xgraph2,int ygraph2,
			   const int & numx,const int & numy,
			   CString sx,CString sy,
			   const COLORREF & clgrid,const COLORREF & clstring)
{
	int i;
	if (xgraph1>xgraph2) {i=xgraph1;xgraph1=xgraph2;xgraph2=i;}
	if (ygraph1>ygraph2) {i=ygraph1;ygraph1=ygraph2;ygraph2=i;}

	CPen newpen;
	newpen.CreatePen(PS_SOLID, 2, clgrid);
	CPen * pOldPen = pdc->SelectObject(&newpen);

	pdc->Rectangle(xgraph1,ygraph1,xgraph2,ygraph2);

   newpen.DeleteObject();
   newpen.CreatePen(PS_SOLID, 1, clgrid);
   pdc->SelectObject(&newpen);

	if (numx>0)
	{
	   double delta=(xgraph2-xgraph1)/numx;
	   for (i=1;i<=numx+1;i++)
	   {
		   if (i<numx) 
		   {
			   pdc->MoveTo((int)(xgraph1+i*delta),(int)ygraph1);
			   pdc->LineTo((int)(xgraph1+i*delta),(int)ygraph2);
		   }
		   Text(pdc,GetNumStr(sx),(int)(xgraph1+(i-1)*delta),(int)ygraph2+10,clstring);
	   }
	}
	if (numy>0)
	{
	   double delta=(ygraph2-ygraph1)/numy;
	   for (i=1;i<=numy+1;i++)
	   {
		   if (i<numy)
		   {
			   pdc->MoveTo((int)xgraph1,(int)(ygraph1+i*delta));
			   pdc->LineTo((int)xgraph2,(int)(ygraph1+i*delta));
		   }
		   Text(pdc,GetNumStr(sy),(int)xgraph1-10,(int)(ygraph2-(i-1)*delta),clstring);
		}
	}
	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}
//---------
void DrawGrid(CDC* pDC, double minx, double maxx,
								 double miny, double maxy,
								 BOOL gridLines,
								 double stepx, double stepy, 
								 const CRect &rect)
{
	pDC->Rectangle(rect);

	CPen m_pen;m_pen.CreatePen(PS_DOT, 1, RGB(0,0,0));
	CPen * m_pOldPen = pDC->SelectObject(&m_pen);
	COLORREF colortext(RGB(0,0,0));

	double deltax = (maxx - minx) / rect.Width();
	double deltay = (maxy - miny) / rect.Height();	

	// num gridlines on X axis
	int numLX = (int)ceil((maxx - minx) / stepx);              
	// num gridlines on Y axis
	int numLY = (int)ceil((maxy - miny) / stepy);  
	
	int pad = 8;
	int i, x, y;
	for (i=0; i<numLX; i++)
	{
		x = rect.left + (int)(i*stepx / deltax);
		Text(pDC, minx+i*stepx, x, rect.bottom+2,colortext);
		if (i>0)
		{
			pDC->MoveTo(x, rect.bottom);
			if (gridLines)
				pDC->LineTo(x, rect.top);
			else
				pDC->LineTo(x, rect.bottom-pad);
		}
	}
	Text(pDC, maxx, rect.right-5, rect.bottom+2,colortext);

	for (i=0; i<numLY; i++)
	{
		y = rect.bottom - (int)(i*stepy / deltay);
		Text(pDC, miny+i*stepy, rect.left-20, y-8,colortext);
		if (i>0)
		{
			pDC->MoveTo(rect.left, y);
			if (gridLines)
				pDC->LineTo(rect.right, y);
			else
				pDC->LineTo(rect.left+pad, y);
		}	
	}
	Text(pDC, maxy, rect.left-20, rect.top-8,colortext);

	pDC->SelectObject(m_pOldPen);
	m_pen.DeleteObject();
}

//////////////////////////////////////////////////////////////////////
// Implementation of CPoint2d
//////////////////////////////////////////////////////////////////////
CPoint2d RotatePoint(const CPoint2d & p0, const CPoint2d & p1, const double & angle)
{
	double dis;
    double goc0;
	CPoint2d p2;

     double goc=angle*PI/180.0;
     dis=sqrt(pow(p1.x-p0.x,2)+pow(p1.y-p0.y,2));
     if (fabs(p1.x-p0.x)>LocalZero) goc0=atan(fabs(p1.y-p0.y)/fabs(p1.x-p0.x));
     else
	 {
         if (p1.y-p0.y>0) goc0=PI/2;
         else  goc0=3*PI/2;
	 }

     if ((p1.x-p0.x<0)&&(p1.y-p0.y>=0))  goc0=PI-fabs(goc0);
     if ((p1.x-p0.x<0)&&(p1.y-p0.y<0))   goc0=PI+fabs(goc0);
     if ((p1.x-p0.x>0)&&(p1.y-p0.y<0))   goc0=2*PI-fabs(goc0);

     p2.x=p0.x+dis*cos(goc+goc0);
     p2.y=p0.y+dis*sin(goc+goc0);
	 return p2;
}

CPoint2d Polar(const CPoint2d & p,const double & angle,const double & r)
{
	double goc=angle*PI/180.0;
	return CPoint2d(p.x+r*cos(goc),p.y+r*sin(goc));
}

bool FindInt2Circle(const CPoint2d & p01,const double & r1,
									const CPoint2d & p02,const double & r2,
									CPoint2d & p1,CPoint2d &p2)
{
	double a=GetDist2P(p01,p02);
	p1.x=p2.x=(r1*r1-r2*r2+a*a)/(2.0*a);
	if (fabs(p1.x)>r1) return false;
	p1.y=sqrt(r1*r1-pow(p1.x,2));
	p2.y=-p1.y;
	double angle=Rad2Deg(Angle(p01,p02,p01+CPoint(100,0)));
	//double angle=Rad2Deg(Angle(p02.x-p01.x,p02.y-p01.y));
	//double angle=0;
	double dau=(p01.y<p02.y)?1.0:-1.0;
	p1=p01+RotatePoint(CPoint2d(0,0),p1,dau*angle);
	p2=p01+RotatePoint(CPoint2d(0,0),p2,dau*angle);
	return true;
}

//Tim giao diem cua duong tron (p0,r) voi duong thang (p1,p2)
bool FindIntLineCircle(const CPoint2d & p1,const CPoint2d & p2,
								const CPoint2d & p0,const double & r,
								CPoint2d & pi1,CPoint2d &pi2)
{
	CPoint2d p3=FindPerPoint(p0,p1,p2);
	double a=GetDist2P(p0,p3);
	bool res=false;
	if (a<=r)
	{
		res=true;
		if (a==r)
		{
			pi1=p3;
			pi2=p3;
		}
		else
		{
			if (a==0)
			{
				double goc=Angle(p1,p2);
				pi1 = Polar(p0,goc,r);
				pi2 = Polar(p0,90.0+goc,r);
			}
			else
			{
				double goc=Angle(p0,p3);
				pi1.x=p0.x+a;
				pi2.x=pi1.x;
				pi1.y=p0.y+r*r-a*a;
				pi2.y=p0.y-r*r-a*a;
				pi1=RotatePoint(p0,pi1,goc);
				pi2=RotatePoint(p0,pi2,goc);
			}
		}
	}
	return res;
}

//=============================================
//=============================================
bool FindIntersect(const double & x11,const double & y11,const double & x12,const double & y12,
				   const double & x21,const double & y21,const double & x22,const double & y22,
				   double & x,double & y, const bool & TestInLine)
{
	double ss=localzero;
	double a1,a2,b1,b2;
	
	if (((fabs(x11-x12)<=ss)&&(fabs(x21-x22)<=ss))
		||((fabs(y11-y12)<=ss)&&(fabs(y21-y22)<=ss))) return false;
	if (fabs(x11-x12)<=ss)//duong 1 thang dung
	{
		x=x11;
		a2=(y22-y21)/(x22-x21);
		b2=y21-x21*a2;
		y=a2*x+b2;
	}  
	else
		if (fabs(x21-x22)<=ss)//duong 2 thang dung
		{
			x=x21;
			a1=(y12-y11)/(x12-x11);
			b1=y11-x11*a1;
			y=a1*x+b1;
		}
		else
		{
			a1=(y12-y11)/(x12-x11);
			b1=y11-x11*a1;
			a2=(y22-y21)/(x22-x21);
			b2=y21-x21*a2;
			if (fabs(a1-a2)<=ss) return false;
			x=-(b2-b1)/(a2-a1);
			y=a1*x+b1;
		}
		if (TestInLine)//kiem tra xem giao diem co nam giua cac doan thang khong
		{
			if (((x-x11)*(x12-x)>=0)&&((y-y11)*(y12-y)>=0))
				if (((x-x21)*(x22-x)>=0)&&((y-y21)*(y22-y)>=0)) return true;
				return false;
		}
		return true;
}

bool FindIntersect(const CPoint2d & p1,const CPoint2d & p2,
				   const CPoint2d & p3,const CPoint2d & p4,
				   CPoint2d & p, const bool & TestInLine)
{
	return FindIntersect(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y,p.x,p.y,TestInLine);
}

bool LineCut(const double & x11,const double & y11,const double & x12,const double & y12,
			 const double & x21,const double & y21,const double & x22,const double & y22)
{
	double x,y;
	return FindIntersect(x11,y11,x12,y12,x21,y21,x22,y22,x,y,true);
}
bool LineCut(const CPoint2d & p1,const CPoint2d & p2,
			 const CPoint2d & p3,const CPoint2d & p4)
{
	return LineCut(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
}
//=============================================
//=============================================
double Angle(const CPoint2d & p0, const CPoint2d & p1, const CPoint2d & p2)
{
	double ang;
	CPoint2d v1=p1-p0;
	CPoint2d v2=p2-p0;
	double t=v1.x*v2.x+v1.y*v2.y;
	double l1=sqrt(v1.x*v1.x+v1.y*v1.y);
	double l2=sqrt(v2.x*v2.x+v2.y*v2.y);
	ang=acos(t/(l1*l2));
	return ang;
}
double Angle(const CPoint2d & p1, const CPoint2d & p2)
{
	double phi=Angle(p2.x-p1.x,p2.y-p1.y);
	if (fabs(phi)<=localzero)
		if (p1.x>p2.x) phi=PI;
	return phi;
}

CPoint2d FindPerPoint(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2)
{
	double a=p2.x-p1.x;
	double b=p2.y-p1.y;
	double c1=p1.x*b-p1.y*a;
	double c2=p0.x*a+p0.y*b;
	CPoint2d p(p0);

	if (a*a+b*b==0) {return p;}
	p.x=(c1*b+c2*a)/(a*a+b*b);
	if (a==0) p.y=p0.y;	else p.y=b*(p.x-p1.x)/a+p1.y;
	return p;	
}
double GetDistP2L(const CPoint2d & p0,const CPoint2d & p1,const CPoint2d & p2)
{
	return GetDist2P(p0,FindPerPoint(p0,p1,p2));
}
double GetDist2P(const CPoint2d & p1,const CPoint2d & p2)
{
	return pow(pow(p1.x-p2.x,2.0)+pow(p1.y-p2.y,2.0),0.5);
}
double GetDistXY(const double & x1,const double & y1,const double & x2,const double & y2)
{
	return pow(pow(x1-x2,2.0)+pow(y1-y2,2.0),2.0);
}
BOOL ComparePoint(const CPoint2d & p1,const CPoint2d & p2)
{
	if ((p1.x==p2.x)&&(p1.y==p2.y)) return true;
    return false;
}
BOOL PointInLine(const CPoint2d & p,const CPoint2d & p1,const CPoint2d & p2)
{
	double dx1=p.x-p1.x;
	double dx2=p.x-p2.x;
	double dy1=p.y-p1.y;
	double dy2=p.y-p2.y;
	double d0=dx1*(p2.y-p1.y)-dy1*(p2.x-p1.x);
	if ((fabs(d0)<=LocalZero)&&((dx1*dx2<=LocalZero)&&(dy1*dy2<=LocalZero))) return true;
	//if ((dx1*dx2<=LocalZero)&&(dy1*dy2<=LocalZero)) return true;
	return false;
}

CPoint2d operator+(const CPoint2d & p1,const CPoint2d & p2)
{
	return CPoint2d(p1.x+p2.x,p1.y+p2.y);
}
CPoint2d operator-(const CPoint2d & p1,const CPoint2d & p2)
{
	return CPoint2d(p1.x-p2.x,p1.y-p2.y);
}

CPoint2d & CPoint2d::operator=(const CPoint2d & p)
{
	x=p.x;
	y=p.y;
	return *this;
}

CPoint2d & CPoint2d::operator=(const CPoint & p)
{
	x=p.x;
	y=p.y;
	return *this;
}

bool CPoint2d::operator==(const CPoint & p)
{
	if ((p.x==x)&&(p.y==y)) return true;
	return false;
}
bool CPoint2d::operator!=(const CPoint & p)
{
	if ((p.x==x)&&(p.y==y)) return false;
	return true;
}

CPoint2d::operator CPoint()
{
	CPoint p((int)x,(int)y);
	return p;
}

double & CPoint2d::operator[](const int & i)
{
	if (i==0) return x;
	return y;
}

//===========================================================
//===========================================================
//===========================================================

typedef struct HALF_SPACE_CODE
{
	bool l,r,t,b;
}half_space_code;

typedef struct RECTREAL
{
	double t,b,l,r;
}rectreal;

//--------
int GetFirstNum(double x)
{
	if (x==0) return 0;
	x=fabs(x);
	if (x<1.0)
		while (x<1.0) x=x*10.0;
	else
		while (x>=10.0)  x=x/10.0;
	return (int)floor(x);
}
//--------
int GetSecNum(double x)
{
	if (x==0.0) return 0;
	x=fabs(x);
	if (x<1.0)
	 while (x<1.0) x=x*10.0;
	else
	 while (x>=10.0) x=x/10.0;
	x=(x-floor(x))*10.0;
	return (int)floor(x);
}
//--------
int GetThreeNum(double x)
{
	if (x==0.0) return 0;
	x=fabs(x);
	if (x<1.0)
	 while (x<1.0) x=x*10.0;
	else
	 while (x>=10.0) x=x/10.0;
	x=(x-floor(x))*10.0;
	x=(x-floor(x))*10.0;
	return (int)floor(x);
}
//--------
int GetExpNum(double x)
{
   if (x==0.0) return 0;
   x=fabs(x);
   if (x<1.0)
   {
     int i=1;
     while (x<1.0)
     {
          x=x*10.0;i=i-1;
     }
     return i;
   }
   int i=1;
   while (x>=10.0)
   {
          x=x/10.0;i=i+1;
   }
   return i;
}
//--------
double Cal_Step(double xmin, double xmax)
{
	double x,xstep;
	int n1,e;
	if (xmin>xmax) {xstep=xmin;xmin=xmax;xmax=xstep;}
	x=xmax-xmin;
	if (x==0) return 1.0;
	n1=GetFirstNum(x);
	e=GetExpNum(x);
	if (n1>=5) xstep=0.1*pow(10,e);
	else
	{
	 if (n1>=2) xstep=0.05*pow(10,e);
	 else
	 {
		 if (n1>=1.25) xstep=0.025*pow(10,e);
		 else xstep=0.02*pow(10,e);
	 }
	}
	return xstep;
}
//--------
double Cal_Step0(double xmin,double xmax)
{
	double xstep,xrun;
	if (xmin>xmax) {xrun=xmin;xmin=xmax;xmax=xrun;}
	if (xmin<0)
	{
	  xmax=-xmin+(xmax-xmin);
	  xmin=-xmin;
	}
	xstep=Cal_Step(xmin,xmax);
	xrun=0;
	while (xrun<xmin) xrun=xrun+xstep;
	return (xrun-xmin);
}
//--------
void encode(const double & x,const double & y,
			half_space_code & c,
			const rectreal & w)
{
     c.l=(x<w.l);
     c.r=(x>w.r);
     c.b=(y>w.b);
     c.t=(y<w.t);
}
void encode(const CPoint2d & p,
			half_space_code & c,
			const rectreal & w)
{
     c.l=(bool)(p.x<w.l);
     c.r=(bool)(p.x>w.r);
     c.b=(bool)(p.y>w.b);
     c.t=(bool)(p.y<w.t);
}

bool ClipView(CPoint2d & p1,CPoint2d & p2,
			  const rectreal & w)
{
    half_space_code c1,c2,tmp_cd;
    CPoint2d tmp_pt;
    double m;
    bool in1,in2;
	int done,vis;
    done=0;vis=0;
    do
    {
		encode(p1,c1,w);
		encode(p2,c2,w);
		in1=(!c1.l)&&(!c1.t)&&(!c1.r)&&(!c1.b);
		in2=(!c2.l)&&(!c2.t)&&(!c2.r)&&(!c2.b);
		if (in1 && in2)
		{
		   done=1;vis=1;
		}
		else
		{
			if ((c1.l && c2.l)||(c1.r && c2.r)||(c1.t && c2.t)||(c1.b && c2.b))
			{
				done=1;vis=0;
			}
			else
			{
				if (in1)
				{
				  tmp_cd=c1;c1=c2;c2=tmp_cd;
				  tmp_pt=p1;p1=p2;p2=tmp_pt;
				}
				if (p2.x==p1.x)
				{
				  if (c1.t) p1.y=(w.t);  else if (c1.b) p1.y=(w.b);
				}
				else
				{
					m=(p2.y-p1.y)/(p2.x-p1.x);
					if (c1.l)
					 {
						 p1.y=(p1.y+(w.l-p1.x)*m); p1.x=(w.l);
					 }
					else
					{
						if (c1.r)
						{
							p1.y=(p1.y+(w.r-p1.x)*m);p1.x=(w.r);
						}
						else
						{
							if (c1.b)
							{
								   p1.x=(p1.x+(w.b-p1.y)/m); p1.y=(w.b);
							}
							else
								   if (c1.t)
								  {
									  p1.x=(p1.x+(w.t-p1.y)/m); p1.y=(w.t);
								  }
						}
					}
			  }//not vertical line
			}
		}//at least one outside
    }//do { } while
    while (!done);
	return (vis==1);
}

bool ClipView(double & x1,double & y1,
			  double & x2,double & y2,
			  const rectreal & w)
{
	CPoint2d p1(x1,y1),p2(x2,y2);
	bool vis=ClipView(p1,p2, w);
	x1=p1.x;y1=p1.y;
	x2=p2.x;y2=p2.y;
	return vis;
}

int GetNumE(const double & x)
{
	int e=GetExpNum(x)-1, n2=GetSecNum(x), n3=GetThreeNum(x);
	if (e<0) e=-e;  else e=0; if (n3!=0) e=e+2; else if (n2!=0) e=e+1;
	return e;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction of CGraph
//////////////////////////////////////////////////////////////////////
void CGraph::SetColorNormal()
{
	colorbound=RGB(0,0,0);
	colorgraph=RGB(255,0,0);
	colorgrid=RGB(0,0,0);
	colortext=RGB(0,0,255);
	m_graphwidth=2;
	m_linegraphstyle=PS_SOLID;
	m_gridwidth=1;
	m_linegridstyle=PS_SOLID;
	m_boundwidth=2;
	m_lineboundstyle=PS_SOLID;
	m_showgridHor=true;
	m_showgridVer=true;
	m_showbound=true;
	m_showlinezero=true;
	m_showstringX=true;
	m_showstringY=true;
}

CGraph::CGraph()
{
	SetColorNormal();
	x1=0;x2=0;y1=0;y2=0;
	xmax =1;
	xmin =0;
	ymax =1;
	ymin =0;
	numpoint=50;
	x0   =x1;
	y0   =y2;
	stepgridHor=0;
	stepgridVer=0;
	pdc=NULL;
}

CGraph::CGraph(int xw1,int yw1,int xw2,int yw2)
{
	SetRect(xw1,yw1,xw2,yw2);
	SetColorNormal();
	pdc=NULL;
	stepgridHor=0;
	stepgridVer=0;
	numpoint=(x2-x1)/5;
}
CGraph::CGraph(CDC * pDC,int xw1,int yw1,int xw2,int yw2)
{
	SetRect(xw1,yw1,xw2,yw2);
	SetColorNormal();
	pdc=pDC;
	stepgridHor=0;
	stepgridVer=0;
	numpoint=(x2-x1)/5;
}

CGraph::~CGraph()
{
}

CRect CGraph::SetRect(int xw1,int yw1,int xw2,int yw2)
{
	CRect r(x1,y1,x2,y2);
	x1=xw1;y1=yw1;x2=xw2;y2=yw2;
	if (xw1>xw2)  { x1=xw2;x2=xw1; }
	if (yw1>yw2)  { y1=yw2;y2=yw1; }
	if (xw1==xw2)  x2=x1+100;
	if (yw1==yw2)  y2=y1+100;
	if (xmax==xmin)  xmax=xmin+(x2-x1);
	if (ymax==ymin)  ymax=ymin+(y2-y1);
	x0=(int)(x1-xmin*(x2-x1)/(xmax-xmin));
	y0=(int)(y2+ymin*(y2-y1)/(ymax-ymin));
	if (numpoint==0) numpoint=(x2-x1)/5;
	return r;
}
CRect CGraph::SetRect(const CRect & r)
{
	return SetRect(r.left,r.top,r.right,r.bottom);
}
CRect CGraph::GetRect(int & xw1,int & yw1,int & xw2,int & yw2)
{
	CRect r(x1,y1,x2,y2);
	xw1=x1;yw1=y1;xw2=x2;yw2=y2;
	return r;
}
CRect CGraph::GetRect()
{
	return CRect(x1,y1,x2,y2);
}

CRect CGraph::SetRectControl(CWnd * win)
{
	return SetRectControl(*win);
}

CRect CGraph::SetRectControl(CWnd & win)
{
	win.UpdateWindow();
	pdc=win.GetDC();
	CRect rout(GetRectControl()),rin;
	win.GetClientRect(&rin);
	rin.right++;rin.bottom++;
	rin.OffsetRect(CPoint(-rin.left,-rin.top));
	SetRectControl(rin);
	return rout;
}

CRect CGraph::SetRectControl(const CRect & rin)
{
	CRect rout(GetRectControl());

	double  dxl=0,dxr=0,dyt=0,dyb=0;
	double xstep,ystep;
	int e;
	CString s;
	CSize Extent;

	
	if (stepgridHor<=0) xstep=Cal_Step(xmin,xmax);	else xstep=stepgridHor;
	if (stepgridVer<=0) ystep=Cal_Step(ymin,ymax);	else ystep=stepgridVer;

	int wt=9,ht=16;

	if (this->m_showstringX)
	{
		e=GetNumE(xmax);
		s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmax);
		Extent = pdc->GetTextExtent(s);
		dyb=PostextHorY+Extent.cy;
		dxr=PostextHorX;
	}
	else
		if (this->m_showstringY)
		{
			Extent = pdc->GetTextExtent("123|!");
			dyb=Extent.cy/2.0+1.0;
		}

	if (this->m_showstringY)
	{
		double ycall[4];
		ycall[0]=ymin;
		ycall[1]=ymin+ystep;
		ycall[2]=ymax-ystep;
		ycall[3]=ymax;
		for (int i=0;i<4;i++)
		{
			e=GetNumE(ycall[i]);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),ycall[i]);
			Extent = pdc->GetTextExtent(s);
			double temp=PostextVerX-Extent.cx;
			if (temp<dxl) dxl=temp;
		}
		Extent = pdc->GetTextExtent("123|!");
		dyt=Extent.cy/2.0+1.0;
	}
	else
		if (this->m_showstringX)
		{
			e=GetNumE(xmin);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmin);
			Extent = pdc->GetTextExtent(s);
			double temp=PostextHorX-Extent.cx;
			if (temp<dxl) dxl=temp;
		}
	x1=(int)(rin.left-dxl);x2=(int)(rin.right-dxr);
	y1=(int)(rin.top+dyt);y2=(int)(rin.bottom-dyb);
	SetRect(x1,y1,x2,y2);
	return rout;
}
CRect CGraph::GetRectControl()
{
	CRect rout(x1,y1,x2,y2);

	if (pdc==NULL) return rout;

	double xstep,ystep;
    int e;
	CString s;
	
	if (stepgridHor<=0) xstep=Cal_Step(xmin,xmax);	else xstep=stepgridHor;
	if (stepgridVer<=0) ystep=Cal_Step(ymin,ymax);	else ystep=stepgridVer;

	CSize Extent;

	//{ghi so hoanh do}
	if (this->m_showstringX)
	{
		e=GetNumE(xmax);
		s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmax);
		Extent = pdc->GetTextExtent(s);
		rout.bottom+=PostextHorY+Extent.cy;
		rout.right+=PostextHorX;
	}
	else
		if (this->m_showstringY)
		{
			Extent = pdc->GetTextExtent("|12!");
			rout.bottom+=Extent.cy/2+1;
		}
	//{ghi so tung do}
	if (this->m_showstringY)
	{
		double ycall[4];
		ycall[0]=ymin;
		ycall[1]=ymin+ystep;
		ycall[2]=ymax-ystep;
		ycall[3]=ymax;
		for (int i=0;i<4;i++)
		{
			e=GetNumE(ycall[i]);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),ycall[i]);
			Extent = pdc->GetTextExtent(s);
			int temp=(int)(x1+PostextVerX-Extent.cx);
			if (temp<rout.left) rout.left=temp;
		}
		rout.top-=Extent.cy/2+1;
	}
	else
		if (this->m_showstringX)
		{
			e=GetNumE(xmin);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmin);
			Extent = pdc->GetTextExtent(s);
			int temp=(int)(x1+PostextHorX-Extent.cx);
			if (temp<rout.left) rout.left=temp;
		}
	return rout;
}

void CGraph::SetRangeX(double xminv,double xmaxv)
{
	xmax =xmaxv; xmin =xminv;
	if (xmaxv<xminv)
	{
	  xmax=xminv; xmin=xmaxv;
	}
	if (xmax==xmin) xmax=xmin+(x2-x1);
	x0=(int)(x1-xmin*(x2-x1)/(xmax-xmin));
	stepgridHor=0;
}//set range draw with x direction
void CGraph::SetRangeY(double yminv,double ymaxv)
{
	ymax =ymaxv;
	ymin =yminv;
	if (ymaxv<yminv)
	{
	  ymax=yminv; ymin=ymaxv;
	}
	if (ymax==ymin) ymax=ymin+(y2-y1);
	y0=(int)(y2+ymin*(y2-y1)/(ymax-ymin));
	stepgridVer=0;
}//set range draw with y direction

double  CGraph::ScaleX()
{
	if (xmax==xmin) xmax=xmin+(x2-x1);
	return (x2-x1)/(xmax-xmin);
}//get scale to draw in X direction
double  CGraph::ScaleY()
{
	if (ymax==ymin) ymax=ymin+(y2-y1);
	return (y2-y1)/(ymax-ymin);
}//end of getting scale to draw in Y direction
void CGraph::SetScaleXY(const double & scale)//dat ti le cua truc Y theo truc X
{
	ymax=ymin+scale*(xmax-xmin)*(y2-y1)/(x2-x1);
	SetRangeY(ymin,ymax);
}
void CGraph::SetScaleYX(const double & scale)//dat ti le cua truc X theo truc Y
{
	xmax=xmin+scale*(ymax-ymin)*(x2-x1)/(y2-y1);
	SetRangeX(xmin,xmax);
}
	
void CGraph::line(const int & x1,const int & y1,const int & x2,const int & y2)
{
	pdc->MoveTo(x1,y1);
	pdc->LineTo(x2,y2);
	//pdc->Ellipse(CRect(x1-5,y1-5,x1+5,y1+5));
	//pdc->Ellipse(CRect(x2-5,y2-5,x2+5,y2+5));
}

void CGraph::DrawBackGround(const COLORREF & color,const bool & bound)
{
	CPen newpen;CPen * pOldPen;
	if (bound)
	{
		newpen.CreatePen(m_linegridstyle,1, colorbound);
		pOldPen = pdc->SelectObject(&newpen);
	}
	else
		pOldPen = (CPen *)pdc->SelectStockObject(NULL_PEN);

	CBrush brush;
	brush.CreateSolidBrush(color);
	CBrush *oldbrush;oldbrush=pdc->SelectObject(&brush);

	pdc->Rectangle(this->GetRectControl());

	if (oldbrush) pdc->SelectObject(oldbrush);
	if (pOldPen) pdc->SelectObject(pOldPen);

	newpen.DeleteObject();
	brush.DeleteObject();
}
void CGraph::DrawTable()
{
	double xstep,ystep;
    double xl1,xl2,yl1,yl2,sx,sy,x;
    int e;
	CString s;
	
	if (stepgridHor<=0) xstep=Cal_Step(xmin,xmax);
	else xstep=stepgridHor;
	if (stepgridVer<=0) ystep=Cal_Step(ymin,ymax);
	else ystep=stepgridVer;

	sx=ScaleX();sy=ScaleY();

	CPen * pOldPen =NULL;

	{
		CPen newpen;
		newpen.CreatePen(m_linegridstyle,m_gridwidth, colorgrid);
		pOldPen = pdc->SelectObject(&newpen);
		//{Ve luoi theo phuong x}
		if (this->m_showgridVer)
		{
			if (x0<x2)
			{
			  xl1=x0;xl2=xl1;yl1=y1;yl2=y2;
			  if ((xl1>x1)&&(xl1<x2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  while (xl1+xstep*sx<x2)
			  {
				   xl1=xl1+xstep*sx;xl2=xl1;
				   if ((xl1>x1)&&(xl1<x2))
					   line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  }
			}
			if (x0>x1)
			{
			  xl1=x0;xl2=xl1;yl1=y1;yl2=y2;
			  if ((xl1>x1)&&(xl1<x2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  while (xl1-xstep*sx>x1)
			  {
				   xl1=xl1-xstep*sx;xl2=xl1;
				   if ((xl1>x1)&&(xl1<x2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  }
			}
		}
		//{Ve luoi theo phuong y}
		if (this->m_showgridHor)
		{
			if (y0>y1)
			{
			  xl1=x1;xl2=x2;yl1=y0;yl2=yl1;
			  if ((yl1>y1)&&(yl1<y2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  while (yl1-ystep*sy>y1)
			  {
				   yl1=yl1-ystep*sy;yl2=yl1;
				   if ((yl1>y1)&&(yl1<y2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  }
			}
			if (y0<y2)
			{
			  xl1=x1;xl2=x2;yl1=y0;yl2=yl1;
			  if ((yl1>y1)&&(yl1<y2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  while (yl1+ystep*sy<y2)
			  {
				   yl1=yl1+ystep*sy;yl2=yl1;
				   if ((yl1>y1)&&(yl1<y2)) line((int)(xl1),(int)(yl1),(int)(xl2),(int)(yl2));
			  }
			}
		}
		pdc->SelectObject(pOldPen);
		newpen.DeleteObject();
	}//end one pen
	CBrush *oldbrush =(CBrush *)pdc->SelectStockObject(NULL_BRUSH);
	if (this->m_showgridHor||this->m_showgridVer) pdc->Rectangle(x1,y1,x2,y2);
	if (this->m_showbound)
	{
		CPen newpen;
		newpen.CreatePen(m_lineboundstyle,m_boundwidth, colorbound);
		pdc->SelectObject(&newpen);
		pdc->Rectangle(x1,y1,x2,y2);
		pdc->SelectObject(pOldPen);
		newpen.DeleteObject();
	}
	pdc->SelectObject(oldbrush);

	//Ke duong goc (0,0)
	{
		CPen newpen;
		newpen.CreatePen(PS_SOLID, 2, colortext);
		pdc->SelectObject(&newpen);
		if (this->m_showlinezero)
		{
			if ((x0>=x1)&&(x0<=x2)) line(x0,y1,x0,y2);
			if ((y0>=y1)&&(y0<=y2)) line(x1,y0,x2,y0);
		}

		//{ghi so hoanh do}
		if (this->m_showstringX)
		{
			e=GetNumE(xmax);
			if (e<GetNumE(xstep)) e=GetNumE(xstep);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmax);	Text(pdc,s,x2+PostextHorX,y2+PostextHorY,colortext);
			e=GetNumE(xmin);
			if (e<GetNumE(xstep)) e=GetNumE(xstep);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),xmin);	Text(pdc,s,x1+PostextHorX,y2+PostextHorY,colortext);
			e=GetNumE(xstep);
			if (x0<x2)
			{
			  xl1=x0;x=0;
			  s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
			  if (( (int)(xl1)>x1 )&&( (int)(xl1)<x2 )) Text(pdc,s,(int)(xl1)+PostextHorX,y2+PostextHorY,colortext);
			  while (xl1+xstep*sx<x2)
			  {
				   x=x+xstep;
				   s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
				   xl1=xl1+xstep*sx;
				   if (((int)(xl1)>x1+1)&&((int)(xl1)<x2-1))  Text(pdc,s,(int)(xl1)+PostextHorX,y2+PostextHorY,colortext);
			  }
			}
			if (x0>x1)
			{
			  xl1=x0;x=0;
			  s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
			  if (((int)(xl1)>x1)&&((int)(xl1)<x2)) Text(pdc,s,(int)(xl1)+PostextHorX,y2+PostextHorY,colortext);
			  while (xl1-xstep*sx>x1)
			  {
				   x=x-xstep;
				   s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
				   xl1=xl1-xstep*sx;
				   if (((int)(xl1)>x1+1)&&((int)(xl1)<x2-1)) Text(pdc,s,(int)(xl1)+PostextHorX,y2+PostextHorY,colortext);
			  }
			}
		}
		//{ghi so tung do}
		if (this->m_showstringY)
		{
			int offset=2;
			e=GetNumE(ymax);
			if (e<GetNumE(ystep)) e=GetNumE(ystep);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),ymax);Text(pdc,s,x1+PostextVerX+offset,y1+PostextVerY,colortext);
			e=GetNumE(ymin);
			if (e<GetNumE(ystep)) e=GetNumE(ystep);
			s.Format("0.%d",e);s.Format(_T("%"+s+"f"),ymin); Text(pdc,s,x1+PostextVerX+offset,y2+PostextVerY,colortext);
			e=GetNumE(ystep);
			if (y0<y2)
			{
			  yl1=y0;x=0;
			  s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
			  if (((int)(yl1)>y1+1)&&((int)(yl1)<y2-1)) Text(pdc,s,x1+PostextVerX+offset,(int)(yl1)+PostextVerY,colortext);
			  while (yl1+ystep*sy<y2)
			  {
				   x=x-ystep;
				   s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
				   yl1=yl1+ystep*sy;
				   if (((int)(yl1)>y1+1)&&((int)(yl1)<y2-1)) Text(pdc,s,x1+PostextVerX+offset,(int)(yl1)+PostextVerY,colortext);
			  }
			}
			if (y0>y1)
			{
			  yl1=y0;x=0;
			  s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
			  if (((int)(yl1)>y1+1)&&((int)(yl1)<y2-1)) Text(pdc,s,x1+PostextVerX+offset,(int)(yl1)+PostextVerY,colortext);
			  while (yl1-ystep*sy>y1)
			  {
				   x=x+ystep;
				   s.Format("0.%d",e);s.Format(_T("%"+s+"f"),x);
				   yl1=yl1-ystep*sy;
				   if (((int)(yl1)>y1+1)&&((int)(yl1)<y2-1)) Text(pdc,s,x1+PostextVerX+offset,(int)(yl1)+PostextVerY,colortext);
			  }
			}
		}
		pdc->SelectObject(pOldPen);
		newpen.DeleteObject();
	}
}//} of Drawwing table grid

void CGraph::DrawFunc(function f)
{
	if (numpoint==0) return;
	double dx,sx,sy,px1,px2,py1,py2;
	int i;
	rectreal r;

	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

	sx=ScaleX();sy=ScaleY();
	dx=(xmax-xmin)/numpoint;
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

	for (i=1;i<=numpoint;i++)
	{
	  px1=xmin+(i-1)*dx;
	  py1=f(px1);
	  px1=x1+(px1-xmin)*sx;
	  py1=y0-py1*sy;

	  px2=xmin+i*dx;
	  py2=f(px2);
	  xcur=px2;ycur=py2;
	  px2=x1+(px2-xmin)*sx;
	  py2=y0-py2*sy;
	  
	  if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	}
	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}//draw graph with function f

void CGraph::DrawFunc(function f,double xminv, double xmaxv)
{
	double dx,sx,sy,px1,px2,py1,py2;
    int i;
    rectreal r;

	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

    sx=ScaleX();sy=ScaleY();
	dx=(xmaxv-xminv)/numpoint;
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

    for (i=1;i<=numpoint;i++)
    {
          px1=xminv+(i-1)*dx;
          py1=f(px1);
          px1=x1+(px1-xmin)*sx;
          py1=y0-py1*sy;

          px2=xminv+i*dx;
          py2=f(px2);
          xcur=px2;ycur=py2;
          px2=x1+(px2-xmin)*sx;
          py2=y0-py2*sy;

          if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	}
    pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}//draw graph with function f and range in x of it

void CGraph::DrawFuncPolar(function f,double start, double end)//draw graph with function f and range in x of it
{
	double dx,sx,sy,px1,px2,py1,py2;
    int i;
    rectreal r;

	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

    sx=ScaleX();sy=ScaleY();
	dx=(end-start)/numpoint;
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

    for (i=1;i<=numpoint;i++)
    {
		double phi=start+(i-1)*dx;
		double rad=f(phi);
		px1=rad*cos(phi);
		py1=rad*sin(phi);
		px1=x1+(px1-xmin)*sx;
		py1=y0-py1*sy;

		phi=start+i*dx;
		rad=f(phi);
		px2=rad*cos(phi);
		py2=rad*sin(phi);
		xcur=px2;ycur=py2;
		px2=x1+(px2-xmin)*sx;
		py2=y0-py2*sy;

		if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	}
    pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::DrawPline(const CPline & pline)
{
	int i;
    rectreal r;
    double sx,sy,px1,py1,px2,py2;
    
	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

	sx=ScaleX();sy=ScaleY();
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

	for (i=1;i<pline.GetSize();i++)
	{
		CPoint2d p=pline[i-1];px1=p.x;py1=p.y;
		px1=x1+(px1-xmin)*sx;
		py1=y0-py1*sy;

		p=pline[i];	px2=p.x;py2=p.y;
		xcur=px2;ycur=py2;
		px2=x1+(px2-xmin)*sx;
		py2=y0-py2*sy;

		if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	}
    pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::DrawPline(double * x, double * y, const int & nump)
{
	if ((x==NULL)||(y==NULL)||(nump<=0)) return; 

	int i;
    rectreal r;
    double sx,sy,px1,py1,px2,py2;
    
	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

	sx=ScaleX();sy=ScaleY();
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

	for (i=1;i<nump;i++)
	{
		px1=x[i-1];py1=y[i-1];
		px1=x1+(px1-xmin)*sx;
		py1=y0-py1*sy;

		px2=x[i];py2=y[i];
		xcur=px2;ycur=py2;
		px2=x1+(px2-xmin)*sx;
		py2=y0-py2*sy;

		if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	}
    pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::DrawLine(double x1v,double y1v,double x2v,double y2v)
{
	rectreal r;
	double sx,sy;
	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);
	xcur=x2v;ycur=y2v;
	sx=ScaleX();sy=ScaleY();
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;
	x1v=x1+(x1v-xmin)*sx;
	y1v=y0-y1v*sy;
	x2v=x1+(x2v-xmin)*sx;
	y2v=y0-y2v*sy;
	if (ClipView(x1v,y1v,x2v,y2v,r))	line((int)(x1v),(int)(y1v),(int)(x2v),(int)(y2v));
	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::DrawLine(const CPoint2d & p1,const CPoint2d & p2)
{
	DrawLine(p1.x,p1.y,p2.x,p2.y);
}

void CGraph::MoveTo(double x,double y)
{
	double sx,sy;
     xcur=x;ycur=y;
     sx=ScaleX();sy=ScaleY();
     x=x1+(x-xmin)*sx;
     y=y0-y*sy;
     pdc->MoveTo((int)(x),(int)(y));
}
void CGraph::LineTo(double x,double y)
{
    rectreal r;
    double sx,sy,px1,py1,px2,py2;

	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen = pdc->SelectObject(&newpen);

	sx=ScaleX();sy=ScaleY();
	r.l=x1;r.t=y1;r.r=x2;r.b=y2;

	px1=xcur;py1=ycur;
	px1=x1+(px1-xmin)*sx;
	py1=y0-py1*sy;

	px2=x;py2=y;
	px2=x1+(px2-xmin)*sx;
	py2=y0-py2*sy;
	xcur=x;ycur=y;

	if (ClipView(px1,py1,px2,py2,r)) line((int)(px1),(int)(py1),(int)(px2),(int)(py2));
	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}
void CGraph::MoveTo(const CPoint2d & p)
{
	MoveTo(p.x,p.y);
}
void CGraph::LineTo(const CPoint2d & p)
{
	LineTo(p.x,p.y);
}

void CGraph::Circle(const CPoint2d & p,const double & rad)
{
	Ellipse(p.x,p.y,rad,rad);
}
void CGraph::Circle(const double & x,const double & y,const double & rad)
{
	Ellipse(x,y,rad,rad);
}

void CGraph::Ellipse(const CPoint2d & p,const double & radx,const double & rady)
{
	Ellipse(p.x,p.y,radx,rady);
}

void CGraph::Ellipse(const double & x,const double & y,const double & radx,const double & rady)
{
    double sx,sy,xe,ye;

	sx=ScaleX();sy=ScaleY();

	CPen newpen;newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen =pdc->SelectObject(&newpen);

	double phi=0,stepphi=2.0*PI/numpoint;
	xe=x+radx*cos(phi);ye=y+rady*sin(phi);
	this->MoveTo(xe,ye);
	for (int i=0;i<=numpoint;i++)
	{
		phi+=stepphi;
		xe=x+radx*cos(phi);ye=y+rady*sin(phi);
		this->LineTo(xe,ye);
	}
	this->MoveTo(x,y);

	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::CircleFill(const CPoint2d & p,const double & rad,const COLORREF & color)
{
	EllipseFill(p.x,p.y,rad,rad,color);
}
void CGraph::CircleFill(const double & x,const double & y,const double & rad,const COLORREF & color)
{
	EllipseFill(x,y,rad,rad,color);
}

void CGraph::EllipseFill(const CPoint2d & p,const double & radx,const double & rady,const COLORREF & color)
{
	EllipseFill(p.x,p.y,radx,rady,color);
}
void CGraph::EllipseFill(const double & x,const double & y,const double & radx,const double & rady,const COLORREF & color)
{
	CBrush brush;brush.CreateSolidBrush(color);
	CBrush *oldbrush;
	oldbrush=GetDC()->SelectObject(&brush);
	CPoint2d pct=Real2Screen(CPoint2d(x,y));
	CPoint2d prc=Real2Screen(CPoint2d(radx,rady))-Real2Screen(CPoint2d(0,0));
	GetDC()->Ellipse((int)(pct.x-prc.x),(int)(pct.y-prc.x),(int)(pct.x+prc.x),(int)(pct.y+prc.x));
	if (oldbrush) GetDC()->SelectObject(oldbrush);
	brush.DeleteObject();
}

void CGraph::CircleByDC(const CPoint2d & p,const double & rad)
{
	EllipseByDC(p.x,p.y,rad,rad);
}
void CGraph::CircleByDC(const double & x,const double & y,const double & rad)
{
	EllipseByDC(x,y,rad,rad);
}

void CGraph::EllipseByDC(const CPoint2d & p,const double & radx,const double & rady)
{
	EllipseByDC(p.x,p.y,radx,rady);
}
void CGraph::EllipseByDC(const double & x,const double & y,const double & radx,const double & rady)
{
	CPoint2d pt(x,y);
	CPoint pct=Real2Screen(pt);
	CPoint prc=Real2Screen(pt+CPoint2d(radx,rady))-pct;
	GetDC()->Ellipse(pct.x-prc.x,pct.y-prc.x,pct.x+prc.x,pct.y+prc.x);
}

void CGraph::DrawVector(const CPoint2d &p1, const CPoint2d &p2, const double & larraw,const double & anglearrow)
{
	CPoint2d pa1,pa2;
	pa1=pa2=Polar(p2,Rad2Deg(Angle(p2,p1)),larraw);
	pa1=RotatePoint(p2,pa1,anglearrow);
	pa2=RotatePoint(p2,pa2,-anglearrow);
	DrawLine(p1,p2);
	DrawLine(p2,pa1);
	DrawLine(pa1,pa2);
	DrawLine(pa2,p2);
}

void CGraph::DrawVector(const CPoint2d &p1, const double & value, const double & angle, const double & larraw,const double & anglearrow)
{
	CPoint2d p2,pa1,pa2;
	p2=Polar(p1,angle,value);
	pa1=pa2=Polar(p2,Rad2Deg(Angle(p2,p1)),larraw);
	pa1=RotatePoint(p2,pa1,anglearrow);
	pa2=RotatePoint(p2,pa2,-anglearrow);
	DrawLine(p1,p2);
	DrawLine(p2,pa1);
	DrawLine(pa1,pa2);
	DrawLine(pa2,p2);
}

void CGraph::Rectangle(const CPoint2d & p1,const CPoint2d & p2)
{
	Rectangle(p1.x,p1.y,p2.x,p2.y);
}

void CGraph::Rectangle(const double & x1v,const double & y1v,const double & x2v,const double & y2v)
{
    double sx,sy;

	sx=ScaleX();sy=ScaleY();

	CPen newpen;
	newpen.CreatePen(m_linegraphstyle, m_graphwidth, colorgraph);
	CPen * pOldPen =pdc->SelectObject(&newpen);

	MoveTo(x2v,y2v);
	LineTo(x2v,y1v);
	LineTo(x1v,y1v);
	LineTo(x1v,y2v);
	LineTo(x2v,y2v);

	pdc->SelectObject(pOldPen);
	newpen.DeleteObject();
}

void CGraph::DrawTextWithColor(const double & x,const double & y,const CString & str,const COLORREF & color,const UINT & just)
{
	double sx=ScaleX(),sy=ScaleY(),xt=x,yt=y;
	 xt=x1+(xt-xmin)*sx;
     yt=y0-yt*sy;

	COLORREF oldcolor=pdc->GetTextColor();
	pdc->SetTextColor(color);

	int oldmode=pdc->SetBkMode(TRANSPARENT);
	UINT olf=pdc->SetTextAlign(just);
	pdc->TextOut((int)xt,(int)yt,str);

	pdc->SetTextColor(oldcolor);
	pdc->SetBkMode(oldmode);

	pdc->SetTextAlign(olf);
}
void CGraph::DrawText(const double & x,const double & y,const CString & str,const UINT & just)
{
	DrawTextWithColor(x,y,str,this->colorgraph,just);
}

void CGraph::DrawTextWithColor(const CString & str,const COLORREF & color,const UINT & just)
{
	DrawTextWithColor(this->xcur,this->ycur,str,color,just);
}
void CGraph::DrawText(const CString & str,const UINT & just)
{
	DrawTextWithColor(this->xcur,this->ycur,str,this->colorgraph,just);
}

void CGraph::DrawTextWithColor(const CPoint2d & p,const CString & str,const COLORREF & color,const UINT & just)
{
	DrawTextWithColor(p.x,p.y,str,color,just);
}
void CGraph::DrawText(const CPoint2d & p,const CString & str,const UINT & just)
{
	DrawTextWithColor(p.x,p.y,str,this->colorgraph,just);
}

int  CGraph::XScreen()
{
	double x,y;
	x=xcur;
	y=ycur;
    x=x1+(x-xmin)*ScaleX();
    y=y0-y*ScaleY();
    return (int)x;
}
int  CGraph::YScreen()
{
	double x,y;
	x=xcur;
	y=ycur;
    x=x1+(x-xmin)*ScaleX();
    y=y0-y*ScaleY();
    return (int)y;
}

void CGraph::Real2Screen(double xr,double yr,int & xscr,int & yscr)
{
	xscr=(int)(x1+(xr-xmin)*ScaleX());
    yscr=(int)(y0-yr*ScaleY());
}
void CGraph::Screen2Real(int xscr,int yscr,double & xr,double & yr)
{
	xr=xscr;
	yr=yscr;
	xr=(xr-x1)/ScaleX()+xmin;
	yr=(y0-yr)/ScaleY();
}
CPoint2d CGraph::Real2Screen(const CPoint2d & p)
{
	int x,y;
	Real2Screen(p.x,p.y,x,y);
	return CPoint2d(x,y);
}
CPoint2d CGraph::Screen2Real(const CPoint2d & p)
{
	CPoint2d ptmp;
	Screen2Real((int)p.x,(int)p.y,ptmp.x,ptmp.y);
	return ptmp;
}

double  CGraph::GetStepgridHor()
{
	double step=stepgridHor;
	if (stepgridHor<=0) step=Cal_Step(xmin,xmax);
	return step;
}

double  CGraph::GetStepgridVer()
{
	double step=stepgridVer;
	if (stepgridVer<=0) step=Cal_Step(ymin,ymax);
	return step;
}

void CGraph::Erase()
{
	CRect r=this->GetRectControl();
	r.InflateRect(0,0,1,1);

	CBrush brush;
	brush.CreateSolidBrush(pdc->GetBkColor());
	CBrush *oldbrush;oldbrush=pdc->SelectObject(&brush);

	CPen * oldpen;oldpen=(CPen *)pdc->SelectStockObject(NULL_PEN);

	pdc->Rectangle(r);

	if (oldbrush) pdc->SelectObject(oldbrush);
	if (oldpen) pdc->SelectObject(oldpen);
	brush.DeleteObject();
}

int CGraph::AddFunc(function f)
{
	if (numpoint==0) return -1;
	CObjectLine pl;
	double dx,px,py;
	int i;

	dx=(xmax-xmin)/numpoint;

	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	for (i=0;i<=numpoint;i++)
	{
	  px=xmin+(i-1)*dx;
	  py=f(px);
	  pl.pline.Add(CPoint2d(px,py));
	}
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddFunc(function f,double xminv, double xmaxv)
{
	if (numpoint==0) return -1;

	CObjectLine pl;
	double dx,px,py;
	int i;

	dx=(xmaxv-xminv)/numpoint;

	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	for (i=0;i<=numpoint;i++)
	{
	  px=xminv+(i-1)*dx;
	  py=f(px);
	  pl.pline.Add(CPoint2d(px,py));
	}
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddFuncPolar(function f,double start, double end)//draw graph with function f and range in x of it
{
	if (numpoint==0) return -1;

	CObjectLine pl;
	double dx,px,py;
    int i;

	dx=(end-start)/numpoint;

	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
    for (i=0;i<=numpoint;i++)
    {
		double phi=start+i*dx;
		double rad=f(phi);
		px=rad*cos(phi);
		py=rad*sin(phi);
		pl.pline.Add(CPoint2d(px,py));
	}
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddPline(const CPline & pline)
{
	CObjectLine pl;
	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	for (int k=0;k<pline.GetSize();k++)
		pl.pline.Add(pline[k]);
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddPline(double * x, double * y, const int & nump)
{
	CObjectLine pl;
	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	for (int k=0;k<nump;k++)
		pl.pline.Add(CPoint2d(x[k],y[k]));
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddLine(const double & x1v,const double & y1v,const double & x2v,const double & y2v)
{
	CObjectLine pl;
	pl.styleline=0;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	pl.pline.Add(CPoint2d(x1v,y1v));
	pl.pline.Add(CPoint2d(x2v,y2v));
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddLine(const CPoint2d & p1,const CPoint2d & p2)
{
	return AddLine(p1.x,p1.y,p2.x,p2.y);
}
int CGraph::AddCircle(const CPoint2d & p,const double & rad)
{
	return AddEllipse(p.x,p.y,rad,rad);
}
int CGraph::AddCircle(const double & x,const double & y,const double & rad)
{
	return AddEllipse(x,y,rad,rad);
}
int CGraph::AddEllipse(const CPoint2d & p,const double & radx,const double & rady)
{
	return AddEllipse(p.x,p.y,radx,rady);
}
int CGraph::AddEllipse(const double & x,const double & y,const double & radx,const double & rady)
{
	CObjectLine pl;
	pl.styleline=1;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	pl.pline.Add(CPoint2d(x,y));
	pl.pline.Add(CPoint2d(radx,rady));
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddRectangle(const CPoint2d & p1,const CPoint2d & p2)
{
	return AddRectangle(p1.x,p1.y,p2.x,p2.y);
}
int CGraph::AddRectangle(const double & x1v,const double & y1v,const double & x2v,const double & y2v)
{
	CObjectLine pl;
	pl.styleline=2;
	pl.color=this->colorgraph;
	pl.style=this->m_linegraphstyle;
	pl.width=this->m_graphwidth;
	pl.pline.Add(CPoint2d(x1v,y1v));
	pl.pline.Add(CPoint2d(x2v,y2v));
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}

int CGraph::AddTextWithColor(const double & x,const double & y,const CString & str,const COLORREF & color,const UINT & just)
{
	CObjectLine pl;
	pl.styleline=3;
	pl.color=color;
	pl.style=just;
	pl.string=str;
	pl.pline.Add(CPoint2d(x,y));
	this->m_objectpline.Add(pl);
	return this->m_objectpline.GetSize()-1;
}
int CGraph::AddText(const double & x,const double & y,const CString & str,const UINT & just)
{
	return AddTextWithColor(x,y,str,this->colorgraph,just);
}
int CGraph::AddTextWithColor(const CPoint2d & p,const CString & str,const COLORREF & color,const UINT & just)
{
	return AddTextWithColor(p.x,p.y,str,this->colorgraph,just);
}
int CGraph::AddText(const CPoint2d & p,const CString & str,const UINT & just)
{
	return AddTextWithColor(p.x,p.y,str,this->colorgraph,just);
}

void CGraph::RemoveObject(const int & id)
{
	CObjectPline temp;
	for (int i=0;i<this->m_objectpline.GetSize();i++)
		if (i!=id)	temp.Add(this->m_objectpline[i]);
	m_objectpline.RemoveAll();
	for (int i=0;i<temp.GetSize();i++)
		m_objectpline.Add(temp[i]);
}
void CGraph::RemoveAllObject()
{
	this->m_objectpline.RemoveAll();
}

CObjectPline *CGraph::GetObjectPline()
{
	return &this->m_objectpline;
}
CObjectLine  *CGraph::GetObject(const int & id)
{
	return &this->m_objectpline[id];
}
COLORREF  CGraph::GetColorObject(const int & id)
{
	return this->m_objectpline[id].color;
}
CPline * CGraph::GetDataObject(const int & id)
{
	return &this->m_objectpline[id].pline;
}

CObjectLine CGraph::SetObject(const int & id,const CObjectLine & obj)
{
	CObjectLine oldobject =this->m_objectpline[id];
	this->m_objectpline[id].color=obj.color;
	this->m_objectpline[id].pline=obj.pline;
	this->m_objectpline[id].string=obj.string;
	this->m_objectpline[id].style=obj.style;
	this->m_objectpline[id].styleline=obj.styleline;
	this->m_objectpline[id].width=obj.width;
	return oldobject;
}
COLORREF  CGraph::SetColorObject(const int & id,const COLORREF & color)
{
	COLORREF oldcolor =this->m_objectpline[id].color;
	this->m_objectpline[id].color=color;
	return oldcolor;
}
CPline CGraph::SetDataObject(const int & id,const CPline & pl)
{
	CPline oldpline =this->m_objectpline[id].pline;
	this->m_objectpline[id].pline=pl;
	return oldpline;
}
CPline CGraph::SetDataObject(const int & id,double * x, double * y, const int & nump)
{
	CPline oldpline =this->m_objectpline[id].pline;
	this->m_objectpline[id].pline.RemoveAll();
	for (int i=0;i<nump;i++)
		this->m_objectpline[id].pline.Add(CPoint2d(x[i],y[i]));
	return oldpline;
}

void	CGraph::DrawObject(const int & id)
{
	COLORREF oldcolor=this->colorgraph;
	UINT oldstyle=this->m_linegraphstyle;
	int oldwidth=this->m_graphwidth;

	this->colorgraph=this->m_objectpline[id].color;
	this->m_linegraphstyle=this->m_objectpline[id].style;
	this->m_graphwidth=this->m_objectpline[id].width;

	switch (this->m_objectpline[id].styleline)
	{
		case 0 ://Draw pline
			this->DrawPline(this->m_objectpline[id].pline);
			break;
		case 1 ://Draw Ellipse
			this->Ellipse(this->m_objectpline[id].pline[0],this->m_objectpline[id].pline[1].x,this->m_objectpline[id].pline[1].y);
			break;
		case 2 ://Draw Rectangle
			this->Rectangle(this->m_objectpline[id].pline[0],this->m_objectpline[id].pline[1]);
			break;
		case 3 ://Draw Text
			/*
			this->DrawTextWithColor(this->m_objectpline[id].pline[0],
				this->m_objectpline[id].string,
				this->m_objectpline[id].color,this->m_objectpline[id].style);
				*/
			this->DrawText(this->m_objectpline[id].pline[0],
				this->m_objectpline[id].string,this->m_objectpline[id].style);
			break;
	};

	this->colorgraph=oldcolor;
	this->m_linegraphstyle=oldstyle;
	this->m_graphwidth=oldwidth;
}
void	CGraph::DrawAllObject()
{
	for (int i=0;i<this->m_objectpline.GetSize();i++)
		DrawObject(i);
}

void	CGraph::MoveObjectTo(const int & id,const double & x,const double & y)
{
	double x0=this->m_objectpline[id].pline[0].x,y0=this->m_objectpline[id].pline[0].y;
	for (int i=0;i<this->m_objectpline[id].pline.GetSize();i++)
	{
		this->m_objectpline[id].pline[i].x=x+(this->m_objectpline[id].pline[i].x-x0);
		this->m_objectpline[id].pline[i].y=y+(this->m_objectpline[id].pline[i].y-y0);;
	}
}
void	CGraph::MoveObjectTrans(const int & id,const double & x,const double & y)
{
	for (int i=0;i<this->m_objectpline[id].pline.GetSize();i++)
	{
		this->m_objectpline[id].pline[i].x+=x;
		this->m_objectpline[id].pline[i].y+=y;
	}
}
