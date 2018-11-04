#include <iostream>
#include "tokenizer.h"

int main()
{
    //auto&& tokenizer = Tokenizer( "1 + 2 - 3 * 4 / 5" );
    auto&& tokenizer = Tokenizer( "1 + 2 - 3 * 4 / 5" );
    //auto&& tokenizer = Tokenizer( "-1.23+4.56-7.89" );
    //auto&& tokenizer = Tokenizer( "-1.23+4.56+(-7.89)" );
    //auto&& tokenizer = Tokenizer( "((2+4) * (10 + -5)) / 10" );

    auto&& token = tokenizer.current();
    do
    {
        std::cout << token << std::endl;
    } while ( ( token = tokenizer.next() ) != "" );

    return 0;
}
