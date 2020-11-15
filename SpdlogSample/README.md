# spdlog

- C++用ロギングライブラリ
- ヘッダーオンリーでコンパイル不要
- 非同期対応
- 結構早いらしい
- GitHub
    - https://github.com/gabime/spdlog
- Documents
    - https://spdlog.docsforge.com/v1.x/

# overview

- SpdlogSample
    - 基本的な使い方
- SpdlogSample2
    - ログファイルへの出力サンプル
- SpdlogSample3
    - コンソールとファイルに同時に出力するloggerのサンプル
# ログレベル

- trace
- debug
- info (既定値)
- warn
- error
- critical
- off

# 備忘録

- VisualStudioの場合、プログラム終了前に`spdlog::drop_all()`を呼び出す必要があるらしい.
- `xxx_md`: multi thread版
- `xxx_st`: single thread版