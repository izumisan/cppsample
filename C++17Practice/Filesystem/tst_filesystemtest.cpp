#include <QtTest>
#include <iostream>
#include <vector>
#include <filesystem>

class FilesystemTest : public QObject
{
    Q_OBJECT

public:
    FilesystemTest(){}
    ~FilesystemTest(){}

private slots:
    void path_test();
    void directory_entry_test();
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
/**
 * std::filesystem::directory_entryクラス
 */
void FilesystemTest::directory_entry_test()
{
    // カレントディレクトリ
    std::filesystem::directory_entry dir( std::filesystem::current_path() );
    qDebug() << dir.path().string().c_str();

    QCOMPARE( dir.exists(), true );

    // ディレクトリ？
    QCOMPARE( dir.is_directory(), true );

    // ファイル？
    QCOMPARE( dir.is_regular_file(), false );

    // ディレクトリ内を走査するイテレータ
    std::filesystem::directory_iterator dirIter( dir.path() );
    auto&& filelist = std::vector<std::string>();

    // カレントディレクトリ内のファイルを列挙
    for ( const std::filesystem::directory_entry& item : dirIter )
    {
        filelist.emplace_back( item.path().filename().string() );
    }
    QCOMPARE( std::any_of( filelist.cbegin(), filelist.cend(), [](auto&& x){ return x == "Makefile"; } ), true );
    QCOMPARE( std::any_of( filelist.cbegin(), filelist.cend(), [](auto&& x){ return x == "Makefile.Debug"; } ), true );
    QCOMPARE( std::any_of( filelist.cbegin(), filelist.cend(), [](auto&& x){ return x == "Makefile.Release"; } ), true );
}

QTEST_APPLESS_MAIN(FilesystemTest)

#include "tst_filesystemtest.moc"
