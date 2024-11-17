// point3d.h: interface for the point3d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT3D_H__C2C82FE8_37C7_4669_A407_4CDE389B0FFA__INCLUDED_)
#define AFX_POINT3D_H__C2C82FE8_37C7_4669_A407_4CDE389B0FFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//using namespace std;
//#include <iostream>
#include <process.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "matrix.h"
#include "point.h"
#include "point2d.h"

class NUMMETHODTOOLS_EXT_CLASS point3d : public point
{
public:
	void SetPoint(const double & x,const double & y,const double & z);
//1
   point3d();
//2
   point3d(const point3d &p);//constructor copy
//3
   point3d(const point &p);//constructor copy
//4
   point3d(const double &  x,const double &  y,const double &  z);
   //khoi tao point trong khong gian 3 chieu
//5
   ~point3d();
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
   void z(const double & dz);
   //z=dz
//10
   double x()const;
//11
   double y()const;
//12
   double z()const;
   //z=dz
//13
   point3d(const point2d & p);
};

#endif // !defined(AFX_POINT3D_H__C2C82FE8_37C7_4669_A407_4CDE389B0FFA__INCLUDED_)
