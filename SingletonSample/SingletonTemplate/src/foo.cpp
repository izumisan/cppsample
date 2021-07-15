#include <iostream>
#include "foo.h"

Foo::Foo()
{
    std::cout << "Foo::ctor." << std::endl;
}

Foo::~Foo()
{
    std::cout << "Foo::dtor." << std::endl;
}

int Foo::count() const
{
    return m_count;
}

void Foo::up()
{
    ++m_count;
}

void Foo::down()
{
    --m_count;
}
