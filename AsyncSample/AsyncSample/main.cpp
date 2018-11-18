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
    std::cout << std::this_thread::get_id() << ":�F����..." << std::endl;

    int ret = x * x;

    std::this_thread::sleep_for( std::chrono::seconds( 5 ) );

    std::cout << std::this_thread::get_id() << ":result=" << ret << std::endl;

    return ret;
}

int main()
{
    std::cout << "main thread id=" << std::this_thread::get_id() << std::endl;

    // case 1: �V���v����
    {
        std::cout << "main:start..." << std::endl;

        // doSomething()��ʃX���b�h�Ŏ��s
        std::future<void> f = std::async( std::launch::async, doSomething );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // �ʃX���b�h�̏I����҂�
        f.wait();

        std::cout << "main:end" << std::endl;
    }

    std::cout << "-----" << std::endl;

    // case 2: �ʃX���b�h�ł̌��ʂ��擾����
    {
        int input = 2;

        // heavyCalculation()��ʃX���b�h�Ŏ��s
        std::future<int> f = std::async( std::launch::async, [input] { return heavyCalculation( input ); } );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // �ʃX���b�h�̏I����҂��A���ʂ��擾����
        int result = f.get();

        std::cout << "main:result=" << result << std::endl;
    }

    std::cout << "-----" << std::endl;

    // case 3: �x�����s
    {
        int input = 2;

        // heavyCalculation()��x�����s
        std::future<int> f = std::async( std::launch::deferred, [input] { return heavyCalculation( input ); } );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // get()�ɂ��AheavyCalculation()�����C���X���b�h�Ŏ��s�����
        int result = f.get();

        std::cout << "main:result=" << result << std::endl;
    }

    return 0;
}
