#include <iostream>
#include <chrono>
#include "asyncbenchmark.h"

int main()
{
    auto&& printResult = [](auto&& x)
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>( std::get<1>( x ) - std::get<0>( x ) ).count();
    };

    int size = std::pow( 10, 7 );;
    {
        auto&& obj = AsyncBenchmark();
        auto&& ret = obj.normal( size );
        std::cout << "normal: " << printResult( ret ) << " [msec]" << std::endl;
    }
    {
        auto&& obj = AsyncBenchmark();
        auto&& ret = obj.thread( size );
        std::cout << "thread: " << printResult( ret ) << " [msec]" << std::endl;
    }
    {
        auto&& obj = AsyncBenchmark();
        auto&& ret = obj.async( size );
        std::cout << " async: " << printResult( ret ) << " [msec]" << std::endl;
    }
    return 0;
}
