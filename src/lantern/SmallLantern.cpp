#include "SmallLantern.h"

SmallLantern::SmallLantern(IBattery& battery)
: mBattery{battery}, mIsTurnedOn {false}
{

}

void SmallLantern::turnOn() {
    if (mIsTurnedOn) return;

    mIsTurnedOn = true;
}

void SmallLantern::turnOff() {
    if (!mIsTurnedOn) return;

    mIsTurnedOn = false;
}

void SmallLantern::chargeBattery() {
    mBattery.charge();
}

const uint8_t& SmallLantern::batteryLife() const {
    return mBattery.life();
}
