#ifndef FOOCONVERTER_H
#define FOOCONVERTER_H

#include <nlohmann/json.hpp>
#include "foo.h"

namespace sample
{

/**
 * @brief to_json()を定義することで、自作クラスをnlohmann::jsonへ暗黙的変換が可能となる
 */
void to_json( nlohmann::json& json, const Foo& foo )
{
    json["name"] = foo.name();
    json["value"] = foo.value();
    json["lucky"] = foo.lucky();
    json["values"] = foo.values();
}

/**
 * @brief from_jsonを定義することで、nlohmann::json::get<T>()により、自作クラスのデシリアライズが可能となる
 */
void from_json( const nlohmann::json& json, Foo& foo )
{
    foo.setName( json.at( "name" ).get<std::string>() );
    foo.setValue( json.at( "value" ).get<double>() );
    foo.setLucky( json.at( "lucky" ).get<bool>() );
    foo.setValues( json.at( "values" ).get<std::vector<int>>() );
}

} // namespace sample

#endif // FOOCONVERTER_H
