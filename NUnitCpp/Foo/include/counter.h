/*!
  @file  counter.h
*/
#ifndef FOO_COUNTER_H
#define FOO_COUNTER_H

namespace foo
{

class Counter
{
public:
    Counter();
    Counter( const double count );
    virtual ~Counter();
public:
    double count() const;
    void setCount( const double value );
    Counter& add( const double value );

private:
    double m_count;
};

} // namespace foo

#endif // FOO_COUNTER_H
