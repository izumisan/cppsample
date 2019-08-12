#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FooTest
{
TEST_CLASS( FooTest )
{
public:
    FooTest()
    {
        Logger::WriteMessage( "ctor" );
    }

    ~FooTest()
    {
        Logger::WriteMessage( "dtor" );
    }

    TEST_CLASS_INITIALIZE( classInitialize )
    {
        Logger::WriteMessage( "class initialize" );
    }

    TEST_CLASS_CLEANUP( classCleanup )
    {
        Logger::WriteMessage( "class cleanup" );
    }

    TEST_METHOD_INITIALIZE( initialize )
    {
        Logger::WriteMessage( "initialize" );
    }

    TEST_METHOD_CLEANUP( cleanup )
    {
        Logger::WriteMessage( "cleanup" );
    }

    TEST_METHOD( testMethod1 )
    {
        Logger::WriteMessage( "testMethod1" );

        int actual = 1 + 2;
        int expected = 3;
        Assert::AreEqual( expected, actual );
        Assert::AreNotEqual( 0, actual );
    }

    TEST_METHOD( testMethod2 )
    {
        Logger::WriteMessage( "testMethod2" );

        int foo = 168;

        int& actual = foo;
        int& expected = foo;
        Assert::AreSame( expected, actual );  // éQè∆î‰är
    }

    TEST_METHOD( testMethod3 )
    {
        Logger::WriteMessage( "testMethod3" );

        bool actual = true;
        Assert::IsTrue( actual == true );
        Assert::IsFalse( actual != true );
    }

    TEST_METHOD( testMethod4 )
    {
        Logger::WriteMessage( "testMethod4" );

        int* actual = nullptr;
        Assert::IsNull( actual );

        actual = new int();
        *actual = 168;
        Assert::IsNotNull( actual );
    }
};
}