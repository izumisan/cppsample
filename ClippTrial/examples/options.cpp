// options.cpp
#include <iostream>
#include <sstream>
#include <clipp/clipp.h>
#include "options.h"

Options::Options( const int argc, const char* argv[] )
{
    auto cli = ( clipp::required( "-a" ).set( m_a ),
                 clipp::option( "-b" ).set( m_b ),
                 clipp::option( "-c", "--ccc" ) & clipp::value( "ccc", m_c ),  // value()により、オプション引数を取得する（オプション引数必須）
                 clipp::option( "-d", "--ddd" ) & clipp::opt_value( "ddd", m_d ),  // opt_value()により、オプション引数を取得する（オプション引数省略可能）
                 clipp::option( "-e", "--eee" ) & clipp::values( "eee", m_e ),  // values()により、全てのオプション引数を取得する（オプション引数必須）
                 clipp::option( "-f", "--fff" ) & clipp::opt_values( "fff", m_f ),  // opt_values()により、全てのオプション引数を取得する（オプション引数省略可能）

                 clipp::any_other( m_any_other_values )  // any_other()により、パースできなかった未定義のオプションを全て取得する
               );

//    m_usage = clipp::make_man_page( cli ).content();
    std::stringstream ss;
    ss << clipp::make_man_page( cli );
    m_usage = ss.str();

    if ( clipp::parse( argc, (char**)argv, cli ) )
    {
        m_success = true;
    }
}

