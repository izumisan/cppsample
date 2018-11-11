#include <vector>
#include <algorithm>
#include <QString>
#include <QtTest>

class AlgorithmTest : public QObject
{
    Q_OBJECT

public:
    AlgorithmTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void all_of();
    void any_of();
    void none_of();
};

AlgorithmTest::AlgorithmTest()
{
}

void AlgorithmTest::initTestCase()
{
}

void AlgorithmTest::cleanupTestCase()
{
}

void AlgorithmTest::init()
{
}

void AlgorithmTest::cleanup()
{
}
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
/*!
  @brief  std::all_of()は全ての要素が指定条件を満たすか否かを判定する
*/
void AlgorithmTest::all_of()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    bool ret = std::all_of( v.begin(), v.end(), [](int x){ return x > 0; } );
    QCOMPARE( ret, true );

    ret = std::all_of( v.begin(), v.end(), [](int x){ return x < 5; } );
    QCOMPARE( ret, false );
}
//------------------------------------------------------------------------------
/*!
  @brief  std::any_of()は指定条件を満たす要素が含まれているか否かを判定する
*/
void AlgorithmTest::any_of()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    bool ret = std::any_of( v.begin(), v.end(), [](int x){ return x % 2 == 0; } );
    QCOMPARE( ret, true );

    ret = std::all_of( v.begin(), v.end(), [](int x){ return 10 < x; } );
    QCOMPARE( ret, false );
}
//------------------------------------------------------------------------------
/*!
  @brief  std::none_of()は全ての要素が指定条件を満たさないことを判定する
*/
void AlgorithmTest::none_of()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    bool ret = std::none_of( v.begin(), v.end(), [](int x){ return x < 0; } );
    QCOMPARE( ret, true );

    ret = std::none_of( v.begin(), v.end(), [](int x){ return x < 5; } );
    QCOMPARE( ret, false );
}

QTEST_APPLESS_MAIN(AlgorithmTest)

#include "tst_algorithmtest.moc"
