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
        // std::shared�ŊǗ�����ꍇ�Adeleter���w�肵�Ȃ��ƃ��\�[�X�̉�����ł��Ȃ��Ȃ�
        // (std::shared�ŊǗ��������|�C���^��delete���Ă͂Ȃ�Ȃ�)

        //auto&& foo = std::shared_ptr<foo::IFoo>( foo::FooLibrary::create() );
        //foo::FooLibrary::destroy( foo.get() );  // �_��!!! ���!!!

        auto&& foo = std::shared_ptr<foo::IFoo>( foo::FooLibrary::create(), foo::FooLibrary::destroy );

        foo->setName( "foo2" );
        std::cout << foo->name() << std::endl;
    }

    return 0;
}
