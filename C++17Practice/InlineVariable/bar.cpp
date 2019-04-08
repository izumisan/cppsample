#include "inline_variable.h"
#include "bar.h"

namespace bar
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
