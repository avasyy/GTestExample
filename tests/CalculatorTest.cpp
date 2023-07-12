#include "Calculator.h"

#include <gtest/gtest.h>

// The purpouse of this file is to remind how to write test cases with class

class CalculatorTest : public ::testing::Test {
protected:
    std::unique_ptr<ICalculator> uPtrCalc;

    CalculatorTest() : uPtrCalc{std::make_unique<Calculator>()} {}

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(CalculatorTest, PositiveSum) {
    ASSERT_EQ(20, uPtrCalc->add(10, 10));
}

TEST_F(CalculatorTest, NegativeSum) {
    ASSERT_EQ(-20, uPtrCalc->add(-10, -10));
}

TEST_F(CalculatorTest, PositiveSumFailed) {
    ASSERT_NE(10, uPtrCalc->add(3, 6));
}

TEST_F(CalculatorTest, NegativeSumFailed) {
    ASSERT_NE(-20, uPtrCalc->add(-10, -7));
}

TEST_F(CalculatorTest, PositiveSub) {
    ASSERT_EQ(20, uPtrCalc->sub(30, 10));
}

TEST_F(CalculatorTest, NegativeSub) {
    ASSERT_EQ(-20, uPtrCalc->sub(-30, -10));
}

TEST_F(CalculatorTest, PositiveSubFailed) {
    ASSERT_NE(3, uPtrCalc->sub(3, 6));
}

TEST_F(CalculatorTest, NegativeSubFailed) {
    ASSERT_NE(-3, uPtrCalc->sub(-11, -9));
}

TEST_F(CalculatorTest, PositiveMul) {
    ASSERT_EQ(400, uPtrCalc->mul(20, 20));
}

TEST_F(CalculatorTest, NegativeMul) {
    ASSERT_EQ(-400, uPtrCalc->mul(-20, 20));
}

TEST_F(CalculatorTest, PositiveMulFailed) {
    ASSERT_NE(300, uPtrCalc->mul(30, 111));
}

TEST_F(CalculatorTest, NegativeMulFailed) {
    ASSERT_NE(-300, uPtrCalc->mul(-100, 33));
}

TEST_F(CalculatorTest, PositiveDiv) {
    ASSERT_EQ(20, uPtrCalc->div(400, 20));
}

TEST_F(CalculatorTest, NegativeDiv) {
    ASSERT_EQ(-3, uPtrCalc->div(-60, 20));
}

TEST_F(CalculatorTest, PositiveDivFailed) {
    ASSERT_NE(33, uPtrCalc->div(999, 112));
}

TEST_F(CalculatorTest, NegativeDivFailed) {
    ASSERT_NE(-5, uPtrCalc->div(-100, 21));
}

TEST_F(CalculatorTest, SubLowestOverload) {

    const int64_t left = std::numeric_limits<int64_t>::lowest();
    const int64_t right = 1;
    const int64_t result = std::numeric_limits<int64_t>::max();

    ASSERT_EQ(result, uPtrCalc->sub(left, right));
}

TEST_F(CalculatorTest, SumMaxOverload) {

    const int64_t left = std::numeric_limits<int64_t>::max();
    const int64_t right = 1;
    const int64_t result = std::numeric_limits<int64_t>::lowest();

    ASSERT_EQ(result, uPtrCalc->add(left, right));
}

TEST_F(CalculatorTest, SubMaxOverload) {

    const int64_t left = -1;
    const int64_t right = std::numeric_limits<int64_t>::max();;
    const int64_t result = std::numeric_limits<int64_t>::lowest();;

    ASSERT_EQ(result, uPtrCalc->sub(left, right));
}

TEST_F(CalculatorTest, SumLowestAndMaxNumbers) {

    const int64_t left = std::numeric_limits<int64_t>::lowest();
    const int64_t right = std::numeric_limits<int64_t>::max();
    const int64_t result = -1;

    ASSERT_EQ(result, uPtrCalc->add(left, right));
}