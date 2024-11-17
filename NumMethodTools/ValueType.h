// Value.h: interface for the Value class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __VALUE_H__
#define __VALUE_H__


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef USE_MFC
class NUMMETHODTOOLS_EXT_CLASS ValueType : public CObject  
#else //	USE_MFC
class NUMMETHODTOOLS_EXT_CLASS ValueType
#endif USE_MFC
{
public:
#ifdef USE_MFC
	DECLARE_SERIAL(Value);
#endif USE_MFC

	virtual void SetValue(double value);	
	virtual double GetValue();	

#ifdef USE_MFC
	virtual void Serialize(CArchive &ar);	//The serialization function
#endif USE_MFC

	ValueType();	//Contructor
	virtual ~ValueType();	//Distructor

protected:
	double m_value;
};


#endif //__VALUE_H__
