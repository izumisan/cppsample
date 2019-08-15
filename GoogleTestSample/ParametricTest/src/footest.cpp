#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <tuple>

///////////////////////////////////////////////////////////////////////////////
// Range( begin, end )
// Range( begin, end, step )
class RangeTest : public ::testing::TestWithParam<int>
{
};

INSTANTIATE_TEST_CASE_P(
    RangeTestData,
    RangeTest,
    ::testing::Range( 0, 10 ) );  // { 0, 1 ... 10 }

INSTANTIATE_TEST_CASE_P(
    RangeTestData2,
    RangeTest,
    ::testing::Range( 0, 10, 3 ) );  // { 0, 3, 6, 9 }

TEST_P( RangeTest, test1 )
{
    int param = GetParam();

    // TEST_Pマクロ内では test_info_ は使えない
    const ::testing::TestInfo* const test_info = ::testing::UnitTest::GetInstance()->current_test_info();
    std::cout << test_info->test_case_name() << " " << test_info->name() << " param: " << param << std::endl;
}

TEST_P( RangeTest, test2 )
{
    int param = GetParam();
    std::cout << "param: " << param << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Values( v1, v2, ... )
class ValuesTest : public ::testing::TestWithParam<std::string>
{
};

INSTANTIATE_TEST_CASE_P(
    ValuesTestData,
    ValuesTest,
    ::testing::Values( "one", "two", "three" ) );

TEST_P( ValuesTest, test1 )
{
    std::string param = GetParam();
    std::cout << "param: " << param << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// ValuesIn( STL-container )
// ValuesIn( iterator first, iterator last )  ※ lastは含まれない
class ValuesInTest : public ::testing::TestWithParam<double>
{
};

const std::vector<double> parameters_ = { 1.1, 3.3, 5.5, 7.7, 9.9 };

INSTANTIATE_TEST_CASE_P(
    ValuesInTestData,
    ValuesInTest,
    ::testing::ValuesIn( parameters_ ) );  // { 1.1, 3.3, 5.5, 7.7, 9.9 }

INSTANTIATE_TEST_CASE_P(
    ValuesInTestData2,
    ValuesInTest,
    ::testing::ValuesIn( parameters_.cbegin(), parameters_.cbegin() + 3 ) );  // { 1.1, 3.3, 5.5 }

TEST_P( ValuesInTest, test1 )
{
    double param = GetParam();
    std::cout << "param: " << param << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Combine( group1, group2, ... )
class CombineTest : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

INSTANTIATE_TEST_CASE_P(
    CombineTestData,
    CombineTest,
    ::testing::Combine( 
        ::testing::Range( 0, 3 ), 
        ::testing::Range( 0, 3 ) ) );  // 全組み合わせ (3 x 3 = 9 パターン)

TEST_P( CombineTest, test1 )
{
    std::tuple<int, int> param = GetParam();
    std::cout << "param: " << std::get<0>( param ) << " " << std::get<1>( param ) << std::endl;
}
