#include <iostream>
#include "tokenizer.h"

int main()
{
    //auto&& tokenizer = Tokenizer( "-1.23+4.56-7.89" );
    auto&& tokenizer = Tokenizer( "-1.23+4.56+(-7.89)" );
    //auto&& tokenizer = Tokenizer( "((2+4) * (10 + -5)) / 10" );

    return 0;
}
