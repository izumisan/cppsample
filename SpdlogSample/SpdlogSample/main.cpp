#include <iostream>
#include <vector>
#include "spdlog/spdlog.h"

int main()
{
    // �f�t�H���g�̃��O���x����"info"�Ȃ̂ŁA"trace"��"debug"�͏o�͂���Ȃ�
    spdlog::trace( "trace" );
    spdlog::debug( "debug" );
    spdlog::info( "info" );
    spdlog::warn( "warn" );
    spdlog::error( "error" );
    spdlog::critical( "critical" );

    //--------------------------------------------------------------------------
    std::cout << ">>> debug" << std::endl;
    spdlog::set_level( spdlog::level::debug );

    spdlog::trace( "trace" );
    spdlog::debug( "debug" );
    spdlog::info( "info" );
    spdlog::warn( "warn" );
    spdlog::error( "error" );
    spdlog::critical( "critical" );

    //--------------------------------------------------------------------------
    std::cout << ">>> trace" << std::endl;;
    spdlog::set_level( spdlog::level::trace );

    spdlog::trace( "trace" );
    spdlog::debug( "debug" );
    spdlog::info( "info" );
    spdlog::warn( "warn" );
    spdlog::error( "error" );
    spdlog::critical( "critical" );

    //--------------------------------------------------------------------------
    std::cout << ">>> off" << std::endl;;
    spdlog::set_level( spdlog::level::off );

    spdlog::trace( "trace" );
    spdlog::debug( "debug" );
    spdlog::info( "info" );
    spdlog::warn( "warn" );
    spdlog::error( "error" );
    spdlog::critical( "critical" );

    //--------------------------------------------------------------------------
    std::cout << ">>> info" << std::endl;
    spdlog::set_level( spdlog::level::info );

    auto&& name = "foo";
    auto&& value = 777;
    auto&& lucky = true;

    // C#��string.Format�̂悤�Ƀt�H�[�}�b�g�\
    spdlog::info( "name: {}, value: {}, lucky: {}", name, value, lucky );
    spdlog::info( "name: {0}, value: {1}, lucky: {2}", name, value, lucky );

    spdlog::info( "int: {:05d}", -12 );  // ��5, 0����
    spdlog::info( "double: {:5.2f}", -1.2345678 );
    spdlog::info( "int: {0:d}, hex: {0:x}, oct: {0:o}, bin: {0:b}", 77 );

    return 0;
}
