#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer
{
public:
    Tokenizer( const std::string& expression );
    virtual ~Tokenizer();
public:
    std::string next();
    std::string current() const;
private:
    void parse( const std::string& expression );
    void search( const std::string& text );
private:
    std::vector<std::string> m_tokens = {};
    int m_current = 0;
};

#endif // TOKENIZER_H
