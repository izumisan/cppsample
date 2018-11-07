#ifndef FACTORPARSER_H
#define FACTORPARSER_H

#include "iparser.h"

class FactorParser : public IParser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;
};

#endif // FACTORPARSER_H
