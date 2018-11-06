#ifndef TERMPASER_H
#define TERMPASER_H

#include "ipaser.h"

class TermPaser : public IPaser
{
public:
    void parse( const std::shared_ptr<Tokenizer>& tokenizer, const std::shared_ptr<ReversePolishNotation>& rpn ) override;

};

#endif // TERMPASER_H
