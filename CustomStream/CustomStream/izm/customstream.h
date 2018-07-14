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
  @class  標準出力とファイルの両方に出力する自作ストリーム
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

    // CustomStreamを引数にとりCustromStreamを返す関数を受け取る
    // 挿入演算子のオーバーロード（クラスメソッドとして定義）
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

// マニピュレータ
#include "csmanipulator.h"

#endif // IZM_CUSTOMSTREAM_H

