#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
// レポートにメモリー確保の箇所を表示させる
#define malloc(X) _malloca_dbg(X, _NORMAL_BLOCK, __FILE__, __LINE__)
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

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
}
