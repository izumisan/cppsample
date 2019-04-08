#ifndef INLINE_VARIABLE_H
#define INLINE_VARIABLE_H

/**
 * inline変数
 *
 * 複数の翻訳単位で実体が共有される（実体はただ一つ）.
 * ヘッダで変数を宣言（extern）し、ソースで実体を定義する必要がない.
 */
inline int inline_value = 0;

#endif // INLINE_VARIABLE_H
