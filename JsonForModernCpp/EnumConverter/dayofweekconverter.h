#ifndef DAYOFWEEKCONVERTER_H
#define DAYOFWEEKCONVERTER_H

#include <nlohmann/json.hpp>
#include "dayofweek.h"

namespace sample
{

// NLOHMANN_JSON_SERIALIZE_ENUMマクロで、列挙型 => 文字列 への変換テーブルを設定することにより、
// to_json() / from_json() が自動的に定義される.
NLOHMANN_JSON_SERIALIZE_ENUM( DayOfWeek, {
    { sample::DayOfWeek::Sunday, "Sunday" },
    { sample::DayOfWeek::Monday, "Monday" },
    { sample::DayOfWeek::Tuesday, "Tuesday" },
    { sample::DayOfWeek::Wednesday, "Wednesday" },
    { sample::DayOfWeek::Thursday, "Thursday" },
    { sample::DayOfWeek::Friday, "Friday" },
    { sample::DayOfWeek::Saturday, "Saturday" }
});

} // namespace sample

#endif // DAYOFWEEKCONVERTER_H
