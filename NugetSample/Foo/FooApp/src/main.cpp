#include <iostream>
#include "foo.h"

int main()
{
#if defined(HAS_FOO)
    std::cout << "HAS_FOO defined" << std::endl;
#else
    std::cout << "HAS_FOO not defined" << std::endl;
#endif

    auto&& foo = Foo();
    std::cout << foo.doSomething() << std::endl;
    std::cout << foo.doSomething() << std::endl;
    std::cout << foo.doSomething() << std::endl;
    
    return 0;
}
