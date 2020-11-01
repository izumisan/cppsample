#include <iostream>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <Psapi.h>

int main()
{
    // コンピュータ名
    // - GetComputerName()
    {
        char buff[256] = {};
        int size = sizeof(buff);
        ::memset( buff, 0x00, size );

        ::GetComputerName( buff, reinterpret_cast<LPDWORD>( &size ) );

        std::cout << "Computer: " << buff << std::endl;
    }
    // ユーザ名
    // - GetUserName()
    {
        char buff[256] = {};
        int size = sizeof(buff);
        ::memset( buff, 0x00, size );

//        ::GetUserName( buff, reinterpret_cast<LPDWORD>( &size ) );

        std::cout << "User: " << buff << std::endl;
    }
    // プロセスID
    // - GetCurrentProcessId()
    // プロセス名
    // - OpenProcess()でプロセスIDに対応するプロセスハンドラを取得
    // - GetModuleBaseName()でプロセスハンドラからプロセス名を取得
    {
        DWORD pid = ::GetCurrentProcessId();

        char processName[256] = {};
        ::memset( processName, 0x00, sizeof(processName) );
        HANDLE handle = ::OpenProcess( PROCESS_ALL_ACCESS, false, pid );
        if ( handle )
        {
            ::GetModuleBaseName( handle, nullptr, processName, sizeof(processName) );
        }

        std::cout << "ProcessId: " << pid << std::endl;
        std::cout << "ProcessName: " << processName << std::endl;
    }
    // 起動チェック
    // - EnumProcesses()でPID一覧を取得してチェックする
    {
        auto tolower = [](const std::string& str) -> std::string
        {
            auto ret = str;
            std::transform( ret.begin(), ret.end(), ret.begin(), ::tolower );
            return ret;
        };
        auto processCheck = [&tolower](const std::string& targetProcessName ) -> bool
        {
            bool ret = false;
            DWORD pids[10000] = {};
            DWORD count = 0;
            ::EnumProcesses( pids, sizeof(pids), &count );

            for ( int i = 0; i < count; ++i )
            {
                HANDLE handle = ::OpenProcess( PROCESS_ALL_ACCESS, false, pids[i] );
                char name[256] = {};
                ::memset( name, 0x00, sizeof(name) );
                ::GetModuleBaseName( handle, nullptr, name, sizeof(name) );

                if ( tolower( name ) == tolower( targetProcessName ) )
                {
                    ret = true;
                    break;
                }
            }
            return ret;
        };

        std::cout << "ProcessInfo.exe?: " << processCheck( "ProcessInfo.exe" ) << std::endl;
        std::cout << "qtcreator.exe?: " << processCheck( "qtcreator.exe" ) << std::endl;
        std::cout << "foo.exe?: " << processCheck( "foo.exe" ) << std::endl;
    }
    return 0;
}
