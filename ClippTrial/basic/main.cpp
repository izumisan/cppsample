#include <iostream>
#include <clipp/clipp.h>

int main( int argc, char* argv[] )
{
    bool enabled = false;
    std::string input("");
    std::string output("");

    // required()やoption()で、オプション文字列を指定する
    // オプション形式で指定した引数を格納する変数をvalue()で指定する（ピリオドではなく "&"演算子で結合することに注意）
    // bool型の場合、set()を使用する
    auto cli = (
        clipp::required( "-i", "--input" ) & clipp::value( "input file", input ).doc( "app input file path" ),
        clipp::option( "-o", "--output" ) & clipp::value( "output file", output ).doc( "app output file path" ),
        clipp::option( "-e", "--enabled" ).set( enabled ).doc( "foo enabled" )
    );

    if ( clipp::parse( argc, argv, cli ) )
    {
        std::cout << "input: " << input << std::endl;
        std::cout << "output: " << output << std::endl;
        std::cout << "enabled: " << ( enabled ? "true" : "false" ) << std::endl;
    }
    else
    {
        // make_man_page()で、ヘルプテキストが生成される
        std::cout << clipp::make_man_page( cli ) << std::endl;

        std::cout << "---" << std::endl;

        // usage_lines（） や documentation() を利用することで、ある程度のカスタマイズが可能
        std::cout << "Usage:" << std::endl
                  << clipp::usage_lines( cli, "basic.exe" ) << std::endl
                  << std::endl
                  << "Options:" << std::endl
                  << clipp::documentation( cli ) << std::endl;
    }

    return 0;
}
