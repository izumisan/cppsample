/*!
  @file  customstream.h
*/
#ifndef IZM_CUSTOMSTREAM_H
#define IZM_CUSTOMSTREAM_H

#include <string>
#include <fstream>
#include <sstream>

namespace izm
{

/*!
  @class  �W���o�͂ƃt�@�C���̗����ɏo�͂��鎩��X�g���[��
*/
class CustomStream
{
public:
    CustomStream();
    virtual ~CustomStream();

public:
    template<class Tvalue> CustomStream& operator << ( const Tvalue value )
    {
        std::stringstream ss;
        ss << value;
        return this->operator<<( ss.str() );
    }
    
    CustomStream& operator << ( const std::string& str );

    // CustomStream�������ɂƂ�CustromStream��Ԃ��֐����󂯎��
    // �}�����Z�q�̃I�[�o�[���[�h�i�N���X���\�b�h�Ƃ��Ē�`�j
    CustomStream& operator << ( CustomStream& ( *manip )( CustomStream& ) );

public:
    void setOnceEvery( const int x );

public:
    CustomStream& eol();
    void flush();

private:
    bool isTiming() const;

private:
    std::ofstream m_ofs;
    unsigned long long m_eolCount;
    int m_onceEveryX;
    unsigned long long m_baseCount;
};

} // namespace izm

// �}�j�s�����[�^
#include "csmanipulator.h"

#endif // IZM_CUSTOMSTREAM_H

