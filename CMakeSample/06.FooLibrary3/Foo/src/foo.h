#ifndef FOO_H
#define FOO_H

#include <string>

namespace foo
{

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;
public:
    std::string hello() const;
};

} // namespace foo

#endif // FOO_H
