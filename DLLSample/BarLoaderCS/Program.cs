using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace BarLoaderCS
{
    class Program
    {
        // DLLのエクスポート関数は、DllImport属性でインポートする
        // C#側の関数宣言は、static externとする
        // 
        // Bar.dllは、ビルド後イベントでコピーしてきている
        // （ビルド順序は、Barプロジェクトより後に設定している）

        // 呼び出し規約（cdecl）関数のインポート
        [DllImport("Bar.dll", EntryPoint = "cdeclMethod", CallingConvention = CallingConvention.Cdecl)]
        static extern int cdeclMethod( int x, int y );

        // 呼び出し規約（stdcall）関数のインポート
        [DllImport("Bar.dll", EntryPoint = "stdcallMethod", CallingConvention = CallingConvention.StdCall)]
        static extern int stdcallMethod( int x, int y );

        // モジュール定義ファイルによるエクスポート関数のインポート
        [DllImport("Bar.dll", EntryPoint = "defExportMethod", CallingConvention = CallingConvention.Cdecl)]
        static extern int defExportMethod( int x, int y );

        static void Main( string[] args )
        {
            Console.WriteLine( $"1. cdeclMethod( 1, 2 ): { cdeclMethod( 1, 2 ) }" );
            Console.WriteLine( $"2. stdcallMethod( 3, 4 ): { stdcallMethod( 3, 4 ) }" );
            Console.WriteLine( $"3. defExportMethod( 5, 6 ): { defExportMethod( 5, 6 ) }" );


            Console.WriteLine( "Please any key." );
            Console.ReadLine();
        }
    }
}
