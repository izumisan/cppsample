#ifndef FOOSERVICEIMPL_H
#define FOOSERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class FooServiceImpl final : public ClientStreamingRpc::FooService::Service
{
public:
    virtual ::grpc::Status Total( ::grpc::ServerContext* context, 
                                  ::grpc::ServerReader<::ClientStreamingRpc::FooRequest>* reader, 
                                  ::ClientStreamingRpc::FooResponse* response ) override
    {
        int total = 0;
        ClientStreamingRpc::FooRequest req {};
        while ( reader->Read( &req ) )
        {
            total += req.value();
        }
        response->set_value( total );
        return ::grpc::Status::OK;
    }
};

#endif // FOOSERVICEIMPL_H
