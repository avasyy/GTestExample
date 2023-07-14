#ifndef __I_BATTERY_H__
#define __I_BATTERY_H__

#include <cinttypes>

class IBattery {
public:
    virtual const uint8_t& life() const = 0;
    virtual void charge() = 0;

    virtual ~IBattery() = default;
};

#endif  // __I_BATTERY_H__
