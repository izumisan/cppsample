# gRPC CLIアダプタ

C++/windowsでgRPCはいろいろメンドウなので、CLIアダプタを試してみた.

# overview

- FooLib
    - C++ static library
    - 当初は、FooLibとFooAdapterを分離するつもりはなく、C++ソースをこのFooAdapter内に含めてしまうつもりだったが、`/clr`オプションに対応していないC++標準ヘッダがあるようなので、分離することにした
- FooAdapter
    - C++/CLI library
- Foo.Core
    - C# library
    - ここでC#になるので、gRPC nuget版が利用できるようになる
- FooServer
- FooClient

![](images/component.svg)

# Tips

## C++標準ヘッダが`/cli`に対応していない

- `<thread>`は対応していなかった
- C++/CLIライブラリ内にC++コードを直接含めてしまう方法ではなく、C++/CLIコードととC++コードを分離してしまう方が無難か...

## `System.BadImageFormatException` が発生する

- C#アプリの`32ビットを優先`のチェックを外す
    - プラットフォームターゲットが`Any CPU`になっている影響で、x64のCLR dllを32bitとしてロードしようとした影響でExceptionが発生したと思われる

## デストラクタ・ファイナライザ [C++/CLI]

- `~Foo()`: デストラクタ
- `!Foo()`: ファイナライザ
- デストラクタが呼び出されている場合、ファイナライザは呼び出されない
    - デストラクタからファイナライザを呼び出すのが一般的？

## gRPCのテストについて (未解決)

- protoファイルから自動生成されたFooServiceBaseのサブクラスに実装したサービス関数を直接テストすることを試みたが、`ServerCallContext`の扱いが不明だったので断念
- 次に、テストクラスでサーバークラスとクライアントクラスを同時に実行することを試みたが、うまくいかなかった
- 結局、テストクラスからサーバープログラムを外部プログラムとして実行することにしたが、コレジャナイ感
