#pragma once

#ifdef NZ_PLATFORM_WINDOWS
	#ifdef NZ_BUILD_DLL
		#define NOZES_API __declspec(dllexport)
	#else
		#define NOZES_API __declspec(dllimport)
	#endif // NZ_BUILD_DLL
#else
	#error Nozes supports only windows by now
#endif // NZ_PLATFORM_WINDOWS
