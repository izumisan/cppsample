#include <QtTest>
#include "cxxopts.hpp"

class Examples : public QObject
{
    Q_OBJECT

public:
    Examples();
    ~Examples();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void confirm_option();
    void option_argument();
    void default_value();
    void implicit_value();
};

Examples::Examples()
{
}

Examples::~Examples()
{
}

void Examples::initTestCase()
{
}

void Examples::cleanupTestCase()
{
}

void Examples::init()
{
}

void Examples::cleanup()
{
}
////////////////////////////////////////////////////////////////////////////////

void Examples::confirm_option()
{
    cxxopts::Options options( "confirm_option" );
    options.add_options()
        ( "a,aaa", "aaa enabled" );

    {
        int argc = 2;
        const char* argv[] = { "app", "-a" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        // count()により、オプションの有無を確認できる
        QCOMPARE( result.count( "a" ), 1 );
        QCOMPARE( result.count( "aaa" ), 1 );

        // オプションが指定されていない場合は 0 となる
        QCOMPARE( result.count( "b" ), 0 );
    }
    {
        int argc = 3;
        const char* argv[] = { "app", "-a", "--aaa" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result.count( "a" ), 2 );
        QCOMPARE( result.count( "aaa" ), 2 );

        QCOMPARE( result.count( "b" ), 0 );
    }
}
////////////////////////////////////////////////////////////////////////////////

void Examples::option_argument()
{
    cxxopts::Options options( "option_argument" );
    options.add_options()
        ( "f,file", "input file", cxxopts::value<std::string>() );

    // OK case: "-short_name option_argument"
    {
        int argc = 3;
        const char* argv[] = { "app", "-f", "path/to/file" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/file" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/file" );
    }
    // OK case: "--long_name option_argument"
    {
        int argc = 3;
        const char* argv[] = { "app", "--file", "path/to/file" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/file" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/file" );
    }
    // OK case: "--long_name=option_argument"
    {
        int argc = 2;
        const char* argv[] = { "app", "--file=path/to/file" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/file" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/file" );
    }
    // NG case: "-short_name=option_argument"
    {
        int argc = 2;
        const char* argv[] = { "app", "-f=path/to/file" };
        char** arg2 = const_cast<char**>( argv );

        QVERIFY_EXCEPTION_THROWN( options.parse( argc, arg2 ), cxxopts::OptionParseException );
    }
}
////////////////////////////////////////////////////////////////////////////////

void Examples::default_value()
{
    cxxopts::Options options( "default_value" );
    options.add_options()
        ( "f,file", "config file", cxxopts::value<std::string>()->default_value( "default" ) );

    // オプションが指定されていない場合、default_value()で指定した値が既定値として設定される
    {
        int argc = 1;
        const char* argv[] = { "app" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "default" );
        QCOMPARE( result["file"].as<std::string>(), "default" );
    }
    // 基本
    {
        int argc = 3;
        const char* argv[] = { "app", "-f", "path/to/foo" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/foo" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/foo" );
    }
    {
        int argc = 3;
        const char* argv[] = { "app", "--file", "path/to/foo" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/foo" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/foo" );
    }
    // オプションは指定するが、オプション引数を省略した場合は、parse()で例外となる
    {
        int argc = 2;
        const char* argv[] = { "app", "-f" };
        char** arg2 = const_cast<char**>( argv );

        QVERIFY_EXCEPTION_THROWN( options.parse( argc, arg2 ), cxxopts::OptionParseException );
    }
    {
        int argc = 2;
        const char* argv[] = { "app", "--file" };
        char** arg2 = const_cast<char**>( argv );

        QVERIFY_EXCEPTION_THROWN( options.parse( argc, arg2 ), cxxopts::OptionParseException );
    }
}
////////////////////////////////////////////////////////////////////////////////

void Examples::implicit_value()
{
    cxxopts::Options options( "implicit_value" );
    options.add_options()
        ( "f,file", "config file", cxxopts::value<std::string>()->implicit_value( "implicit" ) );

    // オプション引数を省略した場合、implicit_value()で指定した値が設定される
    {
        int argc = 2;
        const char* argv[] = { "app", "-f" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "implicit" );
        QCOMPARE( result["file"].as<std::string>(), "implicit" );
    }
    {
        int argc = 2;
        const char* argv[] = { "app", "--file" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "implicit" );
        QCOMPARE( result["file"].as<std::string>(), "implicit" );
    }
    // implicit_value()を指定した場合、スペース区切りのオプション引数はimplicit_value()で指定した値となる
    {
        int argc = 3;
        const char* argv[] = { "app", "-f", "path/to/foo" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "implicit" );
        QCOMPARE( result["file"].as<std::string>(), "implicit" );
    }
    {
        int argc = 3;
        const char* argv[] = { "app", "--file", "path/to/foo" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "implicit" );
        QCOMPARE( result["file"].as<std::string>(), "implicit" );
    }
    // 基本
    {
        int argc = 2;
        const char* argv[] = { "app", "--file=path/to/foo" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].as<std::string>(), "path/to/foo" );
        QCOMPARE( result["file"].as<std::string>(), "path/to/foo" );
    }
    // オプションを省略した場合、既定値は設定されない
    {
        int argc = 1;
        const char* argv[] = { "app" };
        char** arg2 = const_cast<char**>( argv );
        auto&& result = options.parse( argc, arg2 );

        QCOMPARE( result["f"].count(), 0 );
        QCOMPARE( result["file"].count(), 0 );
    }
}

QTEST_APPLESS_MAIN(Examples)

#include "tst_examples.moc"
