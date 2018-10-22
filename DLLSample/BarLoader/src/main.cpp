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
            // �Ăяo���K��icdecl�j�֐��̃C���|�[�g
            auto&& cdeclMethod = reinterpret_cast<int (__cdecl *)( int, int )>( ::GetProcAddress( handler, "cdeclMethod" ) );

            // �Ăяo���K��istdcall�j�֐��̃C���|�[�g
            // `> dumpbin /exports Bar.dll` �Ŋm�F�����G�N�X�|�[�g�����w��
            auto&& stdcallMethod = reinterpret_cast<int( WINAPI * )( int, int )>( ::GetProcAddress( handler, "_stdcallMethod@8" ) );

            // ���W���[����`�t�@�C���ɂ��G�N�X�|�[�g�֐��̃C���|�[�g
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
