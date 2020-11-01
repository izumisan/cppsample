#include <iostream>
#include <string>

#include <nats/nats.h>

// メッセージハンドラ
static void onRecieved( natsConnection* connection, natsSubscription* subscription, natsMsg* msg, void* closure )
{
    auto&& subject = std::string( natsMsg_GetSubject( msg ) );
    auto&& reply = natsMsg_GetReply( msg ) != nullptr ? std::string( natsMsg_GetReply( msg ) ) : std::string();
    auto&& data = std::string( natsMsg_GetData( msg ) );

    std::cout << "Recieved: { "
              << "subject: " << subject << ", "
              << "reply: " << reply << ", "
              << "data: " << data << " }" << std::endl;

    // natsMsgオブジェクトの破棄を忘れないように...
    natsMsg_Destroy( msg );

    *(bool*)(closure) = true;
}

int main()
{
    std::cout << "Subscriber start..." << std::endl;

    // NATSサーバーへの接続
    //
    // - natsConnection_ConnectTo(): urlを指定して接続する(see. Publisher)
    // - natsConnection_Connect(): natsOptionsオブジェクトを指定して接続する

    natsOptions* options = nullptr;
    natsOptions_Create( &options );
    natsOptions_SetURL( options, "nats://localhost:4222" );

    natsConnection* connection = nullptr;
    auto&& status = natsConnection_Connect( &connection, options );

    if ( status == NATS_OK )
    {
        std::cout << "connected." << std::endl;

        std::string bindingKey {};
        std::cout << "bindingKey: ";
        std::getline( std::cin, bindingKey );

        natsSubscription* subscription = nullptr;
        volatile bool done = false;

        // Subscribe
        //
        // 非同期型
        // - natsConnection_Subscribe()
        // - natsConnection_SubscribeTimeout()
        // - サブスクライブ時にメッセージハンドラ(void (natsConnection*, natsSubscription*, natsMsg*, void*)型)を指定する
        //
        // 同期型
        // - natsConnection_SubscribeSync()
        // - 受信メッセージをnatsSubscription_NextMsg()で取り出す
        natsConnection_Subscribe( &subscription, connection, bindingKey.c_str(), onRecieved, (void*)(&done) );


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
    natsOptions_Destroy( options );
    return 0;
}
