#include <iostream>
#include <thread>
#include <future>

void doSomething()
{
    for ( int i = 0; i < 5; ++i )
    {
        std::cout << std::this_thread::get_id() << ":" << i << std::endl;

        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }
}

int heavyCalculation( int x )
{
    std::cout << std::this_thread::get_id() << ":祈祷中..." << std::endl;

    int ret = x * x;

    std::this_thread::sleep_for( std::chrono::seconds( 5 ) );

    std::cout << std::this_thread::get_id() << ":result=" << ret << std::endl;

    return ret;
}

int main()
{
    std::cout << "main thread id=" << std::this_thread::get_id() << std::endl;

    // case 1: シンプル例
    {
        std::cout << "main:start..." << std::endl;

        // doSomething()を別スレッドで実行
        std::future<void> f = std::async( std::launch::async, doSomething );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // 別スレッドの終了を待つ
        f.wait();

        std::cout << "main:end" << std::endl;
    }

    std::cout << "-----" << std::endl;

    // case 2: 別スレッドでの結果を取得する
    {
        int input = 2;

        // heavyCalculation()を別スレッドで実行
        std::future<int> f = std::async( std::launch::async, [input] { return heavyCalculation( input ); } );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // 別スレッドの終了を待ち、結果を取得する
        int result = f.get();

        std::cout << "main:result=" << result << std::endl;
    }

    std::cout << "-----" << std::endl;

    // case 3: 遅延実行
    {
        int input = 2;

        // heavyCalculation()を遅延実行
        std::future<int> f = std::async( std::launch::deferred, [input] { return heavyCalculation( input ); } );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // get()により、heavyCalculation()がメインスレッドで実行される
        int result = f.get();

        std::cout << "main:result=" << result << std::endl;
    }

    return 0;
}
