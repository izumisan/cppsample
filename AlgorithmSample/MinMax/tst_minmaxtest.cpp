#include <QString>
#include <QtTest>
#include <algorithm>
#include <vector>

class MinMaxTest : public QObject
{
    Q_OBJECT

public:
    MinMaxTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void min();
    void max();
    void minmax();

    void min_element();
    void max_element();
    void minmax_element();

    void clamp();
};

MinMaxTest::MinMaxTest()
{
}

void MinMaxTest::initTestCase()
{
}

void MinMaxTest::cleanupTestCase()
{
}

void MinMaxTest::init()
{
}

void MinMaxTest::cleanup()
{
}
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
/*!
*/
void MinMaxTest::min()
{
    // std::minの引数にvector型を指定できないので使い勝手が良くない
    // std::initializer_listは指定できる
    QCOMPARE( std::min( { 1, 2, 3, 4, 5 } ), 1 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::max()
{
    QCOMPARE( std::max( { 1, 2, 3, 4, 5 } ), 5 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::minmax()
{
    // minmax()は、最小値・最大値のpairを返す
    std::pair<int, int>&& actual = std::minmax( { 1, 2, 3, 4, 5 } );

    QCOMPARE( actual.first, 1 );
    QCOMPARE( actual.second, 5 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::min_element()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    QCOMPARE( *( std::min_element( v.cbegin(), v.cend() ) ), 1 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::max_element()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    QCOMPARE( *( std::max_element( v.cbegin(), v.cend() ) ), 5 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::minmax_element()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    // minmax_element()は、最小値・最大値へのイテレータのpairを返す
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>&& actual = std::minmax_element( v.cbegin(), v.cend() );

    QCOMPARE( *( actual.first ), 1 );
    QCOMPARE( *( actual.second ), 5 );
}
//------------------------------------------------------------------------------
/*!
*/
void MinMaxTest::clamp()
{
}


QTEST_APPLESS_MAIN(MinMaxTest)

#include "tst_minmaxtest.moc"
