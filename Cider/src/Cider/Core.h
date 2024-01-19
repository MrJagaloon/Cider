#pragma once

#ifdef CD_PLATFORM_WINDOWS
	#ifdef CD_BUILD_DLL
		#define CIDER_API __declspec(dllexport)
	#else
		#define CIDER_API __declspec(dllimport)
	#endif
#else
	#error Cider only supports Windows!
#endif

#ifdef CD_ENABLE_ASSERTS
    #define CD_ASSERT(x, ...) { if (!(x)) { CD_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();} }
    #define CD_CORE_ASSERT(x, ...) { if (!(x)) { CD_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
    #define CD_ASSERT(x, ...) 
    #define CD_CORE_ASSERT(x, ...)
#endif

