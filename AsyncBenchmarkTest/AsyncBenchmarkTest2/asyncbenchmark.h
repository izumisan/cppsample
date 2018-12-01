#ifndef ASYNCBENCHMARK_H
#define ASYNCBENCHMARK_H

#include <chrono>
#include <tuple>

class AsyncBenchmark
{
public:
    static auto normal( const int size ) -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>;
    static auto thread( const int size ) -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>;
    static auto async( const int size ) -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>;
};

#endif // ASYNCBENCHMARK_H
