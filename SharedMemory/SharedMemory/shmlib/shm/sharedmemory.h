/*!
  @file sharedmemory.h
*/
#ifndef SHM_SHAREDMEMORY_H
#define SHM_SHAREDMEMORY_H

#include <string>

namespace shm
{

class SharedMemory
{
public:
    SharedMemory();
    virtual ~SharedMemory();

public:
    const std::string& name() const { return m_name; }
    unsigned long size() const { return m_size; }
public:
    bool is_open() const;
    bool open( const std::string& name, const unsigned long size );
    void close();

    void write( const unsigned int addr, const void* data, const int size );
    void read( const unsigned int addr, void* data, const int size ) const;
private:
    void open();

private:
    std::string m_name = "";
    unsigned long m_size = 0uL;
    void* m_handle = nullptr;
//    const void* m_view = nullptr;
};

} // namespace shm

#endif // SHM_SHAREDMEMORY_H
