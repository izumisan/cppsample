# 非同期サンプル

# overview

- ThreadSample
    - `std::thread`のサンプル
- AsyncSample
    - `std::async`のサンプル

# std::thread

- `thread`オブジェクトは、`join()`または`detach()`する必要がある
- `thread`オブジェクトにスレッドが関連づいているか否かは`joinable()`で確認できる

# std::async

- 実行ポリシー
    - `std::launch::async`
        - 別スレッドで実行
    - `std::launch::deferred`
        - 遅延評価
    - `std::launch::async | std::launch::deferred`
        - 上記いずれか（実装依存）
    - 指定なし
        - `std::launch::async | std::launch::deferred`と同様
