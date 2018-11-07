#include <algorithm>
#include <cctype>
#include "numberparser.h"

void NumberParser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& token = tokenizer->current();

    if ( std::all_of( token.cbegin(), token.cend(), std::isdigit ) )
    {
        tokenizer->moveNext();

        rpn->add( token );
    }
}
