#include <QtTest>
#include <algorithm>
#include <vector>

class EraseRemoveIdiom : public QObject
{
    Q_OBJECT

public:
    EraseRemoveIdiom();
    ~EraseRemoveIdiom();

private slots:
    void erase_remove_idiom_test();
};

EraseRemoveIdiom::EraseRemoveIdiom()
{
}

EraseRemoveIdiom::~EraseRemoveIdiom()
{
}

/**
 * @brief Erase-Removeイディオム
 */
void EraseRemoveIdiom::erase_remove_idiom_test()
{
    std::vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    QCOMPARE( data.size(), 10 );

    // std::remove()やremove_if()は指定要素をコンテナから削除しないため、コンテナサイズ（要素数）は変化しない。
    // 残す要素を先頭詰めにして、削除要素は末尾に残っている（[result, data.end()に削除要素が残っている）
    auto&& result = std::remove_if( data.begin(), data.end(), [](auto&& x){ return x % 2 == 0; } );
    QCOMPARE( data.size(), 10 );

    // erase()で不要要素を削除することで、コンテナサイズを変更する。
    data.erase( result, data.end() );
    QCOMPARE( data.size(), 5 );
}

QTEST_APPLESS_MAIN(EraseRemoveIdiom)

#include "tst_eraseremoveidiom.moc"
