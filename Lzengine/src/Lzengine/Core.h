#pragma once

#ifdef LZE_PLATFORM_WINDOWS
	#ifdef LZE_BUILD_DLL
		#define LZE_API __declspec(dllexport)
	#else
		#define LZE_API __declspec(dllimport)
	#endif
#else
	#error Lz Engine only supports Windows for now!
#endif

#define BIT(x) (1 << x)