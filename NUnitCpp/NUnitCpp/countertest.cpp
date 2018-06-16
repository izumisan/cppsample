/*!
  @file  countertest.cpp
*/
#using "nunit.framework.dll"

#include "counter.h"

using namespace System;
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
    void Test属性の利用()
    {
        foo::Counter counter( 0.0 );
        counter.setCount( 1.23 );

        Assert::AreEqual( 1.23, counter.count() );
    }

    [TestCase( 0.0, 1.0, 1.0 )]
    [TestCase( 1.1, 2.2, 3.3 )]
    [TestCase( -1.5, -0.5, -2.0 )]
    void TestCase属性の利用( double v1, double v2, double expected )
    {
        foo::Counter counter;
        double actual = counter.add( v1 ).add( v2 ).count();

        Assert::That( actual, Is::EqualTo( expected )->Within( 0.000001 ) );
    }

    [Test]
    [Property( "val0", 1.0 )]
    [Property( "val1", 2.0 )]
    [Property( "val2", 3.0 )]
    [Property( "expected", 6.0 )]
    void Property属性の利用()
    {
        TestContext^ context = TestContext::CurrentContext;
        const double val0 = Double::Parse( context->Test->Properties->Get( "val0" )->ToString() );
        const double val1 = Double::Parse( context->Test->Properties->Get( "val1" )->ToString() );
        const double val2 = Double::Parse( context->Test->Properties->Get( "val2" )->ToString() );
        const double expected = Double::Parse( context->Test->Properties->Get( "expected" )->ToString() );

        double actual = foo::Counter( val0 ).add( val1 ).add( val2 ).count();
        
        Assert::That( actual, Is::EqualTo( expected ) );
    }
};

} // namespace NUnitCpp
