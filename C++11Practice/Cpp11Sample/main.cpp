#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include "newfunctionsyntax.h"

// 前方宣言
void rawStringLiteral();
void convertStringFromToNumeric();
void minmaxFunction();
void tupleSample();

/*!
*/
int main()
{
    std::cout << "-----[rawStringLiteral]" << std::endl;
    rawStringLiteral();

    std::cout << "-----[convertStringFromToNumeric]" << std::endl;
    convertStringFromToNumeric();

    std::cout << "-----[minmaxFunction]" << std::endl;
    minmaxFunction();

    std::cout << "-----[newFunctionSyntax]" << std::endl;
    newFunctionSyntax();

    std::cout << "-----[tupleSample]" << std::endl;
    tupleSample();

    return 0;
}
//------------------------------------------------------------------------------
/*!
  @brief  Raw文字列リテラル
*/
void rawStringLiteral()
{
    auto&& path = R"(C:\path\to\file)";

    auto&& json = R"({
  "foo" : "fuga",
  "hoge" : 1.23
})";

    auto&& xml = R"(<?xml version="1.0" encoding="utf-8"?>
<configuration>
  <startup>
    <supportedRuntime version="v4.0" sku=".NETFramework,Version=v4.6.1" />
  </startup>
<appSettings>
  <add key="key1" value="debug"/>
  <add key="insertBeforeKey.debug" value="insertBefore.debug"/>
  <add key="key2" value="value2"/>
  <add key="insertAfterKey.debug" value="insertAfter.debug"/>
  <add key="key3" value="value3"/>
  <add key="insertKey.debug" value="insert.debug"/>
</appSettings>
</configuration>)";

    std::cout << path << std::endl;
    std::cout << json << std::endl;
    std::cout << xml << std::endl;

}
//------------------------------------------------------------------------------
/*!
  @brief  文字列 <-> 数値変換
*/
void convertStringFromToNumeric()
{
    auto&& str = std::to_string( 123 );
    std::cout << str << std::endl;

    str = std::to_string( 1.23 );
    std::cout << str << std::endl;

    auto&& i = std::stoi( "456" );
    std::cout << i << std::endl;

    auto&& f = std::stof( "4.56" );
    std::cout << f << std::endl;

    auto&& d = std::stod( "4.56" );
    std::cout << d << std::endl;

    // 指数
    std::cout << std::stod( "0.12345e2" ) << std::endl;

    // 2進数
    std::cout << std::stoi( "0111", nullptr, 2 ) << std::endl;

    // 16進数
    std::cout << std::stoi( "0xFF", nullptr, 16 ) << std::endl;
}
//------------------------------------------------------------------------------
/*!
  @brief  文字列 <-> 数値変換
*/
void minmaxFunction()
{
    auto&& minmax = std::minmax( { 7, 3, 1, 5, 9 } );
    std::cout << "min: " << minmax.first << std::endl;
    std::cout << "max: " << minmax.second << std::endl;

    std::vector<int> list = { 6, 2, 0, 4, 8 };
    auto&& minmaxIt = std::minmax_element( list.begin(), list.end() );
    std::cout << "min: " << *(minmaxIt.first) << std::endl;
    std::cout << "max: " << *(minmaxIt.second) << std::endl;
}
//------------------------------------------------------------------------------
/*!
  @brief  タプル
*/
void tupleSample()
{
    std::tuple<int, float, double, std::string> obj = std::make_tuple( 1, 2.0f, 3.0, "hoge" );

    auto&& t0 = std::get<0>( obj );
    auto&& t1 = std::get<1>( obj );
    auto&& t2 = std::get<2>( obj );
    auto&& t3 = std::get<3>( obj );

    std::cout << t0 << "," << t1 << "," << t2 << "," << t3 << std::endl;

    auto&& obj2 = std::make_tuple( 1, 3.4, "hoge" );
    auto&& v0 = std::get<0>( obj2 );
    auto&& v1 = std::get<1>( obj2 );
    auto&& v2 = std::get<2>( obj2 );

    std::cout << typeid( v0 ).name() << "," << typeid( v1 ).name() << "," << typeid( v2 ).name() << std::endl;
}
