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

} // namespace izm
