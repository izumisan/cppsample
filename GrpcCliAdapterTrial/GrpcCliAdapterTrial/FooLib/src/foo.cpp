#include <thread>
#include <chrono>

#include "foo.h"

namespace foo
{

int Foo::sleep( const int seconds )
{
    std::this_thread::sleep_for( std::chrono::seconds( seconds ) );

    return seconds;
}

int Foo::sleep2( const int seconds )
{
    std::this_thread::sleep_for( std::chrono::seconds( seconds ) );

    return seconds;
}

} // namespace foo
