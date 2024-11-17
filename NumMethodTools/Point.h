// point.h: interface for the point class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT_H__FBF0837F_6758_4DF7_8589_E82CAFAB5A01__INCLUDED_)
#define AFX_POINT_H__FBF0837F_6758_4DF7_8589_E82CAFAB5A01__INCLUDED_

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
#include "vector.h"

class vectorm;

class NUMMETHODTOOLS_EXT_CLASS point /*: protected vectorm*/
{
protected:
	int size;
	double *data;
public:
//1
   point();
   point(int n);
   //khoi tao voi he toa do biet truoc
//2
   point(const point &p);//constructor copy
//4
   ~point();
   double operator()(const int & ch)const;
   //lay phan tu cua point theo cac so nguyen

   double  & operator[](const int & i);

   double  const & operator[](const int & i)const;
//6
//gan point
   point& operator=(const point& p);
//7
   friend point NUMMETHODTOOLS_EXT_CLASS operator+(const point & p1,const point & p2);
   //point1+point2
//8
   friend vectorm NUMMETHODTOOLS_EXT_CLASS operator-(const point & p1,const point & p2);
   //point1-point2
//9
   friend ostream& operator<<(ostream & co,const point & p);
   //in mot point ra man hinh
//10
   friend istream& operator>>(istream & ci,const point & p);
   //Nhap du lieu cho point
//11
   friend point NUMMETHODTOOLS_EXT_CLASS operator+(const point & p,const vectorm & vt);
   //point=p+vt2
//12
   friend point NUMMETHODTOOLS_EXT_CLASS operator-(const point & p,const vectorm & vt);
   //point=p-vt
//13
   friend point NUMMETHODTOOLS_EXT_CLASS operator*(const point & p,const double & d);
   //=p*d
//14
   friend point NUMMETHODTOOLS_EXT_CLASS operator/(const point & p,const double & d);
   //=p/d
//15
   friend point NUMMETHODTOOLS_EXT_CLASS operator*(const double & d,const point & p);
   //=d/p
//19
   friend void NUMMETHODTOOLS_EXT_CLASS print(const point & p);
   friend void NUMMETHODTOOLS_EXT_CLASS print(const point & p,const int & d1,const int & d2);
//20
   friend int NUMMETHODTOOLS_EXT_CLASS typepoint(const point & p);
//21
   void setdata(const int & i,const double& d);
//25
   friend int NUMMETHODTOOLS_EXT_CLASS operator==(const point & p1,const point & p2);
   // so sanh 2 diem
//26
//   friend vector operator - (const point & p,const vectorm & vt);
};

#endif // !defined(AFX_POINT_H__FBF0837F_6758_4DF7_8589_E82CAFAB5A01__INCLUDED_)
