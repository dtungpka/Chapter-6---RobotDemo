// SetAttGrid.h: interface for the SetAttGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETATTGRID_H__39DD1C87_BA24_11D7_96EB_EE5EA21FAA74__INCLUDED_)
#define AFX_SETATTGRID_H__39DD1C87_BA24_11D7_96EB_EE5EA21FAA74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

void GRIDCONTROL_EXT_CLASS SetItemTextBold(CGridCtrl & m_grid,const int &row, const int &col);
void GRIDCONTROL_EXT_CLASS SetItemAlign(CGridCtrl & m_grid,const int &row, const int &col, const DWORD &align);
void GRIDCONTROL_EXT_CLASS SetItemTextColor(CGridCtrl & m_grid,const int & row,const int & col,COLORREF clrtext,COLORREF clr);
void GRIDCONTROL_EXT_CLASS SetItemTextColor(CGridCtrl & m_grid,const int & row,const int & col,COLORREF clrtext);
void GRIDCONTROL_EXT_CLASS SetFontGrid(CGridCtrl & m_grid,LOGFONT & lf);

#endif // !defined(AFX_SETATTGRID_H__39DD1C87_BA24_11D7_96EB_EE5EA21FAA74__INCLUDED_)
