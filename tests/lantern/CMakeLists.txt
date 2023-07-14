cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(lantern_ut)

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/../../src/lantern)

include_directories(${SOURCES_DIR})

add_executable(lantern_ut
        main.cpp
        SmallLanternTest.cpp
        ${SOURCES_DIR}/SmallLantern.cpp
        IBatteryMock.h)

enable_testing()
find_package(GTest REQUIRED)

target_link_libraries(lantern_ut GTest::gtest GTest::gmock GTest::gtest_main)
add_test(AllTests lantern_ut)
