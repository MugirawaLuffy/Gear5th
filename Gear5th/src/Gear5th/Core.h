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