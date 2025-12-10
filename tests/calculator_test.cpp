#include <gtest/gtest.h>
#include <tuple>

#include "skeleton_cpp/calculator/Calculator.hpp"
#include "utils/environment.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
// 加法相关测试
////////////////////////////////////////////////////////////////////////////////////////////////////

// 加法参数化测试夹具类
class CalculatorAddTest : public ::testing::TestWithParam<std::tuple<double, double, double>>
{
};

// 加法参数化测试用例
TEST_P(CalculatorAddTest, Add)
{
    auto [a, b, expected] = GetParam();
    if (GlobalLoggerEnvironment::logger) {
        GlobalLoggerEnvironment::logger->info("Testing addition: {} + {} = {}", a, b, expected);
    }
    EXPECT_DOUBLE_EQ(skeleton_cpp::calculator::Calculator::add(a, b), expected);
}

// 定义加法测试用例数据
INSTANTIATE_TEST_SUITE_P(
    AddTestCases,
    CalculatorAddTest,
    ::testing::Values(
        std::make_tuple(2.0, 3.0, 5.0),    // 正数相加
        std::make_tuple(-2.0, -3.0, -5.0), // 负数相加
        std::make_tuple(5.0, -3.0, 2.0),   // 正数和负数相加
        std::make_tuple(1.5, 2.5, 4.0),    // 小数相加
        std::make_tuple(5.0, 0.0, 5.0),    // 与零相加
        std::make_tuple(0.0, 5.0, 5.0)     // 零与其他数相加
        ));

// 简单的调试测试函数，测试加法
TEST(CalculatorAddDebugTest, DebugAdd)
{
    double result = skeleton_cpp::calculator::Calculator::add(10.5, 20.3);
    EXPECT_DOUBLE_EQ(result, 30.8);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// 减法相关测试
////////////////////////////////////////////////////////////////////////////////////////////////////

// 减法参数化测试夹具类
class CalculatorSubtractTest : public ::testing::TestWithParam<std::tuple<double, double, double>>
{
};

// 减法参数化测试用例
TEST_P(CalculatorSubtractTest, Subtract)
{
    auto [a, b, expected] = GetParam();
    EXPECT_DOUBLE_EQ(skeleton_cpp::calculator::Calculator::subtract(a, b), expected);
}

// 定义减法测试用例数据
INSTANTIATE_TEST_SUITE_P(
    SubtractTestCases,
    CalculatorSubtractTest,
    ::testing::Values(
        std::make_tuple(5.0, 3.0, 2.0),   // 正数相减
        std::make_tuple(-2.0, -3.0, 1.0), // 负数相减
        std::make_tuple(5.0, -3.0, 8.0),  // 正数减负数
        std::make_tuple(1.5, 2.5, -1.0),  // 小数相减
        std::make_tuple(5.0, 0.0, 5.0),   // 减去零
        std::make_tuple(0.0, 5.0, -5.0)   // 零减去其他数
        ));

// 简单的调试测试函数，测试减法
TEST(CalculatorSubtractDebugTest, DebugSubtract)
{
    double result = skeleton_cpp::calculator::Calculator::subtract(30.8, 10.5);
    EXPECT_DOUBLE_EQ(result, 20.3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    // 注册全局环境
    ::testing::AddGlobalTestEnvironment(new GlobalLoggerEnvironment);

    return RUN_ALL_TESTS();
}