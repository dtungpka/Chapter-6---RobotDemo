// MyWinApp.h: interface for the CMyWinApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWINAPP_H__E0E34CE1_F058_11D7_93E2_9FDC6E9EE10A__INCLUDED_)
#define AFX_MYWINAPP_H__E0E34CE1_F058_11D7_93E2_9FDC6E9EE10A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TOOLINTER_EXT_CLASS CMyWinApp : public CWinApp
{
	CString m_sAppLocation;

	void GetLocation();

public:
	bool LoadFont(const CString & fname);
	bool LoadVietnamFont();

	CString GetAppLocation();
	
	CMyWinApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyWinApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_MYWINAPP_H__E0E34CE1_F058_11D7_93E2_9FDC6E9EE10A__INCLUDED_)
