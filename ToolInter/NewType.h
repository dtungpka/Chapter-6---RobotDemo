// NewType.h: interface for the CNewType class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_NEWTYPE_H__E7787C4A_C450_4DBC_9FBE_E7A411C28A58__INCLUDED_)
#define AFX_NEWTYPE_H__E7787C4A_C450_4DBC_9FBE_E7A411C28A58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef NEWTYPE_EXT_CLASS
#define NEWTYPE_EXT_CLASS TOOLINTER_EXT_CLASS
#endif NEWTYPE_EXT_CLASS

#include <afxtempl.h>
#include "math.h"

#ifndef DEFINE_NEW_ARRAY
#define DEFINE_NEW_ARRAY

template< class TYPE, class ARG_TYPE > 
class CNewArray : public CArray<TYPE,ARG_TYPE>
{
public:
	CNewArray():CArray<TYPE,ARG_TYPE>()
	{
	}
	CNewArray(const CNewArray & in):CArray<TYPE,ARG_TYPE>()
	{
		this->Copy( in );
	}
	CNewArray operator=(const CNewArray & in)
	{
		this->Copy( in );
		return *this;
	}
	TYPE * GetPointerAt(const int & nId)
	{
		return &(operator [](nId));
	}
};

//type new types
typedef CNewArray<short, short> CShortArray;
typedef CNewArray<int, int> CIntArray;
typedef CNewArray<long, long> CLongArray;
typedef CNewArray<double, double> CDoubleArray;
typedef CNewArray<float, float> CFloatArray;

typedef CNewArray<CString,CString>  CNewStringArray;
typedef CArray<CNewStringArray,CNewStringArray> CArrayStringArray;

//These class really existed !
/*
CByteArray; 
CDWordArray; 
CPtrArray; 
CStringArray; 
CUIntArray; 
CWordArray; 
*/
//

#endif DEFINE_NEW_ARRAY

template<class T>
T absT(const T & in)
{
	return (in<0)? -in : in;
}

template<class T>
T FindMax(const CArray<T,T> & xarray)
{
	T max=0;
	if (xarray.GetSize()<=0) return max;
	max=xarray[0];
	for (int i=0;i<xarray.GetSize();i++)
		if (max<xarray[i]) max=xarray[i];
	return max;
}

template<class T>
T FindMin(const CArray<T,T> & xarray)
{
	T min=0;
	if (xarray.GetSize()<=0) return min;
	min=xarray[0];
	for (int i=0;i<xarray.GetSize();i++)
		if (min>xarray[i]) min=xarray[i];
	return min;
}

template<class T>
int FindIndexMax(const CArray<T,T> & xarray)
{
	int id=-1;
	T max=0;
	if (xarray.GetSize()<=0) return id;
	max=xarray[0];id=0;
	for (int i=0;i<xarray.GetSize();i++)
		if (max<xarray[i]) {max=xarray[i];id=i;}
	return id;
}

template<class T>
int FindIndexMin(const CArray<T,T> & xarray)
{
	int id=-1;
	T max=0;
	if (xarray.GetSize()<=0) return id;
	max=xarray[0];id=0;
	for (int i=0;i<xarray.GetSize();i++)
		if (max>xarray[i]) {max=xarray[i];id=i;}
	return id;
}

template<class T>
T FindNearest(const T & find,const CArray<T,T> & xarray)
{
	int id=FindIndexNearest(find,xarray);
	if (id<0) return (T)0;
	return xarray[id];
}

template<class T>
int FindIndexNearest(const T & find,const CArray<T,T> & xarray)
{
	if (xarray.GetSize()<=0) return -1;
	int id=0;
	T min=absT(find-xarray[0]),temp;
	for (int i=1;i<xarray.GetSize();i++)
	{
		temp=absT(find-xarray[i]);
		if (min>temp) {min=temp;id=i;}
	}
	return id;
}

template<class T>
  T FindGE(const T & find,const CArray<T,T> & xarray)
{
	T re;
	int id=FindIndexGE(find,xarray);
	if (id<0) return re;
	return xarray[id];
}
template<class T>
  int FindIndexGE(const T & find,const CArray<T,T> & xarray)
{
	int pos=-1;
	for (int i=0;i<xarray.GetSize();i++)
			if (xarray[i]>=find) {pos=i;break;}
	return pos;
}

template<class T>
  T FindLE(const T & find,const CArray<T,T> & xarray)
{
	T re;
	int id=FindIndexLE(find,xarray);
	if (id<0) return re;
	return xarray[id];
}
template<class T>
  int FindIndexLE(const T & find,const CArray<T,T> & xarray)
{
	int pos=-1;
	for (int i=0;i<xarray.GetSize();i++)
			if (xarray[i]<=find) {pos=i;break;}
	return pos;
}

template<class T>
  int FindIndexItem(const T & find,const CArray<T,T> & xarray)
{
	int pos=-1;
	for (int i=0;i<xarray.GetSize();i++)
			if (xarray[i]==find) {pos=i;break;}
	return pos;
}
template<class T>
  int FindIndexItem(const T & find,const CArray<T,T> & xarray,const int & from,const int & to)
{
	int pos=-1,rfrom=from,rto=to;
	if (rfrom<0) rfrom=0;
	if (rto>=xarray.GetSize()) rfrom=xarray.GetSize()-1;
	for (int i=rfrom;i<rto;i++)
			if (xarray[i]==find) {pos=i;break;}
	return pos;
}

int  NEWTYPE_EXT_CLASS MakeRound(const double & nin,const int & nto);//lam tron den so chia het cho nto

#endif // !defined(AFX_NEWTYPE_H__E7787C4A_C450_4DBC_9FBE_E7A411C28A58__INCLUDED_)
