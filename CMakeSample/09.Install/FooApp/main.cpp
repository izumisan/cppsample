#include <iostream>
#include "foo.h"
#include "bar.h"

int main() 
{
    auto&& foo = Foo();
    auto&& bar = Bar();
    std::cout << foo.value() << std::endl;
    std::cout << bar.value() << std::endl;
}
