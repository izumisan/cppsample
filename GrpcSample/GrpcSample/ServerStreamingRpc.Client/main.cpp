#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "foo.grpc.pb.h"
#include "fooserviceclient.h"

// Server-side streaming RPC のサンプルプログラム（クライアント側）
// サーバーから複数のリプライを得る

int main()
{
    std::cout << "ServerStreamingRpc client start..." << std::endl;

    const std::string host( "localhost:27182" );
    auto&& channel = grpc::CreateChannel( host, grpc::InsecureChannelCredentials() );
    auto&& client = FooServiceClient( channel );

    auto&& req = ServerStreamingRpc::FooRequest();
    req.set_value( 1 );

    auto&& res = client.GetFooList( req );
    for ( auto&& m : res )
    {
        std::cout << m.value() << std::endl;
    }

    std::cout << "press any key to exit..." << std::endl;
    std::string input{};
    std::getline( std::cin, input );

    return 0;
}
