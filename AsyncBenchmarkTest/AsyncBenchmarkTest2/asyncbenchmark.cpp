#include <vector>
#include <future>
#include "asyncbenchmark.h"

auto AsyncBenchmark::normal( const int size )
    -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>
{
    auto&& input = std::vector<double>();
    for ( int i = 0; i < size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    auto&& start = std::chrono::system_clock::now();

    auto&& answer = std::vector<double>();
    answer.reserve( size );

    for ( auto&& x : input )
    {
        answer.push_back( x * x );
    }

    auto&& end = std::chrono::system_clock::now();

    return std::make_tuple( start, end );
}

auto AsyncBenchmark::thread( const int size )
    -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>
{
    auto&& input = std::vector<double>();
    for ( int i = 0; i < size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    auto&& start = std::chrono::system_clock::now();

    auto&& answer = std::vector<double>();
    answer.reserve( size );

    auto&& thread1 = std::thread( [&input, &answer, size]
    {
        for ( int i = 0; i < size / 2; ++i )
        {
            double x = input.at(i);
            answer.push_back( x * x );
        }
    } );

    auto&& thread2 = std::thread( [&input, &answer, size]
    {
        for ( int i = size / 2; i < size; ++i )
        {
            double x = input.at(i);
            answer.push_back( x * x );
        }
    } );

    thread1.join();
    thread2.join();

    auto&& end = std::chrono::system_clock::now();

    return std::make_tuple( start, end );
}

auto AsyncBenchmark::async( const int size )
    -> std::tuple<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>
{
    auto&& input = std::vector<double>();
    for ( int i = 0; i < size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    auto&& start = std::chrono::system_clock::now();

    auto&& answer = std::vector<double>();
    answer.reserve( size );

    auto&& task1 = std::async( std::launch::async, [&input, &answer, size]
    {
        for ( int i = 0; i < size / 2; ++i )
        {
            double x = input.at(i);
            answer.push_back( x * x );
        }
    } );

    auto&& task2 = std::async( std::launch::async, [&input, &answer, size]
    {
        for ( int i = size / 2; i < size; ++i )
        {
            double x = input.at(i);
            answer.push_back( x * x );
        }
    } );

    task1.get();
    task2.get();

    auto&& end = std::chrono::system_clock::now();

    return std::make_tuple( start, end );
}
