#ifndef __APPLICATIONFONT_H__
#define __APPLICATIONFONT_H__

// ApplicationFont.h : main header file for the SETFONTCOLOR application
//


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


class TOOLINTER_EXT_CLASS TApplicationFont;

BOOL  TOOLINTER_EXT_CLASS __stdcall SetChildFont(HWND hwnd, LPARAM lparam);
BOOL TOOLINTER_EXT_CLASS SetWindowFont(HWND hWndParent);
void TOOLINTER_EXT_CLASS SetWindowFontFace(const CString & fontname);

CString TOOLINTER_EXT_CLASS GetWindowFontFace();
//TApplicationFont* TOOLINTER_EXT_CLASS GetTAppFont();
void TOOLINTER_EXT_CLASS GetTAppFont(TApplicationFont* pTAppFont);

//=============================================================================
//
//
//=============================================================================

class TOOLINTER_EXT_CLASS TApplicationFont : public CObject 
{
private:
  CString m_strFaceName;
  int m_nFontSize;
  int m_nPointSize;
  CFont m_Font;

private:
  void createFont(void);

public:
  TApplicationFont(LPCTSTR szFaceName);
  virtual ~TApplicationFont();

  CFont *GetFont(void);
  CString& GetFaceName(void);
  int GetFontSize(void);
  int GetPointSize(void);
  
  void SetFaceName(LPCTSTR szFaceName);
};

extern TApplicationFont g_Font;

#endif //__APPLICATIONFONT_H__
