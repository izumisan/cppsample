#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

int main()
{
    auto&& basicLogger = spdlog::basic_logger_mt( "basic_logger", "basic.log" );

    // �ȉ��̐ݒ�̏ꍇ�A�ő�T�C�Y1024�o�C�g�ŁA�o�b�N�A�b�v�t�@�C����3�܂ō쐬�����
    // rotation.log, rotation.1.log, rotation.2.log rotation.3.log���쐬�����
    // (rotation.3.log����ԌÂ����O�t�@�C��)
    auto&& rotatingLogger = spdlog::rotating_logger_mt( "rotating_logger", "rotation.log", 1024, 3 );

    // async logger
    auto&& asyncLogger = spdlog::basic_logger_mt<spdlog::async_factory>( "async_logger", "async.log" );
    auto&& asyncRotatingLogger = spdlog::rotating_logger_mt<spdlog::async_factory>( "async_rotating_logger", "async_rotation.log", 1024, 3 );

    for ( int i = 0; i < 1024 * 5; ++i )
    {
        basicLogger->info( "basic: " + std::to_string( i ) );
        rotatingLogger->info( "rotation: " + std::to_string( i ) );
        asyncLogger->info( "async: " + std::to_string( i ) );
        asyncRotatingLogger->info( "async_rotation: " + std::to_string( i ) );
    }

    // VisualStudio�̏ꍇ�Amain�I���O��drop_all()���Ăяo���A
    // �o�^����logger����菜���K�v������炵����...
    spdlog::drop_all();

    return 0;
}
