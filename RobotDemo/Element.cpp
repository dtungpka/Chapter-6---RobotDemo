// Element.cpp: implementation of the CElement class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "RobotDemo.h"
#include "Element.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CElement::CElement()
{
	Reset();
	m_Max[0]=m_Max[1]=m_Max[2]=0;
	m_Min[0]=m_Min[1]=m_Min[2]=0;

	m_glList.m_glMaterial.SetStyleDefault(1);
	m_glList.m_glMaterial.Default();
	m_glList.m_glMaterial.Shininess=10;

	m_l=m_phi=m_theta=0;

	m_drawBound=FALSE;

	m_IndexRotate[0]=1;
	m_IndexRotate[1]=2;
	m_IndexRotate[2]=3;
}
CElement::~CElement()
{
}

void CElement::Serialize(CArchive &ar)
{
	m_glList.m_glMaterial.Serialize(ar);	

	if (ar.IsStoring())
	{
		ar<<m_l<<m_phi<<m_theta;
	}
	else
	{
		ar>>m_l>>m_phi>>m_theta;
	}
}


#include "NewSTLfile.h"
int CElement::LoadModel(CString filename,double translateX, double translateY, double translateZ)
{
	m_glList.BeginNewList();

	glPolygonMode(GL_BACK, GL_POINT);


	/*CNewSTLfile fileModel;	
	int res=fileModel.ReadMBFfile(filename,TRUE);*/

	STLfile fileModel;
	int res=fileModel.ReadBinary(filename,TRUE,translateX, translateY, translateZ);
	//fileModel.Draw(); // use this method to draw when using ReadBinary with FLASE

	m_glList.m_Max=fileModel.Max;
	m_glList.m_Min=fileModel.Min;

	m_glList.EndNewList();
	return res;
}

void CElement::Draw()
{
	glPushMatrix();
		m_glList.m_glMaterial.SetUpMaterial();
		glTranslated(m_OrgPosition[0]+m_Translate[0],m_OrgPosition[1]+m_Translate[1],m_OrgPosition[2]+m_Translate[2]);

		glRotated(
			m_IndexRotate[0]==1 ? m_Angle[0] : 
				(m_IndexRotate[1]==1 ? m_Angle[1] : m_Angle[2]),
			m_IndexRotate[0]==1 ? 1 : 0,
			m_IndexRotate[1]==1 ? 1 : 0,
			m_IndexRotate[2]==1 ? 1 : 0);
		glRotated(
			-(m_IndexRotate[0]==2 ? m_Angle[0] : 
				(m_IndexRotate[1]==2 ? m_Angle[1] : m_Angle[2])),
					m_IndexRotate[0]==2 ? 1 : 0,
					m_IndexRotate[1]==2 ? 1 : 0,
					m_IndexRotate[2]==2 ? 1 : 0);
		glRotated(
			m_IndexRotate[0]==3 ? m_Angle[0] : 
				(m_IndexRotate[1]==3 ? m_Angle[1] : m_Angle[2]),
					m_IndexRotate[0]==3 ? 1 : 0,
					m_IndexRotate[1]==3 ? 1 : 0,
					m_IndexRotate[2]==3 ? 1 : 0);
				
				m_glList.Draw();
				if (m_drawBound) 
				{
					glLineWidth(2);
					m_glList.DrawBound(RGB(255,0,0));
				}
	glPopMatrix();
}

void CElement::SetPosition(double x,double y,double z)
{
	m_OrgPosition[0]=x;m_OrgPosition[1]=y;m_OrgPosition[2]=z;
}
void CElement::SetPositionX(double x)
{
	m_OrgPosition[0]=x;
}
void CElement::SetPositionY(double y)
{
	m_OrgPosition[1]=y;
}
void CElement::SetPositionZ(double z)
{
	m_OrgPosition[2]=z;
}

void CElement::GetPosition(double & x,double& y,double& z)
{
	x=m_OrgPosition[0];y=m_OrgPosition[1];z=m_OrgPosition[2];
}
double CElement::GetPositionX()
{
	return m_OrgPosition[0];
}
double CElement::GetPositionY()
{
	return m_OrgPosition[1];
}
double CElement::GetPositionZ()
{
	return m_OrgPosition[2];
}

void CElement::SetAngle(double x,double y,double z)
{
	m_Angle[0]=x;m_Angle[1]=y;m_Angle[2]=z;
}
void CElement::SetAngleX(double x)
{
	m_Angle[0]=x;
}
void CElement::SetAngleY(double y)
{
	m_Angle[1]=y;
}
void CElement::SetAngleZ(double z)
{
	m_Angle[2]=z;
}

void CElement::GetAngle(double & x,double& y,double& z)
{
	x=m_Angle[0];y=m_Angle[1];z=m_Angle[2];
}
double CElement::GetAngleX()
{
	return m_Angle[0];
}
double CElement::GetAngleY()
{
	return m_Angle[1];
}
double CElement::GetAngleZ()
{
	return m_Angle[2];
}

