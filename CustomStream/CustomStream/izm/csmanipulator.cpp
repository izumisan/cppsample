/*!
  @file  csmanipulator.cpp
*/
#include <ctime>
#include <cstdarg>
#include <cstring>
#include "csmanipulator.h"

namespace izm
{

/*!
  @brief  CustomStream�ɉ��s�R�[�h���o�͂���}�j�s�����[�^
*/
CustomStream & endl( CustomStream& cs )
{
    cs.eol();
    cs.flush();
    return cs;
}

/*!
  @brief  CustomStream�Ƀ^�C���X�^���v���o�͂���}�j�s�����[�^�[
*/
CustomStream& timestamp( CustomStream& cs )
{
    time_t t = time( nullptr );
    const tm* now = localtime( &t );
    char buff[] = "YYYY-MM-DD hh:mm:ss";
    strftime( buff, sizeof( buff ), "%Y-%m-%d %H:%M:%S", now );
    return cs << buff;
}

// callerInfo
//------------------------------------------------------------------------------
/*!
  @brief  �R���X�g���N�^
*/
callerInfo::callerInfo( const std::string& fileName,
                        const long lineNumber,
                        const std::string& funcName,
                        bool excludeDirectoryName )
    : m_fileName( fileName )
    , m_lineNumber( lineNumber )
    , m_funcName( funcName )
{
    if ( excludeDirectoryName )
    {
        // �t�@�C�����𒊏o����
        const auto&& lastDelimiter = m_fileName.find_last_of( "/\\" );
        if ( lastDelimiter != std::string::npos )
        {
            const auto&& startIndex = lastDelimiter + 1;
            if ( startIndex < m_fileName.size() )
            {
                m_fileName = m_fileName.substr( startIndex );
            }
        }
    }
}

/*!
  @brief  �֐��Ăяo�����Z�q
*/
CustomStream& callerInfo::operator()( CustomStream& cs )
{
    return cs << printf( "%s(%d) %s:", m_fileName.c_str(), m_lineNumber, m_funcName.c_str() );
}

/*!
  @brief  CustomStream�N���X�ɑ΂���}�����Z�q�̃I�[�o�[���[�h
*/
CustomStream& operator << ( CustomStream& cs, callerInfo manip )
{
    // callerInfo::operator()����`����Ă���̂ŁA
    // �ϐ�manip�͊֐��I�u�W�F�N�g
    return manip( cs );
}

// printf
//______________________________________________________________________________
/*!
  @brief  �R���X�g���N�^
*/
printf::printf( const char* format, ... )
    : m_buff()
{
    char buff[1024] = {};
    memset( buff, 0x00, sizeof( buff ) );

    va_list valist;
    va_start( valist, format );
    vsnprintf( buff, sizeof( buff ), format, valist );
    va_end( valist );

    m_buff = std::string( buff );
}

/*!
  @brief  printf::operator()
*/
CustomStream& printf::operator ()( CustomStream& cs )
{
    return cs << m_buff;
}

/*!
  @brief  printf�N���X�������ɂƂ�CustomStream�N���X�̑}�����Z�q
*/
CustomStream& operator << ( CustomStream& cs, printf manip )
{
    return manip( cs );
}

// once
//______________________________________________________________________________
/*!
  @brief  �R���X�g���N�^
*/
once::once( const int onceEveryX )
    : m_value( onceEveryX )
{
}

/*!
  @brief  once::operator()
*/
CustomStream& once::operator()( CustomStream& cs )
{
    cs.setOnceEvery( m_value );
    return cs;
}

/*!
  @brief  once�}�j�s�����[�^�[�p�}�����Z�q
*/
CustomStream& operator << ( CustomStream& cs, once manip )
{
    return manip( cs );
}

} // namespace izm
