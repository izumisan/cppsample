#ifndef NUMBERPARSER_H
#define NUMBERPARSER_H

#include "iparser.h"

class NumberParser : public IParser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;

    static bool isNumber( const std::string& str );
};

#endif // NUMBERPARSER_H
