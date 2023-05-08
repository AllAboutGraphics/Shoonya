#pragma once

#ifdef SH_PLATFORM_WINDOWS
	#ifdef SH_BUILD_DLL
		#define SHOONYA_API __declspec(dllexport)
	#else
		#define SHOONYA_API __declspec(dllimport)
	#endif // SH_BUILD_DLL

#else
	#error Shoonya supports only WINDOWS as of now!
#endif

//#define BIT(x) (1 << x)