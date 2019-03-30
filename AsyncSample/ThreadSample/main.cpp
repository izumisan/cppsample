#include <iostream>
#include <thread>
#include <chrono>

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
    {
        std::cout << "main:start..." << std::endl;

        // doSomething()��ʃX���b�h�Ŏ��s
        auto&& th = std::thread( doSomething );

        std::cout << "main:begin sleep 3sec..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
        std::cout << "main:sleep end" << std::endl;

        // �ʃX���b�h�̏I����҂�
        th.join();

        std::cout << "main:end" << std::endl;
    }

    std::cout << "-----" << std::endl;

    {
        std::cout << "main:start..." << std::endl;

        int input = 2;
        int result = 0;
        
        // �����_���ŃL���v�`�����邱�Ƃɂ��A�������ʂ��擾�ł���
        auto&& th = std::thread( [input, &result] { result = heavyCalculation( input ); } );

        th.join();

        std::cout << "main:result=" << result << std::endl;
    }

    return 0;
}