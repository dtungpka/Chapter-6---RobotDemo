#ifndef TOOLINTERDLL_H
	#define TOOLINTERDLL_H

//#ifndef _TOOLINTER_DLL
//	#define _TOOLINTER_DLL
//#endif _TOOLINTER_DLL

#ifndef TOOLINTER_EXT_CLASS
	#ifdef _TOOLINTER_DLL
		#define TOOLINTER_EXT_CLASS _declspec(dllexport)
	#else
		#define TOOLINTER_EXT_CLASS _declspec(dllimport)
	#endif
#endif  TOOLINTER_EXT_CLASS

#ifndef TOOLINTER_TRACE
	#ifdef _DEBUG
		#define TOOLINTER_TRACE(a) TRACE(a)
	#else 
		#ifdef _TOOLINTER_TRACE_LOG
			TOOLINTER_EXT_CLASS extern CStdioFile logerror;
			#define TOOLINTER_TRACE(a) logerror.WriteString(a)
		#else
			#define TOOLINTER_TRACE(a) 
		#endif
	#endif
#endif TOOLINTER_TRACE


#ifndef _TOOLINTER_DLL
#ifndef _TOOLINTER_DLL_LOADED
#define _TOOLINTER_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInter7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\ToolInter7ud.lib")
				#else
					#pragma message("     _Adding library: ToolInter7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\ToolInter7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInter7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\ToolInter7u.lib")
				#else
					#pragma message("     _Adding library: ToolInter7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\ToolInter7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInterud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\ToolInterud.lib")
				#else
					#pragma message("     _Adding library: ToolInterd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\ToolInterd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInteru.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\ToolInteru.lib")
				#else
					#pragma message("     _Adding library: ToolInteru.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../x64/Release\\ToolInter.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInter7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\ToolInter7ud.lib")
				#else
					#pragma message("     _Adding library: ToolInter7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\ToolInter7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInter7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\ToolInter7u.lib")
				#else
					#pragma message("     _Adding library: ToolInter7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\ToolInter7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInterud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\ToolInterud.lib")
				#else
					#pragma message("     _Adding library: ToolInterd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\ToolInterd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: ToolInteru.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\ToolInteru.lib")
				#else
					#pragma message("     _Adding library: ToolInteru.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../Win32/Release\\ToolInter.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _TOOLINTER_DLL_LOADED
#endif  _TOOLINTER_DLL
/*
typedef unsigned long ULONG_PTR;
#include "Other\\GDI_PP\\gdiplus.h"
using namespace Gdiplus; 
*/
#pragma warning(disable : 4518)     // applicationfont

//#include "Expression\\ValueType.h"
//#include "Expression\\Expression.h"

/*
//GridControl ==> GridControl DLL
#include "GridControl\\CellRange.h"
#include "GridControl\\GridCell.h"
#include "GridControl\\GridCellBase.h"
#include "GridControl\\GridDropTarget.h"
#include "GridControl\\InPlaceEdit.h"
#include "GridControl\\MemDC.h"
#include "GridControl\\TitleTip.h"
#include "GridControl\\GridCtrl.h"
#include "GridControl\\GridCellCheck.h"
#include "GridControl\\GridCellCombo.h"

#include "Other\\SetAttGrid.h"
*/


//other
#include "MathLib.h"
#include "Graph.h"
#include "MyBitmap.h"
#include "MyWinApp.h"
#include "ApplicationFont.h"
#include "AutoFont.h"
#include "NewType.h"

//Controls
#include "HyperLink.h"
#include "XTabCtrl.h"

//MyTabCtrl
#include "MyTabCtrl.h"
#include "XPTabCtrl.h"

//CustomTabCtrl ???
//#include "CustomTabCtrl.h"

//CListBoxST
#include "ListBoxST.h"

//ButtonListCtrl
#include "buttonlistctrl.h"

//Splitter
#include "ST_SplitterWnd.h"

//GradientStatic
#include "GradientStatic.h"

//CheckableGroupBox
#include "CheckableGroupBox.h"


//Controls
//#include "NewMenu.h"
//#include "BkDialogST.h"

/*
#include "DialogBar\\sizecbar.h"
#include "DialogBar\\scbarg.h"
#include "DialogBar\\scbarcf.h"
*/

/*
//ButtonCtrls ==> ButtonCtrls DLL
#include "BtnST.h"
#include "ShadeButtonST.h"
#include "xShadeButton.h"
#include "xSkinButton.h"
*/


#endif TOOLINTERDLL_H