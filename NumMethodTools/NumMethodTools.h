#ifndef NUMMETHODTOOLSDLL_H
	#define NUMMETHODTOOLSDLL_H
/*
#ifndef _NUMMETHODTOOLS_DLL
	#define _NUMMETHODTOOLS_DLL
#endif _NUMMETHODTOOLS_DLL
*/
#ifndef NUMMETHODTOOLS_EXT_CLASS
	#ifdef _NUMMETHODTOOLS_DLL
		#define NUMMETHODTOOLS_EXT_CLASS _declspec(dllexport)
	#else
		#define NUMMETHODTOOLS_EXT_CLASS _declspec(dllimport)
	#endif
#endif  NUMMETHODTOOLS_EXT_CLASS

#ifndef NUMMETHODTOOLS_TRACE
	#ifdef _DEBUG
		#define NUMMETHODTOOLS_TRACE(a) TRACE(a)
	#else 
		#ifdef _NUMMETHODTOOLS_TRACE_LOG
			NUMMETHODTOOLS_EXT_CLASS extern CStdioFile logerror;
			#define NUMMETHODTOOLS_TRACE(a) logerror.WriteString(a)
		#else
			#define NUMMETHODTOOLS_TRACE(a) 
		#endif
	#endif
#endif NUMMETHODTOOLS_TRACE

//NumMethodTools
#ifndef _NUMMETHODTOOLS_DLL
#ifndef _NUMMETHODTOOLS_DLL_LOADED
#define _NUMMETHODTOOLS_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodTools7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\NumMethodTools7ud.lib")
				#else
					#pragma message("     _Adding library: NumMethodTools7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\NumMethodTools7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodTools7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\NumMethodTools7u.lib")
				#else
					#pragma message("     _Adding library: NumMethodTools7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\NumMethodTools7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodToolsud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\NumMethodToolsud.lib")
				#else
					#pragma message("     _Adding library: NumMethodToolsd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\NumMethodToolsd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodToolsu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\NumMethodToolsu.lib")
				#else
					#pragma message("     _Adding library: NumMethodToolsu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../x64/Release\\NumMethodTools.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodTools7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\NumMethodTools7ud.lib")
				#else
					#pragma message("     _Adding library: NumMethodTools7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\NumMethodTools7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodTools7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\NumMethodTools7u.lib")
				#else
					#pragma message("     _Adding library: NumMethodTools7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\NumMethodTools7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodToolsud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\NumMethodToolsud.lib")
				#else
					#pragma message("     _Adding library: NumMethodToolsd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\NumMethodToolsd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: NumMethodToolsu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\NumMethodToolsu.lib")
				#else
					#pragma message("     _Adding library: NumMethodToolsu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../Win32/Release\\NumMethodTools.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _NUMMETHODTOOLS_DLL_LOADED
#endif  _NUMMETHODTOOLS_DLL

#include "resource.h"

#include "MConvert.h"
#include "MathLib.h"
#include "matrix.h"
#include "point.h"
#include "vector.h"
#include "point2d.h"

#include "point3d.h"
#include "line.h"
#include "affine2d.h"
#include "affine3d.h"
#include "Sproject.h"

#include "ModulNumMethod.h"

//Expression
#include "ValueType.h"
#include "Expression.h"

#endif NUMMETHODTOOLSDLL_H