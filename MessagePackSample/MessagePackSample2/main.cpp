#include <iostream>
#include <string>
#include "msgpack.hpp"

int main()
{
    msgpack::sbuffer buffer = {};

    // packerによる異なる型のパック
    msgpack::packer<msgpack::sbuffer> packer( &buffer );
    packer.pack( "foo" );
    packer.pack( 777 );
    packer.pack( 1.23f );
    packer.pack( 123.456 );
    packer.pack( true );
    packer.pack( std::vector<int>( { 1, 2, 3 } ) );
    packer.pack( std::vector<std::string>( { "Hello", "World" } ) );

    std::cout << "size: " << buffer.size() << std::endl;


    // unpackerによるデシリアライズ
    msgpack::unpacker unpacker = {};

    // バッファの読み出し
    unpacker.reserve_buffer( buffer.size() );
    memcpy( unpacker.buffer(), buffer.data(), buffer.size() );
    unpacker.buffer_consumed( buffer.size() );
    
    msgpack::object_handle handle = {};
    while ( unpacker.next( handle ) )
    {
        msgpack::object obj = handle.get();
        switch ( obj.type )
        {
        case msgpack::type::BOOLEAN:
            std::cout << "bool: ";
            break;
        case msgpack::type::POSITIVE_INTEGER:
            std::cout << "int: ";
            break;
        case msgpack::type::NEGATIVE_INTEGER:
            std::cout << "uint: ";
            break;
        case msgpack::type::FLOAT32:
            std::cout << "float: ";
            break;
        case msgpack::type::FLOAT64:
            std::cout << "double: ";
            break;
        case msgpack::type::STR:
            std::cout << "string: ";
            break;
        case msgpack::type::ARRAY:
            std::cout << "array: ";
            break;
        default:
            break;
        }
        std::cout << obj << std::endl;
    }


    std::string buff;
    std::getline( std::cin, buff );

    return 0;
}
