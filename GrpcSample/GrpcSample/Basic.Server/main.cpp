#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "fooserviceimpl.h"

// gRPCサーバー側プログラム
// 
// 1. protoファイルより自動生成された`FooService::Service`を継承したサービスクラスを定義・実装する
// 2. サービスクラスのインスタンスを`grpc::ServerBuilder`に登録する
// 3. `grpc::ServerBuilder::BuildAndStart()`により、サーバーを起動する

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
