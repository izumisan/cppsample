#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>

int main()
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    std::cout << "start..." << std::endl;

    int* buff = new int[8];
    *( buff + 0 ) = 1;
    *( buff + 1 ) = 0xFF;
    *( buff + 2 ) = 0xFFFFFFFF;

    // deleteせずにメモリーリークさせる
    //delete [] buff;

    std::cout << "end." << std::endl;
    return 0;
/*
[出力]ウィンドウにメモリリークしていることが出力される

Detected memory leaks!
Dumping objects ->
{153} normal block at 0x00ABA420, 32 bytes long.
 Data: <                > 01 00 00 00 FF 00 00 00 FF FF FF FF CD CD CD CD
Object dump complete.
*/
}
