#include <QtTest>
#include "foo.h"
#include "fooconverter.h"

class JsonForModernCppSample3 : public QObject
{
    Q_OBJECT

public:
    JsonForModernCppSample3();
    ~JsonForModernCppSample3();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void serialize_user_defined_class();
    void deserialize_user_defined_class();
};

JsonForModernCppSample3::JsonForModernCppSample3()
{
}

JsonForModernCppSample3::~JsonForModernCppSample3()
{
}

void JsonForModernCppSample3::initTestCase()
{
}

void JsonForModernCppSample3::cleanupTestCase()
{
}

/**
 * @brief 自作クラスのシリアライズ
 */
void JsonForModernCppSample3::serialize_user_defined_class()
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
void JsonForModernCppSample3::deserialize_user_defined_class()
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

QTEST_APPLESS_MAIN(JsonForModernCppSample3)

#include "tst_jsonformoderncppsample3.moc"
