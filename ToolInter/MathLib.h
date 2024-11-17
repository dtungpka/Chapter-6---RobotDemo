// MathLib.h: interface for the MathLib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_)
#define AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef PPSTOOLS_EXT_CLASS
	#define PPSTOOLS_EXT_CLASS TOOLINTER_EXT_CLASS
#endif PPSTOOLS_EXT_CLASS

#ifndef maxreal
#define maxreal		1.6e35
#endif maxreal

#ifndef minreal
#define minreal		-1.6e35
#endif minreal

#ifndef localzero
#define localzero	1e-30
#endif localzero

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif PI

double PPSTOOLS_EXT_CLASS Rad2Deg(const double & anglerad);
double PPSTOOLS_EXT_CLASS Deg2Rad(const double & angledeg);
double PPSTOOLS_EXT_CLASS NormalAngleRad(const double & angrad);
double PPSTOOLS_EXT_CLASS NormalAngleDeg(const double & angdeg);
double PPSTOOLS_EXT_CLASS _acos(const double & rcos);
double PPSTOOLS_EXT_CLASS _asin(const double & rsin);
double PPSTOOLS_EXT_CLASS tan(const double & angle);
double PPSTOOLS_EXT_CLASS cotan(const double & angle);
double PPSTOOLS_EXT_CLASS atanXY(const double &  x, const double & y);
double PPSTOOLS_EXT_CLASS tan2deg(const double & X,const double & Y);
double PPSTOOLS_EXT_CLASS tan2rad(const double & X,const double & Y);
double PPSTOOLS_EXT_CLASS sin2deg (const double & Y,const double & R);
double PPSTOOLS_EXT_CLASS sin2rad (const double & Y,const double & R);
double PPSTOOLS_EXT_CLASS cos2deg (const double & X,const double & R);
double PPSTOOLS_EXT_CLASS cos2rad (const double & X,const double & R);
double PPSTOOLS_EXT_CLASS Angle(const double & x,const double & y);
double PPSTOOLS_EXT_CLASS AngleLine(const double & x1,const double & y1,const double & x2,const double & y2);
double PPSTOOLS_EXT_CLASS Log (const double & X);
double PPSTOOLS_EXT_CLASS HypSin( const double & x);
double PPSTOOLS_EXT_CLASS HypCos( const double & x);
int PPSTOOLS_EXT_CLASS sign(const double & x);

#endif // !defined(AFX_MATHLIB_H__AC94C70B_6B40_46BD_A822_5FAB316D74D4__INCLUDED_)
