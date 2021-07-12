#include <iostream>
#include "foo.h"

int main()
{
    auto&& foo = Foo();
    std::cout << foo.value() << std::endl;
    return 0;
}
