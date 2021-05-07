#include "singletonclass.h"

namespace foo
{

const std::unique_ptr<SingletonClass>& SingletonClass::instance()
{
    // privateコンストラクタのため、make_uniqueでは生成できない
    //static auto&& instance = std::make_unique<SingletonClass>();

    // 同一クラス内なので、newは可能
    //static std::unique_ptr<SingletonClass> instance( new SingletonClass() );

    // make_uniqueで生成できるようにするため、ローカルのサブクラス（構造体）を定義する
    // サブクラスを定義する関係上、シングルトンクラスはfinal指定できない
    struct ctor_permission : public SingletonClass
    {
        using SingletonClass::SingletonClass;
    };
    static std::unique_ptr<SingletonClass>&& instance = std::make_unique<ctor_permission>();
    return instance;
}

} // namespace singleton
