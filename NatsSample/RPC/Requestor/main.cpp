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

        const std::string procedureKey( "plusone" );
        for ( int i = 0; i < 10; ++i )
        {
            std::cout << "req: " << i << ", ";

            natsMsg* reply = nullptr;
            s = natsConnection_Request( &reply, connection, procedureKey.c_str(), reinterpret_cast<const void*>( &i ), sizeof( i ), 10000 );

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
    }
    else
    {
        std::cout << "Fail to connect server!" << std::endl;
    }

    natsConnection_Close( connection );
    std::cout << "disconnected." << std::endl;

    natsConnection_Destroy( connection );

    return 0;
}
