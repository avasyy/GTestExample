#ifndef __SMALL_LANTERN_H__
#define __SMALL_LANTERN_H__

#include "ILantern.h"
#include "IBattery.h"

class SmallLantern final : public ILantern {
public:
    void turnOn() override;
    void turnOff() override;
    void chargeBattery() override;

    const uint8_t& batteryLife() const override;

    SmallLantern(IBattery&);
    ~SmallLantern() = default;

private:
    IBattery& mBattery;
    bool mIsTurnedOn;
};

#endif  // __SMALL_LANTERN_H__
