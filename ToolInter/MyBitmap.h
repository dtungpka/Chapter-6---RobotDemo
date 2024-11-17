// MyBitmap.h: interface for the CMyBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBITMAP_H__5454C658_D097_11D7_93E2_DCD47BCB397E__INCLUDED_)
#define AFX_MYBITMAP_H__5454C658_D097_11D7_93E2_DCD47BCB397E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TOOLINTER_EXT_CLASS CMyBitmap  
{
public:
	CBitmap m_bmpBitmap;	
	HBITMAP GetHBitmap();

	enum	{
				BKDLGST_MODE_TILE = 0,
				BKDLGST_MODE_CENTER,
				BKDLGST_MODE_STRETCH,
				BKDLGST_MODE_TILETOP,
				BKDLGST_MODE_TILEBOTTOM,
				BKDLGST_MODE_TILELEFT,
				BKDLGST_MODE_TILERIGHT,
				BKDLGST_MODE_TOPLEFT,
				BKDLGST_MODE_TOPRIGHT,
				BKDLGST_MODE_TOPCENTER,
				BKDLGST_MODE_BOTTOMLEFT,
				BKDLGST_MODE_BOTTOMRIGHT,
				BKDLGST_MODE_BOTTOMCENTER,
				BKDLGST_MAX_MODES
			};

	int GetWidth();
	int GetHeight();

	void DrawModeDirect(CDC * pDC,const CRect & rWnd, const BYTE & mode,const UINT & style=SRCCOPY);
	void DrawMode(CDC * pDC,const CRect & rWnd, const BYTE & mode,const UINT & style=SRCCOPY);

	bool SetBitmap(HBITMAP hbitmap);
	bool LoadBmpFile(const CString & fname,const bool & reset=false);
	bool LoadResource(const UINT & id,const bool & reset=false);

	void Draw(CDC * pDC,const CRect & r,const UINT & style=SRCCOPY);

	CMyBitmap();
	virtual ~CMyBitmap();
};

#endif // !defined(AFX_MYBITMAP_H__5454C658_D097_11D7_93E2_DCD47BCB397E__INCLUDED_)
