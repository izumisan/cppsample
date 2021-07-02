#ifndef FOO2SERVICEIMPL_H
#define FOO2SERVICEIMPL_H

#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class Foo2ServiceImpl final : public MultiService::Foo2Service::Service
{
public:
    virtual ::grpc::Status Foo( ::grpc::ServerContext* context,
                                const ::MultiService::FooRequest* request,
                                ::MultiService::FooResponse* response ) override
    {
        response->set_value( request->value() + 2 );
        return ::grpc::Status::OK;
    }
};

#endif // FOO2SERVICEIMPL_H

