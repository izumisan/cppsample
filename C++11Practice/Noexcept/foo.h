#ifndef FOO_H
#define FOO_H

#include <exception>

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;

public:
    void exceptionMethod()
    {
        throwException();
    }

    void noexceptionMethod() noexcept
    {
        throwException();  // noexceptメソッドから強制的に例外をスローする
    }

private:
    void throwException()
    {
        throw std::exception( "exception!!!" );
    }
};

#endif // FOO_H
