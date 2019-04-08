#include <QtTest>
#include <string>
#include <vector>
#include <any>

using namespace std::literals::string_literals;

class AnyClassTest : public QObject
{
    Q_OBJECT

public:
    AnyClassTest(){}
    ~AnyClassTest(){}

private slots:
    void any_sample();
    void any_list();
};
/**
 * anyクラスの基本的な使い方
 */
void AnyClassTest::any_sample()
{
    std::any any;

    QCOMPARE( any.has_value(), false );

    // int型データの保持
    any = 7;
    QCOMPARE( any.has_value(), true );
    QCOMPARE( any.type(), typeid(int) );

    // any_castで値を取り出す
    int int_value = std::any_cast<int>( any );
    QCOMPARE( int_value, 7 );

    // 型はany型なので、is_sameはfalseとなる
    bool isSame = std::is_same<decltype (any), int>::value;
    QCOMPARE( isSame, false );

    // resetで保持している値を破棄する
    any.reset();
    QCOMPARE( any.has_value(), false );

    // double型データの保持
    any = 7.77;
    double double_value = std::any_cast<double>( any );
    QCOMPARE( double_value, 7.77 );

    // const char*型データの保持
    any = "This type is a const char ptr";
    auto&& const_char_ptr = std::any_cast<const char*>( any );
    QCOMPARE( const_char_ptr, "This type is a const char ptr" );

    // std::string型データの保持
    any = "This type is a std::string"s;
    auto&& string_value = std::any_cast<std::string>( any );
    QCOMPARE( string_value, "This type is a std::string" );
}
/**
 * any型リストのサンプル
 */
void AnyClassTest::any_list()
{
    auto&& list = std::vector<std::any> { 7, 7.77, "foo"s, true };

    auto&& item_0 = std::any_cast<int>( list.at(0) );
    auto&& item_1 = std::any_cast<double>( list.at(1) );
    auto&& item_2 = std::any_cast<std::string>( list.at(2) );
    auto&& item_3 = std::any_cast<bool>( list.at(3) );

    QCOMPARE( item_0, 7 );
    QCOMPARE( item_1, 7.77 );
    QCOMPARE( item_2, "foo" );
    QCOMPARE( item_3, true );
}

QTEST_APPLESS_MAIN(AnyClassTest)

#include "tst_anyclasstest.moc"
