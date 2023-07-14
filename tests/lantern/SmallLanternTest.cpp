#include "SmallLantern.h"
#include "IBatteryMock.h"

#include <gmock/gmock.h>

using namespace testing;

// The purpose of this test is to show how Mocks can be used in unit testing

class SmallLanternTest : public Test {
protected:
    IBatteryMock mBatteryMock {};
    SmallLantern mLantern {mBatteryMock};

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SmallLanternTest, BatteryLifeWorksFine) {
    EXPECT_CALL(mBatteryMock, life()).WillOnce(ReturnRef(static_cast<const uint8_t&>(1)));
    EXPECT_EQ(1, mLantern.batteryLife());
}

TEST_F(SmallLanternTest, BatteryChargeWorksFine) {
    EXPECT_CALL(mBatteryMock, charge()).Times(1);
    mLantern.chargeBattery();
}

TEST_F(SmallLanternTest, LifeFunctionIsNotCalledDuringCharge) {
    EXPECT_CALL(mBatteryMock, life()).Times(0);
    EXPECT_CALL(mBatteryMock, charge()).Times(1);
    mLantern.chargeBattery();
}
