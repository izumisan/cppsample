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

- ConsoleApp
- ConsoleApp2
    - 動作確認用プログラム
- runconverage.ps1
    - コンソール版を利用し、複数プログラムによるカバレッジレポートをマージしたサンプルスクリプト

# インストールせずにコンソール版を使用する

- VisualStudio拡張を入れた後、拡張機能のインストール先からバイナリを任意の場所に持っていけばコンソール版を使用することが可能
- 拡張アドインのインストール先
    - `{ユーザ}/AppData/Local/Microsoft/VisualStudio/xxx/Extensions/ivhqknd4.uyt`
    - 上記にある`OpenCppCoverage-x64`フォルダを好きな場所に持っていけばそのまま使用できる
