#include <iostream>
#include <regex>
#include <string>

#include <nats/nats.h>

static bool parse( const std::string& input, std::string& routingKey, std::string& body );

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

        while ( true )
        {
            std::string input {};
            std::cout << "{routingKey} {body}: ";
            std::getline( std::cin, input );

            if ( input == "quit" )
            {
                break;
            }

            std::string routingKey {};
            std::string body {};
            if ( parse( input, routingKey, body ) )
            {
                // publish
                //
                // - natsConnection_Publish(): バイト列をpubする
                // - natsConnection_PublishString(): 文字列データをpubする
                // - natsConnection_PublishMsg(): natsMsgオブジェクトをpubする
                natsConnection_PublishString( connection, routingKey.c_str(), body.c_str() );
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

bool parse( const std::string& input, std::string& routingKey, std::string& body )
{
    bool ret = false;
    if ( input.empty() != true )
    {
        const std::regex regex( "(.+?) (.*)" );
        std::smatch match {};
        if ( std::regex_search( input, match, regex ) && ( match.size() == 3 ) )
        {
            routingKey = match.str( 1 );
            body = match.str( 2 );
        }
        else
        {
            routingKey = input;
            body = "";
        }
        ret = true;
    }
    return ret;
}
