#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cider
{
	class CIDER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Core log macros
#define CD_CORE_ERROR(...)	::Cider::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CD_CORE_WARN(...)	::Cider::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CD_CORE_INFO(...)	::Cider::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CD_CORE_TRACE(...)	::Cider::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CD_CORE_FATAL(...)	::Cider::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CD_ENT_ERROR(...)	::Cider::Log::GetClientLogger()->error(__VA_ARGS__)
#define CD_WARN(...)		::Cider::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CD_INFO(...)		::Cider::Log::GetClientLogger()->info(__VA_ARGS__)
#define CD_TRACE(...)		::Cider::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CD_FATAL(...)		::Cider::Log::GetClientLogger()->fatal(__VA_ARGS__)

