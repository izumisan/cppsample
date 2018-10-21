#ifndef IFOO_H
#define IFOO_H

#include <string>

namespace foo
{

class IFoo
{
public:
    virtual std::string name() const = 0;
    virtual void setName( const std::string& name ) = 0;
};

} // namespace foo

#endif // IFOO_H
