#ifndef FOO_H
#define FOO_H

namespace foo
{

class Foo
{
public:
    Foo() = default;
    virtual ~Foo() noexcept = default;

public:
    int sleep( const int seconds );
    int sleep2( const int seconds );
};

} // namespace foo

#endif // FOO_H
