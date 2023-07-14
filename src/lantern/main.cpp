#include <iostream>
#include <thread>

#include "LanternBattery.h"
#include "SmallLantern.h"

int main() {
    std::unique_ptr<IBattery> battery = std::make_unique<LanternBattery>();
    std::unique_ptr<ILantern> lantern = std::make_unique<SmallLantern>(*battery.get());

    lantern->chargeBattery();

    using namespace std::chrono_literals;

    for (int i = 1; i <= 100; i++) {
        std::this_thread::sleep_for(1000ms);
        std::cout << "Lantern's battery: " << unsigned(lantern->batteryLife()) << std::endl;
    }

    return 0;
}
