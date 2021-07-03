#ifndef FOOSERVICECLIENT_H
#define FOOSERVICECLIENT_H

#include <vector>
#include <grpcpp/grpcpp.h>
#include "foo.grpc.pb.h"

class FooServiceClient
{
public:
    FooServiceClient( const std::shared_ptr<::grpc::Channel>& channel )
        : m_client( ClientStreamingRpc::FooService::NewStub( channel ) )
    {
    }

public:
    int total( const std::vector<int>& values )
    {
        int ret = 0;

        ::grpc::ClientContext context {};
        ClientStreamingRpc::FooResponse response {};

        // proto�t�@�C���Œ�`�����T�[�r�X�֐�(Total)�ɂ��A
        // ���N�G�X�g���C�^�[(ClientWriter)���擾�ł���
        auto&& writer = m_client->Total( &context, &response );
        for ( auto&& value : values )
        {
            ClientStreamingRpc::FooRequest req {};
            req.set_value( value );
            writer->Write( req );
        }

        // ���N�G�X�g�̏������݂��I���������Ƃ��T�[�o�[�ɒʒm����
        writer->WritesDone();

        // Finish()�̎��s�ɂ��A�T�[�o�[����̃��X�|���X���擾����
        auto&& status = writer->Finish();
        if ( status.ok() )
        {
            ret = response.value();
        }
        return ret;
    }

private:
    std::unique_ptr<ClientStreamingRpc::FooService::Stub> m_client {};
};

#endif // FOOSERVICECLIENT_H
