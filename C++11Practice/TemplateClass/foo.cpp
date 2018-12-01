#include "foo.h"

// 明示的インスタンス化（explicit instantiation）
// よく使う型（Foo<int>, Foo<double>）を予めインスタンス化
template class Foo<int>;
template class Foo<double>;
