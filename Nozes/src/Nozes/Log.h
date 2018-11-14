#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nozes {
	class NOZES_API Log
	{
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define NZ_CORE_TRACE(...)  ::Nozes::Log::getCoreLogger()->trace(__VA_ARGS__)
#define NZ_CORE_INFO(...)   ::Nozes::Log::getCoreLogger()->info(__VA_ARGS__)
#define NZ_CORE_WARN(...)   ::Nozes::Log::getCoreLogger()->warn(__VA_ARGS__)
#define NZ_CORE_ERROR(...)  ::Nozes::Log::getCoreLogger()->error(__VA_ARGS__)
#define NZ_CORE_FATAL(...)  ::Nozes::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define NZ_TRACE(...)  ::Nozes::Log::getClientLogger()->trace(__VA_ARGS__)
#define NZ_INFO(...)   ::Nozes::Log::getClientLogger()->info(__VA_ARGS__)
#define NZ_WARN(...)   ::Nozes::Log::getClientLogger()->warn(__VA_ARGS__)
#define NZ_ERROR(...)  ::Nozes::Log::getClientLogger()->error(__VA_ARGS__)
#define NZ_FATAL(...)  ::Nozes::Log::getClientLogger()->fatal(__VA_ARGS__)

