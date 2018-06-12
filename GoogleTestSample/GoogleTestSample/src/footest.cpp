#include <iostream>
#include "gtest/gtest.h"

namespace 
{

class FooTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        std::cout << "SetUp" << std::endl;
    }

    virtual void TearDown()
    {
        std::cout << "TearDown" << std::endl;
    }
};

TEST_F( FooTest, test1 )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;
    ASSERT_EQ( 1, 1 );
}

TEST_F( FooTest, test2 )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;
    ASSERT_EQ( 2, 2 );
}

} // namespace gtestsample
