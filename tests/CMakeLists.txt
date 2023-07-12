cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(calculator_ut)

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/../src)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${SOURCES_DIR})

add_executable(unittests
        main.cpp
        CalculatorUnitTest.cpp
        CalculatorTest.cpp
        ${SOURCES_DIR}/Calculator.cpp)

target_link_libraries(unittests GTest::gtest GTest::gtest_main)
add_test(AllTests unittests)
