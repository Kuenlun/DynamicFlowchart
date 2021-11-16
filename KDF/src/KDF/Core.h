#pragma once

#ifdef KDF_PLATFORM_WINDOWS

#else
	#error KDF only supports Windows
#endif

#ifdef KDF_DEBUG
	#define KDF_ENABLE_ASSERTS
#endif


#ifdef KDF_ENABLE_ASSERTS
	#define KDF_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KDF_CORE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KDF_ASSERT(x, ...)
	#define KDF_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define KDF_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)