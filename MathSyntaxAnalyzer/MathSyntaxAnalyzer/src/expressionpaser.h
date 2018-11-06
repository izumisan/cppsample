#ifndef EXPRESSIONPASER_H
#define EXPRESSIONPASER_H

#include "ipaser.h"

class ExpressionPaser : public IPaser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;
};

#endif // EXPRESSIONPASER_H
