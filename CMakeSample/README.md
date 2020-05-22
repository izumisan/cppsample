# CMake

# overview

- FooApp
    - 単一ファイルの場合
- FooApp2
    - ソースファイルが複数の場合
- FooApp3
    - ソースがサブディレクトリに分割している場合
- FooLibrary
    - スタティックライブラリのビルドとリンク
- FooLibrary2
    - ライブラリとAppをソリューションとして同一プロジェクトにしたサンプル
    - `target_include_directories`により、ライブラリ利用側でインクルードディレクトリの指定を不要としたサンプル
- FooLibrary3
    - CMakeListsで管理されているライブラリを`add_subdirectory`で指定したサンプル
- BuildOptions
    - `target_compile_options`でコンパイルオプションを設定する
    - `target_compile_features`でC++言語標準を設定する
    - `target_compile_definitions`でマクロを定義する


**FooLibrary**
```
Foo/
    CMakeLists.txt
FooApp/
    CMakeLists.txt
        - link_directories()
        - include_directories()
        - target_link_libraries() 
```

**FooLibrary2**
```
CMakeLists.txt
    Foo/
        CMakeLists.txt
            - target_include_directories()
    FooApp/
        CMakeLists.txt
            - target_link_libraries()

* FooLibraryサンプルと異なり、FooApp側でリンクディレクトリやインクルードディレクトリを指定する必要はない
```

**FooLibrary3**
```
Foo/
    CMakeLists.txt
        - target_include_directories()
FooApp/
    CMakeLists.txt
        - add_subdirectory()        [1]
        - target_link_libraries()

*1 FooLibrary2と異なり、FooとFooAppを含む共通のCMakeListsがない場合、add_subdirectory()で追加プロジェクトのビルドディレクトリを指定する必要がある
```


# 基本（コマンドラインツール）

1. buildディレクトリを作成する
    ```bash
    > mkdir build
    > cd build
    ```
1. Configure & Generate
    ```bash
    # cmakeにCMakeLists.txtがあるディレクトリを指定する
    > cmake ..

    # -GでGeneratorを指定できる
    # e.g. VisualStudio2017を指定
    > cmake .. -G "Visual Studio 15 2017"
    ```
1. ビルドする
    - 先のコマンド実行によりVisualStudioのソリューションが作成されているので、ソリューションを使ってビルドする
    - CMakeコマンドからでもビルドできる    
        ```bash
        # --buildオプションにbuildディレクトリを指定する
        > cmake --build .
        ```

# 基本（GUIツール）

1. `Where is the source code`に`CMakeLists.txt`があるディレクトリを指定する
1. `Where to build the binaries`にbuildディレクトリを指定する
    - 存在しない場合は作成してくれる
1. `Configure`ボタンを押下する
1. 中央部に赤く塗られたオプションが表示されるので、設定を変更する
1. **`Configure`ボタンを押下して、設定を反映する**
    - 赤い塗りつぶしが消える
    - 設定変更していなくても`Configure`ボタンを押下すること
1. `Generate`ボタンを押下する
1. `Open Project`ボタンを押下することで、VisualStudioのソリューションが起動する


# `ALL_BUILD` と `ZERO_CHECK`

- ALL_BUILD
    - 全てのプロジェクトをビルドする
- ZERO_CHECK
    - Generate後にCMakeファイルを編集した場合、その編集をプロジェクトファイルに反映するためのプロジェクト
    - `CMakeLists.txt`を編集した際は、`ZERO_CHECK`をビルドすればプロジェクトに反映（更新）される
