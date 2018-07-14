/*!
  @file  customsteam.cpp
*/
#include <iostream>
#include <algorithm>
#include "customstream.h"

namespace izm
{

/*!
  @brief  コンストラクタ
*/
CustomStream::CustomStream()
    : m_ofs( "default.log" )
    , m_eolCount( 0uLL )
    , m_onceEveryX( 1 )
    , m_baseCount( 0uLL )
{
}

/*!
  @brief  デストラクタ
*/
CustomStream::~CustomStream()
{
}

/*!
  @brief  挿入演算子
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
  @brief  マニピュレータを受け取る挿入演算子
  @param  [in]  manip  CustomStreamを引数にとり、CustomStreamを返す関数ポインタ
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
  @brief  改行コードを出力する
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
  @brief  バッファをフラッシュする
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
