cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(calculator_ut)

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/../../src/calculator)

include_directories(${SOURCES_DIR})

add_executable(calculator_ut
        main.cpp
        CalculatorUnitTest.cpp
        CalculatorTest.cpp
        ${SOURCES_DIR}/Calculator.cpp)

enable_testing()
find_package(GTest REQUIRED)

target_link_libraries(calculator_ut GTest::gtest GTest::gtest_main)
add_test(AllTests calculator_ut)
