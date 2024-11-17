
// Express.h : main header file for the FUNCTION application
//
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include "ValueType.h"

#include <map>

#define DIVISION_BY_0 1
#define ILEGAL_OPERATION 2
#define UNDEFINED_VARIABLE 3
#define INVALID_DOMAIN 4

//typedef CTypedPtrMap<CMapStringToOb,CString,Value *> VariableMap;

typedef std::map<CString,ValueType *> VariableMap;

/////////////////////////////////////////////////////////////////////////////
#ifdef USE_MFC
class NUMMETHODTOOLS_EXT_CLASS Expression : public CObject  
#else
class NUMMETHODTOOLS_EXT_CLASS Expression
#endif USE_MFC
{
	
public:
#ifdef USE_MFC
	DECLARE_SERIAL(Expression);
#endif USE_MFC
	
	Expression();	//Constructor
	Expression(VariableMap * pVarMap);
	virtual ~Expression();	//Destructor
	
	Expression operator+(const Expression & expresstion);
	Expression operator-(const Expression & expresstion);
	Expression operator*(const Expression & expresstion);
	Expression operator/(const Expression & expresstion);
	
	Expression &operator=(Expression& expr);	 
	void AttachVariables(VariableMap *pVarMap);	//The table manages unknowns that you define
	Expression(Expression & expression);
	int Differ(Expression & expression, CString var, int cut); // Differentiate follow a variable
	int T_Differ(Expression & expression, CString *var, int sumvar, int cut); // Differentiate follow some variable and the time
	CString GetExpression() const;	// Return expression string
	
	struct node 
	{
		struct node *Left,*Right;
		unsigned char Operator; 
		double ValueNum;
		CString ValueStr;
	} ;
	
	typedef node NODE;
	typedef node* Tree;
	
	BOOL HaveVar(Tree tr);		// Return TRUE if expression have variables and parameters
	Tree CopyTree(void);		// Copy the expression binary tree
	int UpdateTree(void);		// Update the tree
	Tree GetTree();				// Get the expression binary tree
	int GetValue(double & value);	// Gets the value of the expression
	
	int ChangeExpression(CString& sExpression);	// Change sExpression
private:
	void Split(CString Eqt, CStringArray & array); //Cut expression to smaller expressions
	int MergeMul(CStringArray & mul, CStringArray & div, double & hst, double & hsd);	//Merge small expressions to multiplication expression
	void Sort(CStringArray & array, BOOL Mul=TRUE);	// Sort follow A-Z
	unsigned long number(CString st);	
	unsigned long count(Tree tr);
	void Simple(CString & Eqt);		// Simple expression
	BOOL evar(CString *var, CString v, int sumvar);	//Server for differentiate follow the time
	BOOL find(Tree tr, CString var);	//	Find the variable that it is equal var in expression bianry tree
	BOOL T_find(Tree tr, CString *var,int sumvar);	//Find variables that they are equal *var in expression binary tree
	BOOL compare(Tree tr1, Tree tr2); //Compare between two expression binary trees tr1 and tr2 
	void compact(CString & eStr);	// Reduce expression eStr
	CString ftoa(double so);		// Convert double to string
	Tree differ(Tree tr, CString var);
	Tree T_differ(Tree tr,CString *var,int sumvar);
	Tree Create1(Tree Tree1, Tree Tree2);
	unsigned char GetIDNum(CString oper);
	Tree MakeNode(CString oper, unsigned char = 0);
	Tree Create2(Tree Tree1, Tree Tree2, Tree Tree3);
	CString GetID(Tree a);
	BOOL Is2(unsigned char oper);
	void SkipSpaces();
	
	VariableMap * m_pVarMap;	// Pointer to value table
	CString m_sExpression;			// The expression in string
	int m_nCurPos;					// String parsing variable
	Tree m_Tree;				// The expresion as a binary tree
	
	double vexp (Tree a);
	Tree factor (void);			// The partial expresion parsing functions
	Tree identification(void);	// Identification of operator or variable
	Tree putere(void);
	Tree termen(void);
	Tree expression(void);		// Build the expression binary tree
	void FreeMem(Tree a);		// Delete the tree that have root is "a"
	Tree copy(Tree tree);		// Copy expression binary tree
	CString ToStr(Tree tr);		
	CString ToString();			// Convert expression binary tree to expression string
	
#ifdef USE_MFC
	virtual void Serialize(CArchive& ar);		// The serialization function
#endif USE_MFC
};


#endif //__EXPRESSION_H__
