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

#ifdef LZE_ENABLE_ASSERTS
    #define LZE_ASSERT(condition, ...) { if(!(condition)) { LZE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define LZE_CORE_ASSERT(condition, ...) { if(!(condition)) { LZE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define LZE_ASSERT(condition, ...)
    #define LZE_CORE_ASSERT(condition, ...)
#endif

#define BIT(x) (1 << x)