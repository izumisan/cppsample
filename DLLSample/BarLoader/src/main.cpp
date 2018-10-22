#include <iostream>
#include <Windows.h>
#include "barlibrary.h"

int main()
{
    {
        std::cout << "[STATIC LOAD]" << std::endl;
        std::cout << "1. cdeclMethod( 1, 2 ): " << bar::BarLibrary::cdeclMethod( 1, 2 ) << std::endl;;
        std::cout << "2. stdcallMethod( 3, 4 ): " << bar::BarLibrary::stdcallMethod( 3, 4 ) << std::endl;
        std::cout << "3. defExportMethod( 5, 6 ): " << bar::BarLibrary::defExportMethod( 5, 6 ) << std::endl;
    }

    {
        std::cout << "[DYNAMIC LOAD]" << std::endl;

        HINSTANCE handler = ::LoadLibraryA( "Bar.dll" );

        if ( handler != nullptr )
        {
            // 呼び出し規約（cdecl）関数のインポート
            auto&& cdeclMethod = reinterpret_cast<int (__cdecl *)( int, int )>( ::GetProcAddress( handler, "cdeclMethod" ) );

            // 呼び出し規約（stdcall）関数のインポート
            // `> dumpbin /exports Bar.dll` で確認したエクスポート名を指定
            auto&& stdcallMethod = reinterpret_cast<int( WINAPI * )( int, int )>( ::GetProcAddress( handler, "_stdcallMethod@8" ) );

            // モジュール定義ファイルによるエクスポート関数のインポート
            auto&& defExportMethod = reinterpret_cast<int( __cdecl * )( int, int )>( ::GetProcAddress( handler, "defExportMethod" ) );

            if ( ( cdeclMethod != nullptr ) && ( stdcallMethod != nullptr ) && ( defExportMethod != nullptr ) )
            {
                
                std::cout << "1. cdeclMethod( 11, 22 ): " << cdeclMethod( 11, 22 ) << std::endl;;
                std::cout << "2. stdcallMethod( 33, 44 ): " << stdcallMethod( 33, 44 ) << std::endl;
                std::cout << "3. defExportMethod( 55, 66 ): " << defExportMethod( 55, 66 ) << std::endl;
            }
            else
            {
                std::cout << "Fail to load function." << std::endl;
            }

            ::FreeLibrary( handler );
        }
        else
        {
            std::cout << "Fail to load Library." << std::endl;
        }
    }

    return 0;
}
