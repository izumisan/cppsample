#ifndef FOO_H
#define FOO_H

#include <string>
#include <vector>
#include <map>
#include <sstream>

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;

public:
    int getInt() const { return m_int; }
    void setInt( const int value ) { m_int = value; }

    double getDouble() const { return m_double; }
    void setDouble( const double value ) { m_double = value; }

    std::string getString() const { return m_string; }
    void setString( const std::string& value ) { m_string = value; }

    std::vector<std::string> getVector() const { return m_vector; }
    void setVector( const std::vector<std::string>& value ) { m_vector = value; }

    std::map<std::string, std::string> getMap() const {  return m_map; }
    void setMap( const std::map<std::string, std::string>& value ) { m_map = value; }

public:
    std::string toString() const
    {
        auto&& ss = std::stringstream();
        ss << m_int << "," 
           << m_double << "," 
           << m_string << ",";
        
        ss << "{";
        std::for_each( m_vector.cbegin(), m_vector.cend(), [&ss](auto&& x){ ss << x << ","; } );
        ss << "}";

        ss << "{";
        std::for_each( m_map.cbegin(), m_map.cend(), [&ss](auto&& x){ ss << "{" << x.first << ":" << x.second << "}"; } );
        ss << "}";

        return ss.str();
    }

public:
    int m_int = 0;
    double m_double = 0.0;
    std::string m_string = {};
    std::vector<std::string> m_vector = {};
    std::map<std::string, std::string> m_map = {};

public:
    MSGPACK_DEFINE( m_int, m_double, m_string, m_vector, m_map );
};

#endif // FOO_H
