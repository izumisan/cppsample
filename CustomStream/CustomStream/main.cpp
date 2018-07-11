#include "customstream.h"

int main()
{
    auto&& cs = izm::CustomStream();

    cs << "Hello World" << izm::endl;
    cs << "Hello World" << izm::endl;

    return 0;
}
