cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(lantern)

add_executable(lantern
        main.cpp
        SmallLantern.cpp
        LanternBattery.cpp)
