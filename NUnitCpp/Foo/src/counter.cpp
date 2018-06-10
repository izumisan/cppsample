/*!
  @file  counter.cpp
*/
#include "counter.h"

namespace foo
{

Counter::Counter()
    : m_count(0)
{
}

Counter::Counter( const double count )
    : m_count( count )
{
}

Counter::~Counter()
{
}

double Counter::count() const
{
    return m_count;
}

void Counter::setCount( const double value )
{
    m_count = value;
}

Counter& Counter::add( const double value )
{
    m_count += value;
    return *this;
}

} // namespace foo
