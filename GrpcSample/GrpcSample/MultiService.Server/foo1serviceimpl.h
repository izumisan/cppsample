#ifndef FOO1SERVICEIMPL_H
#define FOO1SERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class Foo1ServiceImpl final : public MultiService::Foo1Service::Service
{
public:
    virtual ::grpc::Status Foo( ::grpc::ServerContext* context, 
                                const ::MultiService::FooRequest* request, 
                                ::MultiService::FooResponse* response ) override
    {
        response->set_value( request->value() + 1 );
        return ::grpc::Status::OK;
    }
};

#endif // FOO1SERVICEIMPL_H
