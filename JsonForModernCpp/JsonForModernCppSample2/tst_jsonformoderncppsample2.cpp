#include <QtTest>
#include <string>
#include "nlohmann/json.hpp"
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

QTEST_APPLESS_MAIN(JsonForModernCppSample2)

#include "tst_jsonformoderncppsample2.moc"
