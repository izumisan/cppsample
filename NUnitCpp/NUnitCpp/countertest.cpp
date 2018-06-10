/*!
  @file  countertest.cpp
*/
#using "nunit.framework.dll"

#include "counter.h"

using namespace NUnit::Framework;

namespace NUnitCpp
{

[TestFixture]
public ref class CounterTest
{
public:
    CounterTest()
    {
    }

    [SetUp]
    void setup()
    {
    }

    [TearDown]
    void teardown()
    {
    }

public:
    [Test]
    void setCountの確認()
    {
        foo::Counter counter( 0.0 );
        counter.setCount( 1.23 );

        Assert::AreEqual( 1.23, counter.count() );
    }

    [TestCase( 0.0, 1.0, 1.0 )]
    [TestCase( 1.1, 2.2, 3.3 )]
    [TestCase( -1.5, -0.5, -2.0 )]
    void addの確認( double v1, double v2, double expected )
    {
        foo::Counter counter;
        double actual = counter.add( v1 ).add( v2 ).count();

        Assert::That( actual, Is::EqualTo( expected )->Within( 0.000001 ) );
    }
};

} // namespace NUnitCpp
