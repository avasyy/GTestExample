#include "calculator.h"

int64_t Calculator::add(const int64_t& left, const int64_t& right) const {
    return left + right;
}

int64_t Calculator::sub(const int64_t& left, const int64_t& right) const {
    return left - right;
}

int64_t Calculator::mul(const int64_t& left, const int64_t& right) const {
    return left * right;
}

int64_t Calculator::div(const int64_t& left, const int64_t& right) const {
    return left / right;
}
