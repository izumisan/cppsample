// options.h
#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

class Options
{
public:
    Options( const int argc = 0, const char* argv[] = nullptr );

public:
    bool success() const { return m_success; }
    const std::string& usage() const { return m_usage; }
public:
    bool a() const { return m_a; }
    bool b() const { return m_b; }
    std::string c() const { return m_c; }
    std::string d() const { return m_d; }
    const std::vector<std::string>& e() const { return m_e; }
    const std::vector<std::string>& f() const { return m_f; }

    const std::vector<std::string>& any_other_values() const { return m_any_other_values; }
//    const std::vector<std::string>& any_values() const { return m_any_values; }

private:
    bool m_success = false;
    std::string m_usage = "";

    bool m_a = false;
    bool m_b = false;
    std::string m_c = "";
    std::string m_d = "";
    std::vector<std::string> m_e = {};
    std::vector<std::string> m_f = {};

    std::vector<std::string> m_any_other_values = {};
//    std::vector<std::string> m_any_values = {};
};

#endif // OPTIONS_H
