#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "fooserviceimpl.h"

// gRPC�T�[�o�[���v���O����
// 
// 1. proto�t�@�C����莩���������ꂽ`FooService::Service`���p�������T�[�r�X�N���X���`�E��������
// 2. �T�[�r�X�N���X�̃C���X�^���X��`grpc::ServerBuilder`�ɓo�^����
// 3. `grpc::ServerBuilder::BuildAndStart()`�ɂ��A�T�[�o�[���N������

int main()
{
    std::cout << "Basic server start..." << std::endl;

    const std::string host( "localhost:27182" );
    basic::FooServiceImpl service {};

    grpc::ServerBuilder builder {};
    builder.RegisterService( &service );
    builder.AddListeningPort( host, grpc::InsecureServerCredentials() );

    auto&& server = builder.BuildAndStart();

    std::cout << "running..." << std::endl;

    server->Wait();

    return 0;
}
