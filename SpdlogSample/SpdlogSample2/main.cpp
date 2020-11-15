#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

int main()
{
    auto&& basicLogger = spdlog::basic_logger_mt( "basic_logger", "basic.log" );

    // 以下の設定の場合、最大サイズ1024バイトで、バックアップファイルが3つまで作成される
    // rotation.log, rotation.1.log, rotation.2.log rotation.3.logが作成される
    // (rotation.3.logが一番古いログファイル)
    auto&& rotatingLogger = spdlog::rotating_logger_mt( "rotating_logger", "rotation.log", 1024, 3 );

    // async logger
    auto&& asyncLogger = spdlog::basic_logger_mt<spdlog::async_factory>( "async_logger", "async.log" );
    auto&& asyncRotatingLogger = spdlog::rotating_logger_mt<spdlog::async_factory>( "async_rotating_logger", "async_rotation.log", 1024, 3 );

    for ( int i = 0; i < 1024 * 5; ++i )
    {
        basicLogger->info( "basic: " + std::to_string( i ) );
        rotatingLogger->info( "rotation: " + std::to_string( i ) );
        asyncLogger->info( "async: " + std::to_string( i ) );
        asyncRotatingLogger->info( "async_rotation: " + std::to_string( i ) );
    }

    // VisualStudioの場合、main終了前にdrop_all()を呼び出し、
    // 登録したloggerを取り除く必要があるらしいが...
    spdlog::drop_all();

    return 0;
}
