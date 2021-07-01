#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "foo1serviceimpl.h"
#include "foo2serviceimpl.h"

// �����T�[�r�X��L����T���v���v���O�����i�T�[�o�[���j

int main()
{
    std::cout << "MultiService server start..." << std::endl;

    const std::string host( "localhost:27182" );
    Foo1ServiceImpl service1 {};
    Foo2ServiceImpl service2 {};

    // �w�^��ServiceBuilder���ʂɏ�������̂ł͂Ȃ��A
    // ���̂܂�RegisterService()���邾���ŗǂ����ۂ�...?
    grpc::ServerBuilder builder {};
    builder.RegisterService( &service1 );
    builder.RegisterService( &service2 );
    builder.AddListeningPort( host, grpc::InsecureServerCredentials() );
    auto&& server = builder.BuildAndStart();

    std::cout << "running... (Press any key to exit.)" << std::endl;
    std::string input;
    std::getline( std::cin, input );
    
    server->Shutdown();

    return 0;
}
