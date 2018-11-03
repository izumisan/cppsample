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
    ReversePolishNotation();
    virtual ~ReversePolishNotation();
public:
    void add( const std::string& token );
    double calculate();
private:
    bool isOperator( const std::string& token ) const;

private:
    static const std::map<std::string, std::function<double (double, double)>> m_operation;
    std::vector<std::string> m_tokens = {};
};

} // namespace rpn

#endif // RPN_REVERSEPOLISHNOTATION_H
