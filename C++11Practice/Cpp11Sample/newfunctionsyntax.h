#ifndef NEWFUNCTIONSYNTAX_H
#define NEWFUNCTIONSYNTAX_H

#include <iostream>

auto plus( int a, int b ) -> int
{
    return a + b;
}

auto plus2( int a, int b ) -> decltype( a + b )
{
    return a + b;
}

auto returnVoidFunction() -> void
{
    std::cout << __func__ << std::endl;
}

auto newFunctionSyntax() -> void
{
    std::cout << plus( 1, 2 ) << std::endl;
    std::cout << plus2( 3, 4 ) << std::endl;

    returnVoidFunction();
}

#endif // NEWFUNCTIONSYNTAX_H
