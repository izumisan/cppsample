/*!
  @file  csmanipulator.h
*/
#ifndef IZM_CSMANIPULATOR_H
#define IZM_CSMANIPULATOR_H

#include <string>
#include "customstream.h"

namespace izm
{

// 引数を取らないマニピュレータ
//______________________________________________________________________________

CustomStream& endl( CustomStream& cs );


// 引数を取るマニピュレータ
//______________________________________________________________________________

class callerInfo
{
    // CustomStreamクラスの挿入演算子のオーバーロード（グローバル関数として定義）
    // (callerInfo::operator()（privateメソッド）にアクセスするので、friend関数として定義)
    friend CustomStream& operator << ( CustomStream& cs, callerInfo caller );

public:
    callerInfo( const std::string& fname, const long line, bool excludeDirectoryName = false );

private:
    CustomStream& operator ()( CustomStream& cs );

private:
    std::string m_fname;
    long m_line;
};

// cs << izm::callerInfo( __FILE__, __LINE__ ) を
// cs << CALLERINFO と省略するためのマクロ定義
#define CALLERINFO ( izm::callerInfo( __FILE__, __LINE__ ) )
#define CALLERINFO_S ( izm::callerInfo( __FILE__, __LINE__, true ) )

} // namespace izm

#endif // IZM_CSMANIPULATOR_H
