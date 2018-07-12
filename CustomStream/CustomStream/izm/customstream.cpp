/*!
  @file  customsteam.cpp
*/
#include <iostream>
#include "customstream.h"

namespace izm
{

/*!
  @brief  コンストラクタ
*/
CustomStream::CustomStream()
    : m_ofs("default.log")
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
    std::cout << str;
    m_ofs << str;
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
  @brief  改行コードを出力する
*/
CustomStream& CustomStream::eol()
{
    std::cout << std::endl;
    m_ofs << std::endl;
    return *this;
}

/*!
  @brief  バッファをフラッシュする
*/
void CustomStream::flush()
{
    m_ofs.flush();
}

} // namespace izm
