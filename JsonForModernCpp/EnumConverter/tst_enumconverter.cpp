#include <QtTest>
#include <nlohmann/json.hpp>
#include "dayofweek.h"
#include "dayofweekconverter.h"

class EnumConverter : public QObject
{
    Q_OBJECT

public:
    EnumConverter();
    ~EnumConverter();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void deserialize_enum();
    void serialize_enum();
};

EnumConverter::EnumConverter()
{
}

EnumConverter::~EnumConverter()
{
}

void EnumConverter::initTestCase()
{
}

void EnumConverter::cleanupTestCase()
{
}

/**
 * @brief 列挙型のデシリアライズ
 */
void EnumConverter::deserialize_enum()
{
    auto&& json = R"({
        "yesturday": "Saturday",
        "today": "Sunday",
        "tomorrow": "Monday"
    })"_json;

    auto&& yesturday = json.at( "yesturday" ).get<sample::DayOfWeek>();
    auto&& today = json.at( "today" ).get<sample::DayOfWeek>();
    auto&& tomorrow = json.at( "tomorrow" ).get<sample::DayOfWeek>();

    QCOMPARE( yesturday, sample::DayOfWeek::Saturday );
    QCOMPARE( today, sample::DayOfWeek::Sunday );
    QCOMPARE( tomorrow, sample::DayOfWeek::Monday );
}

/**
 * @brief 列挙型のシリアライズ
 */
void EnumConverter::serialize_enum()
{
    auto&& json = nlohmann::json();

    json["today"] = sample::DayOfWeek::Sunday;
    json["yesturday"] = "Saturday";
    json["tomorrow"] = 0;

    qDebug() << json.dump().c_str();  //=> {"today":"Sunday","tomorrow":0,"yesturday":"Saturday"}
    // DayOfWeek型が文字列に変換されるだけであり、enum値が文字列としてシリアライズされるわけではない

    QCOMPARE( json.at( "today" ).get<std::string>(), "Sunday" );
    QCOMPARE( json.at( "today" ).get<sample::DayOfWeek>(), sample::DayOfWeek::Sunday );

    QCOMPARE( json.at( "yesturday" ).get<std::string>(), "Saturday" );
    QCOMPARE( json.at( "yesturday" ).get<sample::DayOfWeek>(), sample::DayOfWeek::Saturday );

    QCOMPARE( json.at( "tomorrow" ).is_string(), false );
    QCOMPARE( json.at( "tomorrow" ).get<sample::DayOfWeek>(), sample::DayOfWeek::Sunday );  // enum値のデシリアライズは可能
}

QTEST_APPLESS_MAIN(EnumConverter)

#include "tst_enumconverter.moc"
