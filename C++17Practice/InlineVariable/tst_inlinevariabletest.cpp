#include <QtTest>
#include "inline_variable.h"
#include "foo.h"
#include "bar.h"

class InlineVariableTest : public QObject
{
    Q_OBJECT

public:
    InlineVariableTest();
    ~InlineVariableTest();

private slots:
    void inline_value_should_be_only_one();

};

InlineVariableTest::InlineVariableTest()
{
}

InlineVariableTest::~InlineVariableTest()
{
}
/**
 * inline変数（inline_value）は、複数の翻訳単位（foo.obj, bar.obj）で共有される（ただ一つ）
 */
void InlineVariableTest::inline_value_should_be_only_one()
{
    QCOMPARE( foo::get_inline_value(), 0 );
    QCOMPARE( bar::get_inline_value(), 0 );

    foo::set_inline_value( 7 );
    QCOMPARE( foo::get_inline_value(), 7 );
    QCOMPARE( bar::get_inline_value(), 7 );

    bar::set_inline_value( 77 );
    QCOMPARE( foo::get_inline_value(), 77 );
    QCOMPARE( bar::get_inline_value(), 77 );
}

QTEST_APPLESS_MAIN(InlineVariableTest)

#include "tst_inlinevariabletest.moc"
