#include <QtTest>
#include <type_traits>
#include <string>
#include <unordered_map>

class StructuredBindingsTest : public QObject
{
    Q_OBJECT

public:
    StructuredBindingsTest() {}
    ~StructuredBindingsTest() {}

private slots:
    void structured_bindings();

};
/**
 * 構造化束縛
 *
 * std::map(std::unordered_map)のfor文でkey,valueをそれぞれ束縛する
 */
void StructuredBindingsTest::structured_bindings()
{
    auto&& map = std::unordered_map<std::string, int>
    {
        { "foo", 7 },
        { "bar", 77 },
        { "baz", 777 }
    };

    // unordered_mapの要素であるstd::pair<const std::string, int>を
    // k, vに分解（束縛）する
    // kは、const std::string型, vは、int型
    for ( auto&& [k, v] : map )
    {
        QCOMPARE( std::is_const<decltype(k)>::value, true );
        QCOMPARE( std::is_const<decltype(v)>::value, false );

        bool actual = std::is_same<decltype(k), const std::string>::value;
        QCOMPARE( actual, true );

        actual = std::is_same<decltype(v), int>::value;
        QCOMPARE( actual, true );
    }

    // const auto&で受けた場合、
    // kは、const std::string型、 vは、const int型
    for ( const auto& [k, v] : map )
    {
        QCOMPARE( std::is_const<decltype(k)>::value, true );
        QCOMPARE( std::is_const<decltype(v)>::value, true );

        bool actual = std::is_same<decltype(k), const std::string>::value;
        QCOMPARE( actual, true );

        actual = std::is_same<decltype(v), const int>::value;
        QCOMPARE( actual, true );
    }
}

QTEST_APPLESS_MAIN(StructuredBindingsTest)

#include "tst_structuredbindingstest.moc"
