#pragma once

#include "memory"

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace KDF
{
	class KDF_API Log
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


// Core log macros
#define LOG_CORE_TRACE(...) ::KDF::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_DEBUG(...) ::KDF::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::KDF::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::KDF::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::KDF::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::KDF::Log::GetCoreLogger()->critical(__VA_ARGS__)
// Client log macros
#define LOG_TRACE(...)      ::KDF::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)      ::KDF::Log::GetClientLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)       ::KDF::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)       ::KDF::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      ::KDF::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)      ::KDF::Log::GetClientLogger()->critical(__VA_ARGS__)
