#ifndef IPASER_H
#define IPASER_H

#include <memory>
#include "tokenizer.h"
#include "reversepolishnotation.h"

class IPaser
{
public:
    virtual void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) = 0;
};

#endif // IPASER_H
