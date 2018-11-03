#include <stack>
#include "reversepolishnotation.h"

namespace rpn
{

const std::map<std::string, std::function<double( double, double )>> ReversePolishNotation::m_operation =
{
    { "+", []( double x, double y ) { return x + y; } },
    { "-", []( double x, double y ) { return x - y; } },
    { "*", []( double x, double y ) { return x * y; } },
    { "/", []( double x, double y ) { return x / y; } }
};

ReversePolishNotation::ReversePolishNotation()
{
}

ReversePolishNotation::~ReversePolishNotation()
{
}

void ReversePolishNotation::add( const std::string& token )
{
    m_tokens.push_back( token );
}

double ReversePolishNotation::calculate()
{
    auto&& stack = std::stack<double>();

    for ( auto&& token : m_tokens )
    {
        if ( isOperator( token ) )
        {
            double y = stack.top();
            stack.pop();
            double x = stack.top();
            stack.pop();

            auto&& func = m_operation.at( token );
            double z = func( x, y );

            stack.push( z );
        }
        else
        {
            stack.push( std::stod( token ) );
        }
    }

    return stack.top();
}

bool ReversePolishNotation::isOperator( const std::string& token ) const
{
    bool ret = false;
    if ( m_operation.find( token ) != m_operation.end() )
    {
        ret = true;
    }
    return ret;
}

} // namespace rpn
