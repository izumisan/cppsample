#include <QtTest>
#include "options.h"

class Examples : public QObject
{
    Q_OBJECT

public:
    Examples();
    ~Examples();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void required_test();
    void value_test();
    void opt_value_test();
    void values_test();
    void opt_values_test();

    void any_other_test();
};

Examples::Examples()
{
}

Examples::~Examples()
{
}

void Examples::initTestCase()
{
    auto&& opt = Options();
    qDebug() << endl << opt.usage().c_str();
}

void Examples::cleanupTestCase()
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

void Examples::values_test()
{
    {
        const int argc = 6;
        const char* argv[] = { "foo", "-a", "-e", "xxx", "yyy", "zzz" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.e(), (std::vector<std::string> { "xxx", "yyy", "zzz" }) );
    }
    {
        const int argc = 3;
        const char* argv[] = { "foo", "-a", "-e" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), false );  // values()はオプション引数必須なので、パースは失敗する
        QCOMPARE( options.e().empty(), true );
    }
}

void Examples::opt_values_test()
{
    {
        const int argc = 6;
        const char* argv[] = { "foo", "-a", "-f", "xxx", "yyy", "zzz" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.f(), (std::vector<std::string> { "xxx", "yyy", "zzz" }) );
    }
    {
        const int argc = 3;
        const char* argv[] = { "foo", "-a", "-f" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );  // opt_values()はオプション引数省略可能なので、パースは成功する
        QCOMPARE( options.f().empty(), true );
    }
}

void Examples::any_other_test()
{
    {
        const int argc = 4;
        const char* argv[] = { "foo", "-a", "--undefined-option", "undefined-option-argument" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), true );
        QCOMPARE( options.any_other_values(), (std::vector<std::string> { "--undefined-option", "undefined-option-argument" }) );
    }
    {
        const int argc = 3;
        const char* argv[] = { "foo", "--undefined-option", "undefined-option-argument" };
        auto&& options = Options( argc, argv );
        QCOMPARE( options.success(), false );
        QCOMPARE( options.any_other_values(), (std::vector<std::string> { "--undefined-option", "undefined-option-argument" }) );
    }
}

QTEST_APPLESS_MAIN(Examples)

#include "tst_examples.moc"
