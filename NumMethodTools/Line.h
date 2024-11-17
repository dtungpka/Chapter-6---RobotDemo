// line.h: interface for the line class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__0AED2BF8_D44B_46F6_9664_77A12E66C585__INCLUDED_)
#define AFX_LINE_H__0AED2BF8_D44B_46F6_9664_77A12E66C585__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//using namespace std;
//#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include "matrix.h"
#include "point.h"
#include "vector.h"
#include <math.h>

//===========================================================================
//===========================================================================
//CLASS Line
//===========================================================================
//===========================================================================
class NUMMETHODTOOLS_EXT_CLASS line
{
protected:
   point point1,point2;
//===========================================================================
public:
//1
   line();
//2
   line(const int & n);//khoi tao line voi he toa do biet truoc
//3
   line(const point & p1,const point & p2);
   //khoi tao line tu 2 point
   line(double l,double b,double r,double t);
//4
   line(const point & p,const vectorm & vt);
   //khoi tao point tu 1 point va 1 vector
//5
   line(const line & l); //constructor copy
//===========================================================================
//6
   friend void NUMMETHODTOOLS_EXT_CLASS print(const line & l);
   //in toa do line ra man hinh gom hai toa do
   //Gom : Toa do diem dau va diem cuoi cua line
//7
   friend ostream& operator<<(ostream & co,const line & l);
   //in toa do line ra man hinh gom hai toa do
   //Gom : Toa do diem dau va diem cuoi cua line
//8
   friend istream& operator>>(istream & ci,line & l);
   //Nhap du lieu cho line gom toa do diem dau va diem cuoi
//9
//gan 2 duong thang
   line& operator=(const line & l);
//===========================================================================
   //phep lay diem cua line
//10
   friend point NUMMETHODTOOLS_EXT_CLASS getlpoint1(const line & l);//=lay diem thu nhat cua l
//11
   friend point NUMMETHODTOOLS_EXT_CLASS getlpoint2(const line & l);//=lay diem thu hai cua l
//12
   void setlpoint1(const point & p);//=dat lai diem thu nhat cua line
//13
   void setlpoint2(const point & p);//=dat lai diem thu hai cua line
//14
   friend point NUMMETHODTOOLS_EXT_CLASS pointline(const line & l,const double & t);
      //lay mot diem thuoc line theo tham so
//15
   friend double NUMMETHODTOOLS_EXT_CLASS angleline(const line& l1,const line& l2);
   //cho goc giua 2 doan thang l1 va l2 do bang radian
//16
   friend int NUMMETHODTOOLS_EXT_CLASS checkintersect(const line& l1,const line& l2);
   //kiem tra vi tri tuong doi cua 2 doan thang
   //int = -1 neu l1 va l2 khong cung loai he toa do
   //       0 neu l1 va l2 khong cat nhau
   //       1 neu l1 va l2 cat nhau trong
   //       2 neu l1 va l2 cat nhau ngoai
   //       3 neu l1 va l2 trung nhau trong
   //       4 neu l1 va l2 trung nhau ngoai

//17
   friend point NUMMETHODTOOLS_EXT_CLASS intersect(const line& l1,const line& l2);
   //cho giao diem cua l1 va l2
//18
   friend vectorm NUMMETHODTOOLS_EXT_CLASS ltov(const line& l);
   //Chuyen mot doan thang thanh mot vector
//19
   point & operator[](const int & i);
   point const & operator[](const int & i) const;
//20
   friend double NUMMETHODTOOLS_EXT_CLASS length(const line & l);
   friend double NUMMETHODTOOLS_EXT_CLASS length(const point & p1,const point & p2);
//21
   friend double NUMMETHODTOOLS_EXT_CLASS typeline(const line & l);
};
//---------------------------------------------------------------------------
//***************************************************************************

//===========================================================================

struct rect
{
double l,t,r,b;
};
//============================================================================
//============================================================================
void NUMMETHODTOOLS_EXT_CLASS setrect(double lf,double tp,double rh,double bm,rect& w);
struct half_space_code
{
double l,t,r,b;
};

void NUMMETHODTOOLS_EXT_CLASS encode(const point & p,half_space_code & c,const rect& w);
void NUMMETHODTOOLS_EXT_CLASS clip(point& p1,point& p2,int & vis,const rect&w);
//===========================================================================

#endif // !defined(AFX_LINE_H__0AED2BF8_D44B_46F6_9664_77A12E66C585__INCLUDED_)
