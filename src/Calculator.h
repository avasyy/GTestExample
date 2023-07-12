#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "ICalculator.h"

class Calculator final : public ICalculator {
public:
    int64_t add(const int64_t& left, const int64_t& right) const override;
    int64_t sub(const int64_t& left, const int64_t& right) const override;
    int64_t mul(const int64_t& left, const int64_t& right) const override;
    int64_t div(const int64_t& left, const int64_t& right) const override;

    Calculator() = default;
    ~Calculator() = default;
};

#endif  // __CALCULATOR_H__
