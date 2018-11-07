#ifndef TERMPARSER_H
#define TERMPARSER_H

#include "iparser.h"

class TermParser : public IParser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;
};

#endif // TERMPARSER_H
