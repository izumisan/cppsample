#include <QtTest>
#include <iostream>
#include <filesystem>

class FilesystemTest : public QObject
{
    Q_OBJECT

public:
    FilesystemTest(){}
    ~FilesystemTest(){}

private slots:
    void path_test();

};
/**
 * std::filesystem::pathクラス
 */
void FilesystemTest::path_test()
{
    // カレントパス
    std::filesystem::path current = std::filesystem::current_path();
    qDebug() << current.string().c_str();

    // append()により、pathオブジェクトは変化する
    std::filesystem::path parent = current.append("..");
    QVERIFY( current != std::filesystem::current_path() );

    // 絶対パス
    parent = std::filesystem::absolute( parent );

    // 親パス
    QCOMPARE( std::filesystem::current_path().parent_path(), parent );

    // ファイル名
    std::filesystem::path foo = std::filesystem::path( "path/to/foo.txt" );
    QCOMPARE( foo.filename(), "foo.txt" );

    // pathオブジェクトがディレクトリの場合、filename()でディレクトリ名が取得できる
    QCOMPARE( parent.filename().string(), "C++17Practice" );

    // 拡張子を除いたファイル名
    QCOMPARE( foo.stem(), "foo" );

    // 拡張子
    QCOMPARE( foo.extension(), ".txt" );

    // ファイルが存在するか否か
    QCOMPARE( std::filesystem::exists( foo ), false );

    std::filesystem::path profile = parent;  // 複製
    profile.append( "C++17Practice.pro" );
    QCOMPARE( std::filesystem::exists( profile ), true );
}

QTEST_APPLESS_MAIN(FilesystemTest)

#include "tst_filesystemtest.moc"
