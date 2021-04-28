// options.h
#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

class Options
{
public:
    Options( const int argc, const char* argv[] );

public:
    bool success() const { return m_success; }
public:
    bool a() const { return m_a; }
    bool b() const { return m_b; }
    std::string c() const { return m_c; }
    std::string d() const { return m_d; }

private:
    bool m_success = false;
    bool m_a = false;
    bool m_b = false;
    std::string m_c = "";
    std::string m_d = "";
};

#endif // OPTIONS_H
