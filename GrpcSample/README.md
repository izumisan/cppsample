# gRPC for C++

# overview

- Basic

# protoファイルのコンバート

```
> protoc.exe --proto_path=./ --cpp_out=./ path/to/proto
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
