// Affine2d.h: interface for the Affine2d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFFINE2D_H__17FAA23E_A5F0_439D_AA97_0207E4F37295__INCLUDED_)
#define AFX_AFFINE2D_H__17FAA23E_A5F0_439D_AA97_0207E4F37295__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <process.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "matrix.h"
#include "point.h"
#include "vector.h"
#include "point2d.h"
#include "line.h"

class NUMMETHODTOOLS_EXT_CLASS transform2d : public matrix
{
public:
//1
   transform2d();
//2
   transform2d(const transform2d &mt);//constructor copy
//3
   transform2d(const matrix &mt);//constructor copy
//4
   void translation(const vectorm &vt);
   void translation(const double &dx,const double &dy);
   point2d translation(const point2d & p);
   friend point2d NUMMETHODTOOLS_EXT_CLASS translation(const point2d & p,const vectorm & vt);
   //tinh tien mot diem theo mot vector
   friend point2d NUMMETHODTOOLS_EXT_CLASS translation(const point2d & p,const double & dx,const double & dy);
   //tinh tien mot diem theo dx va dy
//5
   void rotation(const double & goc);
   void rotation(const point2d & p,const double & goc);
   point2d rotation(const point2d & p);
   friend point2d NUMMETHODTOOLS_EXT_CLASS rotation(const point2d & p,const double & goc);
   friend point2d NUMMETHODTOOLS_EXT_CLASS rotation(const point2d & p1,const point2d & p2,const double & goc);
//6
   void scale(const double & dx,const double & dy);
   point2d scale(const point2d & p);
   friend point2d NUMMETHODTOOLS_EXT_CLASS scale(const point2d & p,const double & dx,const double & dy);
//7
   void shearing(const double &dx,const double &dy);
   point2d shearing(const point2d & p);
   friend point2d NUMMETHODTOOLS_EXT_CLASS shearing(const point2d & p,const double & dx,const double & dy);
//8
   void mirrorx();
   friend point2d NUMMETHODTOOLS_EXT_CLASS mirrorx(const point2d & p);
//9
   void mirrory();
   friend point2d NUMMETHODTOOLS_EXT_CLASS mirrory(const point2d & p);
//10
   void mirror(const point2d & p1,const point2d & p2);
   void mirror(const line & l);
   point2d mirror(const point2d & p);
   friend point2d NUMMETHODTOOLS_EXT_CLASS mirror(const point2d & p,const point2d & p1,const point2d & p2);
   friend point2d NUMMETHODTOOLS_EXT_CLASS mirror(const point2d & p,const line & l);

 ~transform2d();
};

#endif // !defined(AFX_AFFINE2D_H__17FAA23E_A5F0_439D_AA97_0207E4F37295__INCLUDED_)
