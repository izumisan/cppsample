#ifndef RPN_REVERSEPOLISHNOTATION_H
#define RPN_REVERSEPOLISHNOTATION_H

#include <string>
#include <map>
#include <vector>
#include <functional>

namespace rpn
{

class ReversePolishNotation
{
public:
    static double calculate( const std::string& expression, const std::string& delimiter = " " );
private:
    static const std::map<std::string, std::function<double( double, double )>> m_operation;

public:
    ReversePolishNotation();
    ReversePolishNotation( const std::string& expression, const std::string& delimiter = " " );
    virtual ~ReversePolishNotation();
public:
    void add( const std::string& token );
    double calculate();
private:
    bool isOperator( const std::string& token ) const;

private:
    std::vector<std::string> m_tokens = {};
};

} // namespace rpn

#endif // RPN_REVERSEPOLISHNOTATION_H
