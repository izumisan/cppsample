#include <QtTest>
#include <cmath>
#include <vector>
#include <algorithm>

class NewFunctionsTest : public QObject
{
    Q_OBJECT

public:
    NewFunctionsTest(){}
    ~NewFunctionsTest(){}

private slots:
    void for_each_n_test();

    void clamp_test_data();
    void clamp_test();

    void hypot_test_data();
    void hypot_test();

    void gcd_test();
    void lcm_test();
};
//------------------------------------------------------------------------------
/**
 * std::for_each_n() サンプル
 */
void NewFunctionsTest::for_each_n_test()
{
    auto&& foo = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 };

    // 先頭の5要素を2乗する
    std::for_each_n( foo.begin(), 5, [](auto&& x) { x *= x; } );

    auto&& expected = std::vector<int>{ 1, 4, 9, 16, 25, 6, 7 };
    QCOMPARE( foo, expected );
}
//------------------------------------------------------------------------------
/**
 * clamp_testデータ
 */
void NewFunctionsTest::clamp_test_data()
{
    QTest::addColumn<double>("_input");
    QTest::addColumn<double>("_expected");

    QTest::newRow("-2.0") << -2.0 << -1.0;
    QTest::newRow("-1.1") << -1.1 << -1.0;
    QTest::newRow("-1.0") << -1.0 << -1.0;
    QTest::newRow("-0.9") << -0.9 << -0.9;
    QTest::newRow("0.0") << 0.0 << 0.0;
    QTest::newRow("0.9") << 0.9 << 0.9;
    QTest::newRow("1.0") << 1.0 << 1.0;
    QTest::newRow("1.1") << 1.1 << 1.0;
    QTest::newRow("2.0") << 2.0 << 1.0;
}
/**
 * std::clamp(): 指定した値を[min, max]の範囲に収める
 */
void NewFunctionsTest::clamp_test()
{
    QFETCH( double, _input );
    QFETCH( double, _expected );

    constexpr double min = -1.0;
    constexpr double max = 1.0;

    double actual = std::clamp( _input, min, max );
    QCOMPARE( actual, _expected );
}
//------------------------------------------------------------------------------
/**
 * hypot_testデータ
 */
void NewFunctionsTest::hypot_test_data()
{
    QTest::addColumn<double>("_x");
    QTest::addColumn<double>("_y");
    QTest::addColumn<double>("_z");
    QTest::addColumn<double>("_expected");

    QTest::addRow("case 1") << 1.0 << 1.0 << 0.0 << std::sqrt(2.0);
    QTest::addRow("case 2") << 1.0 << 1.0 << 1.0 << std::sqrt(3.0);
    QTest::addRow("case 3") << 2.0 << 2.0 << 2.0 << std::sqrt(12.0);
    QTest::addRow("case 4") << 2.0 << 3.0 << 4.0 << std::sqrt(29.0);
}
/**
 * std::hypot(): √(x^2 + y^2 + z^2)を求める
 */
void NewFunctionsTest::hypot_test()
{
    QFETCH( double, _x );
    QFETCH( double, _y );
    QFETCH( double, _z );
    QFETCH( double, _expected );

    double actual = std::hypot( _x, _y, _z );
    QCOMPARE( actual, _expected );
}
//------------------------------------------------------------------------------
/**
 * std::gcd(): 最大公約数を求める
 */
void NewFunctionsTest::gcd_test()
{
    double value = std::gcd( 12, 18 );
    QCOMPARE( value, 6 );
}
//------------------------------------------------------------------------------
/**
 * std::lcm(): 最小公約数を求める
 */
void NewFunctionsTest::lcm_test()
{
    double value = std::lcm( 2, 3 );
    QCOMPARE( value, 6 );
}

QTEST_APPLESS_MAIN(NewFunctionsTest)

#include "tst_newfunctionstest.moc"
