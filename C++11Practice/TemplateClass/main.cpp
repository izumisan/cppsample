#include <iostream>
#include <string>
#include "foo.h"

int main()
{
    // Foo<int>, Foo<double>はexternされているので、
    // main.cppのコンパイルではコンパイルされない（main.oに含まれない）
    auto&& foo1 = Foo<int>(1);
    auto&& foo2 = Foo<double>(1.2);

    // Foo<unsined int>, Foo<long>は
    // main.cppのコンパイル時にコンパイルされる（main.oに含まれる）
    auto&& foo3 = Foo<unsigned int>(2u);
    auto&& foo4 = Foo<long>(2L);

    auto&& printfoo = [](auto& foo)
    {
        std::cout << foo.dataType() << ":" << foo.data() << std::endl;
    };

    printfoo( foo1 );
    printfoo( foo2 );
    printfoo( foo3 );
    printfoo( foo4 );

    return 0;
}
