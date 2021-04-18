/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace engine {

    std::shared_ptr<spdlog::logger> Log::coreLogger;
    std::shared_ptr<spdlog::logger> Log::clientLogger;

    void Log::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("engine.log", true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        coreLogger = std::make_shared<spdlog::logger>("ENGINE", begin(logSinks), end(logSinks));
        spdlog::register_logger(coreLogger);
        coreLogger->set_level(spdlog::level::trace);
        coreLogger->flush_on(spdlog::level::trace);

        clientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
        spdlog::register_logger(clientLogger);
        clientLogger->set_level(spdlog::level::trace);
        clientLogger->flush_on(spdlog::level::trace);
    }

}
