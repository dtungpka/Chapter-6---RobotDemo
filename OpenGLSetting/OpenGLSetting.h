#ifndef OPENGLSETTINGDLL_H
	#define OPENGLSETTINGDLL_H

#ifndef OPENGLSETTING_EXT_CLASS
	#ifdef _OPENGLSETTING_DLL
		#define OPENGLSETTING_EXT_CLASS _declspec(dllexport)
	#else
		#define OPENGLSETTING_EXT_CLASS _declspec(dllimport)
	#endif
#endif  OPENGLSETTING_EXT_CLASS

#ifndef OPENGLSETTING_TRACE
	#ifdef _DEBUG
		#define OPENGLSETTING_TRACE(a) TRACE(a)
	#else 
		#ifdef _OPENGLSETTING_TRACE_LOG
			OPENGLSETTING_EXT_CLASS extern CStdioFile logerror;
			#define OPENGLSETTING_TRACE(a) logerror.WriteString(a)
		#else
			#define OPENGLSETTING_TRACE(a) 
		#endif
	#endif
#endif OPENGLSETTING_TRACE


#ifndef _OPENGLSETTING_DLL
#ifndef _OPENGLSETTING_DLL_LOADED
#define _OPENGLSETTING_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTING7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLSETTING7ud.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTING7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLSETTING7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTING7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGLSETTING7u.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTING7.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGLSETTING7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTINGud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLSETTINGud.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTINGd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLSETTINGd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTINGu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGLSETTINGu.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTINGu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGLSETTING.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTING7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLSETTING7ud.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTING7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLSETTING7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTING7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGLSETTING7u.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTING7.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGLSETTING7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTINGud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLSETTINGud.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTINGd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLSETTINGd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLSETTINGu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGLSETTINGu.lib")
				#else
					#pragma message("     _Adding library: OPENGLSETTINGu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGLSETTING.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _OPENGLSETTING_DLL_LOADED
#endif  _OPENGLSETTING_DLL

#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
		
#include <gl/gl.h>
#pragma comment(lib, "opengl32.lib")

/*
#include <gl/glAux.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
*/

#include "Resource.h"
#include "DlgSettingLight.h"
#include "DlgSettingMaterial.h"
#include "DlgSettingMaterialMultiObject.h"

#endif OPENGLSETTINGDLL_H