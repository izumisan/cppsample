#include <iostream>
#include <string>
#include "cxxopts.hpp"

int main( int argc, char* argv[] )
{
    /*
    cxxopts basic trial program
    Usage:
      basic [OPTION...]

      -e, --enabled     foo enabled
      -i, --input arg   app input file path
      -o, --output arg  app output file path (default: path/to/output)
    */
    cxxopts::Options options( "basic", "cxxopts basic trial program" );
    options.add_options()
        ( "e,enabled", "foo enabled" )
        ( "i,input", "app input file path", cxxopts::value<std::string>() )
        ( "o,output", "app output file path", cxxopts::value<std::string>()->default_value("path/to/output") );

    auto&& result = options.parse( argc, argv );

    bool enabled = result["enabled"].as<bool>();
    std::cout << "enabled: " << enabled << std::endl;

    // プログラム引数に "-i" or "--input" が指定されていない場合、results["input"] で例外が発生する
    std::string input = result["input"].as<std::string>();
    std::cout << "input  : " << input << std::endl;

    std::string output = result["output"].as<std::string>();
    std::cout << "output : " << output << std::endl;

    // help() でヘルプテキストが取得できる
    std::cout << options.help() << std::endl;

    return 0;
}
