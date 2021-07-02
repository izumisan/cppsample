#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <grpcpp/grpcpp.h>

#include "foo.grpc.pb.h"
#include "fooserviceclient.h"

// Client-side streaming RPC �̃T���v���v���O�����i�N���C�A���g���j
// �������N�G�X�g�𑗐M���A�T�[�o�[����P���v���C�𓾂�

int main()
{
    std::cout << "ClientStreamingRpc client start..." << std::endl;

    const std::string host( "localhost:27182" );
    auto&& channel = grpc::CreateChannel( host, grpc::InsecureChannelCredentials() );
    auto&& client = FooServiceClient( channel );

    std::vector<int> values {};
    for ( int i = 0; i < 10; ++i )
    {
        values.emplace_back( i + 1 );
    }
    auto&& reply = client.total( values );
    std::cout << "reply: " << reply << std::endl;

    std::cout << "press any key to exit..." << std::endl;
    std::string input {};
    std::getline( std::cin, input );

    return 0;
}
