#include <QString>
#include <QtTest>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <iterator>

class AsyncBenchmarkTest : public QObject
{
    Q_OBJECT

public:
    AsyncBenchmarkTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void normal_data();
    void normal();

    void thread_data();
    void thread();

    void async_data();
    void async();
};

AsyncBenchmarkTest::AsyncBenchmarkTest()
{
}

void AsyncBenchmarkTest::initTestCase()
{
}

void AsyncBenchmarkTest::cleanupTestCase()
{
}

void AsyncBenchmarkTest::init()
{
}

void AsyncBenchmarkTest::cleanup()
{
}

void AsyncBenchmarkTest::normal_data()
{
    QTest::addColumn<int>("_size");
    QTest::newRow(       "100") << 100;
    QTest::newRow(     "1,000") << 1000;
    QTest::newRow(    "10,000") << 10000;
    QTest::newRow(   "100,000") << 100000;
    QTest::newRow( "1,000,000") << 1000000;
    QTest::newRow("10,000,000") << 10000000;
}

void AsyncBenchmarkTest::normal()
{
    QFETCH( int, _size );

    auto&& input = std::vector<double>();
    for ( int i = 0; i < _size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    QBENCHMARK
    {
        auto&& answer = std::vector<double>();
        answer.reserve( _size );

        for ( auto&& x : input )
        {
            answer.push_back( x * x );
        }
    }
}

void AsyncBenchmarkTest::thread_data()
{
    QTest::addColumn<int>("_size");
    QTest::newRow(       "100") << 100;
    QTest::newRow(     "1,000") << 1000;
    QTest::newRow(    "10,000") << 10000;
    QTest::newRow(   "100,000") << 100000;
    QTest::newRow( "1,000,000") << 1000000;
    QTest::newRow("10,000,000") << 10000000;
}

void AsyncBenchmarkTest::thread()
{
    QFETCH( int, _size );

    auto&& input = std::vector<double>();
    for ( int i = 0; i < _size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    QBENCHMARK
    {
        auto&& answer = std::vector<double>();
        answer.reserve( _size );

        auto&& thread1 = std::thread( [&input, &answer, _size]
        {
            for ( int i = 0; i < _size / 2; ++i )
            {
                double x = input.at(i);
                answer.push_back( x * x );
            }
        } );

        auto&& thread2 = std::thread( [&input, &answer, _size]
        {
            for ( int i = _size / 2; i < _size; ++i )
            {
                double x = input.at(i);
                answer.push_back( x * x );
            }
        } );

        thread1.join();
        thread2.join();
    }
}

void AsyncBenchmarkTest::async_data()
{
    QTest::addColumn<int>("_size");
    QTest::newRow(       "100") << 100;
    QTest::newRow(     "1,000") << 1000;
    QTest::newRow(    "10,000") << 10000;
    QTest::newRow(   "100,000") << 100000;
    QTest::newRow( "1,000,000") << 1000000;
    QTest::newRow("10,000,000") << 10000000;
}

void AsyncBenchmarkTest::async()
{
    QFETCH( int, _size );

    auto&& input = std::vector<double>();
    for ( int i = 0; i < _size; ++i )
    {
        input.push_back( static_cast<double>( i + 1 ) );
    }

    QBENCHMARK
    {
        auto&& answer = std::vector<double>();
        answer.reserve( _size );

        auto&& task1 = std::async( std::launch::async, [&input, &answer, _size]
        {
            for ( int i = 0; i < _size / 2; ++i )
            {
                double x = input.at(i);
                answer.push_back( x * x );
            }
        } );

        auto&& task2 = std::async( std::launch::async, [&input, &answer, _size]
        {
            for ( int i = _size / 2; i < _size; ++i )
            {
                double x = input.at(i);
                answer.push_back( x * x );
            }
        } );

        task1.get();
        task2.get();
    }
}


QTEST_APPLESS_MAIN(AsyncBenchmarkTest)

#include "tst_asyncbenchmarktest.moc"
