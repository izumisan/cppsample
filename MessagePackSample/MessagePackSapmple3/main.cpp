#include <iostream>
#include "msgpack.hpp"
#include "foo.h"

int main()
{
    auto&& foo = Foo();
    foo.setInt( 7 );
    foo.setDouble( 777.7777 );
    foo.setString( "foo" );
    foo.setVector( { "foo", "bar", "baz" } );
    foo.setMap(
    {
        { "foo", "FOO" },
        { "bar", "BAR" },
        { "baz", "BAZ" }
    } );

    // �V���A���C�Y
    //--------------------------------------------------------------------------
    msgpack::sbuffer buffer;
    msgpack::pack( buffer, foo );

    std::cout << "sizeof: " << sizeof( foo ) << " buffer: " << buffer.size() << std::endl;


    // �f�V���A���C�Y
    //--------------------------------------------------------------------------
    msgpack::object_handle handle = msgpack::unpack( buffer.data(), buffer.size() );
    msgpack::object object = handle.get();

    std::cout << object << std::endl;

    auto&& refoo = Foo();
    object.convert( refoo );

    std::cout << foo.toString() << std::endl;

    // as()�ł��\
    auto&& x = object.as<Foo>();
    std::cout << x.toString() << std::endl;

    return 0;
}
