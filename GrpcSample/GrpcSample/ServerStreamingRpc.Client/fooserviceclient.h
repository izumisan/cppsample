#ifndef FOOSERVICECLIENT_H
#define FOOSERVICECLIENT_H

#include <vector>
#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class FooServiceClient
{
public:
    FooServiceClient( const std::shared_ptr<::grpc::Channel>& channel )
        : m_client( ServerStreamingRpc::FooService::NewStub( channel ) )
    {
    }

public:
    std::vector<ServerStreamingRpc::FooResponse> GetFooList( const ServerStreamingRpc::FooRequest& request )
    {
        std::vector<ServerStreamingRpc::FooResponse> ret {};

        ::grpc::ClientContext context {};

        // protoファイルで定義したサービス関数(GetFooList)により、
        // レスポンスストリームリーダー(ClientReader)を取得できる
        auto&& reader = m_client->GetFooList( &context, request );

        ServerStreamingRpc::FooResponse res {};
        while ( reader->Read( &res ) )
        {
            ret.emplace_back( res );
        }
        return ret;
    }

private:
    std::unique_ptr<ServerStreamingRpc::FooService::Stub> m_client {};
};

#endif // FOOSERVICECLIENT_H
