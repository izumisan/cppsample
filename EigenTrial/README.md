# Eigen

ヘッダーオンリーな線形代数ライブラリ

- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [Gitlab](https://gitlab.com/libeigen/eigen)

# マクロ

- `EIGEN_INITIALIZE_MATRICES_BY_ZERO`
    - デフォルトではmatrixやarrayの要素は不定値だが、定義することにより要素が0で初期化される
- `EIGEN_MPL2_ONLY`
    - 定義することにより、LGPLの機能を無効にする
- `EIGEN_NO_DEBUG`
    - 定義することにより、Eigenアサーションが無効になる（`NODEBUG`が定義されていない場合のみ）
    - かなり高速になるらしい
- `EIGEN_NO_STATIC_ASSERT`
    - 定義することにより、静的アサーションが無効になる（コンパイル時間短縮）
- [その他のマクロ](https://eigen.tuxfamily.org/dox/TopicPreprocessorDirectives.html)

# Link

- [C++行列計算ライブラリEigen入門 - Qiita](https://qiita.com/yohm/items/a03006790dc1e54a87be)
- [ベクトル/行列演算の定番ライブラリEigen - Qiita](https://qiita.com/vs4sh/items/7e8bc95250db8d88bc41)
- [Eigenを用いた密行列演算・分解の概要 - Qiita](https://qiita.com/MusicScience37/items/13fefa6bed25ab8fb6e9)
- [Eigen - C++で使える線形代数ライブラリ - でらうま倶楽部](http://blog.livedoor.jp/tek_nishi/archives/8623876.html)
- [Eigen ー C++で線形代数を！(2)](http://www.singularpoint.org/blog/c/eigen_2/)
- [Eigen ー C++で線形代数を！(3)](http://www.singularpoint.org/blog/math/eigen-3/)
- [C++線形代数ライブラリEigenの注意点](https://www.regentechlog.com/2018/12/09/eigen-note/)
- [行列ライブラリEigenのメモ 暗黒通信団](http://ankokudan.org/d/dl/pdf/pdf-eigennote.pdf)
