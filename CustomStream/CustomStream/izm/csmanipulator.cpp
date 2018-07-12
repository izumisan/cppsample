/*!
  @file  csmanipulator.cpp
*/
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
  @brief  CustomStream�N���X�ɑ΂���}�����Z�q�̃I�[�o�[���[�h
*/
CustomStream& operator << ( CustomStream& cs, callerInfo caller )
{
    // callerInfo::operator()����`����Ă���̂ŁA
    // �ϐ�caller�͊֐��I�u�W�F�N�g
    return caller( cs );
}


// callerInfo�N���X
//------------------------------------------------------------------------------
/*!
  @brief  �R���X�g���N�^
*/
callerInfo::callerInfo( const std::string& fname, const long line, bool excludeDirectoryName )
    : m_fname( fname )
    , m_line( line )
{
    if ( excludeDirectoryName )
    {
        // �t�@�C�����𒊏o����
        const auto&& lastDelimiter = m_fname.find_last_of( "/\\" );
        if ( lastDelimiter != std::string::npos )
        {
            const auto&& lastIndex = m_fname.size() - 1;
            if ( lastDelimiter < lastIndex )
            {
                m_fname = m_fname.substr( lastDelimiter + 1 );
            }
        }
    }
}

/*!
  @brief  �֐��Ăяo�����Z�q
*/
CustomStream& callerInfo::operator()( CustomStream& cs )
{
    return cs << m_fname << "(" << m_line << ")";
}

} // namespace izm
