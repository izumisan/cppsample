#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vstestconsole
{

TEST_CLASS( BazTest )
{
public:
    TEST_METHOD( test1 )
    {
        Assert::AreEqual( 3, 1 + 2 );
    }
};

} // namespace vstestconsole
