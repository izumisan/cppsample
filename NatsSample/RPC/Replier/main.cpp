#include <iostream>
#include <string>

#include <nats/nats.h>

static void onPlusOne( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure );

static void publish( const std::string& routingKey, const void* bytes, int size );

static natsConnection* connection_ = nullptr;

int main()
{
    std::cout << "Replier start..." << std::endl;

    // NATSサーバーへの接続
    natsStatus s = natsConnection_ConnectTo( &connection_, "nats://localhost:4222" );

    if ( s == NATS_OK )
    {
        std::cout << "connected!" << std::endl;

        std::string procedureKey( "plusone" );
        natsSubscription* subscription = nullptr;
        volatile bool done = false;

        natsConnection_Subscribe( &subscription, connection_, procedureKey.c_str(), onPlusOne, (void*)( &done ) );

        std::cout << "running..." << std::endl;

        std::cout << "Press any key to quit." << std::endl;
        std::string input;
        std::getline( std::cin, input );

        // NATSサーバーから切断
        natsConnection_Close( connection_ );
        std::cout << "disconnected." << std::endl;

        natsSubscription_Destroy( subscription );
    }
    else
    {
        std::cout << "Fail to connect server!" << std::endl;
    }

    natsConnection_Destroy( connection_ );

    return 0;
}

void onPlusOne( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure )
{
    auto&& reply = ( natsMsg_GetReply( msg ) != nullptr ) ? std::string( natsMsg_GetReply( msg ) ) : std::string();
    auto&& data = std::string( natsMsg_GetData( msg ) );

    if ( reply.empty() != true )
    {
        const int value = *( reinterpret_cast<const int*>( data.c_str() ) );
        int result = value + 1;

        publish( reply, &result, sizeof( result ) );

        std::cout << "input: " << value << ", reply: " << result << std::endl;
    }

    natsMsg_Destroy( msg );

    *(bool*)(closure) = true;
}

void publish( const std::string& routingKey, const void* bytes, int size )
{
    natsConnection_Publish( connection_, routingKey.c_str(), bytes, size );
}

