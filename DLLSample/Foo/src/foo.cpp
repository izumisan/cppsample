#include <iostream>
#include "foo.h"

namespace foo
{

Foo::Foo()
    : Foo( "no-name" )
{
}

Foo::Foo( const std::string& name )
    : m_name( name )
{
    std::cout << "[" << m_name << "]" << "Foo::ctor" << std::endl;
}

Foo::~Foo()
{
    std::cout << "[" << m_name << "]" << "Foo::dtor" << std::endl;
}

std::string Foo::name() const
{
    return m_name;
}

void Foo::setName( const std::string& name )
{
    m_name = name;
}

} // namespace foo
