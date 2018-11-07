#include "termparser.h"
#include "expressionparser.h"

void ExpressionParser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& term = TermParser();
    term.parse( tokenizer, rpn );

    auto&& token = tokenizer->current();
    while ( ( token == "+" ) || ( token == "-" ) )
    {
        tokenizer->moveNext();

        auto&& term2 = TermParser();
        term2.parse( tokenizer, rpn );

        rpn->add( token );

        token = tokenizer->current();
    }
}
