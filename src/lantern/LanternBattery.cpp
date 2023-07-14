#include "LanternBattery.h"

#include <thread>
#include <chrono>
#include <iostream>

LanternBattery::LanternBattery()
: mLifePercentage(0)
{

}

const uint8_t& LanternBattery::life() const {
    return mLifePercentage;
}

void LanternBattery::charge() {
    std::function<void()> timerThreadFunc = [=]() {
        using namespace std::chrono_literals;

        for (int i = 1; i <= 100; i++) {
            std::lock_guard<std::mutex> lock(mMutex);
            this->mLifePercentage = i;
            std::this_thread::sleep_for(1000ms);
        }
    };

    mThread.reset(new std::thread(timerThreadFunc));
    mThread->detach();
}
