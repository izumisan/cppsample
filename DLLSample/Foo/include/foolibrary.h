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

extern "C"
{
    DLLEXPORT IFoo* createFoo();
    DLLEXPORT void deleteFoo( IFoo* ptr );
}

} // namespace foo

#endif // FOOLIBRARY_H