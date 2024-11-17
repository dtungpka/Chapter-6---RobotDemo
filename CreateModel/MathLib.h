// MathLib.h: interface for the MathLib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_)
#define AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef MATHLIB_EXT_CLASS
	#define MATHLIB_EXT_CLASS CREATEMODEL_EXT_CLASS
#endif MATHLIB_EXT_CLASS

#ifndef maxreal
#define maxreal		1.6e25
#endif maxreal

#ifndef minreal
#define minreal		-1.6e25
#endif minreal

#ifndef localzero
#define localzero	1e-20
#endif localzero

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif PI

double MATHLIB_EXT_CLASS Rad2Deg(const double & anglerad);
double MATHLIB_EXT_CLASS Deg2Rad(const double & angledeg);
double MATHLIB_EXT_CLASS NormalAngleRad(const double & angrad);
double MATHLIB_EXT_CLASS NormalAngleDeg(const double & angdeg);

double MATHLIB_EXT_CLASS acosmath(const double & rcos);
double MATHLIB_EXT_CLASS asinmath(const double & rsin);
double MATHLIB_EXT_CLASS tanmath(const double & angle);
double MATHLIB_EXT_CLASS cotanmath(const double & angle);

double MATHLIB_EXT_CLASS atanXY(const double &  x, const double & y);
double MATHLIB_EXT_CLASS tan2deg(const double & X,const double & Y);
double MATHLIB_EXT_CLASS tan2rad(const double & X,const double & Y);
double MATHLIB_EXT_CLASS sin2deg (const double & Y,const double & R);
double MATHLIB_EXT_CLASS sin2rad (const double & Y,const double & R);
double MATHLIB_EXT_CLASS cos2deg (const double & X,const double & R);
double MATHLIB_EXT_CLASS cos2rad (const double & X,const double & R);
double MATHLIB_EXT_CLASS Angle(const double & x,const double & y);
double MATHLIB_EXT_CLASS AngleLine(const double & x1,const double & y1,const double & x2,const double & y2);
double MATHLIB_EXT_CLASS Log (const double & X);
double MATHLIB_EXT_CLASS HypSin( const double & x);
double MATHLIB_EXT_CLASS HypCos( const double & x);
int MATHLIB_EXT_CLASS sign(const double & x);

#endif // !defined(AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_)
