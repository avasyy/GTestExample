cmake_minimum_required(VERSION 3.14)

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(calculator
        ${SOURCES_DIR}/main.cpp
        ${SOURCES_DIR}/calculator.cpp)
