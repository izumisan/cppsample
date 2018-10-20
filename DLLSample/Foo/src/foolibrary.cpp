#include "foolibrary.h"
#include "foo.h"

namespace foo
{

IFoo* createFoo()
{
    return new Foo();
}

void deleteFoo( IFoo* ptr )
{
    delete ptr;
}

} // namespace foo
