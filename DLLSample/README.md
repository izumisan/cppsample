# DLLサンプル

# Overview

- Foo
    - DLLサンプル
- FooLoader
    - DLLの静的リンク
    - プロジェクト参照を追加するだけで、そのままリンクされる
- FooLoader2
    - DLLの動的リンク
    - `LoadLibrary`でDLLをロード
    - `GetProcAddress`で関数ポインタを取得
    - `FreeLibrary`でDLLをアンロード

# 呼び出し規約

- cdecl
    - x86系C/C++の呼び出し規約に使われることが多い
    - Linux等のWindows以外で使われることが多い
    - VisualStudioのデフォルト設定は、`__cdecl`になっている
- stdcall
    - Windows APIの呼び出し規約
    - `WINAPI`マクロは、`__stdcall`に展開される
    - エクスポート関数が`foo@4`のように修飾されるので、動的ロード時の関数名指定時、エクスポート名を別途確認する必要がある
- thiscall
    - メンバ関数の呼び出し規約

# エクスポート名を確認する

VisualStudioの開発者用コマンドプロンプトを起動し、下記を実行する

```
> dumpbin /exports path/to/file.dll
```
