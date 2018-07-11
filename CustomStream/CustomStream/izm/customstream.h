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
    標準出力とファイルの両方に出力する自作ストリーム
*/
class CustomStream
{
public:
    CustomStream();
    virtual ~CustomStream();

public:
    //CustomStream& operator << ( const int value );
    //CustomStream& operator << ( const double value );
    template<class Tvalue> CustomStream& operator << ( const Tvalue value )
    {
        std::stringstream ss;
        ss << value;
        return this->operator<<( ss.str() );
    }
    
    CustomStream& operator << ( const std::string& str );
    CustomStream& operator << ( CustomStream& ( *manip )( CustomStream& ) );

public:
    CustomStream& eol();
    void flush();

private:
    std::ofstream m_ofs;
};

// マニピュレータ
CustomStream& endl( CustomStream& cs );

} // namespace izm

#endif // IZM_CUSTOMSTREAM_H

