#include <iostream>
#include "barlibrary.h"

namespace bar
{
namespace BarLibrary
{

int __cdecl cdeclMethod( int x, int y )
{
    std::cout << __func__ << std::endl;
    return x + y;
}

int __stdcall stdcallMethod( int x, int y )
{
    std::cout << __func__ << std::endl;
    return x + y;
}

int defExportMethod( int x, int y )
{
    std::cout << __func__ << std::endl;
    return x + y;
}

}  // namespace BarLibrary
}  // namespace bar
