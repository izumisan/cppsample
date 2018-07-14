/*!
  @file  customsteam.cpp
*/
#include <iostream>
#include <algorithm>
#include "customstream.h"

namespace izm
{

/*!
  @brief  �R���X�g���N�^
*/
CustomStream::CustomStream()
    : m_ofs( "default.log" )
    , m_eolCount( 0uLL )
    , m_onceEveryX( 1 )
    , m_baseCount( 0uLL )
{
}

/*!
  @brief  �f�X�g���N�^
*/
CustomStream::~CustomStream()
{
}

/*!
  @brief  �}�����Z�q
*/
CustomStream& CustomStream::operator << ( const std::string& str )
{
    if ( isTiming() )
    {
        std::cout << str;
        m_ofs << str;
    }
    return *this;
}

/*!
  @brief  �}�j�s�����[�^���󂯎��}�����Z�q
  @param  [in]  manip  CustomStream�������ɂƂ�ACustomStream��Ԃ��֐��|�C���^
*/
CustomStream& CustomStream::operator << ( CustomStream& ( *manip )( CustomStream& ) )
{
    return ( *manip )( *this );
}

/*!
*/
void CustomStream::setOnceEvery( const int x )
{
    m_onceEveryX = std::max( 1, x );
    m_baseCount = m_eolCount;
}

/*!
  @brief  ���s�R�[�h���o�͂���
*/
CustomStream& CustomStream::eol()
{
    if ( isTiming() )
    {
        std::cout << std::endl;
        m_ofs << std::endl;
    }
    ++m_eolCount;
    return *this;
}

/*!
  @brief  �o�b�t�@���t���b�V������
*/
void CustomStream::flush()
{
    m_ofs.flush();
}

/*!
*/
bool CustomStream::isTiming() const
{
    return ( ( m_eolCount - m_baseCount ) % m_onceEveryX == 0 );
}

} // namespace izm
