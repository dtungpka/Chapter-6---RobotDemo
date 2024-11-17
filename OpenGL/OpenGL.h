#ifndef OPENGLDLL_H
	#define OPENGLDLL_H

#ifndef OPENGL_EXT_CLASS
	#ifdef _OPENGL_DLL
		#define OPENGL_EXT_CLASS _declspec(dllexport)
	#else
		#define OPENGL_EXT_CLASS _declspec(dllimport)
	#endif
#endif  OPENGL_EXT_CLASS

#ifndef OPENGL_TRACE
	#ifdef _DEBUG
		#define OPENGL_TRACE(a) TRACE(a)
	#else 
		#ifdef _OPENGL_TRACE_LOG
			OPENGL_EXT_CLASS extern CStdioFile logerror;
			#define OPENGL_TRACE(a) logerror.WriteString(a)
		#else
			#define OPENGL_TRACE(a) 
		#endif
	#endif
#endif OPENGL_TRACE


#ifndef _OPENGL_DLL
#ifndef _OPENGL_DLL_LOADED
#define _OPENGL_DLL_LOADED
	#ifdef _WIN64 //_M_X64
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGL7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGL7ud.lib")
				#else
					#pragma message("     _Adding library: OPENGL7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGL7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGL7u.lib")
				#else
					#pragma message("     _Adding library: OPENGL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGL7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLud.lib")
				#else
					#pragma message("     _Adding library: OPENGLd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../x64/Debug\\OPENGLd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../x64/Release\\OPENGLu.lib")
				#else
					#pragma message("     _Adding library: OPENGLu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../x64/Release\\OPENGL.lib")
				#endif
			#endif
		#endif
	#else
		#ifdef _MFC_7
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGL7ud.lib: MFC7.0, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGL7ud.lib")
				#else
					#pragma message("     _Adding library: OPENGL7d.lib: MFC7.0, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGL7d.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGL7u.lib")
				#else
					#pragma message("     _Adding library: OPENGL7u.lib: MFC7.0, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGL7.lib")
				#endif
			#endif
		#else
			#ifdef _DEBUG
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLud.lib: MFC4.2, Debug, UNICODE" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLud.lib")
				#else
					#pragma message("     _Adding library: OPENGLd.lib: MFC4.2, Debug, MBCS" ) 
					#pragma comment(lib, "../Win32/Debug\\OPENGLd.lib")
				#endif
			#else
				#ifdef _UNICODE
					#pragma message("     _Adding library: OPENGLu.lib: MFC4.2, Release, UNICODE" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGLu.lib")
				#else
					#pragma message("     _Adding library: OPENGLu.lib: MFC4.2, Release, MBCS" ) 
					#pragma comment(lib, "../Win32/Release\\OPENGL.lib")
				#endif
			#endif
		#endif
	#endif _WIN64
#endif  _OPENGL_DLL_LOADED
#endif  _OPENGL_DLL

#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
			
//#include <gl/glAux.h>
#include <gl/gl.h>
#include <gl/glu.h>

//#include <afxtempl.h>
//#include <assert.h>
			
#pragma comment (lib, "legacy_stdio_definitions.lib")

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")

#include "OpenGLCtrl.h"
//#include "DrawShell.h"
//#include "Nurbs.h"
#include "STLfile.h"

#endif OPENGLDLL_H