#include "numberparser.h"
#include "expressionparser.h"
#include "factorparser.h"

void FactorParser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& number = NumberParser();
    number.parse( tokenizer, rpn );

    auto&& token = tokenizer->current();
    if ( token == "(" )
    {
        tokenizer->moveNext();

        auto&& expr = ExpressionParser();
        expr.parse( tokenizer, rpn );

        auto&& token2 = tokenizer->current();
        if ( token2 == ")" )
        {
            tokenizer->moveNext();
        }
        else
        {
            auto&& msg = std::string( "ERROR: " ) + __FILE__ + "(" + std::to_string( __LINE__ ) + ")";
            throw std::exception( msg.c_str() );
        }
    }
}
