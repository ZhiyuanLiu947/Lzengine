#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace LZE {
    class LZE_API Log {
    public:
        static void Init();
    
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log Macros (Engine side)
#define LZE_CORE_TRACE(...)         ::LZE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LZE_CORE_INFO(...)          ::LZE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LZE_CORE_WARN(...)          ::LZE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LZE_CORE_ERROR(...)         ::LZE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LZE_CORE_FATAL(...)         ::LZE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros (Application side)
#define LZE_TRACE(...)          ::LZE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LZE_INFO(...)           ::LZE::Log::GetClientLogger()->info(__VA_ARGS__)
#define LZE_WARN(...)           ::LZE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LZE_ERROR(...)          ::LZE::Log::GetClientLogger()->error(__VA_ARGS__)
#define LZE_FATAL(...)          ::LZE::Log::GetClientLogger()->fatal(__VA_ARGS__)
