#include "termpaser.h"
#include "expressionpaser.h"

void ExpressionPaser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& term = TermPaser();
    term.parse( tokenizer, rpn );

    auto&& token = tokenizer->current();
    while ( ( token == "+" ) || ( token == "-" ) )
    {
        tokenizer->next();

        auto&& term2 = TermPaser();
        term2.parse( tokenizer, rpn );

        token = tokenizer->current();
    }
}
