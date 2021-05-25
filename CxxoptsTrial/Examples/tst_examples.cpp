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

QTEST_APPLESS_MAIN(Examples)

#include "tst_examples.moc"
