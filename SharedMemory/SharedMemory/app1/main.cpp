#include <iostream>
#include "sharedmemory.h"

int main()
{
    auto&& shm = shm::SharedMemory();
    std::cout << "name: " << shm.name() << std::endl;
    std::cout << "size: " << shm.size() << std::endl;

    int value1 = 123;
    int value2 = 456;
    shm.write( 0x00, &value1, sizeof( value1 ) );
    shm.write( 0x04, &value2, sizeof( value2 ) );

    int rvalue1 = 0;
    int rvalue2 = 0;
    shm.read( 0x00, &rvalue1, sizeof( rvalue1 ) );
    shm.read( 0x04, &rvalue2, sizeof( rvalue2 ) );

    std::cout << "rvalue1: " << rvalue1 << std::endl;
    std::cout << "rvalue2: " << rvalue2 << std::endl;

    return 0;
}
