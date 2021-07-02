#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "fooserviceimpl.h"

// Server-side streaming RPC のサンプルプログラム（サーバー側）
// クライアントからの１リクエストに対し、複数のリプライを返送する

int main()
{
    std::cout << "ServerStreamingRpc server start..." << std::endl;

    const std::string host( "localhost:27182" );
    FooServiceImpl service {};

    grpc::ServerBuilder builder{};
    builder.RegisterService( &service );
    builder.AddListeningPort( host, grpc::InsecureServerCredentials() );
    auto&& server = builder.BuildAndStart();

    std::cout << "running... (Press any key to exit.)" << std::endl;
    std::string input;
    std::getline( std::cin, input );

    server->Shutdown();

    return 0;
}
