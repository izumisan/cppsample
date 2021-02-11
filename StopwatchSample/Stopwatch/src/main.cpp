#include <iostream>
#include <thread>
#include "stopwatch.h"

int main()
{
    auto&& stopwatch = diagnostics::Stopwatch();
    stopwatch.start();

    std::this_thread::sleep_for( std::chrono::milliseconds( 1500 ) );

    stopwatch.stop();

    std::cout << "frequency: " << stopwatch.frequency() << " [Hz]" << std::endl;
    std::cout << "elapsed: " << stopwatch.elapsed() << " [sec]" << std::endl;
    std::cout << "elapsed: " << stopwatch.elapsedSeconds() << " [sec]" << std::endl;
    std::cout << "elapsed: " << stopwatch.elapsedMilliseconds() << " [msec]" << std::endl;
    std::cout << "elapsed: " << stopwatch.elapsedMicroseconds() << " [usec]" << std::endl;
    std::cout << "elapsed: " << stopwatch.elapsedNanoseconds() << " [nsec]" << std::endl;

    return 0;
}
