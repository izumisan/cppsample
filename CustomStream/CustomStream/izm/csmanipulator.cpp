/*!
  @file  csmanipulator.cpp
*/
#include "csmanipulator.h"

namespace izm
{

/*!
  @brief  CustomStreamに改行コードを出力するマニピュレータ
*/
CustomStream & endl( CustomStream& cs )
{
    cs.eol();
    cs.flush();
    return cs;
}

/*!
  @brief  CustomStreamクラスに対する挿入演算子のオーバーロード
*/
CustomStream& operator << ( CustomStream& cs, callerInfo caller )
{
    // callerInfo::operator()が定義されているので、
    // 変数callerは関数オブジェクト
    return caller( cs );
}


// callerInfoクラス
//------------------------------------------------------------------------------
/*!
  @brief  コンストラクタ
*/
callerInfo::callerInfo( const std::string& fname, const long line )
    : m_fname( fname )
    , m_line( line )
{
}

/*!
  @brief  関数呼び出し演算子
*/
CustomStream& callerInfo::operator()( CustomStream& cs )
{
    return cs << m_fname << "(" << m_line << ")";
}

} // namespace izm
