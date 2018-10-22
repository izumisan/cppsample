#ifndef BARLIBRARY_H
#define BARLIBRARY_H

#if defined(BARLIBRARY_EXPORTS)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace bar
{
namespace BarLibrary
{

extern "C"
{
    // cdecl関数
    // __declspec(dllexport)でエクスポート
    DLLEXPORT int __cdecl cdeclMethod( int x, int y );

    // stdcall関数
    // __declspec(dllexport)でエクスポート
    DLLEXPORT int __stdcall stdcallMethod( int x, int y );

    // cdecl関数（VisualStudioのデフォルト）
    // モジュール定義ファイルでエクスポート
    int defExportMethod( int x, int y );
}

} // namespace BarLibrary
} // namespace bar

#endif // BARLIBRARY_H
