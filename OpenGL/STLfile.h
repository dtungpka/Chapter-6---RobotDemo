// STLfile.h: interface for the STLfile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STLFILE_H__54646A9A_28FE_4649_A629_BA0A2591C1BC__INCLUDED_)
#define AFX_STLFILE_H__54646A9A_28FE_4649_A629_BA0A2591C1BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct OPENGL_EXT_CLASS STL_FACE
{
	Vec3f normal;
	Vec3f vertex[3];

	STL_FACE();
	STL_FACE(const  STL_FACE & face);

	void Copy(const  STL_FACE & face);
	STL_FACE operator=(const  STL_FACE & face);

	void SetVertex(const int & id, const double & x,const double & y,const double & z);
	void SetNormal(const double & x,const double & y,const double & z);

	void Draw();
}stl_face;

class OPENGL_EXT_CLASS STLfile  
{
public:
	Vec3f Max,Min;
	CArray<STL_FACE,STL_FACE> listFace;

	STLfile();
	virtual ~STLfile();

	int ReadBinary(CStdioFile &file, const BOOL & drawDirect=FALSE, const double & dTransX=0, const double & dTransY=0, const double & dTransZ=0);
	int ReadText(CStdioFile &file, const BOOL & drawDirect=FALSE, const double & dTransX=0, const double & dTransY=0, const double & dTransZ=0);
	int ReadBinary(const CString & fname, const BOOL & drawDirect=FALSE, const double & dTransX=0, const double & dTransY=0, const double & dTransZ=0);
	int ReadText(const CString & fname, const BOOL & drawDirect=FALSE, const double & dTransX=0, const double & dTransY=0, const double & dTransZ=0);

	int WriteText(CStdioFile &file);
	int WriteText(const CString &fname);

	void Draw();
};

#endif // !defined(AFX_STLFILE_H__54646A9A_28FE_4649_A629_BA0A2591C1BC__INCLUDED_)
