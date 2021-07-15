#include <QtTest>
#include "singletonclass.h"

class SingletonClassTest : public QObject
{
    Q_OBJECT

public:
    SingletonClassTest();
    ~SingletonClassTest();

private slots:
    void basic_test();
};

SingletonClassTest::SingletonClassTest()
{
}

SingletonClassTest::~SingletonClassTest()
{
}

void SingletonClassTest::basic_test()
{
    auto&& obj1 = foo::SingletonClass::instance();
    QCOMPARE( obj1->count(), 0 );

    obj1->up();
    QCOMPARE( obj1->count(), 1 );

    auto&& obj2 = foo::SingletonClass::instance();
    QCOMPARE( obj2->count(), 1 );

    obj1->up();
    QCOMPARE( obj1->count(), 2 );
    QCOMPARE( obj2->count(), 2 );

    obj2->down();
    QCOMPARE( obj1->count(), 1 );
    QCOMPARE( obj2->count(), 1 );
}

QTEST_APPLESS_MAIN(SingletonClassTest)

#include "tst_singletonclasstest.moc"
