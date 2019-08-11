#include <iostream>
#include "foo.h"

int main()
{
    std::cout << "start..." << std::endl;

    auto&& foo = Foo();
    std::cout << foo.doSomething() << std::endl;
    std::cout << foo.doSomething() << std::endl;
    std::cout << foo.doSomething() << std::endl;
    
    return 0;
}
