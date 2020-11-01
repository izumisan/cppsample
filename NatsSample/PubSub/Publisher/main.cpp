#include <iostream>
#include <string>

#include <nats/nats.h>

int main()
{
    std::cout << "Publisher start..." << std::endl;

    // NATSサーバーへの接続
    //
    // - natsConnection_ConnectTo(): urlを指定して接続する
    // - natsConnection_Connect(): natsOptionsオブジェクトを指定して接続する(see. Subscriber)
    natsConnection* connection = nullptr;
    auto&& status = natsConnection_ConnectTo( &connection, "nats://localhost:4222" );

    if ( status == NATS_OK )
    {
        std::cout << "connected." << std::endl;

        std::string routingKey {};
        std::cout << "routingKey: ";
        std::getline( std::cin, routingKey );

        while ( true )
        {
            std::string message {};
            std::cout << "message: ";
            std::getline( std::cin, message );
            if ( message == "quit" )
            {
                break;
            }

            // publish
            //
            // - natsConnection_Publish(): バイト列をpubする
            // - natsConnection_PublishString(): 文字列データをpubする
            // - natsConnection_PublishMsg(): natsMsgオブジェクトをpubする
            natsConnection_PublishString( connection, routingKey.c_str(), message.c_str() );
        }

        // 切断
        natsConnection_Close( connection );

        std::cout << "disconnected." << std::endl;
    }
    else
    {
        std::cout << "Fail to connect server!" << std::endl;
    }

    // オブジェクトの破棄
    natsConnection_Destroy( connection );

    return 0;
}
