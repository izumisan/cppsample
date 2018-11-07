#include <memory>
#include <string>
#include <iostream>

#include "tokenizer.h"
#include "reversepolishnotation.h"
#include "expressionparser.h"

int main()
{
    //std::string&& expr = "1 + 2 + 3 + 4 + 5";
    //std::string&& expr = "((2 + 3) * (5 + -2)) / -3";
    std::string&& expr = "1290 * 1.08";

    auto&& tokenizer = std::make_shared<Tokenizer>( expr );
    auto&& rpn = std::make_shared<ReversePolishNotation>();

    auto&& parser = ExpressionParser();
    parser.parse( tokenizer, rpn );

    std::cout << rpn->calculate() << std::endl;

    return 0;
}
