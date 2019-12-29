# OpenCppCoverage

Windows用のC++カバレッジ計測ツール

- GitHub
    - https://github.com/OpenCppCoverage/OpenCppCoverage
    - https://github.com/OpenCppCoverage/OpenCppCoveragePlugin
- 要インストール
- HTMLのレポート出力可能
- [VisualStudio用拡張アドイン](https://marketplace.visualstudio.com/items?itemName=OpenCppCoverage.OpenCppCoveragePlugin)有り
    - OpenCppCoverage本体が統合されているので、本体そのものをインストールしていなくても使用可能
    - VisualStudioウィンドウでカバレッジ確認可能
- 計測しているのは命令網羅（statement coverage）（C0）っぽい

# overview

- ConsoleApp / ConsoleApp2
    - VisualStudioアドインの動作確認用プログラム
- runcoverage.ps1
    - コンソール版を利用し、複数プログラムによるカバレッジレポートをマージしたサンプルスクリプト
    - 実行にはOpenCppCoverageのバイナリを別途コピーしてくること（リポジトリには登録していない）
    ```
    OpenCppCoverageExample/
        OpenCppCoverage-x64/        # これをコピーしてくる
            OpenCppCoverage.exe
             :
        runcoverage.ps1
    ```

# OpenCppCoverageをインストールせずにコンソール版を使用する

- VisualStudio拡張を入れた後、拡張機能のインストール先からバイナリを任意の場所に持っていけばコンソール版を使用することが可能
- 拡張アドインのインストール先
    - `{ユーザ}/AppData/Local/Microsoft/VisualStudio/xxx/Extensions/ivhqknd4.uyt`
    - 上記にある`OpenCppCoverage-x64`フォルダを好きな場所に持っていけばそのまま使用できる

# レポート

- `--export_type`を指定しない場合、規定の場所にHTMLレポートが出力される
- `--export_type=html:Foo`でFooディレクトリにHTMLレポートを出力する
    - 出力先ディレクトリは省略可
- `--export_type=binary:foo.cov`でバイナリ形式のレポートを出力する
    - 出力先ファイルは省略可
- `--export_type`は複数指定可能
    - `--export_type=html:FooDir --export_type=binary:foo.cov` とすることで、HTMLとバイナリを共に出力する
- `--input_coverage`でバイナリ形式のレポートを指定することで、レポートをマージする
    ```sh
    # foo.cov と bar.cov をマージする
    > OpenCppCoverage.exe --input_coverage=foo.cov --input_coverage=bar.cov
    ```
