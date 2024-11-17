// NewSTLfile.cpp: implementation of the CNewSTLfile class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "NewSTLfile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define PI 3.1415926535897932384626
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNewSTLfile::CNewSTLfile()
{
	STLfile::STLfile();
}

CNewSTLfile::~CNewSTLfile()
{
	STLfile::~STLfile();
}

void CNewSTLfile::CalNormalVertex(double angleAddIn, double disSamePoint)
{
	listNormalVertex.SetSize(listFace.GetSize());
	CArray<byte,byte> listNormalVertexCalled[3];
	CArray<int,int> listVertexSameNormal[2];
	for (int i=0;i<3;i++)
	{
		listNormalVertexCalled[i].SetSize(listFace.GetSize());
		for (int j=0;j<listFace.GetSize();j++)
			listNormalVertexCalled[i][j]=0;
	}
	for (int i=0;i<listFace.GetSize();i++)
	{
		listNormalVertex[i].normal=listFace[i].normal;
		for (int j=0;j<3;j++)
			if (listNormalVertexCalled[j][i]==0)
			{
				listVertexSameNormal[0].RemoveAll();
				listVertexSameNormal[1].RemoveAll();
				listNormalVertex[i].vertex[j]=listFace[i].normal;
				for (int k=0;k<listFace.GetSize();k++)
					if (k!=i)
					{
						int idVertex=0;
						if (FaceHavePoint(listFace[k],listFace[i].vertex[j],idVertex,disSamePoint))
						{
							if (listNormalVertexCalled[idVertex][k]==0)
								if (AngleVectorDeg(listFace[i].normal,listFace[k].normal)<=angleAddIn)
								{
									listNormalVertex[i].vertex[j]+=listFace[k].normal;
									listNormalVertexCalled[idVertex][k]=1;
									listVertexSameNormal[0].Add(k);
									listVertexSameNormal[1].Add(idVertex);
								}
						}
					}
				listNormalVertex[i].vertex[j]/=listNormalVertex[i].vertex[j].Length();
				for (int k=0;k<listVertexSameNormal[0].GetSize();k++)
					listNormalVertex[listVertexSameNormal[0][k]].vertex[listVertexSameNormal[1][k]]=listNormalVertex[i].vertex[j];
			}
	}
}

double CNewSTLfile::AngleVectorRad(const Vec3f &v1, const Vec3f &v2)
{
	double ang;
	double t=v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
	double l1=sqrt(v1.x*v1.x+v1.y*v1.y+v1.z*v1.z);
	double l2=sqrt(v2.x*v2.x+v2.y*v2.y+v2.z*v2.z);
	ang=acos(t/(l1*l2));
	return ang;
}
double CNewSTLfile::AngleVectorDeg(const Vec3f &v1, const Vec3f &v2)
{	
	return AngleVectorRad(v1,v2)*180.0/PI;
}

BOOL CNewSTLfile::FaceHavePoint(STL_FACE face, Vec3f point,int & idVertex, double delta)
{
	for (int i=0;i<3;i++)
	{
		double dx,dy,dz;
		dx=fabs(point.x-face.vertex[i].x);
		dy=fabs(point.y-face.vertex[i].y);
		dz=fabs(point.z-face.vertex[i].z);
		if ((dx<=delta)&&(dy<=delta)&&(dz<=delta)) 
		{
			idVertex=i;
			return TRUE;
		}
	}
	return FALSE;
}

void CNewSTLfile::DrawNew()
{
	for (int i=0;i<listFace.GetSize();i++) 
	{
		glBegin(GL_TRIANGLES);
			for (int j=0;j<3;j++) 
			{
				if (i<listNormalVertex.GetSize())
					glNormal3f(
						listNormalVertex[i].vertex[j][0],
						listNormalVertex[i].vertex[j][1],
						listNormalVertex[i].vertex[j][2]);
				glVertex3f(
					listFace[i].vertex[j][0],
					listFace[i].vertex[j][1],
					listFace[i].vertex[j][2]);
			}
		glEnd();
	}
}

