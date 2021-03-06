#include <QtTest>
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "msgpack.hpp"

using nlohmann::json;

class JsonForModernCppSample2 : public QObject
{
    Q_OBJECT

public:
    JsonForModernCppSample2();
    ~JsonForModernCppSample2();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void messagepack_binary();
    void deserialized_by_messagepack();
    void deserialize_msgpack_binary();
};

JsonForModernCppSample2::JsonForModernCppSample2()
{
}

JsonForModernCppSample2::~JsonForModernCppSample2()
{
}

void JsonForModernCppSample2::initTestCase()
{
}

void JsonForModernCppSample2::cleanupTestCase()
{
}

void JsonForModernCppSample2::init()
{
}

void JsonForModernCppSample2::cleanup()
{
}
//------------------------------------------------------------------------------
/**
 * MessagePackバイナリへのシリアライズ／デシリアライズ
 */
void JsonForModernCppSample2::messagepack_binary()
{
    std::string&& jstr = R"({"name": "foo", "value": 777.777, "lucky": true})";
    json&& jobj = json::parse( jstr );

    // シリアライズ to MessagePack binary
    std::vector<uint8_t>&& bytes = json::to_msgpack( jobj );

    qDebug() << jstr.size() << bytes.size();

    // デシリアライズ from MessagePack binary
    json&& jobj2 = json::from_msgpack( bytes );

    QCOMPARE( jobj2["name"], "foo" );
    QCOMPARE( jobj2["value"], 777.777 );
    QCOMPARE( jobj2["lucky"], true );
}
//------------------------------------------------------------------------------
/**
 * JSON for Modern C++で生成したバイナリを正規のMessePackC++でデシリアライズ
 */
void JsonForModernCppSample2::deserialized_by_messagepack()
{
    auto&& jobj = R"({"name": "foo", "value": 777.777, "lucky": true})"_json;

    // serialize to MessagePack binary
    std::vector<uint8_t>&& bytes = json::to_msgpack( jobj );

    // deserialized　by official MessagePack (msgpack-c)
    msgpack::object_handle handle = msgpack::unpack( reinterpret_cast<char*>( bytes.data() ), bytes.size() );
    msgpack::object obj = handle.get();

    std::cout << obj << std::endl;

    std::string name = "";
    double value = 0.0;
    bool lucky = false;

    for ( msgpack::object_kv* p = obj.via.map.ptr;
          p < obj.via.map.ptr + obj.via.map.size;
          ++p )
    {
        std::string key = p->key.as<std::string>();
        if ( key == "name" )
        {
            name = p->val.as<std::string>();
        }
        else if ( key == "value" )
        {
            value = p->val.as<double>();
        }
        else if ( key == "lucky" )
        {
            lucky = p->val.as<bool>();
        }
        else
        {
        }
    }

    QCOMPARE( name.c_str(), "foo" );
    QCOMPARE( value, 777.777 );
    QCOMPARE( lucky, true );
}
//------------------------------------------------------------------------------
/**
 * 正規のMessagePackC++で生成したバイナリをJSON for Modern C++でデシリアライズ
 */
void JsonForModernCppSample2::deserialize_msgpack_binary()
{
    // serialized by MessagePack C++
    msgpack::sbuffer buffer;
    msgpack::packer<msgpack::sbuffer> packer( &buffer );
    packer.pack_map( 3 );
    packer.pack( "name" );
    packer.pack( "foo" );
    packer.pack( "value" );
    packer.pack( 777 );
    packer.pack( "lucky" );
    packer.pack( true );

    // msgpack::sbuffer -> std::vectory<uint8_t>
    std::vector<uint8_t> bytes;
    for ( int i = 0; i < buffer.size(); ++i )
    {
        bytes.push_back( *( buffer.data() + i ) );
    }

    // deserialized by Json for Modern C++
    json&& obj = json::from_msgpack( bytes );

    QCOMPARE( obj["name"], "foo" );
    QCOMPARE( obj["value"], 777 );
    QCOMPARE( obj["lucky"], true );
}

QTEST_APPLESS_MAIN(JsonForModernCppSample2)

#include "tst_jsonformoderncppsample2.moc"
