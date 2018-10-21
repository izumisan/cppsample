#ifndef FOO_H
#define FOO_H

#include "ifoo.h"

namespace foo
{

class Foo : public IFoo
{
public:
    Foo();
    Foo( const std::string& name );
    Foo( const Foo& ) = default;
    virtual ~Foo();
public:
    std::string name() const override;
    void setName( const std::string& name ) override;

private:
    std::string m_name;
};

}  // namespace foo

#endif // FOO_H