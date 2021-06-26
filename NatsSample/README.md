# NATS C Client

[NATS](https://nats.io/)の公式C言語クライアントである[nats.c](https://github.com/nats-io/nats.c)のサンプル

# overview

- Pub/Sub
    - Pub/Subの基本サンプル
- RPC
    - RPCのサンプル

# ビルド

cmake例
```
> cmake .. -G "Visual Studio 15 2017" -DCMAKE_GENERATOR_PLATFORM=x64 -DNATS_BUILD_WITH_TLS=OFF  -DNATS_BUILD_STREAMING=OFF
```
- TLS/SSLを使用しないので、`NATS_BUILD_WITH_TLS=OFF`を指定
    - デフォルト設定（ON）の場合、OpenSSLのインストールが必要
- NATS Streaming Serverを使用しないので、`NATS_BUILD_STREAMING=OFF`を指定
    - デフォルト設定（ON）の場合、Protocol Bufferへのリンク設定が必要
