#include "foolibrary.h"
#include "foo.h"

namespace foo
{
namespace FooLibrary
{

IFoo* create()
{
    return new Foo();
}

void destroy( IFoo* ptr )
{
    delete static_cast<Foo*>( ptr );
}

} // namespace FooLibrary
} // namespace foo
