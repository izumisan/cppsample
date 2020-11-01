#include <iostream>
#include <string>

#include <nats/nats.h>

// メッセージハンドラ
static void onRecieved( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure );
static void onRecieved2( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure );

int main()
{
    std::cout << "Subscriber2 start..." << std::endl;

    natsConnection* connection = nullptr;
    auto&& status = natsConnection_ConnectTo( &connection, "nats://localhost:4222" );

    if ( status == NATS_OK )
    {
        std::cout << "connected." << std::endl;

        natsSubscription* subscription = nullptr;

        // 1つのnatsSubscriptionに対し、複数回のSubscribeが可能

        std::string bindingKey {};
        std::cout << "bindingKey1: ";
        std::getline( std::cin, bindingKey );
        natsConnection_Subscribe( &subscription, connection, bindingKey.c_str(), onRecieved, nullptr );

        std::string bindingKey2 {};
        std::cout << "bindingKey2: ";
        std::getline( std::cin, bindingKey2 );
        natsConnection_Subscribe( &subscription, connection, bindingKey2.c_str(), onRecieved2, nullptr );


        std::cout << "Press any key to quit." << std::endl;
        std::string input;
        std::getline( std::cin, input );

        // 切断
        natsConnection_Close( connection );
        std::cout << "disconnected." << std::endl;

        // オブジェクトの破棄は忘れないように...
        natsSubscription_Destroy( subscription );
    }
    else
    {
        std::cout << "Fail to connect server!" << std::endl;
    }

    // オブジェクトの破棄
    natsConnection_Destroy( connection );
    return 0;
}

void onRecieved( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure )
{
    auto&& subject = std::string( natsMsg_GetSubject( msg ) );
    auto&& reply = natsMsg_GetReply( msg ) != nullptr ? std::string( natsMsg_GetReply( msg ) ) : std::string();
    auto&& data = std::string( natsMsg_GetData( msg ) );

    std::cout << "Recieved: { "
              << "subject: " << subject << ", "
              << "reply: " << reply << ", "
              << "data: " << data << " }" << std::endl;

    natsMsg_Destroy( msg );
}

void onRecieved2( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure )
{
    auto&& subject = std::string( natsMsg_GetSubject( msg ) );
    auto&& reply = natsMsg_GetReply( msg ) != nullptr ? std::string( natsMsg_GetReply( msg ) ) : std::string();
    auto&& data = std::string( natsMsg_GetData( msg ) );

    std::cout << "Recieved2: { "
              << "subject: " << subject << ", "
              << "reply: " << reply << ", "
              << "data: " << data << " }" << std::endl;

    natsMsg_Destroy( msg );
}
