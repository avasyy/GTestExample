#include "Calculator.h"

#include <gtest/gtest.h>

TEST(CalculatorUnitTest, PositiveSum) {
    auto calc = Calculator();
    ASSERT_EQ(20, calc.add(10, 10));
}

TEST(CalculatorUnitTest, NegativeSum) {
    auto calc = Calculator();
    ASSERT_EQ(-20, calc.add(-10, -10));
}

TEST(CalculatorUnitTest, PositiveSumFailed) {
    auto calc = Calculator();
    ASSERT_NE(10, calc.add(3, 6));
}

TEST(CalculatorUnitTest, NegativeSumFailed) {
    auto calc = Calculator();
    ASSERT_NE(-20, calc.add(-10, -7));
}

TEST(CalculatorUnitTest, PositiveSub) {
    auto calc = Calculator();
    ASSERT_EQ(20, calc.sub(30, 10));
}

TEST(CalculatorUnitTest, NegativeSub) {
    auto calc = Calculator();
    ASSERT_EQ(-20, calc.sub(-30, -10));
}

TEST(CalculatorUnitTest, PositiveSubFailed) {
    auto calc = Calculator();
    ASSERT_NE(3, calc.sub(3, 6));
}

TEST(CalculatorUnitTest, NegativeSubFailed) {
    auto calc = Calculator();
    ASSERT_NE(-3, calc.sub(-11, -9));
}

TEST(CalculatorUnitTest, PositiveMul) {
    auto calc = Calculator();
    ASSERT_EQ(400, calc.mul(20, 20));
}

TEST(CalculatorUnitTest, NegativeMul) {
    auto calc = Calculator();
    ASSERT_EQ(-400, calc.mul(-20, 20));
}

TEST(CalculatorUnitTest, PositiveMulFailed) {
    auto calc = Calculator();
    ASSERT_NE(300, calc.mul(30, 111));
}

TEST(CalculatorUnitTest, NegativeMulFailed) {
    auto calc = Calculator();
    ASSERT_NE(-300, calc.mul(-100, 33));
}

TEST(CalculatorUnitTest, PositiveDiv) {
    auto calc = Calculator();
    ASSERT_EQ(20, calc.div(400, 20));
}

TEST(CalculatorUnitTest, NegativeDiv) {
    auto calc = Calculator();
    ASSERT_EQ(-3, calc.div(-60, 20));
}

TEST(CalculatorUnitTest, PositiveDivFailed) {
    auto calc = Calculator();
    ASSERT_NE(33, calc.div(999, 112));
}

TEST(CalculatorUnitTest, NegativeDivFailed) {
    auto calc = Calculator();
    ASSERT_NE(-5, calc.div(-100, 21));
}

TEST(CalculatorUnitTest, SubLowestOverload) {
    auto calc = Calculator();

    const int64_t left = std::numeric_limits<int64_t>::lowest();
    const int64_t right = 1;
    const int64_t result = std::numeric_limits<int64_t>::max();

    ASSERT_EQ(result, calc.sub(left, right));
}

TEST(CalculatorUnitTest, SumMaxOverload) {
    auto calc = Calculator();

    const int64_t left = std::numeric_limits<int64_t>::max();
    const int64_t right = 1;
    const int64_t result = std::numeric_limits<int64_t>::lowest();

    ASSERT_EQ(result, calc.add(left, right));
}

TEST(CalculatorUnitTest, SubMaxOverload) {
    auto calc = Calculator();

    const int64_t left = -1;
    const int64_t right = std::numeric_limits<int64_t>::max();;
    const int64_t result = std::numeric_limits<int64_t>::lowest();;

    ASSERT_EQ(result, calc.sub(left, right));
}

TEST(CalculatorUnitTest, SumLowestAndMaxNumbers) {
    auto calc = Calculator();

    const int64_t left = std::numeric_limits<int64_t>::lowest();
    const int64_t right = std::numeric_limits<int64_t>::max();
    const int64_t result = -1;

    ASSERT_EQ(result, calc.add(left, right));
}