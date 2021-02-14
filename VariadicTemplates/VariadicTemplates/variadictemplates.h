#ifndef VARIADICTEMPLATES_H
#define VARIADICTEMPLATES_H

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////
// 可変引数テンプレート関数例
// - Argsやargsはパラメータパックといい、Argsはテンプレートパラメータパック、argsを関数パラメータパックと言う.
// - '...' の位置に注意.
template<class... Args>
void func1( Args... args )
{
    // sizeof...()で、パラメータパックのサイズが取得できる
    std::cout << sizeof...( args ) << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// パラメータパックの展開例１
void foo2( const int i = 0, const double d = 0.0, const std::string& s = "(empty)" )
{
    std::cout << "i: " << i << ", d: " << d << ", s: " << s << std::endl;
}
template<class... Args>
void func2( Args... args )
{
    // '...' で関数パラメータパックを展開して、foo2(int, doube, std::string)に渡す
    // 当然、func2を呼び出す際は、foo2を呼び出し可能な引数リストにである必要がある
    foo2( args... );
}

////////////////////////////////////////////////////////////////////////////////



#endif // VARIADICTEMPLATES_H
