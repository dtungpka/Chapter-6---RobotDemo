// vectorm.h: interface for the vectorm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_vectorm_H__904F9BB5_F6DC_4721_A53A_F1E4CCBEE38E__INCLUDED_)
#define AFX_vectorm_H__904F9BB5_F6DC_4721_A53A_F1E4CCBEE38E__INCLUDED_

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

class point;
class NUMMETHODTOOLS_EXT_CLASS vectorm : public matrix
{
protected: int size;//double *data;
public:
//1
   vectorm();
//2
   vectorm(const vectorm &v);
   vectorm(const double &x,const double &y);
   vectorm(const double &x,const double &y,const double &z);
//3
   vectorm(const int &m);
   void SetSize(const int &m);
//4
   ~vectorm();
//5
	friend double NUMMETHODTOOLS_EXT_CLASS module(const vectorm & a); /*Tinh do dai vectorm*/
	friend double NUMMETHODTOOLS_EXT_CLASS length(const vectorm & a); /*Tinh do dai vectorm*/
//6
	friend double NUMMETHODTOOLS_EXT_CLASS StandardVal(const vectorm & a);
	/*Tinh chuan tuyet doi*/
//7
	friend double NUMMETHODTOOLS_EXT_CLASS StandardEuclide(const vectorm & a);
    /*Tinh chuan Euclide*/
//8
    friend double NUMMETHODTOOLS_EXT_CLASS StandardMax(const vectorm & a);
    /*Tinh chuan cuc dai*/
//9
   friend vectorm NUMMETHODTOOLS_EXT_CLASS standard(const vectorm & a);
   //chuan hoa vectorm theo thanh phan co tri tuyet doi lon nhat
//10
   friend vectorm NUMMETHODTOOLS_EXT_CLASS normalize(const vectorm & a);   //chuan hoa theo Euclide//
   //tra ve vectorm co do dai = 1 don vi
//11
   vectorm(const matrix & ma1);
   //khoi tao vectorm tu mot matrix dac biet : chi co 1 hang hoac 1 cot
//12
   double const& operator()(const int &i)const;
   double & operator()(const int &i);
   //lay phan tu cua vectorm
   double& operator[](const int &i);
   double const & operator[](const int &i)const;
//13
   friend double NUMMETHODTOOLS_EXT_CLASS dot(const vectorm& matrix1,const vectorm & matrix2);
   friend double NUMMETHODTOOLS_EXT_CLASS dotT(const vectorm& matrix1,const vectorm & matrix2);
   //dot product or scalar product
   //lay tich vo huong cua 2 vectorm (!vectorm1)*vectorm2
//14
   friend vectorm NUMMETHODTOOLS_EXT_CLASS cross(const vectorm& vectorm1,const vectorm & vectorm2);
   //cross product
   //lay tich co huong cua 2 vectorm (!vectorm1)*vectorm2
//-----------
//15
   friend double NUMMETHODTOOLS_EXT_CLASS angle(const vectorm& vt1,const vectorm & vt2);
   //cho goc giua 2 vectorm do bang radian
//16
//   vectorm(const point & p1,const point & p2);
   //khoi tao vectorm tu 2 diem
//17
   void SetData(const int& i,const double& d);
//19
   friend int NUMMETHODTOOLS_EXT_CLASS GetSize(const vectorm & vt);
//28
   const vectorm & operator=(const vectorm & v);
};
//==============================================================================
vectorm NUMMETHODTOOLS_EXT_CLASS minuspoint(const point& p1,const point& p2);
/*
// thuc hien tru 2 diem de co vectorm
   {
   vectorm v(typepoint(p1));
   for (int i=0;i<typepoint(p1);i++)
	   v.setdata(i,p2(i)-p1(i));
   return v;
   }
*/
vectorm NUMMETHODTOOLS_EXT_CLASS project(const vectorm & v1,const vectorm & v2);
/*
{
if (getrow(v1)!=getrow(v2))
	{
	printf("Error on size of vectorm !");
	exit(1);
	}
vectorm v(getrow(v1));
  v=(dot(v1,v2)/pow(length(v2),2))*v2;
return v;
}
*/
double NUMMETHODTOOLS_EXT_CLASS area(const point * p,const int & n);
/*
{
vectorm *vt;
vt = new vectorm [n-1];
for (int i=1;i<n;i++)
  vt[i-1] = minuspoint(p[0],p[i]);
double s=0;
i=0;
vectorm un=cross(vt[0],vt[1]);
un=normalize(un);
for (i=0;i<n-2;i++)
  s+=(dot(un,cross(vt[i],vt[i+1])))/2;
return fabs(s);
}
*/


#endif // !defined(AFX_vectorm_H__904F9BB5_F6DC_4721_A53A_F1E4CCBEE38E__INCLUDED_)
