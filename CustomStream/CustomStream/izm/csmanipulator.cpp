/*!
  @file  csmanipulator.cpp
*/
#include <ctime>
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
  @brief  CustomStreamにタイムスタンプを出力するマニピュレーター
*/
CustomStream& timestamp( CustomStream& cs )
{
    time_t t = time( nullptr );
    const tm* now = localtime( &t );
    char buff[] = "YYYY-MM-DD hh:mm:ss";
    strftime( buff, sizeof( buff ), "%Y-%m-%d %H:%M:%S", now );
    return cs << buff;
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
        // ファイル名を抽出する
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
  @brief  関数呼び出し演算子
*/
CustomStream& callerInfo::operator()( CustomStream& cs )
{
    return cs << m_fileName << "(" << m_lineNumber << ")" << ":" << m_funcName << ":";
}

} // namespace izm
