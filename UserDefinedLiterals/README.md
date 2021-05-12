# ユーザ定義リテラル (User-defined literals)

リテラルに対してサフィックスを付加して、サフィックスに意味を持たせる（オーバーロード）機能

ユーザ定義リテラルは、`operator""サフィックス名` 演算子（リテラル演算子）をオーバーロードする

- [ユーザ定義リテラル - C++日本語リファレンス](https://cpprefjp.github.io/lang/cpp11/user_defined_literals.html)

# サフィックス名について

アンダースコアで始まらないサフィックス名、アンダースコア+大文字、2つ以上の連続したアンダースコアで始まるサフィックス名は、標準C++用に予約されているので注意すること

# 負数リテラルに対するリテラル演算子

`-1_deg` や `-1.23_deg` のように、負数リテラルに対するリテラル演算子には、正数部分のみが渡される（マイナス記号はリテラルの一部とみなされない）

マイナス記号はリテラル演算子の結果に対するマイナス単項演算子として適用されることに注意すること

- `_deg` や `_ft` 等の単位換算目的のリテラル演算子は問題ないが、例えば、温度単位の換算（セルシウス℃ <=> ケルビン）を目的とした `_degC` リテラル演算子は、負数に対応できない
    - `10.0_degC` => `283.15` OK
    - `-10.0_degC` => `-283.15` NG