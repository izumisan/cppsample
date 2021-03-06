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

    void for_each();

    void find();
    void find_if();
    void find_if_not();

    void find_first_of();

    void search();
    void find_end();

    void count();
    void count_if();

    void equal();
    void mismatch();
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
//------------------------------------------------------------------------------
/*!
  @brief  for_each()は、全ての要素に指定した関数（ラムダ式）を適用する
*/
void AlgorithmTest::for_each()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    std::for_each( v.begin(), v.end(), [](int x){ x *= x; } );
    QCOMPARE( v.at(0), 1 );
    QCOMPARE( v.at(1), 2 );
    QCOMPARE( v.at(2), 3 );
    QCOMPARE( v.at(3), 4 );
    QCOMPARE( v.at(4), 5 );

    // 参照で受けると、要素を書き換えることができる
    std::for_each( v.begin(), v.end(), [](int& x){ x *= x; } );
    QCOMPARE( v.at(0), 1 );
    QCOMPARE( v.at(1), 4 );
    QCOMPARE( v.at(2), 9 );
    QCOMPARE( v.at(3), 16 );
    QCOMPARE( v.at(4), 25 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定した要素を検索する
*/
void AlgorithmTest::find()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    // 一致する要素のイテレータを返す
    auto&& it = std::find( v.begin(), v.end(), 3 );

    QVERIFY( it != v.end() );
    QCOMPARE( it, v.begin() + 2 );
    QCOMPARE( *it, 3 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定条件に一致する要素を検索する
*/
void AlgorithmTest::find_if()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    // 条件式に一致する最初の要素のイテレータを返す
    auto&& it = std::find_if( v.begin(), v.end(), [](int x)
    {
        return ( ( x % 2 == 0 ) && ( x > 3 ) );
    } );

    QVERIFY( it != v.end() );
    QCOMPARE( *it, 4 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定条件に一致しない要素を検索する
*/
void AlgorithmTest::find_if_not()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };

    // 条件式に一致しない最初の要素のイテレータを返す
    auto&& it = std::find_if_not( v.begin(), v.end(), [](int x)
    {
        return ( ( x % 2 == 0 ) || ( x < 3 ) );
    } );

    QVERIFY( it != v.end() );
    QCOMPARE( *it, 3 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定した要素の1つに一致する最初の要素を検索する
*/
void AlgorithmTest::find_first_of()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };
    auto&& search = std::vector<int> { 5, 4, 3 };

    // { 5, 4, 3 }のうち、最初に一致する要素のイテレータを返す
    auto&& it = std::find_first_of( v.begin(), v.end(), search.begin(), search.end() );

    QVERIFY( it != v.end() );
    QCOMPARE( it, v.begin() + 2 );
    QCOMPARE( *it, 3 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定したシーケンスに一致する最初のシーケンスを検索する
*/
void AlgorithmTest::search()
{
    auto&& v = std::vector<int> { 3, 1, 2, 1, 2, 3 };
    auto&& target = std::vector<int> { 1, 2 };

    // 最初に見つかった{1, 2}列のイテレータを返す
    auto&& it = std::search( v.begin(), v.end(), target.begin(), target.end() );

    QVERIFY( it != v.end() );
    QCOMPARE( it, v.begin() + 1 );
    QCOMPARE( *it, 1 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定したシーケンスに一致する最後のシーケンスを検索する
*/
void AlgorithmTest::find_end()
{
    auto&& v = std::vector<int> { 3, 1, 2, 1, 2, 3 };
    auto&& target = std::vector<int> { 1, 2 };

    // 最後に見つかった{1, 2}列のイテレータを返す
    auto&& it = std::find_end( v.begin(), v.end(), target.begin(), target.end() );

    QVERIFY( it != v.end() );
    QCOMPARE( it, v.begin() + 3 );
    QCOMPARE( *it, 1 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定した要素の数をカウントする
*/
void AlgorithmTest::count()
{
    auto&& v = std::vector<int> { 1, 2, 2, 3, 3, 3 };

    QCOMPARE( std::count( v.begin(), v.end(), 1 ), 1 );
    QCOMPARE( std::count( v.begin(), v.end(), 2 ), 2 );
    QCOMPARE( std::count( v.begin(), v.end(), 3 ), 3 );
    QCOMPARE( std::count( v.begin(), v.end(), 4 ), 0 );
}
//------------------------------------------------------------------------------
/*!
  @brief  指定した条件を満たす要素の数をカウントする
*/
void AlgorithmTest::count_if()
{
    auto&& v = std::vector<int> { 1, 2, 2, 3, 3, 3 };

    QCOMPARE( std::count_if( v.begin(), v.end(), [](int x){ return x == 3; } ), 3 );
    QCOMPARE( std::count_if( v.begin(), v.end(), [](int x){ return x % 2 == 0; } ), 2 );
    QCOMPARE( std::count_if( v.begin(), v.end(), [](int x){ return x % 2 != 0; } ), 4 );
}
//------------------------------------------------------------------------------
/*!
  @brief  2つのシーケンスの等値比較する
*/
void AlgorithmTest::equal()
{
    auto&& v = std::vector<int> { 1, 2, 2, 3, 3, 3 };
    auto&& t1 = std::vector<int> { 1, 2, 2, 3, 3 };
    auto&& t2 = std::vector<int> { 1, 2, 2, 3, 3, 3 };
    auto&& t3 = std::vector<int> { 3, 2, 2, 3, 3, 1 };

    QCOMPARE( std::equal( v.begin(), v.end(), t1.begin(), t1.end() ), false );
    QCOMPARE( std::equal( v.begin(), v.end(), t2.begin(), t2.end() ), true );
    QCOMPARE( std::equal( v.begin(), v.end(), t3.begin(), t3.end() ), false );
}
//------------------------------------------------------------------------------
/*!
  @brief  2つのシーケンスを比較し、異なる要素のイテレータを返す
*/
void AlgorithmTest::mismatch()
{
    auto&& v = std::vector<int> { 1, 2, 3, 4, 5 };
    auto&& t1 = std::vector<int> { 1, 2, 3 };
    auto&& t2 = std::vector<int> { 1, 2, 3, 4, 5 };

    // 2つのシーケンスを比較し、異なる要素のイテレータのペアを返す
    auto&& it1 = std::mismatch( v.begin(), v.end(), t1.begin(), t1.end() );
    QCOMPARE( it1.first - v.begin(), 3 );
    QCOMPARE( it1.second - t1.begin(), 3 );

    // 2つのシーケンスの要素数が等しい場合、第4引数は省略できる
    // (要素数が異なるシーケンスに対し第4引数を省略すると、プログラムが落ちる)
    auto&& it2 = std::mismatch( v.begin(), v.end(), t2.begin() );
    QCOMPARE( it2.first, v.end() );
    QCOMPARE( it2.second, t2.end() );
}


QTEST_APPLESS_MAIN(AlgorithmTest)

#include "tst_algorithmtest.moc"
