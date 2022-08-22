#include "fooadapter.h"

namespace adapter
{

// �R���X�g���N�^
FooAdapter::FooAdapter()
    : m_foo( new foo::Foo() )
{
}

// �f�X�g���N�^
// - [cli] gcnew���delete����X�R�[�v�𔲂����Ƃ��H�ɌĂ΂��
// - [c#] Dispose()�ŌĂ΂��
FooAdapter::~FooAdapter()
{
    this->!FooAdapter();
}

// �t�@�C�i���C�U
// - �K�x�[�W�R���N�V�������ɌĂ΂��
//   - C#�̏ꍇ�A�X�R�[�v�𔲂������ɃK�x�R���ŉ�������̂ŁA�Ă΂��̂͂��̃t�@�C�i���C�U
//   - CLI�̏ꍇ�A�X�R�[�v�𔲂����ۂ̓f�X�g���N�^���Ă΂��i���Ԃ�j
// - C#�̃f�X�g���N�^�ɑ�������
// - �f�X�g���N�^���Ă΂��ƃt�@�C�i���C�U�͌Ă΂�Ȃ��Ȃ�
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
