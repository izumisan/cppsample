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
    //@@@ TODO
    // �X�y�[�X���폜���Ă��܂��̂ł͂Ȃ��A
    // �X�y�[�X�ŕ������A���������e�v�f�ɑ΂���search���\�b�h�����s����悤�ɂ���

    std::string text( expression );
    text.erase( std::remove( text.begin(), text.end(), ' ' ), text.end() );

    search( text );
}

void Tokenizer::search( const std::string& text )
{
    std::regex number_pattern( R"(^(-?\d+(\.\d+)?)\D?.*)" );
    std::regex symbol_pattern( R"(^[\+\-\*\/\(\)])" );
    std::smatch match;
    auto&& matchText = std::string();

    if ( std::regex_search( text, match, number_pattern ) )
    {
        matchText = match.str(1);  // match.str(0)�͑S�̃}�b�`
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