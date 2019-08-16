# spdlog

- C++用ロギングライブラリ
- GitHub
    - https://github.com/gabime/spdlog
- ヘッダーオンリーでコンパイル不要
- 非同期対応
- 結構早いらしい

# overview

- SpdlogSample

# ログレベル

- trace
- debug
- info
- warn
- error
- critical
- off

# Note

- VisualStudioの場合、プログラム終了前に`spdlog::drop_all()`を呼び出す必要があるらしい.