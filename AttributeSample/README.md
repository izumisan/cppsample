# Attributesサンプル

C++11以降で追加された属性構文のサンプルコード

属性は`[[attribute]]`のように、２重角カッコで指定する.

# overview

- DeprecatedAttribute
    - `deprecated`属性のサンプル

# 標準属性

- `noreturn`  [C++11]
- `carries_dependency`  [C++11]
- `deprecated`  [C++14]
    - 非推奨であることを示す属性
- `fallthrough`  [C++17]
- `maybe_unused`  [C++17]
    - 未使用な変数や関数に指定することで、未使用であることをコンパイラに伝えることで警告を抑制するための属性
- `nodiscard`  [C++17]
    - 関数の戻り値を破棄してはいけないことをコンパイラに伝え、破棄した場合には警告する属性

# 覚書

- VisualStudioの場合、SDLチェックをいいえ（/sdl-）に設定しないと、`deprecated`属性が警告ではなくエラーとして扱われる.
