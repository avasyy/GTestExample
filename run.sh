#!/bin/bash

function help() {
    echo "Usage:"
    echo ""
    echo "    binary - run calculator binary"
    echo "    tests - run tests binary"
    echo "    clear - remove build directory"
    exit 1
}

if [[ $1 == "" ]] || [[ $1 == "help" ]]; then
    help
fi

function build_binaries() {
    if [[ ! -d "build" ]]; then
        ./build.sh
    fi

    if [[ -f "build/src/calculator" ]] && [[ -f "build/tests/unittests" ]]; then
        return 0
    else
        return 1
    fi
}

if [[ $1 == "binary" ]]; then
    if build_binaries; then
        echo "Run binary:"
        echo ""
        ./build/src/calculator
    fi
elif [[ $1 == "tests" ]]; then
    if build_binaries; then
        echo "Run tests:"
        echo ""
        ./build/tests/unittests
    fi
elif [[ $1 == "clear" ]]; then
    echo "Remove build directory"
    rm -r build
else
    echo "Passed wrong argument: $1"
fi
