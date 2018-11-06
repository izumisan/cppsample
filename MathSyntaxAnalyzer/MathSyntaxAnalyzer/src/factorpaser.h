#ifndef FACTORPASER_H
#define FACTORPASER_H

#include "ipaser.h"

class FactorPaser : public IPaser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;

};

#endif // FACTORPASER_H
