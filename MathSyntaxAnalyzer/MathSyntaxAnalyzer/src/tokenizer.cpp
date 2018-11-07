#include <algorithm>
#include <regex>
#include <exception>
#include "util.h"
#include "tokenizer.h"

Tokenizer::Tokenizer( const std::string& expression )
{
    parse( expression );
}

Tokenizer::~Tokenizer()
{
}

bool Tokenizer::moveNext()
{
    ++m_current;
    return !isEnd();
}

void Tokenizer::reset()
{
    m_current = 0;
}

std::string Tokenizer::current() const
{
    std::string&& ret = "";
    if ( ( 0 <= m_current ) && ( m_current < m_tokens.size() ) )
    {
        ret = m_tokens.at( m_current );
    }
    return ret;
}

// current() + moveNext()
std::string Tokenizer::get()
{
    std::string&& ret = current();
    moveNext();
    return ret;
}

bool Tokenizer::isEnd() const
{
    return !( m_current < m_tokens.size() );
}

void Tokenizer::parse( const std::string& expression )
{
    for ( auto&& item : izm::split( expression, " " ) )
    {
        search( item );
    }
}

void Tokenizer::search( const std::string& text )
{
    std::regex number_pattern( R"(^(-?\d+(\.\d+)?)\D?.*)" );
    std::regex symbol_pattern( R"(^[\+\-\*\/\(\)])" );
    std::smatch match;
    auto&& matchText = std::string();

    if ( std::regex_search( text, match, number_pattern ) )
    {
        matchText = match.str(1);  // match.str(0)は全体マッチ
        m_tokens.push_back( matchText );
    }
    else if ( std::regex_search( text, match, symbol_pattern ) )
    {
        matchText = match.str();
        m_tokens.push_back( matchText );
    }
    else
    {
        throw std::exception( "ERROR" );
    }

    if ( !matchText.empty() )
    {
        if ( text != matchText )
        {
            auto&& nextText = text.substr( matchText.size() );
            search( nextText );
        }
    }
}