#include <iostream>
#include "foo.h"
int main()
{
    auto&& foo = foo::Foo();

    std::cout << "start..." << std::endl;

    foo.sleep( 3 );

    std::cout << "end." << std::endl;

    return 0;
}
