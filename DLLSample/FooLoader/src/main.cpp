#include <iostream>
#include <memory>
#include "foolibrary.h"

int main()
{
    {
        auto&& foo = foo::FooLibrary::create();

        foo->setName( "foo1" );
        std::cout << foo->name() << std::endl;

        foo::FooLibrary::destroy( foo );
    }

    {
        // std::sharedで管理する場合、deleterを指定しないとリソースの解放ができなくなる
        // (std::sharedで管理した生ポインタをdeleteしてはならない)

        //auto&& foo = std::shared_ptr<foo::IFoo>( foo::FooLibrary::create() );
        //foo::FooLibrary::destroy( foo.get() );  // ダメ!!! 絶対!!!

        auto&& foo = std::shared_ptr<foo::IFoo>( foo::FooLibrary::create(), foo::FooLibrary::destroy );

        foo->setName( "foo2" );
        std::cout << foo->name() << std::endl;
    }

    return 0;
}
