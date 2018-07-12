/*!
  @file  customsteam.cpp
*/
#include <iostream>
#include "customstream.h"

namespace izm
{

/*!
  @brief  �R���X�g���N�^
*/
CustomStream::CustomStream()
    : m_ofs("default.log")
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
    std::cout << str;
    m_ofs << str;
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
  @brief  ���s�R�[�h���o�͂���
*/
CustomStream& CustomStream::eol()
{
    std::cout << std::endl;
    m_ofs << std::endl;
    return *this;
}

/*!
  @brief  �o�b�t�@���t���b�V������
*/
void CustomStream::flush()
{
    m_ofs.flush();
}

} // namespace izm
