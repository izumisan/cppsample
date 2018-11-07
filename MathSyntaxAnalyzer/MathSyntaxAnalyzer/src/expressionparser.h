#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include "iparser.h"

class ExpressionParser : public IParser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;
};

#endif // EXPRESSIONPARSER_H
