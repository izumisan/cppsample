#ifndef FOOLIBRARY_H
#define FOOLIBRARY_H

#if defined(FOOLIBRARY_EXPORTS)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include "ifoo.h"

namespace foo
{
namespace FooLibrary
{

extern "C"
{
    DLLEXPORT IFoo* create();
    DLLEXPORT void destroy( IFoo* ptr );
}

} // namespace FooLibrary
} // namespace foo

#endif // FOOLIBRARY_H