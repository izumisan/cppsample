#include <QtTest>

enum class Foo
{
    Foo_0,
    Foo_1,
    Foo_2
};

class EnumClassInitializerTest : public QObject
{
    Q_OBJECT

public:
    EnumClassInitializerTest(){}
    ~EnumClassInitializerTest(){}

private slots:
    void enum_class_initializer();

};
/**
 * enum classの初期化時の制限緩和
 */
void EnumClassInitializerTest::enum_class_initializer()
{
    // C++17で、初期化時、整数値でenum要素値を指定することができるようになった
    Foo foo { 1 };

    QCOMPARE( foo, Foo::Foo_1 );
}

QTEST_APPLESS_MAIN(EnumClassInitializerTest)

#include "tst_enumclassinitializertest.moc"
