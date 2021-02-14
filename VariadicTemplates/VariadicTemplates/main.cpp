#include <iostream>
#include "variadictemplates.h"

int main()
{
    // func1()
    {
        func1();  // => 0
        func1( 1, 2.2, "3" );  // => 3
    }

    // func2()
    {
        func2();  // => i: 0, d: 0, s: (empty)
        func2( 1, 2.2 );  // => i: 1, d: 2.2, s: (empty)
        func2( 1, 2.2, "3" );  // => i: 1, d: 2.2, s: 3
//        foo2( "abc" );  // func2（）はここに展開されて　foo2("abc")　を呼び出そうするので、コンパイルエラーとなる
    }

    return 0;
}
