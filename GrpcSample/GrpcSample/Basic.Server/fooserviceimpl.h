#ifndef FOOSERVICEIMPL_H
#define FOOSERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

namespace basic
{

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
