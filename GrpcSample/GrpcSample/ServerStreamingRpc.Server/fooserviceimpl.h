#ifndef FOOSERVICEIMPL_H
#define FOOSERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class FooServiceImpl final : public ServerStreamingRpc::FooService::Service
{
public:
    virtual ::grpc::Status GetFooList( ::grpc::ServerContext* context,
                                       const ::ServerStreamingRpc::FooRequest* request,
                                       ::grpc::ServerWriter<::ServerStreamingRpc::FooResponse>* writer ) override
    {
        const int base = request->value() + 100;
        for ( int i = 0; i < 10; ++i )
        {
            auto&& res = ::ServerStreamingRpc::FooResponse();
            res.set_value( base + i );
            writer->Write( res );
        }
        return ::grpc::Status::OK;
    }
};

#endif // FOOSERVICEIMPL_H
