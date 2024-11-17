// point2d.h: interface for the point2d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT2D_H__F7FDC3B2_9F91_4616_93C6_FEEC664E668B__INCLUDED_)
#define AFX_POINT2D_H__F7FDC3B2_9F91_4616_93C6_FEEC664E668B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//using namespace std;
//#include <iostream>
#include "point.h"

class NUMMETHODTOOLS_EXT_CLASS point2d : public point
{
public:
	void SetPoint(const double & x,const double & y);
//1
   point2d();
//2
   point2d(const point2d &p);//constructor copy
//3
   point2d(const point &p);//constructor copy
//4
   point2d(double x,double y);
   //khoi tao point trong khong gian 2 chieu
//5
   ~point2d();
//6
   double operator()(const char & ch)const;
   //lay phan tu cua point theo cac toa do x,y,z

//7
   void x(const double & dx);
   //x=dx
//8
   void y(const double & dy);
   //y=dy
//9
   double x()const;
//10
   double y()const;
};

#endif // !defined(AFX_POINT2D_H__F7FDC3B2_9F91_4616_93C6_FEEC664E668B__INCLUDED_)
