/*!
  @file sharedmemory.cpp
*/
#include <cassert>
#include <cstring>
#include <windows.h>
#include "sharedmemory.h"

namespace shm
{

SharedMemory::SharedMemory()
{
    open( "shm.default", 1024uL );
}

SharedMemory::~SharedMemory()
{
    close();
}

bool SharedMemory::is_open() const
{
    return ( m_handle != nullptr );
}

bool SharedMemory::open( const std::string& name, const unsigned long size )
{
    bool success = false;

    close();

    m_handle = ::CreateFileMappingA(
                   INVALID_HANDLE_VALUE,
                   nullptr,
                   PAGE_READWRITE,
                   0,
                   size,
                   name.c_str()
               );

    if ( m_handle != nullptr )
    {
        m_name = name;
        m_size = size;
        success = true;
    }
    return success;
}

void SharedMemory::close()
{
    if ( is_open() )
    {
        ::CloseHandle( m_handle );

        m_name = "";
        m_size = 0uL;
        m_handle = nullptr;
    }
}

void SharedMemory::write( const unsigned int addr, const void* data, const int size )
{
    assert( m_handle != nullptr );

    void* view = ::MapViewOfFile(
                     m_handle,
                     FILE_MAP_WRITE,
                     0uL,
                     0uL,
                     0
                 );

    if ( view != nullptr )
    {
        ::memcpy( (char*)view + addr, data, static_cast<size_t>( size ) );

        ::UnmapViewOfFile( view );
    }
}

void SharedMemory::read( const unsigned int addr, void* data, const int size ) const
{
    assert( m_handle != nullptr );

    void* view = ::MapViewOfFile(
                     m_handle,
                     FILE_MAP_READ,
                     0uL,
                     0uL,
                     0
                 );

    if ( view != nullptr )
    {
        ::memcpy( data, (char*)view + addr, static_cast<size_t>( size ) );

        ::UnmapViewOfFile( view );
    }
}

} // namespace shm
