#include <QString>
#include <QtTest>

#include "angleliterals.h"
using namespace angleliterals;

#include "lengthliterals.h"
using namespace lengthliterals;

class UserDefinedLiterals : public QObject
{
    Q_OBJECT

public:
    UserDefinedLiterals() = default;

private Q_SLOTS:
    void angleLiteralsTest();
    void lengthLiteralsTest();
};

/*!
  @brief  アングルリテラルのテスト
*/
void UserDefinedLiterals::angleLiteralsTest()
{
    double one_deg = 1.0_deg;
    double one_rad = 1.0_rad;

    const double pi = 4.0 * std::atan( 1.0 );

    QCOMPARE( one_deg, pi / 180.0 );
    QCOMPARE( one_rad, 1.0 );
}

/*!
  @brief レンジリテラルのテスト
*/
void UserDefinedLiterals::lengthLiteralsTest()
{
    double one_km = 1.0_km;
    double one_m = 1.0_m;
    double one_cm = 1.0_cm;
    double one_mm = 1.0_mm;

    QCOMPARE( one_km, 1000.0 );
    QCOMPARE( one_m, 1.0 );
    QCOMPARE( one_cm, 0.01 );
    QCOMPARE( one_mm, 0.001 );
}

QTEST_APPLESS_MAIN(UserDefinedLiterals)

#include "tst_userdefinedliterals.moc"
