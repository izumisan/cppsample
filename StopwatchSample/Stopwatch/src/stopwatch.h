// stopwatch.h
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace diagnostics
{

class Stopwatch
{
public:
    Stopwatch() = default;
    Stopwatch( const Stopwatch& ) = default;
    Stopwatch( Stopwatch&& ) noexcept = default;
    virtual ~Stopwatch() noexcept = default;
public:
    Stopwatch& operator=( const Stopwatch& ) = default;
    Stopwatch& operator=( Stopwatch&& ) noexcept = default;

public:
    long frequency() const;
    bool isHighResolution() const;
    bool isRunning() const;
public:
    double elapsed() const;
    long long elapsedSeconds() const;
    long long elapsedMilliseconds() const;
    long long elapsedMicroseconds() const;
    long long elapsedNanoseconds() const;
public:
    static Stopwatch startNew();
    void start();
    void stop();
    void reset();
    void restart();
private:
    std::chrono::duration<long long, std::nano> currentElapsedTime() const;

private:
    bool m_isRunning = false;
    std::chrono::high_resolution_clock::time_point m_begin = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point m_end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds m_elapsed {};
};

} // namespace diagnostics

#endif // STOPWATCH_H
