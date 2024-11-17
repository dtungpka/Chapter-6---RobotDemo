// MConvert.h: interface for the MConvert class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _MCONVERT_H_
#define _MCONVERT_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CONVERT_m_km	0.001
#define CONVERT_m_mm	1000.0
#define CONVERT_m_cm	100.0

#define CONVERT_ft_in	12.0
#define CONVERT_in_m	0.0254
#define CONVERT_ft_m	0.3048
#define CONVERT_kip_N	4448.221615
#define CONVERT_kipPERin2_MPa	6.894757293
#define CONVERT_MPa_NPERm2 1000000.0
#define CONVERT_MPa_NPERmm2 1.0

//double NUMMETHODTOOLS_EXT_CLASS Convert(const double & in,const double & measure);
double NUMMETHODTOOLS_EXT_CLASS Convert_m_km(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_m_mm(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_m_cm(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_km_m(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_mm_m(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_cm_m(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_ft_in(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_in_ft(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_ft_m(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_m_ft(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_in_m(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_m_in(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_in_cm(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_cm_in(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_in_mm(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_mm_in(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_in2_mm2(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_mm2_in2(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_in4_mm4(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_mm4_in4(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_kipPERin_NPERmm(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_NPERmm_kipPERin(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_kip_N(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_kipPERin2_MPa(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_MPa_NPERm2(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_MPa_NPERmm2(const double & in);

double NUMMETHODTOOLS_EXT_CLASS Convert_N_kip(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_MPa_kipPERin2(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_NPERm2_MPa(const double & in);
double NUMMETHODTOOLS_EXT_CLASS Convert_NPERmm2_MPa(const double & in);

#endif _MCONVERT_H_
