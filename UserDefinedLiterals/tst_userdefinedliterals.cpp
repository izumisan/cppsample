#include <QString>
#include <QtTest>

#include "angleliterals.h"
using namespace angleliterals;

#include "lengthliterals.h"
using namespace lengthliterals;

#include "temperatureliterals.h"
using namespace temperatureliterals;

class UserDefinedLiterals : public QObject
{
    Q_OBJECT

public:
    UserDefinedLiterals() = default;

private Q_SLOTS:
    void angleLiteralsTest();
    void lengthLiteralsTest();

    void temperatureliterals_test();
};

/*!
  @brief  アングルリテラルのテスト
*/
void UserDefinedLiterals::angleLiteralsTest()
{
    const double pi = 4.0 * std::atan( 1.0 );
    QCOMPARE( 1.0_deg, pi / 180.0 );
    QCOMPARE( 1.0_rad, 1.0 );
}

/*!
  @brief レンジリテラルのテスト
*/
void UserDefinedLiterals::lengthLiteralsTest()
{
    QCOMPARE( 1.0_km, 1000.0 );
    QCOMPARE( 1.0_m, 1.0 );
    QCOMPARE( 1.0_cm, 0.01 );
    QCOMPARE( 1.0_mm, 0.001 );
}

/**
 * @brief UserDefinedLiterals::temperatureliterals_test
 */
void UserDefinedLiterals::temperatureliterals_test()
{
    QCOMPARE( 0.0_degC, 273.15 );
    QCOMPARE( 1.0_degC, 274.15 );
    QCOMPARE( 2.0_degC, 275.15 );

    // degC <=> K 変換のような場合、
    // ユーザ定義リテラルは負数には対応できないので、意図通りの結果にならない
    QVERIFY( -1.0_degC != 272.15 );
    QVERIFY( -1.0_degC == -274.15 );
}

QTEST_APPLESS_MAIN(UserDefinedLiterals)

#include "tst_userdefinedliterals.moc"
