#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "IBattery.h"

#include <thread>
#include <mutex>

class LanternBattery final : public IBattery {
public:
    const uint8_t& life() const override;
    void charge() override;

    LanternBattery();
    ~LanternBattery() = default;
    LanternBattery(const LanternBattery&) = delete;
    LanternBattery(LanternBattery&&) = delete;
    LanternBattery& operator=(const LanternBattery&) = delete;
    LanternBattery& operator=(LanternBattery&&) = delete;

private:
    uint8_t mLifePercentage;
    std::unique_ptr<std::thread> mThread;
    std::mutex mMutex;
};

#endif  // __BATTERY_H__
