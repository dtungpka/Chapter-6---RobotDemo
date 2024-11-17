// Element.h: interface for the CElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMENT_H__507F54F8_DF6D_4253_B319_0DDC11D3A555__INCLUDED_)
#define AFX_ELEMENT_H__507F54F8_DF6D_4253_B319_0DDC11D3A555__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define PI 3.1415926535897932384626433832795

class CElement
{
public:
	void Reset();
	void Serialize(CArchive &ar);
	CElement();
	virtual ~CElement();
	
	int LoadModel(CString filename,double translateX=0, double translateY=0, double translateZ=0);
	void Draw();
	
	void SetPosition(double x,double y,double z);
	void SetPositionX(double x);
	void SetPositionY(double y);
	void SetPositionZ(double z);
	
	void GetPosition(double & x,double& y,double& z);
	double GetPositionX();
	double GetPositionY();
	double GetPositionZ();
	
	void SetAngle(double x,double y,double z);
	void SetAngleX(double x);
	void SetAngleY(double y);
	void SetAngleZ(double z);
	
	void GetAngle(double & x,double& y,double& z);
	double GetAngleX();
	double GetAngleY();
	double GetAngleZ();

	void SetTranslate(double x,double y,double z);
	void SetTranslateX(double x);
	void SetTranslateY(double y);
	void SetTranslateZ(double z);
	
	void GetTranslate(double & x,double& y,double& z);
	double GetTranslateX();
	double GetTranslateY();
	double GetTranslateZ();
	
	void GetPosEnd(double & x, double & y, double & z);
	double GetPosEndX();
	double GetPosEndY();
	double GetPosEndZ();
	
	STRUCT_OBJECTGLLIST m_glList;
	BOOL m_drawBound;

	//vi tri cua goc khau
	double m_OrgPosition[3];
	double m_Angle[3];
	double m_Translate[3];
	int m_IndexRotate[3];
	
	double m_l;//khoang cach tu diem goc den diem cuoi cua khau
	double m_phi;//goc quay quanh truc Z cua khau
	double m_theta;//goc quay tu mat Oxy cua khau
	
	double m_Max[3];
	double m_Min[3];
};

#endif // !defined(AFX_ELEMENT_H__507F54F8_DF6D_4253_B319_0DDC11D3A555__INCLUDED_)
