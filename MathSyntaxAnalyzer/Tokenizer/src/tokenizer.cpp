#include <algorithm>
#include <regex>
#include <exception>
#include "tokenizer.h"

Tokenizer::Tokenizer( const std::string& expression )
{
    parse( expression );
}

Tokenizer::~Tokenizer()
{
}

std::string Tokenizer::next()
{
    auto&& ret = std::string();
    if ( m_current < m_tokens.size() - 1 )
    {
        ++m_current;
        ret = m_tokens.at( m_current );
    }
    return ret;
}

std::string Tokenizer::current() const
{
    return m_tokens.at( m_current );
}


void Tokenizer::parse( const std::string& expression )
{
    std::string text( expression );
    text.erase( std::remove( text.begin(), text.end(), ' ' ), text.end() );

    search( text );
}

void Tokenizer::search( const std::string& text )
{
    std::regex number_pattern( R"(^(-?\d+(\.\d+)?)\D?.*)" );
    std::regex symbol_pattern( R"(^[\+\-\*\/\(\)])" );
    std::smatch match;

    if ( std::regex_search( text, match, number_pattern ) )
    {
        auto&& value = match.str(1);  // match.str(0)は全体マッチ
        m_tokens.push_back( value );

        if ( text.size() != value.size() )
        {
            auto&& buff = text.substr( value.size() );
            search( buff );
        }
    }
    else if ( std::regex_search( text, match, symbol_pattern ) )
    {
        auto&& value = match.str();
        m_tokens.push_back( value );

        if ( text.size() != value.size() )
        {
            auto&& buff = text.substr( value.size() );
            search( buff );
        }
    }
    else
    {
        throw std::exception( "ERROR" );
    }
}