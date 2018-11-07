#include <regex>
#include "numberparser.h"

void NumberParser::parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn )
{
    auto&& token = tokenizer->current();

    if ( isNumber( token ) )
    {
        tokenizer->moveNext();

        rpn->add( token );
    }
}

bool NumberParser::isNumber( const std::string& str )
{
    bool ret = false;
    std::regex number_pattern( R"(^-?\d+(\.\d+)?\D*?$)" );
    std::smatch match;
    if ( std::regex_match( str, match, number_pattern ) )
    {
        ret = true;
    }
    return ret;
}
