// matrix.h: interface for the matrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__3D8A8D71_A1AF_40B0_AE3A_1367156674A3__INCLUDED_)
#define AFX_MATRIX_H__3D8A8D71_A1AF_40B0_AE3A_1367156674A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;
#include <iostream>

#ifndef PI
	#define PI 3.141592654
#endif
//===========================================================================
//===========================================================================
//CLASS BASE MATRIX
//===========================================================================
//===========================================================================
class NUMMETHODTOOLS_EXT_CLASS matrix
{
protected:
   int sizecol/*size collum*/,sizerow/*size row*/;
   double **data;
//===========================================================================
public:
//1
   matrix();
//2
   matrix(const int & m,const int & n);
//3
   matrix(const matrix & matrix1);
//4
   ~matrix();
//===========================================================================
//5
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator+(const matrix & matrix1,const matrix & matrix2);
   //matrix1+matrix2
//6
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator-(const matrix & matrix1,const matrix & matrix2);
   //matrix1-matrix2
//7
   friend  matrix NUMMETHODTOOLS_EXT_CLASS operator*(const matrix & matrix1,const matrix & matrix2);
   //matrix1*matrix2
//===========================================================================
//8
   matrix operator+=(const double & add);//matrix+=add
//9
   matrix operator-=(const double & minus);//matrix-=minus
//10
   matrix operator*=(const double & multiply);//matrix*=multiply
//11
   matrix operator/=(const double & devide);//matrix/=devide
//===========================================================================
//12 a
   //matrix operator+(const double & add)const;//matrix=matrix+add
   //b
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator+(const double & add,const matrix& matrix1);
   //matrix=add+matrix
   //c
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator+(const matrix& matrix1,const double & add);
   //matrix=matrix+add
//13 a
  // matrix operator-(const double & minus)const;//matrix=matrix-minus
   //b
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator-(const double & minus,const matrix& matrix1);
   //matrix=minus-matrix
   //c
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator-(const matrix& matrix1,const double & minus);
   //matrix=matrix-minus
//14 a
   //matrix operator*(const double & multiply)const;//matrix=matrix*multiply
   //b
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator*(const matrix& matrix1,const double & multiply);
   //matrix=matrix1*multiply
   //c
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator*(const double & multiply,const matrix& matrix1);
   //matrix=multiply*matrix1
//15
   matrix operator/(const double & devide)const;//matrix=matrix/devide
//===========================================================================
    //matrix operator+(const matrix & matrix1);//matrix=matrix+matrix1
    //matrix operator-(const matrix & matrix1);//matrix=matrix-matrix1
//16
    matrix operator+=(const matrix & matrix1);//matrix+=matrix1
//17
    matrix operator-=(const matrix & matrix1);//matrix-=matrix1

//===========================================================================
//18
   matrix operator++(int);//matrix++
//19
   matrix operator--(int);//matrix--

//20
   matrix& operator++();//++matrix
//21
   matrix& operator--();//--matrix
//===========================================================================
//22
   friend matrix NUMMETHODTOOLS_EXT_CLASS operator!(const matrix & matrix1);//chuyen vi
//===========================================================================
   //int&  operator[](int &i)operator[](int &j);//lay phan tu
//23
   double const & operator()(const int &i,const int &j)const;//lay phan tu
   double & operator()(const int &i,const int &j);//lay phan tu
//===========================================================================
//24
   friend void NUMMETHODTOOLS_EXT_CLASS print(const matrix& matrix1);
   //in mot matrix ra man hinh
//25
   friend ostream& operator<<(ostream & co,const matrix & matrix2);
   //in mot matrix ra man hinh
//26
   friend istream& operator>>(istream & ci,matrix & matrix2);
   //Nhap du lieu cho ma tran
//===========================================================================
//27
//sua chua du lieu ma tran
//   void change();
//===========================================================================
//28
//gan ma tran
   matrix & operator=(const matrix&matrix1);
//29
   //so sanh ma tran
   friend int NUMMETHODTOOLS_EXT_CLASS operator==(const matrix&matrix1,const matrix&matrix2);
//===========================================================================
   //phep lay kich thuoc matrix
//30
   friend int NUMMETHODTOOLS_EXT_CLASS GetCol(const matrix&matrix1);//=sizecol
//31
   friend int NUMMETHODTOOLS_EXT_CLASS GetRow(const matrix&matrix1);//=sizerow
//32
//   matrix operator-();
   matrix operator-(const matrix&matrix1);
//===========================================================================
//Tinh cac chuan cua matran
//33
   friend double NUMMETHODTOOLS_EXT_CLASS StandardCollum(const matrix & m1);
   //tinh chuan cot
//34
   friend double NUMMETHODTOOLS_EXT_CLASS StandardRow(const matrix & m1);
   //tinh chuan hang
//35
   friend double NUMMETHODTOOLS_EXT_CLASS StandardEuclide(const matrix & m1);
   //tinh chuan Euclide
//36
   friend void NUMMETHODTOOLS_EXT_CLASS SetMember(matrix & mt,const int& i,const int& j, const double & d);//=sizerow
//37
//   void setdata(const int& i,const int& j,const double& d);
//38
	friend double NUMMETHODTOOLS_EXT_CLASS StandardMax(const matrix & m);
	//Tinh chuan cuc dai
//39
	friend void NUMMETHODTOOLS_EXT_CLASS SwapCol(matrix & m,const int & i,const int&j);
	//Hoan vi 2 cot
//40
	friend void NUMMETHODTOOLS_EXT_CLASS SwapRow(matrix & m,const int & i,const int&j);
	//Hoan vi 2 hang
//41
	friend int NUMMETHODTOOLS_EXT_CLASS GetMaxInCol(const matrix &m,const int& i);
	//lay vi tri phan tu lon nhat trong cot thu i
//42
	friend int NUMMETHODTOOLS_EXT_CLASS GetMaxInRow(const matrix &m,const int& i);
	//lay vi tri phan tu lon nhat trong hang thu i
//43
	friend int NUMMETHODTOOLS_EXT_CLASS GetAbsMaxInCol(const matrix &m,const int& i);
	//lay vi tri phan tu lon nhat trong cot thu i
//44
	friend int NUMMETHODTOOLS_EXT_CLASS GetAbsMaxInRow(const matrix &m,const int& i);
	//lay vi tri phan tu lon nhat trong hang thu i
//45
	void SetSize(const int & m,const int & n);
	//Dat kich thuoc ma tran
//46
   friend matrix NUMMETHODTOOLS_EXT_CLASS Transpose(const matrix & matrix1);//chuyen vi
};
//***************************************************************************
//***************************************************************************
//CLASS SQUARE MATRIX
//***************************************************************************
//***************************************************************************
class NUMMETHODTOOLS_EXT_CLASS smatrix : public matrix
{
private: int size;
public:
//1
   smatrix();
   ~smatrix();
//2
   smatrix(const int & m);
//3
   smatrix(const smatrix & smatrix1);
//4
   smatrix(const matrix & ma1);
//5--phep phan tich LU------------------
   friend matrix NUMMETHODTOOLS_EXT_CLASS LU(const smatrix & m1,int & boolRes);
   //neu thanh cong ham cho boolRes=0 nguoc lai cho boolRes=-1
   //Cho ma tran U la ma tran tam giac tren (tren duong cheo chinh)
   //Cho ma tran L la ma tran tam giac duoi (duoi duong cheo chinh) voi cac phan tu tren duong cheo chinh = 1
//6--phep tinh dinh thuc-----------------
   friend double NUMMETHODTOOLS_EXT_CLASS det(const smatrix & m1,int& boolRes);
   //neu thanh cong ham cho bool=0 nguoc lai cho bool=-1
//7--phep tinh matran nghich dao---------
   friend smatrix NUMMETHODTOOLS_EXT_CLASS inverse(const smatrix & m1,int & boolRes);
	 //neu thanh cong ham cho bool=0 nguoc lai cho bool=-1
//8--phep lay kich thuoc ma tran
   friend int NUMMETHODTOOLS_EXT_CLASS GetSize(const smatrix & m1);
//9
   void SetSize(const int & m);
	//Dat kich thuoc ma tran
//10
   friend void	NUMMETHODTOOLS_EXT_CLASS SetToUnit(smatrix & m);
//11
   friend smatrix NUMMETHODTOOLS_EXT_CLASS NormalizeByCol(const smatrix & m);//chuan hoa cho cac cot : co do dai =1
   friend smatrix NUMMETHODTOOLS_EXT_CLASS NormalizeByRow(const smatrix & m);//chuan hoa cho cac hang : co do dai =1
};

#endif // !defined(AFX_MATRIX_H__3D8A8D71_A1AF_40B0_AE3A_1367156674A3__INCLUDED_)
