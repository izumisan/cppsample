#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "fooserviceimpl.h"

int main()
{
    std::cout << "Basic server start..." << std::endl;

    const std::string host( "localhost:27182" );
    basic::FooServiceImpl service {};

    grpc::ServerBuilder builder {};
    builder.AddListeningPort( host, grpc::InsecureServerCredentials() );
    builder.RegisterService( &service );

    std::unique_ptr<grpc::Server> server( builder.BuildAndStart() );

    std::cout << "running..." << std::endl;

    server->Wait();

    return 0;
}
