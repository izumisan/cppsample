#include <QtTest>
#include "singleton.h"
#include "foo.h"

class SingletonTemplateTest : public QObject
{
    Q_OBJECT

public:
    SingletonTemplateTest();
    ~SingletonTemplateTest();

private slots:
    void singleton_test();
};

SingletonTemplateTest::SingletonTemplateTest()
{
}

SingletonTemplateTest::~SingletonTemplateTest()
{
}

void SingletonTemplateTest::singleton_test()
{
    auto&& foo1 = Singleton<Foo>::instance();
    auto&& foo2 = Singleton<Foo>::instance();
    QCOMPARE( foo1->count(), 0 );
    QCOMPARE( foo2->count(), 0 );

    foo1->up();
    QCOMPARE( foo1->count(), 1 );
    QCOMPARE( foo2->count(), 1 );

    foo2->down();
    QCOMPARE( foo1->count(), 0 );
    QCOMPARE( foo2->count(), 0 );
}

QTEST_APPLESS_MAIN(SingletonTemplateTest)

#include "tst_singletontemplatetest.moc"
