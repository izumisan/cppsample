#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <memory>

namespace foo
{

class SingletonClass
{
public:
    static const std::unique_ptr<SingletonClass>& instance();

private:
    SingletonClass() = default;
    SingletonClass( const SingletonClass& ) = delete;
    SingletonClass( SingletonClass&& ) = delete;
public:
    virtual ~SingletonClass() = default;
private:
    SingletonClass& operator=( const SingletonClass& ) = delete;
    SingletonClass& operator=( SingletonClass&& ) = delete;

public:
    int count() const { return m_count; }
    void up() { ++m_count; }
    void down() { --m_count; }

private:
    int m_count = 0;
};

} // namespace foo

#endif // SINGLETONCLASS_H
