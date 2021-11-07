#pragma once

#ifdef KDF_PLATFORM_WINDOWS
	#ifdef KDF_BUILD_DLL
		#define KDF_API __declspec(dllexport)
	#else
		#define KDF_API __declspec(dllimport)
	#endif
#else
	#error KDF only supports Windows
#endif

#define BIT(x) (1 << x)