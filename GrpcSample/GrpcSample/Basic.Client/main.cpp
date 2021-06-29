#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "foo.grpc.pb.h"

// gRPC�N���C�A���g���v���O����
//
// 1. `grpc::CreateChannel()`�ɂ��A�R�l�N�V�������m������
// 2. proto�t�@�C����莩���������ꂽ`FooService::NewStub()`�ɂ��A�N���C�A���g�𐶐�����
// 3. �N���C�A���g����āA�֐��������[�g���s����

int main()
{
    std::cout << "Basic client start..." << std::endl;

    const std::string host( "localhost:27182" );
    auto&& channel = grpc::CreateChannel( host, grpc::InsecureChannelCredentials() );
    auto&& client = basic::FooService::NewStub( channel );
    // �������OK
    //auto&& client = std::make_unique<basic::FooService::Stub>( basic::FooService::Stub( channel ) );

    grpc::ClientContext context {};

    basic::FooRequest request {};
    request.set_value( "Foo" );

    basic::FooReply reply {};

    auto&& status = client->FooMethod( &context, request, &reply );
    if ( status.ok() )
    {
        std::cout << "received: " << reply.value() << std::endl;
    }
    else
    {
        std::cout << "Fail to RPC!!!" << std::endl;
    }

    std::cout << "press any key to exit..." << std::endl;
    std::string input {};
    std::getline( std::cin, input );

    return 0;
}
