#ifndef FOOSERVICEIMPL_H
#define FOOSERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

namespace basic
{

/* foo.proto
syntax = "proto3";
package basic;
service FooService
{
    rpc FooMethod( FooRequest ) returns( FooReply ) {}
}
message FooRequest
{
    string value = 1;
}
message FooReply
{
    string value = 1;
}
*/

// foo.protoから自動生成された`FooService::Service`を継承したサービスクラスを定義し、
// 関数を実装する

class FooServiceImpl final : public FooService::Service
{
public:
    grpc::Status FooMethod( grpc::ServerContext* context, const FooRequest* request, FooReply* reply ) override
    {
        reply->set_value( "Hello " + request->value() );
        return grpc::Status::OK;
    }
};

} // namespace basic

#endif // FOOSERVICEIMPL_H
