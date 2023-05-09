#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace Shoonya
{
	class SHOONYA_API Log
	{
		public:
			static void Init();
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger;   }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#pragma region Log Macros
//Core Log Macros
#define SH_CORE_TRACE(...)   ::Shoonya::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SH_CORE_INFO(...)    ::Shoonya::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SH_CORE_WARN(...)    ::Shoonya::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SH_CORE_ERROR(...)   ::Shoonya::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SH_CORE_FATAL(...)   ::Shoonya::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define SH_TRACE(...)		 ::Shoonya::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SH_INFO(...)		 ::Shoonya::Log::GetClientLogger()->info(__VA_ARGS__)
#define SH_WARN(...)		 ::Shoonya::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SH_ERROR(...)		 ::Shoonya::Log::GetClientLogger()->error(__VA_ARGS__)
#define SH_FATAL(...)		 ::Shoonya::Log::GetClientLogger()->fatal(_VA_ARGS__)

#pragma endregion