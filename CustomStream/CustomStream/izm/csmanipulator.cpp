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
    return cs << m_fileName << "(" << m_lineNumber << ")" << ":" << m_funcName << ":";
}

} // namespace izm
