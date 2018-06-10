/*!
  @file  main.cpp
*/
#include <iostream>
#include "counter.h"

int main()
{
    foo::Counter counter( 1.0 );
    
    std::cout << counter.count() << std::endl;

    counter.add( 2.0 ).add( 3.0 );

    std::cout << counter.count() << std::endl;

    return 0;
}
