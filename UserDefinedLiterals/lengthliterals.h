#ifndef LENGTHLITERALS_H
#define LENGTHLITERALS_H

namespace lengthliterals
{

/*!
  @brief  1.0_km -> 1000.0 [m]
*/
constexpr double operator ""_km( const long double value )
{
    return value * 1000.0;
}

/*!
  @brief  1.0_m -> 1.0 [m]
*/
constexpr double operator ""_m( const long double value )
{
    return value;
}

/*!
  @brief  100.0_cm -> 1.0 [m]
*/
constexpr double operator ""_cm( const long double value )
{
    return value * 0.01;
}

/*!
  @brief  1000.0_mm -> 1.0 [m]
*/
constexpr double operator ""_mm( const long double value )
{
    return value * 0.001;
}

}

#endif // LENGTHLITERALS_H
