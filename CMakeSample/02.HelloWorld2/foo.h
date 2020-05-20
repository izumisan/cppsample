#ifndef FOO_H
#define FOO_H

#include <string>

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;
public:
    std::string hello() const;
};

#endif // FOO_H