void CNewSTLfile::DrawNormalVector(int StyleShow)
{
	glDisable(GL_LIGHTING);
	for (int i=0;i<listFace.GetSize();i++) 
	{		
		glColor3d(1,0,0);
		Vec3f vCen;
		for (int j=0;j<3;j++) 
		{
			vCen+=listFace[i].vertex[j];
			if ((i<listNormalVertex.GetSize())&&(StyleShow!=0))
			{
				glBegin(GL_LINES);
				glVertex3f(
					listFace[i].vertex[j][0],
					listFace[i].vertex[j][1],
					listFace[i].vertex[j][2]);
				glVertex3f(
					listFace[i].vertex[j][0]+listNormalVertex[i].vertex[j][0],
					listFace[i].vertex[j][1]+listNormalVertex[i].vertex[j][1],
					listFace[i].vertex[j][2]+listNormalVertex[i].vertex[j][2]);
				glEnd();
			}			
		}
		vCen/=3.0;
		if (StyleShow>=0)
		{
			glColor3d(0,1,0);			
			glBegin(GL_LINES);
			glVertex3f(vCen[0],vCen[1],vCen[2]);
			glVertex3f(
				vCen[0]+listFace[i].normal[0],
				vCen[1]+listFace[i].normal[1],
				vCen[2]+listFace[i].normal[2]);
			glEnd();
		}		
	}
	glEnable(GL_LIGHTING);
}

int CNewSTLfile::ReadBinary(CStdioFile &file, const BOOL & drawDirect)
{
	listNormalVertex.RemoveAll();
	return STLfile::ReadBinary(file,drawDirect);
}
int CNewSTLfile::ReadText(CStdioFile &file, const BOOL & drawDirect)
{
	listNormalVertex.RemoveAll();
	return STLfile::ReadText(file,drawDirect);
}
int CNewSTLfile::ReadBinary(const CString & fname, const BOOL & drawDirect)
{
	listNormalVertex.RemoveAll();
	return STLfile::ReadBinary(fname,drawDirect);
}
int CNewSTLfile::ReadText(const CString & fname, const BOOL & drawDirect)
{
	listNormalVertex.RemoveAll();
	return STLfile::ReadText(fname,drawDirect);;
}

int CNewSTLfile::SaveMTFfile(const CString &fname)
{
	if (listNormalVertex.GetSize()<=0) return 1;
	if (fname.IsEmpty()) return -2;//file name is not supported
	CStdioFile file;
	if (!file.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeText)) return -1;
	CString sWrite;
	sWrite.Format("%d",listFace.GetSize());
	file.WriteString(sWrite);
	for (int i=0;i<listFace.GetSize();i++)
	{
		sWrite.Format("\n%f %f %f",listFace[i].normal[0],listFace[i].normal[1],listFace[i].normal[2]);
		file.WriteString(sWrite);
		for (int j=0;j<3;j++) 
		{
			sWrite.Format("\n%f %f %f",listNormalVertex[i].vertex[j][0],listNormalVertex[i].vertex[j][1],listNormalVertex[i].vertex[j][2]);
			file.WriteString(sWrite);
			sWrite.Format("\n%f %f %f",listFace[i].vertex[j][0],listFace[i].vertex[j][1],listFace[i].vertex[j][2]);
			file.WriteString(sWrite);
		}
	}
	file.Close();
	return 0;
}

