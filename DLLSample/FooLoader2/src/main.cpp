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
        // ���O��Ԃ��܂߂����S���ifoo::FooLibrary::create�j�ł͂Ȃ����Ƃɒ���
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
