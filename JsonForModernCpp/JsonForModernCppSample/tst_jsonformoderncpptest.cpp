#include <QString>
#include <QtTest>
#include <vector>
#include <fstream>
#include <sstream>

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
    void deserialize_file();
    void type_check();
    void STL_like_access();
    void serialize();
    void serialize2();

    void support_comma_in_keyword();
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
//-----------------------------------------------------------------------------
/**
 * @brief nlohmann::json::parse()にifstreamを渡すことで、ファイル読み込み＆デシリアライズできる.
 */
void JsonForModernCppTest::deserialize_file()
{
    auto&& jsonfile = QFINDTESTDATA("foo.json");
    QVERIFY( QFile::exists( jsonfile ) == true );

    std::ifstream ifs( jsonfile.toStdString(), std::ios::in );
    auto&& json = json::parse( ifs );  // ファイル読み込み＆デシリアライズ

    QCOMPARE( json.at( "foo" ).get<std::string>(), "Foo" );
    QCOMPARE( json.at( "pi" ).get<double>(), 3.14 );
    QCOMPARE( json.at( "happy" ).get<bool>(), true );
    QCOMPARE( json.at( "lists" ).get<std::vector<double>>(), std::vector<double>( { 1.1, 2.2, 3.3 } ) );
}
//------------------------------------------------------------------------------
/**
 * @brief is_xxx()で型判定が可能.
 */
void JsonForModernCppTest::type_check()
{
    auto&& json = R"(
    {
        "foo": "Foo",
        "pi": 3.14,
        "happy": true,
        "lists": [1.1, 2.2, 3.3]
    })"_json;

    QCOMPARE( json.is_object(), true );
    QCOMPARE( json.at( "foo" ).is_string(), true );
    QCOMPARE( json.at( "pi" ).is_number(), true );
    QCOMPARE( json.at( "happy" ).is_boolean(), true );
    QCOMPARE( json.at( "lists" ).is_array(), true );
}
//------------------------------------------------------------------------------
/**
 * @brief STLコンテナのように要素にアクセスできる
 */
void JsonForModernCppTest::STL_like_access()
{
    auto&& json = R"(
    {
        "foo": "Foo",
        "pi": 3.14,
        "happy": true,
        "lists": [1.1, 2.2, 3.3]
    })"_json;

    // size()により、要素数を取得できる
    QCOMPARE( json.size(), 4 );

    // contains()により、キーの有無を確認できる
    QCOMPARE( json.contains( "foo" ), true );
    QCOMPARE( json.contains( "bar" ), false );

    // find()により、要素を取得できる
    QVERIFY( json.find( "foo" ) != json.end() );
    QVERIFY( json.find( "bar" ) == json.end() );

    // イテレータによるアクセス
    qDebug() << "----- iterator";
    for ( json::const_iterator it = json.cbegin(); it != json.cend(); ++it )
    {
        // 挿入演算子(<<)がオーバーライドされているので、std::coutやstd::stringstreamに出力可能.
        std::stringstream ss;
        ss << it.key() << " " << it.value();
        qDebug() << ss.str().c_str();
    }

    // items()により、range-for文で要素を取得できるようになる
    qDebug() << "----- range for";
    for ( auto&& element : json.items() )
    {
        std::stringstream ss;
        ss << element.key() << " " << element.value();
        qDebug() << ss.str().c_str();
    }

    // 構造化バインディング
    qDebug() << "----- structured bindings";
    for ( auto& [key, value] : json.items() )
    {
        std::stringstream ss;
        ss << key << " " << value;
        qDebug() << ss.str().c_str();
    }
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
////////////////////////////////////////////////////////////////////////////////
/**
 * @brief keyにコンマ(.)が含まれていても(de)serializeできる
 */
void JsonForModernCppTest::support_comma_in_keyword()
{
    auto&& jsonString = R"(
    {
        "foo": "FOO",
        "foo.bar": true,
        "foo.bar.baz": 123
    })";

    json&& obj = json::parse( jsonString );

    QCOMPARE( obj["foo"], "FOO" );
    QCOMPARE( obj["foo.bar"], true );
    QCOMPARE( obj["foo.bar.baz"], 123 );

    std::string serialized = obj.dump();  // std::string への 暗黙的変換
    QCOMPARE( serialized, R"({"foo":"FOO","foo.bar":true,"foo.bar.baz":123})" );
}

QTEST_APPLESS_MAIN(JsonForModernCppTest)

#include "tst_jsonformoderncpptest.moc"
