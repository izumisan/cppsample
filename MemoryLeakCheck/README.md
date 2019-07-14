# MemoryLeakCheck

メモリーリークの検出

# overview

- MemoryLeakCheck
- MemoryLeakCheck2

# 覚書

サンプルコード

```cpp
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
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
```

出力ウィンドウ

```
Detected memory leaks!
Dumping objects ->
{153} normal block at 0x00ABA420, 32 bytes long.
 Data: <                > 01 00 00 00 FF 00 00 00 FF FF FF FF CD CD CD CD 
Object dump complete.
```

出力レポートで、メモリーが確保された箇所を表示させる

```cpp
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
// レポートにメモリー確保の箇所を表示させる
#define malloc(X) _malloca_dbg(X, _NORMAL_BLOCK, __FILE__, __LINE__)
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
```

# 参考

- [CRT ライブラリを使用したメモリ リークの検出 - Microsoft Docs](https://docs.microsoft.com/ja-jp/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019#interpret-the-memory-leak-report)
- https://urashita.com/archives/1271
