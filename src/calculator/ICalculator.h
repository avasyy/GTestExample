#ifndef __ICALCULATOR_H__
#define __ICALCULATOR_H__

#include <cinttypes>

class ICalculator {
public:
    virtual int64_t add(const int64_t& left, const int64_t& right) const = 0;
    virtual int64_t sub(const int64_t& left, const int64_t& right) const = 0;
    virtual int64_t mul(const int64_t& left, const int64_t& right) const = 0;
    virtual int64_t div(const int64_t& left, const int64_t& right) const = 0;

    virtual ~ICalculator() = default;
};

#endif // __ICALCULATOR_H__
