/*
 * ログレベルの表示名を変更するサンプル
 */
#include <iostream>
#include <thread>
#include <chrono>

// 以下のように、common.h で spdlog::level::level_enum の要素名がマクロ定義されているので
// これを変更することで、ログレベルの表示名を変更することができる.
//#define SPDLOG_LEVEL_NAMES { "trace", "debug", "info", "warning", "error", "critical", "off" }
#define SPDLOG_LEVEL_NAMES { "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL", "OFF" }

#include "spdlog/spdlog.h"

int main()
{
    spdlog::set_level( spdlog::level::trace );

    spdlog::trace( "trace message" );
    spdlog::debug( "debug message" );
    spdlog::info( "info message" );
    spdlog::warn( "warn message" );
    spdlog::error( "error message" );
    spdlog::critical( "critical message" );

    return 0;
}
