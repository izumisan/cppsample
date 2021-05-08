#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template <class T>
class Singleton
{
public:
    static const std::unique_ptr<T>& instance()
    {
        static std::unique_ptr<T> singleton( new T() );
        return singleton;
    }
protected:
    Singleton() = default;
    Singleton( const Singleton<T>& ) = delete;
    Singleton( Singleton<T>&& ) = delete;
public:
    virtual ~Singleton() noexcept = default;

private:
    Singleton<T>& operator=( const Singleton<T>& ) = delete;
    Singleton<T>& operator=( Singleton<T>&& ) = delete;
};

#endif // SINGLETON_H
