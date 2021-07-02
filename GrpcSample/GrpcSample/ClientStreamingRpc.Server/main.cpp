#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "fooserviceimpl.h"

// Client-side streaming RPC �̃T���v���v���O�����i�T�[�o�[���j
// �N���C�A���g����̕������N�G�X�g�ɑ΂��A�P���v���C��Ԃ�

int main()
{
    std::cout << "ClientStreamingRpc server start..." << std::endl;

    const std::string host( "localhost:27182" );
    FooServiceImpl service {};

    grpc::ServerBuilder builder {};
    builder.RegisterService( &service );
    builder.AddListeningPort( host, grpc::InsecureServerCredentials() );
    auto&& server = builder.BuildAndStart();

    std::cout << "running... (Press any key to exit.)" << std::endl;
    std::string input;
    std::getline( std::cin, input );

    server->Shutdown();

    return 0;
}
