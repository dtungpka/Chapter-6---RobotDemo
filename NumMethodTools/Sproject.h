// sproject.h: interface for the sproject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPROJECT_H__A7598978_17FE_430B_9DC2_96C28DD9A2B3__INCLUDED_)
#define AFX_SPROJECT_H__A7598978_17FE_430B_9DC2_96C28DD9A2B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <graphics.h>
#include "point3d.h"

//Bo 3 dong sau neu su dung trong mode : console
//*
#ifndef _USE_WINDOW_
	#define _USE_WINDOW_
#endif _USE_WINDOW_
//*/
#ifdef _USE_WINDOW_
	#include <afxwin.h>
#endif _USE_WINDOW_

#ifndef PI
	#define PI 3.141592654
#endif

class NUMMETHODTOOLS_EXT_CLASS sproject
{
#ifdef _USE_WINDOW_
public:
	CPen* setcolor(const int &style,const int &width,const DWORD & cl);
	void	SetDC(CDC * pDC);
private:
	CDC * m_pDC;
#else _USE_WINDOW_
	typedef	unsigned int DWORD;
	void setcolor(const int & cl);
#endif _USE_WINDOW_

private:
	void moveto(const int & c,const int & h);
	void lineto(const int & c,const int & h);
	void outtextxy(const int & c,const int & h,char * st);

public:
  double rh0,theta,phi,de,kx,ky;
  int c0,h0;
//  int mode;//mode = 0 :chieu song song
		   //mode = 1 :chieu phoi canh
public:
  sproject();
  sproject(//const int & mode,
		const double & rh01,
	    const double & theta1,
	    const double & phi1,
	    const double & de1,
		const double & kx1,
		const double & ky1,
		const int & c01,const int & h01);
  sproject(const point3d & viewpoint,
		const double & kx1,
		const double & ky1,
		const int & c01,const int & h01	);
protected:
  virtual void pro(const double & x,const double & y,const double & z,double & xpro,double & ypro);
public:
  virtual void smoveto(const double & x,const double & y,const double & z);
  virtual void smoveto(const point3d & p);
  virtual void slineto(const double & x,const double & y,const double & z);
  virtual void slineto(const point3d & p);
  virtual void sline(const double & x1,const double & y1,const double & z1,
	const double & x2,const double & y2,const double & z2);
  virtual void sline(const point3d & p1,const point3d & p2);
  virtual void swrite(const double & x,const double & y,const double & z,char * st);
  virtual void swrite(const point3d & p,char * st);
  virtual void sdirection(const double & d,const DWORD & c1,const DWORD & c2);
  sproject & operator=(const sproject & prj);
  virtual void set_rh0(const double & x);
  virtual void set_theta(const double & x);
  virtual void set_phi(const double & x);
  virtual void set_de(const double & x);
  virtual void set_kx(const double & x);
  virtual void set_ky(const double & x);
  virtual void set_c0(const double & x);
  virtual void set_h0(const double & x);
};

class NUMMETHODTOOLS_EXT_CLASS sprojectp:public sproject  //space project para
{
 public:
  sprojectp();
  sprojectp(const double & rh01,
		const double & theta1,
		const double & phi1,
		const double & de1,
		const double & kx1,
		const double & ky1,
		const int & c01,const int & h01);
 protected:
  virtual void pro(const double & x,const double & y,const double & z,double & xpro,double & ypro);
};

#endif // !defined(AFX_SPROJECT_H__A7598978_17FE_430B_9DC2_96C28DD9A2B3__INCLUDED_)
