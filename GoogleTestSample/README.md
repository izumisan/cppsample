# GoogleTestSample

Google Testのサンプル

- Google Test ドキュメント日本語訳
    - [入門ガイド](http://opencv.jp/googletestdocs/primer.html#primer-important-note-4vc)
    - [上級ガイド](http://opencv.jp/googletestdocs/advancedguide.html)

# overview

- GoogleTestSample
    - GoogleTestの基本
    - nugetのstaticライブラリを利用
- GoogleTestSample2
    - GitHubのソースコードを利用
- ParametricTest
    - パラメトリックテストのサンプル

# アサーション

致命的なアサーション（`ASSERT_XXX`）とそうでないアサーション（`EXPECT_XXX`）の２タイプがある.

- 致命的なアサーションは失敗した場合にテスト実行が中断（失敗）する
- 致命的でないアサーションは失敗した場合においてもテスト実行が継続される

## アサーションマクロ

|致命的|致命的でない||
|---|---|---|
|**条件判定**|
|ASSERT_TRUE(condition)|EXPECT_TRUE(condition)|condition is true|
|ASSERT_FALSE(condition)|EXPECT_FALSE(condition)|condition is false|
|**値の判定**|
|ASSERT_EQ(expected, actual)|EXPECT_EQ(expected, actual)|expected == actual|
|ASSERT_NE(val1, val2)|EXPECT_NE(val1, val2)|val1 != val2|
|ASSERT_LT(val1, val2)|EXPECT_LT(val1, val2)|val1 < val2|
|ASSERT_LE(val1, val2)|EXPECT_LE(val1, val2)|val1 <= val2|
|ASSERT_GT(val1, val2|EXPECT_GT(val1, val2)|val1 > val2|
|ASSERT_GE(val1, val2|EXPECT_GE(val1, val2)|val1 >= val2|
|**浮動小数点の判定**|
|ASSERT_FLOAT_EQ(expected, actual)|EXPECT_FLOAT_EQ(expected, actual)|float値が許容誤差範囲内|
|ASSERT_DOUBLE_EQ(expected, actual)|EXPECT_DOUBLE_EQ(expected, actual)|double値が許容誤差範囲内|
|ASSERT_NEAR(val1, val2, epsilon)|EXPECT_NEAR(val1, val2, epsilon)|val1とval2が指定した許容誤差範囲（epsilon）内|
|**文字列の判定**|
|ASSERT_STREQ(expected, actual)|EXPECT_STREQ(expected, actual)|expected == actual|
|ASSERT_STRNE(str1, str2)|EXPECT_STRNE(str1, str2)|str1 != str2|
|ASSERT_STRCASEEQ(expected, actual|EXPECT_STRCASEEQ(expected, actual)|expected == actual (ignore case)|
|ASSERT_STRCASENE(str1, str2)|EXPECTED_STRCASENE(str1, str2)|str1 != str2 (ignore case)|
|**例外の判定**|
|ASSERT_THROW(statement, type)|EXPECT_THROW(statement, type)|statementがtypeの例外を発生する|
|ASSERT_ANY_THROW(statement)|EXPECT_ANY_THROW(statement)|statementが例外を発生する|
|ASSERT_NO_THROW(statement)|EXPECT_NO_THROW(statement)|statementは例外を発生しない|

# 覚書

- `TEST(テストケース名, テスト名)`
    - **テストケース名やテスト名にアンダースコアを使用してはいけない**
- テスト失敗時のエラーメッセージ
    ```cpp
    EXPECT_EQ( 1, 2 ) << "Error Message.";
    ```
- テストコンテキスト
    - `test_info_`ポインタで各種テスト情報を取得できる
    - `TEST_P`マクロ内では`test_info_`が使えないので、自分でポインタを取得する
        ```cpp
        const ::testing::TestInfo* const test_info = ::testing::UnitTest::GetInstance()->current_test_info();
        ```
- main関数
    ```cpp
    #include <gtest/gtest.h>
    int main( int argc, char **argv )
    {
        ::testing::InitGoogleTest( &argc, argv );
        return RUN_ALL_TESTS();
    }
    ```

# Tips

## VisualStudio 2017でビルドできない

C4996でビルドできない場合、
`_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING`を定義すると解消されるかもしれない

## C4251, C4275がうざい

nuget版（DLL版）を利用する場合、DLLリンク関連で`C4251`, `C4275`の警告が大量に出てしまう. 警告抑制安定.

## 環境構築が上手くいかない

GoogleTestをライブラリをとしてリンクするのではなく、テストコードと一緒にビルドしてしまえば手っ取り早かったりする。

GoogleTestを含めてビルドする場合は、`gtest-all.cc`をビルド対象ソースに追加するだけでよい。

`gtest-all.cc`をビルドしてもmain関数は含まれないので、`gtest_main.cc`を合わせてビルドすると、main関数を書く必要はない。

