#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Gear5th
{
	class GEAR5TH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//MACROS for logging Engine messages
#define G5_CORE_TRACE(...)	::Gear5th::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define G5_CORE_INFO(...)	::Gear5th::Log::GetCoreLogger()->info(__VA_ARGS__)
#define G5_CORE_WARN(...)	::Gear5th::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define G5_CORE_ERROR(...)	::Gear5th::Log::GetCoreLogger()->error(__VA_ARGS__)
#define G5_CORE_FATAL(...)	::Gear5th::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//MACROS for logging Client sided messages
#define G5_TRACE(...)		::Gear5th::Log::GetClientLogger()->trace(__VA_ARGS__)
#define G5_INFO(...)		::Gear5th::Log::GetClientLogger()->info(__VA_ARGS__)
#define G5_WARN(...)		::Gear5th::Log::GetClientLogger()->warn(__VA_ARGS__)
#define G5_ERROR(...)		::Gear5th::Log::GetClientLogger()->error(__VA_ARGS__)
#define G5_FATAL(...)		::Gear5th::Log::GetClientLogger()->fatal(__VA_ARGS__)