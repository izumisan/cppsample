#ifndef FOO_H
#define FOO_H

#include <string>
#include <vector>

namespace sample
{

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;

public:
    const std::string& name() const { return m_name; }
    double value() const { return m_value; }
    bool lucky() const { return m_lucky;}
    const std::vector<int>& values() const { return m_values; }

    void setName( const std::string& value ) { m_name = value; }
    void setValue( const double value ) { m_value = value; }
    void setLucky( const bool value ) { m_lucky = value; }
    void setValues( const std::vector<int>& values ) { m_values = values; }

private:
    std::string m_name {};
    double m_value = 0.0;
    bool m_lucky = false;
    std::vector<int> m_values {};
};

} // namespace sample

#endif // FOO_H
