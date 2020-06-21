#include <QtTest>
#include "foo.h"
#include "fooconverter.h"

class ClassConverter : public QObject
{
    Q_OBJECT

public:
    ClassConverter();
    ~ClassConverter();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void serialize_user_defined_class();
    void deserialize_user_defined_class();
};

ClassConverter::ClassConverter()
{
}

ClassConverter::~ClassConverter()
{
}

void ClassConverter::initTestCase()
{
}

void ClassConverter::cleanupTestCase()
{
}

/**
 * @brief 自作クラスのシリアライズ
 */
void ClassConverter::serialize_user_defined_class()
{
    auto&& foo = sample::Foo();
    foo.setName( "Foo's name" );
    foo.setValue( 213 );
    foo.setLucky( true );
    foo.setValues( { 3, 1, 4, 1, 5 } );

    // to_json()をユーザ定義クラスと同じ名前空間（or グローバル名前空間）に定義している場合、
    // nlohmann::jsonへの暗黙的変換ができる.
    nlohmann::json json = foo;  // sample::Foo -> nlohmann::json

    QCOMPARE( json.at( "name" ).get<std::string>(), "Foo's name" );
    QCOMPARE( json.at( "value" ).get<double>(), 213.0 );
    QCOMPARE( json.at( "lucky" ).get<bool>(), true );
    QCOMPARE( json.at( "values" ).get<std::vector<int>>(), std::vector<int>( { 3, 1, 4, 1, 5 } ) );
}

/**
 * @brief 自作クラスのデシリアライズ
 */
void ClassConverter::deserialize_user_defined_class()
{
    auto&& json = R"({
        "name": "foo",
        "value": 3.14,
        "lucky": true,
        "values": [1,2,3]
    })"_json;

    // from_json()をユーザ定義クラスと同じ名前空間（or グローバル名前空間）に定義している場合、
    // nlohmann::json::get<T>()でデシリアライズできる.
    auto&& foo = json.get<sample::Foo>();

    QCOMPARE( foo.name(), "foo" );
    QCOMPARE( foo.value(), 3.14 );
    QCOMPARE( foo.lucky(), true );
    QCOMPARE( foo.values(), std::vector<int>( { 1, 2, 3 } ) );
}

QTEST_APPLESS_MAIN(ClassConverter)

#include "tst_classconverter.moc"
