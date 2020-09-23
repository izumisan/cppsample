#include <iostream>
#include <string>

#include <nats.h>

int main()
{
    std::cout << "Publisher start..." << std::endl;

    natsConnection* connection = nullptr;

    // NATSサーバーへの接続
    //
    // - natsConnection_ConnectTo(): urlを指定して接続する
    // - natsConnection_Connect(): natsOptionsオブジェクトを指定して接続する(see. Subscriber)
    auto&& status = natsConnection_ConnectTo( &connection, "nats://localhost:4222" );

    if ( status == NATS_OK )
    {
        std::cout << "connected." << std::endl;

        while ( true )
        {
            std::string input;
            std::cout << "> ";
            std::cin >> input;

            if ( input != "quit" )
            {
                // publish
                //
                // - natsConnection_Publish(): バイト列をpubする
                // - natsConnection_PublishString(): 文字列データをpubする
                // - natsConnection_PublishMsg(): natsMsgオブジェクトをpubする
                natsConnection_PublishString( connection, "foo.bar", input.c_str() );
            }
            else
            {
                break;
            }
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
