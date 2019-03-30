#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "msgpack.hpp"

int main()
{
    std::vector<std::string> strlist = { "Hello World", "MessagePack" };

    // �V���A���C�Y
    msgpack::sbuffer buffer = {};
    msgpack::pack( buffer, strlist );

    std::cout << "sizeof: " << sizeof( strlist ) << " buffer: " << buffer.size() << std::endl;


    // �f�V���A���C�Y
    std::vector<std::string> deserialized = {};
    msgpack::object_handle handle = msgpack::unpack( buffer.data(), buffer.size() );
    msgpack::object obj = handle.get();
    obj.convert( deserialized );

    bool isEqual = std::equal( strlist.cbegin(), strlist.cend(), deserialized.cbegin(), deserialized.cend() );
    assert( isEqual );

    // msgpack::object�́Astd::cout�Ńv�����g�\
    std::cout << obj << std::endl;

    return 0;
}
