#ifndef ANGLELITERALS_H
#define ANGLELITERALS_H

#include <cmath>

namespace angleliterals
{

/*!
  @brief  360.0_deg -> 2π [rad]
*/
constexpr double operator ""_deg( const long double value )
{
//    double pi = 4.0 * std::atan( 1.0 );
//    return value * pi / 180.0;
    return value * M_PI / 180.0;
}

/*!
  @brief  1.0_rad -> 1.0 [rad]
*/
constexpr double operator ""_rad( const long double value )
{
    return value;
}

}

#endif // ANGLELITERALS_H
