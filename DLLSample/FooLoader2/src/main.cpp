#include <iostream>
#include <string>
#include <Windows.h>
#include "ifoo.h"

int main()
{
    auto&& path = std::string( "Foo.dll" );

    HINSTANCE handler = ::LoadLibraryA( path.c_str() );
    if ( handler != nullptr )
    {
        // 名前空間を含めた完全名（foo::FooLibrary::create）ではないことに注意
        auto&& createFunc = reinterpret_cast<foo::IFoo* (*)()>( ::GetProcAddress( handler, "create" ) );
        auto&& destroyFunc = reinterpret_cast<void (*)(foo::IFoo*)>( ::GetProcAddress( handler, "destroy" ) );

        if ( ( createFunc != nullptr ) && ( destroyFunc != nullptr ) )
        {
            auto&& foo = createFunc();

            foo->setName( "foo" );
            std::cout << foo->name() << std::endl;

            destroyFunc( foo );
        }
        else
        {
            std::cout << "Fail to load function." << std::endl;
        }

        ::FreeLibrary( handler );
    }
    else
    {
        std::cout << "Fail to load Library." << std::endl;
    }

    return 0;
}
