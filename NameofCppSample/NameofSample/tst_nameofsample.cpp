#include <QtTest>
#include <iostream>

#include <nameof.hpp>
#include "month.h"

class NameofSample : public QObject
{
    Q_OBJECT

public:
    NameofSample();
    ~NameofSample();

private slots:
    void NAMEOF_can_get_name_of_variable_method_and_macro();
    void NAMEOF_ENUM_can_get_enum_element_name();
    void NAMEOF_TYPE_can_get_type_name();
    void NAMEOF_retval();
};

NameofSample::NameofSample()
{
}

NameofSample::~NameofSample()
{
}

/**
 * @brief NAMEOFマクロにより、変数名、メソッド名、マクロ名が取得できる
 */
void NameofSample::NAMEOF_can_get_name_of_variable_method_and_macro()
{
    std::string foo = "foo string";

    // 変数名
    std::cout << NAMEOF( foo ) << std::endl;  // -> "foo"

    // メソッド名
    std::cout << NAMEOF( foo.empty() ) << std::endl;  // -> "empty"

    // マクロ名
    std::cout << NAMEOF( _MSC_VER ) << std::endl;  // -> "_MSC_VER"
}

/**
 * @brief NAMEOF_ENUMにより、列挙型要素を文字列として取得できる
 */
void NameofSample::NAMEOF_ENUM_can_get_enum_element_name()
{
    auto&& month = Month::April;

    // 列挙型変数を指定すると、列挙型要素の文字列として得る
    std::cout << NAMEOF_ENUM( month ) << std::endl;  // -> "April"
    std::cout << nameof::nameof_enum( month ) << std::endl;  // -> "April"

    // 列挙型要素を直接指定してもよい
    std::cout << NAMEOF_ENUM( Month::May ) << std::endl;  // -> "May"
    std::cout << nameof::nameof_enum( Month::June ) << std::endl;  // -> "June"
}

/**
 * @brief NAMEOF_TYPEにより、型名を文字列で取得できる
 */
void NameofSample::NAMEOF_TYPE_can_get_type_name()
{
    // NAMEOF_TYPEにより、型名を文字列として得る
    std::cout << NAMEOF_TYPE( const int&& ) << std::endl;  // -> "int"
    std::cout << nameof::nameof_type<const int&&>() << std::endl;  // -> "int"

    // NAMEOF_FULL_TYPEだと、完全名で得る
    std::cout << NAMEOF_FULL_TYPE( const int&& ) << std::endl;  // -> "int const &&"
    std::cout << nameof::nameof_full_type<const int&&>() << std::endl;  // -> "int const &&"

    auto&& foo = 123;

    // 変数の型名を得る場合は、NAMEOF_TYPE_EXPRを使う
    std::cout << NAMEOF_TYPE_EXPR( foo ) << std::endl;  // -> "int"
    std::cout << NAMEOF_FULL_TYPE_EXPR( foo ) << std::endl;  // -> "int &&"

    std::cout << nameof::nameof_type<decltype(foo)>() << std::endl;  // -> "int"
    std::cout << nameof::nameof_full_type<decltype(foo)>() << std::endl;  // -> "int &&"
}

/**
 * @brief NAMEOFの戻り値の型
 */
void NameofSample::NAMEOF_retval()
{
    bool lucky = true;

    // NAMEOFの戻り値は、nameof::cstring<>型
    auto retval = NAMEOF( lucky );
    qDebug() << typeid( retval ).name();  // -> "class nameof::cstring<5>"

    // nameof::cstring::str()で、std::string型に変換できる
    std::string str = retval.str();
}

QTEST_APPLESS_MAIN(NameofSample)

#include "tst_nameofsample.moc"
