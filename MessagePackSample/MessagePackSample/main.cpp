#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "msgpack.hpp"

int main()
{
    std::vector<std::string> strlist = { "Hello World", "MessagePack" };

    // シリアライズ
    msgpack::sbuffer buffer = {};
    msgpack::pack( buffer, strlist );

    std::cout << "sizeof: " << sizeof( strlist ) << " buffer: " << buffer.size() << std::endl;


    // デシリアライズ
    std::vector<std::string> deserialized = {};
    msgpack::object_handle handle = msgpack::unpack( buffer.data(), buffer.size() );
    msgpack::object obj = handle.get();
    obj.convert( deserialized );

    bool isEqual = std::equal( strlist.cbegin(), strlist.cend(), deserialized.cbegin(), deserialized.cend() );
    assert( isEqual );

    // msgpack::objectは、std::coutでプリント可能
    std::cout << obj << std::endl;

    return 0;
}
