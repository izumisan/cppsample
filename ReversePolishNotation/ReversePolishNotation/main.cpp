#include <iostream>
#include <vector>
#include "reversepolishnotation.h"

int main()
{
    auto&& print = []( const std::vector<std::string>& expression, double result )
    {
        std::cout << "   RPN: ";
        for ( auto& x : expression )
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
        std::cout << "RESULT: " << result << std::endl;
    };

    {
        auto&& rpn = rpn::ReversePolishNotation();
        auto&& expression = std::vector<std::string> { "1", "2", "+", "3", "+" };  // 1 + 2 + 3

        for ( auto&& x : expression )
        {
            rpn.add( x );
        }

        double ret = rpn.calculate();

        print( expression, ret  );
    }
    {
        auto&& rpn = rpn::ReversePolishNotation();
        auto&& expression = std::vector<std::string>{ "1", "2", "-", "3", "-" };  // 1 - 2 - 3

        for ( auto&& x : expression )
        {
            rpn.add( x );
        }

        double ret = rpn.calculate();

        print( expression, ret );
    }
    {
        auto&& rpn = rpn::ReversePolishNotation();
        auto&& expression = std::vector<std::string>{ "1", "2", "*", "3", "*" };  // 1 * 2 * 3

        for ( auto&& x : expression )
        {
            rpn.add( x );
        }

        double ret = rpn.calculate();

        print( expression, ret );
    }
    {
        auto&& rpn = rpn::ReversePolishNotation();
        auto&& expression = std::vector<std::string>{ "1", "2", "/", "3", "/" };  // 1 / 2 / 3

        for ( auto&& x : expression )
        {
            rpn.add( x );
        }

        double ret = rpn.calculate();

        print( expression, ret );
    }

    return 0;
}
