#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "foo.grpc.pb.h"

int main()
{
    std::cout << "MultiService client start..." << std::endl;

    const std::string host( "localhost:27182" );
    auto&& channel = grpc::CreateChannel( host, grpc::InsecureChannelCredentials() );
    auto&& client1 = MultiService::Foo1Service::NewStub( channel );
    auto&& client2 = MultiService::Foo2Service::NewStub( channel );

    // call Foo1Service::Foo( 123 )
    {
        grpc::ClientContext context{};
        MultiService::FooRequest request{};
        request.set_value( 123 );
        MultiService::FooResponse reply{};
        auto&& status = client1->Foo( &context, request, &reply );
        if ( status.ok() )
        {
            std::cout << "received: " << reply.value() << std::endl;
        }
        else
        {
            std::cout << "Fail to RPC!!!" << std::endl;
        }
    }
    // call Foo2Service::Foo( 123 )
    {
        grpc::ClientContext context{};
        MultiService::FooRequest request{};
        request.set_value( 123 );
        MultiService::FooResponse reply{};
        auto&& status = client2->Foo( &context, request, &reply );
        if ( status.ok() )
        {
            std::cout << "received: " << reply.value() << std::endl;
        }
        else
        {
            std::cout << "Fail to RPC!!!" << std::endl;
        }
    }

    std::cout << "press any key to exit..." << std::endl;
    std::string input{};
    std::getline( std::cin, input );

    return 0;
}
