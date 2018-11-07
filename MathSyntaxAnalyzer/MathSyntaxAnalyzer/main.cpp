#include <memory>
#include <string>
#include <iostream>

#include "tokenizer.h"
#include "reversepolishnotation.h"
#include "expressionparser.h"

int main()
{
    //std::string&& expr = "1 + 2 - 3 * 4 / 5";  //=> 0.6
    //std::string&& expr = "1-2";  // ‚±‚Ì‘Ž®‚É‚Í‘Î‰ž‚Å‚«‚Ä‚¢‚È‚¢...
    //std::string&& expr = "1 + (2 - 3) * 4 / 5";  //=> 0.2
    std::string&& expr = "(1 + (2 - 3) * 4) / 5";  //=> -0.6

    auto&& tokenizer = std::make_shared<Tokenizer>( expr );
    auto&& rpn = std::make_shared<ReversePolishNotation>();

    auto&& parser = ExpressionParser();
    parser.parse( tokenizer, rpn );

    if ( tokenizer->isEnd() )
    {
        std::cout << rpn->calculate() << std::endl;
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
