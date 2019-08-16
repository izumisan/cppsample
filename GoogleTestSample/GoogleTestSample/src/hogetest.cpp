#include <iostream>
#include <functional>
#include "gtest/gtest.h"

TEST( HogeTest, test1 )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;

    EXPECT_EQ( 1, 1 );  // expected = actual

    EXPECT_NE( 1, 2 );  // val1 not equal val2
    EXPECT_LT( 1, 2 );  // val1 less than val2
    EXPECT_LE( 1, 1 );  // val1 less than or equal to val2
    EXPECT_GT( 1, 0 );  // val1 greater than val2
    EXPECT_GE( 1, 1 );  // val1 greater than or equal to val2
}

TEST( HogeTest, test2 )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;

    EXPECT_FLOAT_EQ( 0.123456f, 0.123456f );

    EXPECT_DOUBLE_EQ( 0.123456, 0.123456 );

    EXPECT_NEAR( 0.1230, 0.1231, 0.0005 );
}

TEST( HogeTest, test3 )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;

    EXPECT_STREQ( "abcde", "abcde" );  // val1 == val2
    EXPECT_STRNE( "abcde", "aaaaa" );  // val1 != val2

    EXPECT_STRCASEEQ( "abcde", "ABCDE" );  // val1 == val2 (ignore case)
    EXPECT_STRCASENE( "abcde", "AAAAA" );  // val1 != val2 (ignore case)
}

TEST( HogeTest, exceptionTest )
{
    auto&& throwException = [] { throw std::runtime_error( "error" ); };

    ASSERT_THROW( throwException(), std::runtime_error );
    ASSERT_THROW( throwException(), std::exception );  // これもSUCCESSとなる

    ASSERT_ANY_THROW( throwException() );

    auto&& dontThrowException = [] {};

    ASSERT_NO_THROW( dontThrowException() );
}

TEST( HogeTest, errorMessage )
{
    std::cout << test_info_->test_case_name() << "::" << test_info_->name() << std::endl;

    // 必ず失敗するテスト
    EXPECT_TRUE( false ) << "Error message on failed.";
}
