/*!
  @file  csmanipulator.h
*/
#ifndef IZM_CSMANIPULATOR_H
#define IZM_CSMANIPULATOR_H

#include <string>
#include "customstream.h"

namespace izm
{

// ���������Ȃ��}�j�s�����[�^�[
//______________________________________________________________________________
/*!
  @fn  endl�}�j�s�����[�^�[
*/
CustomStream& endl( CustomStream& cs );

/*!
  @fn  timestamp�}�j�s�����[�^�[
*/
CustomStream& timestamp( CustomStream& cs );

// ���������}�j�s�����[�^�[
//______________________________________________________________________________
/*!
  @class  callerInfo�}�j�s�����[�^�[
*/
class callerInfo
{
    // CustomStream�N���X�̑}�����Z�q�̃I�[�o�[���[�h�i�O���[�o���֐��Ƃ��Ē�`�j
    // (callerInfo::operator()�iprivate���\�b�h�j�ɃA�N�Z�X����̂ŁAfriend�֐��Ƃ��Ē�`)
    friend CustomStream& operator << ( CustomStream& cs, callerInfo manip );

public:
    callerInfo( const std::string& fileName,
                const long lineNumber,
                const std::string& funcName,
                bool excludeDirectoryName = true );

private:
    CustomStream& operator ()( CustomStream& cs );

private:
    std::string m_fileName;
    long m_lineNumber;
    std::string m_funcName;
};

// cs << izm::callerInfo( __FILE__, __LINE__, __func__ ) ��
// cs << CALLERINFO �Əȗ����邽�߂̃}�N����`
#define CALLERINFO ( izm::callerInfo( __FILE__, __LINE__, __func__, true ) )
#define CALLERINFO_L ( izm::callerInfo( __FILE__, __LINE__,__func__, false ) )

/*!
  @class printf�}�j�s�����[�^�[
*/
class printf
{
    friend CustomStream& operator << ( CustomStream& cs, printf manip );

public:
    printf( const char* format, ... );
private:
    CustomStream& operator ()( CustomStream& cs );
private:
    std::string m_buff;
};

} // namespace izm

#endif // IZM_CSMANIPULATOR_H
