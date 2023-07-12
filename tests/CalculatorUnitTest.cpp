#include "Calculator.h"

#include <gtest/gtest.h>

TEST(CalculatorTest, PositiveSum) {
    auto calc = Calculator();
    ASSERT_EQ(20, calc.add(10, 10));
}
