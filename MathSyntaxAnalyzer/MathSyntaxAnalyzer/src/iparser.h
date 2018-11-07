#ifndef IPARSER_H
#define IPARSER_H

#include <memory>
#include "tokenizer.h"
#include "reversepolishnotation.h"

class IParser
{
public:
    virtual void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) = 0;
};

#endif // IPARSER_H
