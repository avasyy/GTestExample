#ifndef __I_BATTERY_MOCK_H__
#define __I_BATTERY_MOCK_H__

#include "IBattery.h"

#include "gmock/gmock.h"

class IBatteryMock : public IBattery {
public:
    MOCK_CONST_METHOD0(life, const uint8_t&());
    MOCK_METHOD0(charge, void());

    ~IBatteryMock() = default;
};

#endif  // __I_BATTERY_MOCK_H__
