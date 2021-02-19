#include <QtTest>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/chrono.h>

class FmtSample : public QObject
{
    Q_OBJECT

public:
    FmtSample();
    ~FmtSample();

private slots:
    void print_test();
    void format_test();
};

FmtSample::FmtSample()
{
}

FmtSample::~FmtSample()
{
}

void FmtSample::print_test()
{
    ::fmt::print( "foo: {}\n", 123 );  //=> "foo: 123"

    // C#のstring.Format()のように、{n}で出力箇所を指定できる
    int ivalue = 123;
    double dvalue = 123.456;
    std::string str("foo");
    ::fmt::print( "ivalue: {0}, dvalue: {1}, str: {2}\n", ivalue, dvalue, str );  //=> "ivalue: 123, dvalue: 123.456, str: foo"

    // fmt/ranges.h をインクルードすることで、std::vectorもprintできる
    std::vector<int> vec { 1, 2, 3 };
    ::fmt::print( "vec: {}\n", vec );  //=> "vec: {1, 2, 3}"

    // fmt/chrono.h をインクルードすることで、tm構造体をフォーマットできる
    std::chrono::time_point now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t( now );
    std::tm* tm = std::localtime( &time );
    ::fmt::print( "{:%Y-%m-%d %H:%M:%S}\n", *tm );

    std::cout << std::put_time( tm, "%c" ) << std::endl;  // おまけ
}

void FmtSample::format_test()
{
    QVERIFY( ::fmt::format( "{0}", 12.345 ) == "12.345" );

    // 小数点以下桁数指定
    QVERIFY( ::fmt::format( "{0:.1f}", 12.345 ) == "12.3" );
    QVERIFY( ::fmt::format( "{0:.2f}", 12.345 ) == "12.35" );  // 四捨五入される
    QVERIFY( ::fmt::format( "{0:.6f}", 12.345 ) == "12.345000" );

    // HEX
    QVERIFY( ::fmt::format( "0x{0:x}", 127 ) == "0x7f" );
    QVERIFY( ::fmt::format( "0x{0:X}", 127 ) == "0x7F" );
    QVERIFY( ::fmt::format( "0x{0:x}", 256 ) == "0x100" );
    QVERIFY( ::fmt::format( "0x{0:04x}", 256 ) == "0x0100" );  // 幅4, 0パディング
}

QTEST_APPLESS_MAIN(FmtSample)

#include "tst_fmtsample.moc"
