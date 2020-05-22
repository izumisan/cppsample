#include <iostream>
#include <string>

namespace foo::bar
{
class Foo
{
public:
    Foo() = default;
    virtual ~Foo() = default;
public:
    std::string hello() const { return "Hello World."; }
};
} // namespace foo::bar

int main()
{
    std::cout << "start..." << std::endl;

#if defined(FOO_DEFINITION)
    std::cout << "FOO_DEFINITION is defined." << std::endl;
#else
    std::cout << "FOO_DEFINITION is NOT defined." << std::endl;
#endif

    auto&& foo = foo::bar::Foo();
    std::cout << "foo: " << foo.hello() << std::endl;

    std::cout << "end." << std::endl;
    return 0;
}
