# JSON for Modern C++

- C++用JSONライブラリ
- GitHub
    - https://github.com/nlohmann/json

# overview

- JsonForModernCppSample
    - はじめてのJSON for Modern C++
- JsonForModernCppSample2
    - MessagePackとの相互変換サンプル
- ClassConverter
    - 自作クラスの(de)serializeサンプル
- EnumConverter
    - 列挙型の(de)serializeサンプル

# 備忘録

- デシリアライズ
    - `nlohmann::json::parse()`
    - 引数に`std::ifstream`を指定することで、json文字列だけでなくjsonファイルのシリアライズが可能
    - <b><u>Keyにコンマが含まれていても良い</u></b>
    - 自作クラスのデシリアライズには、`from_json()`を定義する
- シリアライズ
    - `nlohmann::json::dump()`
    - 引数にインデント幅を指定することで、整形されたjson文字列にシリアライズ可能
    - 自作クラスのシリアら慈雨には、`to_json()`を定義する

# 参考

- [C++のjsonライブラリ決定版 nlohmnn-json - Qiita](https://qiita.com/yohm/items/0f389ba5c5de4e2df9cf)
