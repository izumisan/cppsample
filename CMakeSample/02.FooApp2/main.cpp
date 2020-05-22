#include <iostream>
#include "foo.h"

int main()
{
    auto&& foo = Foo();
    std::cout << foo.hello() << std::endl;
    return 0;
}
