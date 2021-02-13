/*
 * set_pattern()によるメッセージフォーマットを指定するサンプル
 */
#include <iostream>
#include <thread>
#include <chrono>
#include "spdlog/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main()
{
    // 既定のフォーマット
    // [yyyy-MM-dd hh:mm:ss.fff] [name] [level] message
    ::spdlog::info( "spdlog default message format" );  // "[2021-02-13 23:45:59.678] [info] xxxxx"

    auto&& sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto&& foo = std::make_shared<spdlog::logger>( "foo", sink );
    foo->info( "spdlog default message format" );  // "[2021-02-13 23:45:59.678] [foo] [info] xxxxx"

    // 既定フォーマットから日付部分の角カッコを取り除いたサンプル
    // yyyy-MM-dd hh:mm:ss.fff [name] [level] message
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e [%n] [%^%l%$] %v" );  // '%^' と '%$' で囲んだ部分は色付けされる
    foo->info( "custom format" );  // "2021-02-13 23:45:59.678 [foo] [info] xxxx"

    // 幅指定サンプル(右寄せ)
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e [%n] [%^%8l%$] %v" );  // '%' と 'flag'　の間に幅を指定することができる
    foo->info( "right" );  // "2021-02-13 23:45:59.678 [foo] [    info] xxxx"

    // 幅指定サンプル(左寄せ)
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e [%n] [%^%-8l%$] %v" );
    foo->info( "left" );  // "2021-02-13 23:45:59.678 [foo] [info    ] xxxx"

    // 幅指定サンプル(中央寄せ)
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e [%n] [%^%=8l%$] %v" );
    foo->info( "center" );  // "2021-02-13 23:45:59.678 [foo] [  info  ] xxxx"

    // '%o'で、前回メッセージからの経過時間をmillisecondsで出力できる
    // (%i: microseconds, %u: nanoseconds)
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e(%o) [%n] [%^%l%$] %v" );
    foo->info( "1st" );
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    foo->info( "2nd" );  // "2021-02-13 23:45:59.678(100) [foo] [info] xxxx"
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    foo->info( "3rd" );  // "2021-02-13 23:45:59.678(100) [foo] [info] xxxx"

    // log level と　logger名 の順序を入れ替えたフォーマット
    // (logger毎にログファイルを分割するなら、logger名を付加する必要はないかも...)
    // yyyy-MM-dd hh:mm:ss.fff level [name] message
    foo->set_pattern( "%Y-%m-%d %H:%M:%S.%e %^%l%$ [%n] %v" );
    foo->info( "my recommended formart" ); //  "2021-02-13 23:45:59.678 info [foo] xxxx"

    ::spdlog::shutdown();
    return 0;
}
