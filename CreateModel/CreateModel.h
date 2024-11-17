#ifndef CREATEMODELDLL_H
	#define CREATEMODELDLL_H

#ifndef CREATEMODEL_EXT_CLASS
	#ifdef _CREATEMODEL_DLL
		#define CREATEMODEL_EXT_CLASS _declspec(dllexport)
	#else
		#define CREATEMODEL_EXT_CLASS _declspec(dllimport)
	#endif
#endif  CREATEMODEL_EXT_CLASS

#ifndef CREATEMODEL_TRACE
	#ifdef _DEBUG
		#define CREATEMODEL_TRACE(a) TRACE(a)
	#else 
		#ifdef _CREATEMODEL_TRACE_LOG
			CREATEMODEL_EXT_CLASS extern CStdioFile logerror;
			#define CREATEMODEL_TRACE(a) logerror.WriteString(a)
		#else
			#define CREATEMODEL_TRACE(a) 
		#endif
	#endif
#endif CREATEMODEL_TRACE


#ifndef _CREATEMODEL_DLL
#ifndef _CREATEMODEL_DLL_LOADED
#define _CREATEMODEL_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODEL7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\CREATEMODEL7ud.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\CREATEMODEL7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODEL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\CREATEMODEL7u.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL7.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\CREATEMODEL7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODELud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\CREATEMODELud.lib")
				#else
					#pragma message("     _Adding library: CREATEMODELd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\CREATEMODELd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODELu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\CREATEMODELu.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\CREATEMODEL.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODEL7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\CREATEMODEL7ud.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\CREATEMODEL7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODEL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\CREATEMODEL7u.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL7.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\CREATEMODEL7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODELud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\CREATEMODELud.lib")
				#else
					#pragma message("     _Adding library: CREATEMODELd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\CREATEMODELd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: CREATEMODELu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\CREATEMODELu.lib")
				#else
					#pragma message("     _Adding library: CREATEMODEL.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\CREATEMODEL.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _CREATEMODEL_DLL_LOADED
#endif  _CREATEMODEL_DLL

#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
		
#include <gl/gl.h>
#pragma comment(lib, "opengl32.lib")

/*
#include <gl/glu.h>
#include <gl/glAux.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
*/

#include "NewType.h"
#include "MathLib.h"
#include "DataCreate.h"
#include "CreateTools.h"

#endif CREATEMODELDLL_H