#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bartest
{

TEST_CLASS( BarTest )
{
public:

    TEST_METHOD( test1 )
    {
        Assert::AreEqual( 1, 1 );
    }
};

} // namespace bartest
