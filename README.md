# GTestExample
Simple example of GTest framework usage

## Preparement

### CMake

Install `CMake` on your laptop.

To do that you can use next command:
- `brew install cmake` on Mac laptops (if you have `brew` installed, if you don't then just google it)
- `sudo apt-get install cmake` on Linux laptops

### GTest

You need to install `GTest` framework on your laptop.

To install `GTest` you need to perform few steps:

- Clone the sources: `git clone https://github.com/google/googletest.git -b v1.13.0`
- Go to the dir with cloned sources: `cd googletest`
- Create `build` directory: `mkdir build && cd build`
- Generate `Makefile` and other needed build files: `cmake ..`
- Build binaries: `make`
- Install built binaries: `sudo make install`

More information can be found here: [googletest](https://github.com/google/googletest/blob/main/googletest/README.md)

## Purpose

1. Provide an example of GTest framework usage
2. Provide an example of CMake basic rules usage

## Sources

The sources represent simple class `Calculator` which has four main operations:
- `add` - addition operation: `a + b`
- `sub` - subtraction operation: `a - b`
- `mul` - multiplication operation: `a * b`
- `div` - division operation: `a / b`

The `Calculator` class is derived from `ICalculator` which is interface and contains skeleton for previous one.

All sources can be found in `src` directory.

## Tests

The tests represent regular unit tests, which were written, using `GTest` framework.

There are two files with unit tests:
- `CalculatorUnitTests` - file with simple unit tests, which use `TEST()` body and not rely on class.
- `CalculatorTest` - file with simple unit tests, which use `TEST_F()` body and rely on class.

## Build system

As a build system was choosen `CMake` to automate build process.

The `CMake` structure is next:
- Main `CMake` file
  - `CMake` file in `src` directory
  - `CMake` file in `tests` directory

- The main `CMake` file calls `CMake` files in sub directories and each sub `CMake` file builds its module.
- Each sub `CMake` file can build its module witout being inkoked from main `CMake`.

## Build & Run

- Use `build.sh` script just to build binaries
- Use `run.sh` script to run binaries
