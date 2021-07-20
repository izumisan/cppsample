// stopwatch.cpp
#include <windows.h>
#include "stopwatch.h"

namespace diagnostics
{

long Stopwatch::frequency() const
{
    ::LARGE_INTEGER freq {};
    ::QueryPerformanceFrequency( &freq );
    return static_cast<long>( freq.QuadPart );
}

bool Stopwatch::isHighResolution() const
{
    ::LARGE_INTEGER freq {};
    return ( ::QueryPerformanceFrequency( &freq ) != 0 );
}

bool Stopwatch::isRunning() const
{
    return m_isRunning;
}

double Stopwatch::elapsed() const
{
    return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>( currentElapsedTime() ).count();
}

long long Stopwatch::elapsedSeconds() const
{
    return std::chrono::duration_cast<std::chrono::seconds>( currentElapsedTime() ).count();
}

long long Stopwatch::elapsedMilliseconds() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>( currentElapsedTime() ).count();
}

long long Stopwatch::elapsedMicroseconds() const
{
    return std::chrono::duration_cast<std::chrono::microseconds>( currentElapsedTime() ).count();
}

long long Stopwatch::elapsedNanoseconds() const
{
    return currentElapsedTime().count();
}

Stopwatch Stopwatch::startNew()
{
    auto&& sw = Stopwatch();
    sw.start();
    return std::move( sw );
}

void Stopwatch::start()
{
    if ( m_isRunning != true )
    {
        m_begin = std::chrono::high_resolution_clock::now();
        m_end = m_begin;
        m_isRunning = true;
    }
}

void Stopwatch::stop()
{
    if ( m_isRunning )
    {
        m_end = std::chrono::high_resolution_clock::now();
        m_elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>( m_end - m_begin );
        m_isRunning = false;
    }
}

void Stopwatch::reset()
{
    m_begin = std::chrono::high_resolution_clock::now();
    m_end = m_begin;
    m_elapsed = std::chrono::nanoseconds(0);
    m_isRunning = false;
}

void Stopwatch::restart()
{
    m_begin = std::chrono::high_resolution_clock::now();
    m_end = m_begin;
    m_elapsed = std::chrono::nanoseconds(0);
    m_isRunning = true;
}

std::chrono::duration<long long, std::nano> Stopwatch::currentElapsedTime() const
{
    return m_isRunning ? ( std::chrono::high_resolution_clock::now() - m_begin ) : ( m_end - m_begin );
}

} // namespace diagnostics
