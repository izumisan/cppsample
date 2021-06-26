#include <iostream>
#include <string>

#include <nats/nats.h>

int main()
{
    std::cout << "Requestor start..." << std::endl;

    // NATSサーバーへの接続
    natsConnection* connection = nullptr;
    natsStatus s = natsConnection_ConnectTo( &connection, "nats://localhost:4222" );

    if ( s == NATS_OK )
    {
        std::cout << "connected." << std::endl;

        std::cout << "Press Enter to start." << std::endl;
        std::string input;
        std::getline( std::cin, input );

        for ( int i = 0; i < 10; ++i )
        {
            std::cout << "req: " << i << ", ";

            // Request用関数
            // - replyキーを指定してpublish
            //   - natsConnection_PublishRequest()
            //   - natsConnection_PublishRequestString()
            // - replyメッセージを待機する
            //   - natsConnection_Request()
            //   - natsConnection_RequestString()
            //   - natsConnection_RequestMsg()

            natsMsg* reply = nullptr;
            if ( i % 2 == 0 )
            {
                s = natsConnection_Request( &reply, connection, "plusone", reinterpret_cast<const void*>( &i ), sizeof( i ), 1000 );
            }
            else
            {
                s = natsConnection_Request( &reply, connection, "plustwo", reinterpret_cast<const void*>( &i ), sizeof( i ), 1000 );
            }

            if ( s != NATS_TIMEOUT )
            {
                if ( const int* result = reinterpret_cast<const int*>( natsMsg_GetData( reply ) );
                     result != nullptr )
                {
                    std::cout << "reply: " << *result << std::endl;
                }
            }
            else
            {
                std::cout << "NO RESPONSE" << std::endl;
            }

            natsMsg_Destroy( reply );
        }

        // NATSサーバーから切断
        natsConnection_Close( connection );
        std::cout << "disconnected." << std::endl;
    }
    else
    {
        std::cout << "Fail to connect server!" << std::endl;
    }

    natsConnection_Destroy( connection );

    return 0;
}
