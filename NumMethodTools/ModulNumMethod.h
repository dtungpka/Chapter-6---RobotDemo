// Modulpps.h: interface for the Modulpps class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULPPS_H__6EBA035D_4505_4E62_A521_9B67A114FBF4__INCLUDED_)
#define AFX_MODULPPS_H__6EBA035D_4505_4E62_A521_9B67A114FBF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "matrix.h"
#include "vector.h"

#ifndef MaxReal
#define MaxReal		1.6e35
#endif MaxReal
#ifndef MinReal
#define MinReal		-1.6e35
#endif MinReal
#ifndef LocalZero
#define LocalZero	1.0e-30
#endif LocalZero

//////////////////////////////////////////////////////////////////////////
int NUMMETHODTOOLS_EXT_CLASS Gauss_Jordan(const matrix & a,const vectorm & f,vectorm & x);
//Giai he ft dai so tuyen tinh bang phuong phap Gauss_Jordan
//Tru xoay trong hang (hoan vi cot)
//a : matran he so
//f : vector ve phai
//x : vector chua ket qua
//Neu thanh cong ham tra lai 0 nguoc lai ham cho -1
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS linear(const smatrix & m1,const vectorm & f,vectorm & x);
//Giai he ft dai so tuyen tinh bang phuong phap su dung phan tich LU
//Tru xoay trong hang (hoan vi cot)
//a : matran he so
//f : vector ve phai
//x : vector chua ket qua
//Neu thanh cong ham tra lai 0 nguoc lai ham cho -1
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS Jacobi(const smatrix& a,const vectorm & b,vectorm & x,const double & eps=1e-10,const int & Max=100);
//giai he phuong trinh dai so tuyen tinh bang phuong phap lap Jacobi
//x : chua xap xi dau dong thoi se chua ket qua ra
//a : ma tran he so
//b : vector ve phai
//eps:do chinh xac can dat
//Max:so lan lap toi da cho phep
//Neu do chinh xac thoa man ham tra ve gia tri = 0
//Neu so lan lap toi da thoa man ham tra ve gia tri = -1
//Ham tra lai -2 neu dieu kien hoi tu khong duoc thoa man
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS Gauss_Seidel(const smatrix& a,const vectorm & b,vectorm & x,const double & eps=1e-10,const int & Max=100);
//giai he phuong trinh dai so tuyen tinh bang phuong phap lap Gauss_Seidel
//x : chua xap xi dau dong thoi se chua ket qua ra
//a : ma tran he so
//b : vector ve phai
//eps:do chinh xac can dat
//Max:so lan lap toi da cho phep
//Neu do chinh xac thoa man ham tra ve gia tri = 0
//Neu so lan lap toi da thoa man ham tra ve gia tri = -1
//Ham tra lai -2 neu dieu kien hoi tu khong duoc thoa man
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS InverseByLinear(const smatrix & m1,smatrix & m2);
//Tinh nghich dao cua ma tran bang cach giai he phuong trinh dai so tuyen tinh
//voi phuong phap su dung phan tich LU
//m1 : la ma tran ban dau
//m2 : la ma tran nghich dao cua m1
//ham tra lai 0 neu thanh cong
// "   "   " -1 neu khong thanh cong
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS InverseByJacobi(const smatrix & m1,smatrix & m2);
//Tinh nghich dao cua ma tran bang cach giai he phuong trinh dai so tuyen tinh
//voi phuong phap Jacobi
//m1 : la ma tran ban dau
//m2 : la ma tran nghich dao cua m1
//ham tra lai 0 neu thanh cong
// "   "   " -1 neu khong thanh cong
// "   "   " -2 neu dieu kien hoi tu khong duoc thoa man
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS InverseByGaussSeidel(const smatrix & m1,smatrix & m2);
//Tinh nghich dao cua ma tran bang cach giai he phuong trinh dai so tuyen tinh
//voi phuong phap GaussSeidel
//m1 : la ma tran ban dau
//m2 : la ma tran nghich dao cua m1
//ham tra lai 0 neu thanh cong
// "   "   " -1 neu khong thanh cong
// "   "   " -2 neu dieu kien hoi tu khong duoc thoa man
//////////////////////////////////////////////////////////////////////////

