# gRPC

gRPC for C++

# overview

- Basic
    - gRPCのサンプル
- MultiService
    - 複数サービスを有するサンプル
- ServerStreamingRpc
    - Server-side streaming RPC (1リクエスト-複数レスポンス) のサンプル
- ClientStreamingRPC
    - Client-side streaming RPC (複数リクエスト-1レスポンス) のサンプル

# protoファイルのコンバート

```sh
# protobuf用コードを生成する
> protoc.exe --proto_path=./ --cpp_out=./ path/to/proto

# gRPC用コードを生成する
> protoc.exe --proto_path=./ --grpc_out=./ --plugin=protoc_gen_grpc=grpc_cpp_plugin.exe path/to/proto
```

# ビルド

1. vcpkgを利用してgRPCをビルドする
    ```
    > vcpkg install grpc:x64-windows
    ```
1. nugetパッケージ化
    ```
    > vcpkg export grpc:x64-windows --nuget
    ```
1. （VisualStuidoの場合）プロジェクトに作成したnugetパッケージ(native)を適用する
1. 下記のlibファイルを追加する
    - `ws2_32.lib`
    - `advapi32.lib`

# サーバー側プログラムGist

1. protoファイルより自動生成された`{サービス名}::Service`クラスを継承したサービスクラスを定義・実装する
1. サービスクラスのインスタンスを`grpc::ServerBuilder`に登録する
1. `BuildAndStart()`により、サーバーを起動する

# クライアント側プログラムGist

1. `grpc::CreateChannel()`により、コネクションを確立する
1. protoファイルより自動生成された`{サービス名}::NewStub()`により、クライアントを生成する
1. クライアントを介して、サービス関数を実行する

# 備忘録

- gRPCのビルドに30～40分かかる
- exportパッケージ(nuget, zip)が400MBを超える
    - 展開したパッケージは2GBを超える...
