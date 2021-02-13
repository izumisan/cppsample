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
- MessageFormatting
    - set_pattern()によるメッセージフォーマットを指定するサンプル
- LevelName
    - ログレベルの表示名を変更するサンプル
      - "critical"は文字数が多いので、"fatal"に変更したサンプル
    
# ログレベル

- trace
- debug
- info (既定値)
- warn
- error
- critical
- off

# 備忘録

- `xxx_md`: multi thread版
- `xxx_st`: single thread版
- VisualStudioでasync loggerを使用した場合、VisualStudioランタイムのバグにより、デッドロックが発生するので,
プログラム終了前に`spdlog::shutdown()`を呼び出す必要があるらしい.
    - https://github.com/gabime/spdlog/wiki/6.-Asynchronous-logging
