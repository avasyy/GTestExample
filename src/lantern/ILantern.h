#ifndef __I_LANTERN_H__
#define __I_LANTERN_H__

#include <cinttypes>

class ILantern {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void chargeBattery() = 0;
    virtual const uint8_t& batteryLife() const = 0;

    virtual ~ILantern() = default;
};

#endif  // __I_LANTERN_H__
