#include "inline_variable.h"
#include "foo.h"

namespace foo
{

void set_inline_value( const int value )
{
    inline_value = value;
}

int get_inline_value()
{
    return inline_value;
}

}
