#ifndef FOO_H
#define FOO_H

#include "ifoo.h"

namespace foo
{

class Foo : public IFoo
{
public:
    std::string name() const override;
};

}  // namespace foo

#endif // FOO_H