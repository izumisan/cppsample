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
void sub2( const int i = 0, const double d = 0.0, const std::string& s = "(empty)" )
{
    std::cout << "i: " << i << ", d: " << d << ", s: " << s << std::endl;
}
template<class... Args>
void func2( Args... args )
{
    // '...' で関数パラメータパックを展開して、foo2(int, doube, std::string)に渡す
    // 当然、func2を呼び出す際は、foo2を呼び出し可能な引数リストにである必要がある
    sub2( args... );
}

////////////////////////////////////////////////////////////////////////////////
// パラメータハパックの展開例２（再帰）
// 複数の任意の型パラメータを受け取る関数の場合は、
// 先頭とそれ以外を受け取る関数で再帰処理する.

// パラメータパックが空の場合に呼びされる
void sub3()
{
    std::cout << std::endl;
}

// 先頭とそれ以外に分割する
template<class Head, class... Tail>
void sub3( Head&& head, Tail&&... tail )
{
    std::cout << head << ", ";
    sub3( tail... );  // 再帰
}

template<class... Args>
void func3( Args... args )
{
    sub3( args... );
}

////////////////////////////////////////////////////////////////////////////////
// パラメータパックの展開例３（initializer_list）
// 要素の型が全て同じ場合、initializer_listを利用することでパラメータパックを展開できる
template<class T>
void sub4( std::initializer_list<T> list )
{
    for ( auto&& x : list )
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}

template<class... Args>
void func4( Args... args )
{
    sub4( { args... } );  // initializer_list<T>によるパック展開
}


#endif // VARIADICTEMPLATES_H