int CNewSTLfile::ReadMTFfile(const CString &fname, const BOOL & drawDirect)
{
	listFace.RemoveAll();
	listNormalVertex.RemoveAll();
	Max.Set(0,0,0);Min.Set(0,0,0);

	if (fname.IsEmpty()) return -2;//file name is not supported
	CStdioFile file;
	if (!file.Open(fname, CFile::modeRead|CFile::typeText)) return -1;
	CString sRead;
	file.ReadString(sRead);
	int numface=atoi(sRead);

	STL_FACE facetVetex,facetNormal;
	for (int i=0;i<numface;i++)
	{
		file.ReadString(sRead);
		if (sRead.IsEmpty()) break;
		sscanf_s(sRead,"%f %f %f",&facetVetex.normal[0],&facetVetex.normal[1],&facetVetex.normal[2]);
		facetNormal.normal=facetVetex.normal;
		for (int j=0;j<3;j++) 
		{
			file.ReadString(sRead);
			sscanf_s(sRead,"%f%f%f",&facetNormal.vertex[j][0],&facetNormal.vertex[j][1],&facetNormal.vertex[j][2]);
			file.ReadString(sRead);
			sscanf_s(sRead,"%f%f%f",&facetVetex.vertex[j][0],&facetVetex.vertex[j][1],&facetVetex.vertex[j][2]);
			for (int k=0;k<3;k++)
			{
				if ((j==0)&&(i==0)) {Min[k]=facetVetex.vertex[j][k];Max[k]=facetVetex.vertex[j][k];}
				else {Min[k]=min(Min[k],facetVetex.vertex[j][k]);Max[k]=max(Max[k],facetVetex.vertex[j][k]);}
			}
		}
		AddFacet(facetNormal,facetVetex,drawDirect);	
	}
	file.Close();
	return 0;
}

int CNewSTLfile::ReadMBFfile(const CString &fname, const BOOL & drawDirect)
{
	listFace.RemoveAll();
	listNormalVertex.RemoveAll();
	Max.Set(0,0,0);Min.Set(0,0,0);

	if (fname.IsEmpty()) return -2;//file name is not supported
	CFile file;
	if (!file.Open(fname, CFile::modeRead|CFile::typeBinary)) return -1;
	
	int num=0;
	file.Read(&num,sizeof(num));

	float vectorRead[7][3];
	STL_FACE facetVetex,facetNormal;
	for (int i=0;i<num;i++)
	{
		file.Read(&vectorRead,sizeof(float)*21);
		for (int k=0;k<3;k++) 
			facetVetex.normal[k]=facetNormal.normal[k]=vectorRead[0][k];
		for (int j=0;j<3;j++) 
		{
			for (int k=0;k<3;k++) 
			{
				facetNormal.vertex[j][k]=vectorRead[2*j+1][k];
				facetVetex.vertex[j][k]=vectorRead[2*j+2][k];

				if ((j==0)&&(i==0)) {Min[k]=facetVetex.vertex[j][k];Max[k]=facetVetex.vertex[j][k];}
				else {Min[k]=min(Min[k],facetVetex.vertex[j][k]);Max[k]=max(Max[k],facetVetex.vertex[j][k]);}
			}
		}
		AddFacet(facetNormal,facetVetex,drawDirect);
	}
	file.Close();
	return 0;
}

int CNewSTLfile::SaveMBFfile(const CString &fname)
{
	if (listNormalVertex.GetSize()<=0) return 1;
	if (fname.IsEmpty()) return -2;//file name is not supported
	CFile file;
	if (!file.Open(fname, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary)) return -1;
	
	int num=listFace.GetSize();
	file.Write(&num,sizeof(num));
	for (int i=0;i<listFace.GetSize();i++)
	{
		for (int k=0;k<3;k++) 
			file.Write(&listFace[i].normal[k],sizeof(listFace[i].normal[k]));
		for (int j=0;j<3;j++) 
		{
			for (int k=0;k<3;k++) 
				file.Write(&listNormalVertex[i].vertex[j][k],sizeof(listNormalVertex[i].vertex[j][k]));
			for (int k=0;k<3;k++) 
				file.Write(&listFace[i].vertex[j][k],sizeof(listFace[i].vertex[j][k]));
		}
	}
	file.Close();
	return 0;
}

void CNewSTLfile::AddFacet(const STL_FACE & facetNormal, const  STL_FACE & facetVertex, const BOOL & drawDirect)
{
	if (drawDirect)
	{
		glBegin(GL_TRIANGLES);
		for (int j=0;j<3;j++) 
		{
			glNormal3f(facetNormal.vertex[j][0],facetNormal.vertex[j][1],facetNormal.vertex[j][2]);
			glVertex3f(facetVertex.vertex[j][0],facetVertex.vertex[j][1],facetVertex.vertex[j][2]);
		}
		glEnd();
	}
	else
	{
		listNormalVertex.Add(facetNormal);
		listFace.Add(facetVertex);
	}
}
