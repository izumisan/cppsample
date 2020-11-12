#include <QtTest>
////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <streambuf>
#include <string>

class FileReader
{
public:
    /**
     * @brief ファイル内容を全て読み込む.
     */
    static std::string readAll( const std::string fileName )
    {
        std::string contents("");
        std::ifstream ifs( fileName );
        if ( ifs.is_open() )
        {
            std::istreambuf_iterator<char> it( ifs );
            std::istreambuf_iterator<char> last {};
            contents = std::string( it, last );
        }
        return contents;
    }
};
////////////////////////////////////////////////////////////////////////////////

class FileReadAll : public QObject
{
    Q_OBJECT

public:
    FileReadAll();
    ~FileReadAll();

private slots:
    void readAll_test();
};

FileReadAll::FileReadAll()
{
}

FileReadAll::~FileReadAll()
{
}

void FileReadAll::readAll_test()
{
    auto&& filePath = QFINDTESTDATA( "foo.json" );
    QVERIFY( QFile::exists( filePath ) );

    auto&& expected = R"({
    "foo": "Foo",
    "pi": 3.14,
    "lucky": true
}
)";
    auto&& actual = FileReader::readAll( filePath.toStdString() );
    QCOMPARE( actual, expected );
}

QTEST_APPLESS_MAIN(FileReadAll)

#include "tst_filereadall.moc"
