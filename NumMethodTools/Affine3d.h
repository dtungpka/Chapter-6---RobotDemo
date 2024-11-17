// Affine3d.h: interface for the Affine3d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFFINE3D_H__0B48C31E_6EF1_4229_9E00_064B8779F51A__INCLUDED_)
#define AFX_AFFINE3D_H__0B48C31E_6EF1_4229_9E00_064B8779F51A__INCLUDED_

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
#include "point3d.h"
#include "point.h"
#include "line.h"
#include "vector.h"

class vectorm;

class NUMMETHODTOOLS_EXT_CLASS transform3d : public matrix
{
public:
//1
   transform3d();
//2
   transform3d(const transform3d &mt);//constructor copy
//3
   transform3d(const matrix &mt);//constructor copy
//4
   void translation(const vectorm &vt);
   void translation(const double &dx,const double &dy,const double &dz);
   point3d translation(const point3d & p);
   friend point3d NUMMETHODTOOLS_EXT_CLASS translation(const point3d & p,const vectorm & vt);
   //tinh tien mot diem theo mot vector
   friend point3d NUMMETHODTOOLS_EXT_CLASS translation(const point3d & p,const double & dx,const double & dy,const double & dz);
   //tinh tien mot diem theo dx va dy va dz
//5
//a
   void rotationx(const double & goc);
//b
   void rotationy(const double & goc);
//c
   void rotationz(const double & goc);
//d
   void rotation(const point3d & p1,const point3d & p2,const double & goc);
//e
   void rotation(const line & l,const double & goc);
//f
   point3d rotation(const point3d & p);
//g
   friend point3d NUMMETHODTOOLS_EXT_CLASS rotationx(const point3d & p,const double & goc);
//h
   friend point3d NUMMETHODTOOLS_EXT_CLASS rotationy(const point3d & p,const double & goc);
//i
   friend point3d NUMMETHODTOOLS_EXT_CLASS rotationz(const point3d & p,const double & goc);
//j
   friend point3d NUMMETHODTOOLS_EXT_CLASS rotation(const point3d & p,const point3d & p1,const point3d & p2,const double & goc);
//k
   friend point3d NUMMETHODTOOLS_EXT_CLASS rotation(const point3d & p,const line & l,const double & goc);
//6
   void scale(const double & dx,const double & dy,const double & dz);
   point3d scale(const point3d & p);
   friend point3d NUMMETHODTOOLS_EXT_CLASS scale(const point3d & p,const double & dx,const double & dy,const double & dz);

//7
   void shearing(const double &dx,const double &dy,const double &dz);
   void shearingxy(const double &dx,const double &dy);
   void shearingyz(const double &dy,const double &dz);
   void shearingzx(const double &dz,const double &dx);
   point3d shearing(const point3d & p);
   friend point3d NUMMETHODTOOLS_EXT_CLASS shearing(const point3d & p,const double & dx,const double & dy,const double & dz);
   friend point3d NUMMETHODTOOLS_EXT_CLASS shearingxy(const point3d & p,const double & dx,const double & dy);
   friend point3d NUMMETHODTOOLS_EXT_CLASS shearingyz(const point3d & p,const double & dy,const double & dz);
   friend point3d NUMMETHODTOOLS_EXT_CLASS shearingzx(const point3d & p,const double & dz,const double & dx);
//8
   void mirrorxy();
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirrorxy(const point3d & p);
//9
   void mirroryz();
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirroryz(const point3d & p);
//10
   void mirrorzx();
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirrorzx(const point3d & p);

//11
   void mirror(const point3d & p1,const point3d & p2,const point3d & p3);
   void mirror(const line & l1,const line & l2);
   void mirror(const point3d & p1,const line & l);
   void mirror(const point3d & p1,const vectorm & vt);
   point3d mirror(const point3d & p);
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirror(const point3d & p,const point3d & p1,const point3d & p2,const point3d & p3);
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirror(const point3d & p,const line & l1,const line & l2);
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirror(const point3d & p,const point3d & p1,const line & l);
   friend point3d NUMMETHODTOOLS_EXT_CLASS mirror(const point3d & p,const point3d & p1,const vectorm & vt);

   ~transform3d();
};

#endif // !defined(AFX_AFFINE3D_H__0B48C31E_6EF1_4229_9E00_064B8779F51A__INCLUDED_)
