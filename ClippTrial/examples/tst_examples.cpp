#include <QtTest>
#include "options.h"

class Examples : public QObject
{
    Q_OBJECT

public:
    Examples();
    ~Examples();

private slots:
    void required_test();
    void value_test();
    void opt_value_test();
};

Examples::Examples()
{
}

Examples::~Examples()
{
}

void Examples::required_test()
{
    {
        const int argc = 2;
        const char* argv[] = { "foo", "-a" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.a(), true );
        QCOMPARE( options.b(), false );
    }
    {
        const int argc = 2;
        const char* argv[] = { "foo", "-b" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), false );  // "-a"は必須オプションなので、パースは失敗する
        QCOMPARE( options.a(), false );
        QCOMPARE( options.b(), true );  // パースは失敗しても、set()は実行されるっぽい
    }
}

void Examples::value_test()
{
    {
        const int argc = 4;
        const char* argv[] = { "foo", "-a", "-c", "xxx" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.c(), "xxx" );
    }
    {
        const int argc = 3;
        const char* argv[] = { "foo", "-a", "-c" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), false );  // value()はオプション引数必須なので、パースは失敗する
        QCOMPARE( options.c(), "" );
    }
}

void Examples::opt_value_test()
{
    {
        const int argc = 4;
        const char* argv[] = { "foo", "-a", "-d", "xxx" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.d(), "xxx" );
    }
    {
        const int argc = 3;
        const char* argv[] = { "foo", "-a", "-d" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );  // opt_value()はオプション引数省略可能なので、パースは成功する
        QCOMPARE( options.d(), "" );
    }
}

QTEST_APPLESS_MAIN(Examples)

#include "tst_examples.moc"
