#ifndef TEMPERATURELITERALS_H
#define TEMPERATURELITERALS_H

namespace temperatureliterals
{

/**
 * @brief 1.0_degC -> 273.15
 * @attention 正数のみ対応（負数の場合は意図通りに変換結果にならない）
 * @note !!!この実装は適切ではない!!!
 */
constexpr double operator ""_degC( const long double value )
{
    // !!!ATTENTION!!!
    //
    // ユーザ定義リテラルの場合、マイナス記号はリテラルによる変換結果に対するマイナス単項演算子扱いとなる
    // "-23.0_degC" は "-(23_degC)" となるので "250.15" ではなく "-293.15" となる
    return value + 273.15;
}

constexpr double operator ""_K( const long double value )
{
    return value;
}

} // namespace temperatureliterals

#endif // TEMPERATURELITERALS_H
