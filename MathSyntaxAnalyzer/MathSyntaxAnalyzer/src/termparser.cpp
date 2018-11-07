#include "factorparser.h"
#include "termparser.h"

void TermParser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& factor = FactorParser();
    factor.parse( tokenizer, rpn );
    
    auto&& token = tokenizer->current();
    while ( ( token == "*" ) || ( token == "/" ) )
    {
        tokenizer->moveNext();

        auto&& factor2 = FactorParser();
        factor2.parse( tokenizer, rpn );

        rpn->add( token );

        token = tokenizer->current();
    }
}
