# GoogleTestSample

- GoogleTestSample
    - GoogleTestの基本
    - nugetのstaticライブラリを利用
- GoogleTestSample2
    - GitHubのソースコードを利用
- ParametricTest
    - パラメトリックテストのサンプル

# 覚書

- テスト失敗時のエラーメッセージ
    ```cpp
    EXPECT_EQ( 1, 2 ) << "Error Message.";
    ```
- テストコンテキスト
    - `test_info_`ポインタで各種テスト情報を取得できる


# Tips

## VisualStudio 2017でビルドできない

C4996でビルドできない場合、
`_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING`を定義すると解消されるかもしれない

## 環境構築が上手くいかない

GoogleTestをライブラリをとしてリンクするのではなく、テストコードと一緒にビルドしてしまえば手っ取り早かったりする。

GoogleTestをビルドする場合は、`gtest-all.cc`をビルド対象ソースに追加するだけでよい。

`gtest-all.cc`をビルドしてもmain関数は含まれないので、`gtest_main.cc`を合わせてビルドすると、main関数を書く必要はない。

