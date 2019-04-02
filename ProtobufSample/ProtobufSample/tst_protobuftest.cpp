#include <QtTest>
#include <string>
#include "google/protobuf/util/json_util.h"
#include "Foo.pb.h"

class ProtobufTest : public QObject
{
    Q_OBJECT

public:
    ProtobufTest();
    ~ProtobufTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void serialize_deserialize();

    void serialize_to_json();
    void deserialize_json();
};

ProtobufTest::ProtobufTest()
{
}

ProtobufTest::~ProtobufTest()
{
}

void ProtobufTest::initTestCase()
{
}

void ProtobufTest::cleanupTestCase()
{
}

void ProtobufTest::init()
{
}

void ProtobufTest::cleanup()
{
}
//------------------------------------------------------------------------------
/**
 * シリアライズ／デシリアライズ
 */
void ProtobufTest::serialize_deserialize()
{
    auto&& foo = foo::Foo();
    foo.set_id( 777 );
    foo.set_name( "foo" );
    foo.set_value( 123.4567 );
    foo.set_lucky( true );

    // シリアライズ
    std::string&& bytes = foo.SerializeAsString();
    qDebug() << bytes.size();

    // デシリアライズ
    auto&& refoo = foo::Foo();
    refoo.ParseFromString( bytes );

    QCOMPARE( refoo.id(), 777 );
    QCOMPARE( refoo.name(), "foo" );
    QCOMPARE( refoo.value(), 123.4567 );
    QCOMPARE( refoo.lucky(), true );
}
//------------------------------------------------------------------------------
/**
 * JSONへのシリアライズ
 */
void ProtobufTest::serialize_to_json()
{
    auto&& foo = foo::Foo();
    foo.set_id( 777 );
    foo.set_name( "foo" );
    foo.set_value( 123.4567 );
    foo.set_lucky( true );

    // serialize to JSON
    std::string jstr;
    google::protobuf::util::MessageToJsonString( foo, &jstr );

    qDebug() << jstr.c_str();

    QVERIFY( jstr.find( R"("id":777)" ) != std::string::npos );
    QVERIFY( jstr.find( R"("name":"foo")" ) != std::string::npos );
    QVERIFY( jstr.find( R"("value":123.4567)" ) != std::string::npos );
    QVERIFY( jstr.find( R"("lucky":true)" ) != std::string::npos );
}
//------------------------------------------------------------------------------
/**
 * JSONのデシリアライズ
 */
void ProtobufTest::deserialize_json()
{
    auto&& json = R"({"id": 777, "name": "foo", "value": 777.7777, "lucky": true})";

    // deserialize JSON
    auto&& foo = foo::Foo();
    google::protobuf::util::JsonStringToMessage( json, &foo );

    QCOMPARE( foo.id(), 777 );
    QCOMPARE( foo.name(), "foo" );
    QCOMPARE( foo.value(), 777.7777 );
    QCOMPARE( foo.lucky(), true );
}

QTEST_APPLESS_MAIN(ProtobufTest)

#include "tst_protobuftest.moc"
