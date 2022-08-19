#include "fooadapter.h"

namespace adapter
{

// コンストラクタ
FooAdapter::FooAdapter()
    : m_foo( new foo::Foo() )
{
}

// デストラクタ
// - [cli] gcnew後のdelete時やスコープを抜けたとき？に呼ばれる
// - [c#] Dispose()で呼ばれる
FooAdapter::~FooAdapter()
{
    this->!FooAdapter();
}

// ファイナライザ
// - ガベージコレクション時に呼ばれる
//   - C#の場合、スコープを抜けた時にガベコレで回収されるので、呼ばれるのはこのファイナライザ
//   - CLIの場合、スコープを抜けた際はデストラクタが呼ばれる（たぶん）
// - C#のデストラクタに相当する
// - デストラクタが呼ばれるとファイナライザは呼ばれなくなる
FooAdapter::!FooAdapter()
{
    if ( m_foo != nullptr )
    {
        delete m_foo;
        m_foo = nullptr;
    }
}

int FooAdapter::Sleep( const int seconds )
{
    return m_foo->sleep( seconds );
}

int FooAdapter::Sleep2( const int seconds )
{
    return m_foo->sleep2( seconds );
}

} // namespace adapter
