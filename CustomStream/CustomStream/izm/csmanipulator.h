/*!
  @file  csmanipulator.h
*/
#ifndef IZM_CSMANIPULATOR_H
#define IZM_CSMANIPULATOR_H

#include <string>
#include "customstream.h"

namespace izm
{

// ���������Ȃ��}�j�s�����[�^
//______________________________________________________________________________

CustomStream& endl( CustomStream& cs );


// ���������}�j�s�����[�^
//______________________________________________________________________________

class callerInfo
{
    // CustomStream�N���X�̑}�����Z�q�̃I�[�o�[���[�h�i�O���[�o���֐��Ƃ��Ē�`�j
    // (callerInfo::operator()�iprivate���\�b�h�j�ɃA�N�Z�X����̂ŁAfriend�֐��Ƃ��Ē�`)
    friend CustomStream& operator << ( CustomStream& cs, callerInfo caller );

public:
    callerInfo( const std::string& fname, const long line, bool excludeDirectoryName = false );

private:
    CustomStream& operator ()( CustomStream& cs );

private:
    std::string m_fname;
    long m_line;
};

// cs << izm::callerInfo( __FILE__, __LINE__ ) ��
// cs << CALLERINFO �Əȗ����邽�߂̃}�N����`
#define CALLERINFO ( izm::callerInfo( __FILE__, __LINE__ ) )
#define CALLERINFO_S ( izm::callerInfo( __FILE__, __LINE__, true ) )

} // namespace izm

#endif // IZM_CSMANIPULATOR_H
