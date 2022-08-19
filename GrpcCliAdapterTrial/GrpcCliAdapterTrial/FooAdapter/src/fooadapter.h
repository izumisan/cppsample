#ifndef FOOADAPTER_H
#define FOOADAPTER_H

#include "foo.h"

namespace adapter
{

public ref class FooAdapter
{
public:
    FooAdapter();
    ~FooAdapter();
    !FooAdapter();
public:
    int Sleep( const int seconds );
    int Sleep2( const int seconds );

private:
    foo::Foo* m_foo = nullptr;
};

} // namespace adapter

#endif // FOOADAPTER_H
