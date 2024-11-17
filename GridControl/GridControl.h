#ifndef GRIDCONTROLDLL_H
	#define GRIDCONTROLDLL_H

//#ifndef _GRIDCONTROL_DLL
//	#define _GRIDCONTROL_DLL
//#endif _GRIDCONTROL_DLL

#ifndef GRIDCONTROL_EXT_CLASS
	#ifdef _GRIDCONTROL_DLL
		#define GRIDCONTROL_EXT_CLASS _declspec(dllexport)
	#else
		#define GRIDCONTROL_EXT_CLASS _declspec(dllimport)
	#endif
#endif  GRIDCONTROL_EXT_CLASS

#ifndef GRIDCONTROL_TRACE
	#ifdef _DEBUG
		#define GRIDCONTROL_TRACE(a) TRACE(a)
	#else 
		#ifdef _GRIDCONTROL_TRACE_LOG
			GRIDCONTROL_EXT_CLASS extern CStdioFile logerror;
			#define GRIDCONTROL_TRACE(a) logerror.WriteString(a)
		#else
			#define GRIDCONTROL_TRACE(a) 
		#endif
	#endif
#endif GRIDCONTROL_TRACE


#ifndef _GRIDCONTROL_DLL
#ifndef _GRIDCONTROL_DLL_LOADED
#define _GRIDCONTROL_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControl7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\GridControl7ud.lib")
				#else
					#pragma message("     _Adding library: GridControl7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\GridControl7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControl7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\GridControl7u.lib")
				#else
					#pragma message("     _Adding library: GridControl7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\GridControl7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControlud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\GridControlud.lib")
				#else
					#pragma message("     _Adding library: GridControld.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\GridControld.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControlu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\GridControlu.lib")
				#else
					#pragma message("     _Adding library: GridControlu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../x64/Release\\GridControl.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControl7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\GridControl7ud.lib")
				#else
					#pragma message("     _Adding library: GridControl7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\GridControl7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControl7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\GridControl7u.lib")
				#else
					#pragma message("     _Adding library: GridControl7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\GridControl7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControlud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\GridControlud.lib")
				#else
					#pragma message("     _Adding library: GridControld.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\GridControld.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: GridControlu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\GridControlu.lib")
				#else
					#pragma message("     _Adding library: GridControlu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../Win32/Release\\GridControl.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _GRIDCONTROL_DLL_LOADED
#endif  _GRIDCONTROL_DLL

#pragma warning(disable : 4518)     // applicationfont

#include "CellRange.h"
#include "GridCell.h"
#include "GridCellBase.h"
#include "GridDropTarget.h"
#include "InPlaceEdit.h"
//#include "MemDC.h"
#include "TitleTip.h"
#include "GridCtrl.h"
#include "GridCellCheck.h"
#include "GridCellCombo.h"

#include "SetAttGrid.h"

#endif GRIDCONTROLDLL_H