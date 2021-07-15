#ifndef FOO_H
#define FOO_H

#include "singleton.h"

class Foo : public Singleton<Foo>
{
public:
    Foo();
    virtual ~Foo() noexcept;

public:
    int count() const;
    void up();
    void down();

private:
    int m_count = 0;
};

#endif // FOO_H
