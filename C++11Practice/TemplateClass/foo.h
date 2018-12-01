#ifndef FOO_H
#define FOO_H

#include <string>
#include <typeinfo>

template<class T> class Foo
{
public:
    Foo() : m_data() {}
    Foo( const T& data ) : m_data( data ) {}

public:
    T data() const
    {
        return m_data;
    }
    std::string dataType() const
    {
        return typeid( T ).name();
    }

private:
    T m_data;
};

// よく使う型（Foo<int>, Foo<double>）をあらかじめ"foo.cpp"でインスタンス化し公開し、
// 利用側（"foo.h"のインクルード側）毎のインスタンス化を抑制する
// （コンパイル時間の短縮、オブジェクトサイズの増加を抑制できる）
extern template class Foo<int>;
extern template class Foo<double>;

#endif // FOO_H
