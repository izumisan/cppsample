#include <iostream>
#include <type_traits>
#include "foo.h"

int main()
{
    auto&& foo = Foo();

    // noexcept()で、noexceptメソッドか否かを判定できる

    // noexceptメソッドではないので、コンパイルエラーとなる
    //static_assert( noexcept( foo.exceptionMethod() ), "NOT noexcept-method" );

    // noexceptメソッドなので、コンパイルOK
    static_assert( noexcept( foo.noexceptionMethod() ), "NOT noexcept-method" );

    try
    {
        std::cout << "------ exceptionMethod()" << std::endl;
        foo.exceptionMethod();  // 例外スロー
    }
    catch ( std::exception& ex )
    {
        std::cout << "catch" << std::endl;
        std::cout << ex.what() << std::endl;
    }


    try
    {
        std::cout << "------ noexceptionMethod()" << std::endl;

        // noexceptメソッドがexceptionをスローした場合、catchできずにterminateする
        foo.noexceptionMethod();  // 例外スロー
    }
    catch ( std::exception& ex )
    {
        std::cout << "catch 1";
        std::cout << ex.what() << std::endl;
    }
    catch ( ... )
    {
        std::cout << "catch 2";
    }

    return 0;
}
