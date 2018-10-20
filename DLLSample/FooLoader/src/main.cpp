#include <iostream>
#include "foolibrary.h"

int main()
{
    auto&& foo = foo::createFoo();
    std::cout << foo->name() << std::endl;
    return 0;
}
