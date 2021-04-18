/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_LOG_H
#define WEHAPPYFEW_LOG_H

#include <memory>
#include <spdlog/spdlog.h>

#include "EngineApi.h"

namespace engine {

    class ENGINE_API Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> coreLogger;
        static std::shared_ptr<spdlog::logger> clientLogger;
    };

}

#ifdef NDEBUG
    // Core log macros
    #define LOG_CORE_TRACE(...)
    #define LOG_CORE_INFO(...)
    #define LOG_CORE_WARN(...)
    #define LOG_CORE_ERROR(...)
    #define LOG_CORE_CRITICAL(...)

    // Client log macros
    #define LOG_TRACE(...)
    #define LOG_INFO(...)
    #define LOG_WARN(...)
    #define LOG_ERROR(...)
    #define LOG_CRITICAL(...)
#else
    // Core log macros
    #define LOG_CORE_TRACE(...)    ::engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
    #define LOG_CORE_INFO(...)     ::engine::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define LOG_CORE_WARN(...)     ::engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define LOG_CORE_ERROR(...)    ::engine::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define LOG_CORE_CRITICAL(...) ::engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

    // Client log macros
    #define LOG_TRACE(...)         ::engine::Log::GetClientLogger()->trace(__VA_ARGS__)
    #define LOG_INFO(...)          ::engine::Log::GetClientLogger()->info(__VA_ARGS__)
    #define LOG_WARN(...)          ::engine::Log::GetClientLogger()->warn(__VA_ARGS__)
    #define LOG_ERROR(...)         ::engine::Log::GetClientLogger()->error(__VA_ARGS__)
    #define LOG_CRITICAL(...)      ::engine::Log::GetClientLogger()->critical(__VA_ARGS__)
#endif

#endif //WEHAPPYFEW_LOG_H
