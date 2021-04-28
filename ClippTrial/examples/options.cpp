// options.cpp
#include <clipp/clipp.h>
#include "options.h"

Options::Options( const int argc, const char* argv[] )
{
    auto cli = ( clipp::required( "-a" ).set( m_a ),
                 clipp::option( "-b" ).set( m_b ),
                 clipp::option( "-c", "--ccc" ) & clipp::value( "ccc", m_c ),  // value()は、オプション引数必須
                 clipp::option( "-d", "--ddd" ) & clipp::opt_value( "ddd", m_d )  // opt_value()は、オプション引数省略可能
               );

    if ( clipp::parse( argc, (char**)argv, cli ) )
    {
        m_success = true;
    }
}

