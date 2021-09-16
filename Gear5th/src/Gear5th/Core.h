#pragma once

#ifdef G5_PLATFORM_WINDOWS
	#ifdef G5_BUILD_DLL
		#define GEAR5TH_API __declspec(dllexport)
	#else
		#define GEAR5TH_API __declspec(dllimport)
	#endif
#else
	#error Gear5th ony supports windows x64
#endif

#ifdef G5_ENABLE_ASSERTS
#define G5_ASSERT(x, ...) { if(!(x)) { G5_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define G5_CORE_ASSERT(x, ...) { if(!(x)) { G5_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define G5_ASSERT(x, ...)
#define G5_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) // generates a bitfield e.g 100101 where each bit belongs to a different event category 
						// this means that an Event byte can carry information about multiple events being assigned
						// to different bits inside one bitfiled