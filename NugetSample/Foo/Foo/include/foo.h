#ifndef FOO_H
#define FOO_H

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;
public:
    int doSomething();
private:
    int m_count = 0;
};

#endif // FOO_H