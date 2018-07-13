/*!
  @file  csmanipulator.h
*/
#ifndef IZM_CSMANIPULATOR_H
#define IZM_CSMANIPULATOR_H

#include <string>
#include "customstream.h"

namespace izm
{

// 引数を取らないマニピュレーター
//______________________________________________________________________________
/*!
  @fn  endlマニピュレーター
*/
CustomStream& endl( CustomStream& cs );

/*!
  @fn  timestampマニピュレーター
*/
CustomStream& timestamp( CustomStream& cs );

// 引数を取るマニピュレーター
//______________________________________________________________________________
/*!
  @class  callerInfoマニピュレーター
*/
class callerInfo
{
    // CustomStreamクラスの挿入演算子のオーバーロード（グローバル関数として定義）
    // (callerInfo::operator()（privateメソッド）にアクセスするので、friend関数として定義)
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

// cs << izm::callerInfo( __FILE__, __LINE__, __func__ ) を
// cs << CALLERINFO と省略するためのマクロ定義
#define CALLERINFO ( izm::callerInfo( __FILE__, __LINE__, __func__, true ) )
#define CALLERINFO_L ( izm::callerInfo( __FILE__, __LINE__,__func__, false ) )

/*!
  @class printfマニピュレーター
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
