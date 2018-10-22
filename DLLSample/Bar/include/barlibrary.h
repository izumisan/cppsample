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
    // cdecl�֐�
    // __declspec(dllexport)�ŃG�N�X�|�[�g
    DLLEXPORT int __cdecl cdeclMethod( int x, int y );

    // stdcall�֐�
    // __declspec(dllexport)�ŃG�N�X�|�[�g
    DLLEXPORT int __stdcall stdcallMethod( int x, int y );

    // cdecl�֐��iVisualStudio�̃f�t�H���g�j
    // ���W���[����`�t�@�C���ŃG�N�X�|�[�g
    int defExportMethod( int x, int y );
}

} // namespace BarLibrary
} // namespace bar

#endif // BARLIBRARY_H
