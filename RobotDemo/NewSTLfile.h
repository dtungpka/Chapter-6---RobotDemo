// NewSTLfile.h: interface for the CNewSTLfile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWSTLFILE_H__A5C172A8_1CAF_45B9_AB56_182477260F18__INCLUDED_)
#define AFX_NEWSTLFILE_H__A5C172A8_1CAF_45B9_AB56_182477260F18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNewSTLfile  : public STLfile
{
public:
	int ReadMBFfile(const CString &fname, const BOOL & drawDirect=TRUE);
	int SaveMBFfile(const CString & fname);
	int ReadMTFfile(const CString &fname, const BOOL & drawDirect=TRUE);
	int SaveMTFfile(const CString & fname);

	void DrawNormalVector(int StyleShow=0);
	void DrawNew();
	double AngleVectorRad(const Vec3f & v1,const Vec3f & v2);
	double AngleVectorDeg(const Vec3f & v1,const Vec3f & v2);
	void CalNormalVertex(double angleAddIn=45, double disSamePoint=1.0E-3);
	CNewSTLfile();
	virtual ~CNewSTLfile();

	int ReadBinary(CStdioFile &file, const BOOL & drawDirect=FALSE);
	int ReadText(CStdioFile &file, const BOOL & drawDirect=FALSE);
	int ReadBinary(const CString & fname, const BOOL & drawDirect=FALSE);
	int ReadText(const CString & fname, const BOOL & drawDirect=FALSE);
	
	CArray<STL_FACE,STL_FACE> listNormalVertex;
protected:
	void AddFacet(const STL_FACE & facetNormal, const  STL_FACE & facetVertex, const BOOL & drawDirect=FALSE);
	BOOL FaceHavePoint(STL_FACE face, Vec3f point,int & idVertex, double delta = 1.0E-5);
};

#endif // !defined(AFX_NEWSTLFILE_H__A5C172A8_1CAF_45B9_AB56_182477260F18__INCLUDED_)
