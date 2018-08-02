#include <QString>
#include <QtTest>
#include <vector>

#include "nlohmann/json.hpp"

// エイリアス
using json = nlohmann::json;

class JsonForModernCppTest : public QObject
{
    Q_OBJECT

public:
    JsonForModernCppTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void deserialize();
    void deserialize2();

    void serialize();
    void serialize2();
};

JsonForModernCppTest::JsonForModernCppTest()
{
}

void JsonForModernCppTest::initTestCase()
{
}

void JsonForModernCppTest::cleanupTestCase()
{
}

void JsonForModernCppTest::init()
{
}

void JsonForModernCppTest::cleanup()
{
}
//------------------------------------------------------------------------------
/*!
  @brief  nlohmann::json::parse()で文字列からJSONオブジェクトを生成する
*/
void JsonForModernCppTest::deserialize()
{
    auto&& jsonstring  = R"(
    {
        "foo": "Foo",
        "pi": 3.14,
        "happy": true
    })";

    json&& obj = json::parse( jsonstring );

    QCOMPARE( obj["foo"], "Foo" );
    QCOMPARE( obj["pi"], 3.14 );
    QCOMPARE( obj["happy"], true );

    QCOMPARE( obj["hoge"], nullptr );
}
//------------------------------------------------------------------------------
/*!
  @brief  _jsonリテラルでJSONオブジェクトを生成する
*/
void JsonForModernCppTest::deserialize2()
{
    json&& j = R"(
    {
        "foo": "Foo",
        "pi": 3.14,
        "happy": true
    })"_json;

    QCOMPARE( j["foo"], "Foo" );
    QCOMPARE( j["pi"], 3.14 );
    QCOMPARE( j["happy"], true );

    QCOMPARE( j["hoge"], nullptr );
}
//------------------------------------------------------------------------------
/*!
  @brief  nlohmann::json::dump()でJSONを生成する
*/
void JsonForModernCppTest::serialize()
{
    json obj;

    obj["foo"] = "Foo";
    obj["fuga"] = "Fuga";
    obj["pi"] = 3.141592;
    obj["happy"] = true;
    obj["null"] = nullptr;
    obj["array"] = std::vector<int>{ 1, 2, 3, };

    // シリアライズ
    auto&& str = obj.dump();

    qDebug() << str.c_str();

    auto&& actual = json::parse( str );
    QCOMPARE( actual["foo"], "Foo" );
    QCOMPARE( actual["fuga"], "Fuga" );
    QCOMPARE( actual["pi"], 3.141592 );
    QCOMPARE( actual["happy"], true );
    QCOMPARE( actual["null"], nullptr );
    QCOMPARE( actual["array"].at(0), 1 );
    QCOMPARE( actual["array"].at(1), 2 );
    QCOMPARE( actual["array"].at(2), 3 );
}
//------------------------------------------------------------------------------
/*!
  @brief  nlohmann::json::dump()でJSONを生成する
*/
void JsonForModernCppTest::serialize2()
{
    // initializer-listバージョン
    json obj = {
        { "foo", "Foo" },
        { "fuga", "Fuga" },
        { "pi", 3.14 },
        { "happy", true },
        { "null", nullptr },
        { "array", { 1, 2, 3 } }
    };

    // シリアライズ
    // 引数を指定した場合、引数で指定した数のスペースでインデントされる
    auto&& str = obj.dump(4);

    qDebug() << str.c_str();

    auto&& actual = json::parse( str );
    QCOMPARE( actual["foo"], "Foo" );
    QCOMPARE( actual["fuga"], "Fuga" );
    QCOMPARE( actual["pi"], 3.14 );
    QCOMPARE( actual["happy"], true );
    QCOMPARE( actual["null"], nullptr );
    QCOMPARE( actual["array"].size(), 3 );
    QCOMPARE( actual["array"][0], 1 );
    QCOMPARE( actual["array"][1], 2 );
    QCOMPARE( actual["array"][2], 3 );
}

QTEST_APPLESS_MAIN(JsonForModernCppTest)

#include "tst_jsonformoderncpptest.moc"