int NUMMETHODTOOLS_EXT_CLASS InverseByGaussJordan(const smatrix & m1,smatrix & m2);
//Tinh nghich dao cua ma tran bang cach giai he phuong trinh dai so tuyen tinh
//voi phuong phap GaussJordan
//m1 : la ma tran ban dau
//m2 : la ma tran nghich dao cua m1
//ham tra lai 0 neu thanh cong
// "   "   " -1 neu khong thanh cong
//////////////////////////////////////////////////////////////////////////
typedef void functionNR(smatrix & a,vectorm & c,const vectorm & x);

int NUMMETHODTOOLS_EXT_CLASS Newton_Raphson(vectorm & x,functionNR & func,const double & eps=1e-10,const int& Max=100);
//Giai he phuong trinh phi tuyen bang phuong Newton_Raphson
//x : vector chua sap xi dau va se chua ket qua ra
//eps:do chinh xac can dat
//Max:so lan lap toi da cho phep
//Ham tra lai 0 neu thanh cong; nguoc lai ham cho -1
// Buoc 1 : F(x)*X=-f(x)
//Chu y : de su dung ham truoc het phai tao ham Func(Smatrix & A,vector & c,vector & x);
/*
void Func(smatrix & a,vectorm & c,const vectorm & x)
{
	a(0,0)=5.0; a(0,1)=6.0; a(0,2)=3.0;
	a(1,0)=1.0; a(1,1)=1.0; a(1,2)=1.0;
	a(2,0)=2.0; a(2,1)=7.0; a(2,2)=0.5;
	c[0]=(5.0*x[0]+6.0*x[1]+3.0*x[2]-26.0);
	c[1]=(x[0]+x[1]+x[2]-6.0);
	c[2]=(2.0*x[0]+7.0*x[1]+0.5*x[2]-17.5);
//Ket qua nghiem cua phuong trinh nay la :
// x[0]=1;
// x[1]=2;
// x[3]=3;
}
*/
//	  ham se tao matran Jacobi dat vao  matran a,
//	  vector c chua vector f(x)
//	  vector x chua X (la vector dau vao)

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
smatrix NUMMETHODTOOLS_EXT_CLASS Cholesky(const smatrix & m);
//Phan tich ma tran doi xung m thanh ma tran tam giac duoi
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//Tim tri rieng va vector rieng
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int NUMMETHODTOOLS_EXT_CLASS ValueByInverseIteration(const smatrix & m, vectorm & tr, smatrix & R,const double & eps=1e-10,const int & Max=100);
//Tim tri rieng va vector rieng cua phuong trinh : m.x=ld.x bang phuong phap lap nguoc
//ld la cac tri rieng
//tr : vector chua cac tri rieng
// R : chua cac vector rieng

int NUMMETHODTOOLS_EXT_CLASS ValueByJacobi(const smatrix & m, vectorm & tr, smatrix & R,const double & eps=1e-10,const int & Max=100);
//Tim tri rieng va vector rieng cua phuong trinh : m.x=ld.x
//ld la cac tri rieng
//tr : vector chua cac tri rieng
// R : chua cac vector rieng

//==============================================================================================
int NUMMETHODTOOLS_EXT_CLASS ValueByInverseIteration(const smatrix & M, const smatrix & K, vectorm & tr, smatrix & R,const double & eps=1e-10,const int & Max=100);
//Tim tri rieng va vector rieng cua phuong trinh : M.x: + K.x = 0 bang phuong phap lap nguoc
//tuc la cac tan so dao dong rieng va cac dang rieng ung voi cac tan so dao dong rieng
// M : ma tran khoi luong
// K : ma tran do cung
// tr : vector chua cac tan so dao dong rieng
// R : chua cac dang rieng cua dao dong

int NUMMETHODTOOLS_EXT_CLASS ValueByJacobi(const smatrix & M, const smatrix & K, vectorm & tr, smatrix & R,const double & eps=1e-10,const int & Max=100);
//Tim tri rieng va vector rieng cua phuong trinh : M.x: + K.x = 0
//tuc la cac tan so dao dong rieng va cac dang rieng ung voi cac tan so dao dong rieng
// M : ma tran khoi luong
// K : ma tran do cung
// tr : vector chua cac tan so dao dong rieng
// R : chua cac dang rieng cua dao dong

#endif // !defined(AFX_MODULPPS_H__6EBA035D_4505_4E62_A521_9B67A114FBF4__INCLUDED_)