void CElement::SetTranslate(double x,double y,double z)
{
	m_Translate[0]=x;m_Translate[1]=y;m_Translate[2]=z;
}
void CElement::SetTranslateX(double x)
{
	m_Translate[0]=x;
}
void CElement::SetTranslateY(double y)
{
	m_Translate[1]=y;
}
void CElement::SetTranslateZ(double z)
{
	m_Translate[2]=z;
}

void CElement::GetTranslate(double & x,double& y,double& z)
{
	x=m_Translate[0];y=m_Translate[1];z=m_Translate[2];
}
double CElement::GetTranslateX()
{
	return m_Translate[0];
}
double CElement::GetTranslateY()
{
	return m_Translate[1];
}
double CElement::GetTranslateZ()
{
	return m_Translate[2];
}

void CElement::GetPosEnd(double &x, double &y, double &z)
{
	double c1=cos(m_Angle[0]*PI/180.0);
	double c2=cos(m_Angle[1]*PI/180.0);
	double c3=cos(m_Angle[2]*PI/180.0);

	double s1=sin(m_Angle[0]*PI/180.0);
	double s2=sin(m_Angle[1]*PI/180.0);
	double s3=sin(m_Angle[2]*PI/180.0);

	/*
	smatrix m(3);
	m(0,0)=c2*c3;			m(0,1)=-c2*s3;			m(0,2)=s2;
	m(1,0)=s1*s2*c3+c1*s3;	m(1,1)=-s1*s2*s3+c1*c3;	m(1,2)=-s1*c2;
	m(2,0)=-c1*s2*c3+s1*s3;	m(2,1)=c1*s2*s3+s1*c3;	m(2,2)=c1*c2;
	*/
	smatrix m1(3),m2(3), m3(3);
	
	m1(0,0)=1;	m1(0,1)=0;	m1(0,2)=0;
	m1(1,0)=0;	m1(1,1)=c1;	m1(1,2)=-s1;
	m1(2,0)=0;	m1(2,1)=s1;	m1(2,2)=c1;

	m2(0,0)=c2;	m2(0,1)=0;	m2(0,2)=-s2;
	m2(1,0)=0;	m2(1,1)=1;	m2(1,2)=0;
	m2(2,0)=s2;	m2(2,1)=0;	m2(2,2)=c2;

	m3(0,0)=c3;	m3(0,1)=-s3;	m3(0,2)=0;
	m3(1,0)=s3;	m3(1,1)=c3;	m3(1,2)=0;
	m3(2,0)=0;	m3(2,1)=0;	m3(2,2)=1;

	vectorm v(3);
	v(0)=m_l*cos(PI*m_theta/180.0)*cos(PI*m_phi/180.0);
	v(1)=m_l*cos(PI*m_theta/180.0)*sin(PI*m_phi/180.0);
	v(2)=m_l*sin(PI*m_theta/180.0);

	smatrix m(3);
	m = m_IndexRotate[0]==1 ? m1 : (m_IndexRotate[1]==1 ? m2 : m3);
	m = m * (m_IndexRotate[0]==2 ? m1 : (m_IndexRotate[1]==2 ? m2 : m3));
	m = m * (m_IndexRotate[0]==3 ? m1 : (m_IndexRotate[1]==3 ? m2 : m3));
	v=m*v;

// 	x=m_OrgPosition[0]+m_Translate[0]+m_l*cos(PI*m_theta/180.0)*cos(PI*m_phi/180.0);
// 	y=m_OrgPosition[1]+m_Translate[1]+m_l*cos(PI*m_theta/180.0)*sin(PI*m_phi/180.0);
// 	z=m_OrgPosition[2]+m_Translate[2]+m_l*sin(PI*m_theta/180.0);

	x=m_OrgPosition[0]+m_Translate[0]+v(0);
	y=m_OrgPosition[1]+m_Translate[1]+v(1);
	z=m_OrgPosition[2]+m_Translate[2]+v(2);
}

double CElement::GetPosEndX()
{
	//return m_OrgPosition[0]+m_Translate[0]+m_l*cos(PI*m_theta/180.0)*cos(PI*m_phi/180.0);

	double x,y,z;
	GetPosEnd(x,y,z);
	return x;
}
double CElement::GetPosEndY()
{
	//return m_OrgPosition[1]+m_Translate[1]+m_l*cos(PI*m_theta/180.0)*sin(PI*m_phi/180.0);

	double x,y,z;
	GetPosEnd(x,y,z);
	return y;
}
double CElement::GetPosEndZ()
{
	//return m_OrgPosition[2]+m_Translate[2]+m_l*sin(PI*m_theta/180.0);

	double x,y,z;
	GetPosEnd(x,y,z);
	return z;
}

void CElement::Reset()
{
	m_OrgPosition[0]=m_OrgPosition[1]=m_OrgPosition[2]=0;
	m_Angle[0]=m_Angle[1]=m_Angle[2]=0;
	m_Translate[0]=m_Translate[1]=m_Translate[2]=0;
}
