#include <iostream>

// �񐄏��ȃN���X
class [[deprecated("FooClass is deprecated. Please use new-FooClass.")]] FooClass{};

// �񐄏��ȗ񋓌^
enum class[[deprecated( "FooEnum is deprecated. Please use new FooEnum." )]] FooEnum { Foo, Bar, Baz };

// �񐄏��Ȋ֐�
[[deprecated("fooMethod() is deprecated. Please use new-fooMethod.")]]
void fooMethod(){}

// �񐄏��ȕϐ�
[[deprecated("foo is deprecated. Please use new-foo.")]]
int foo = 0;

int main()
{
    FooClass foo_object {};

    FooEnum foo_enum = FooEnum::Foo;

    fooMethod();

    foo = 168;

    return 0;
}
