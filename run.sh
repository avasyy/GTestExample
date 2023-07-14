#!/bin/bash

function help() {
    echo "Usage:"
    echo ""
    echo "    calculator - run calculator binary"
    echo "    calculator_ut - run calculator unit tests"
    echo "    lantern - run lantern binary"
    echo "    lantern_ut - run lantern unit tests"
    echo "    clear - remove build directory"
    exit 1
}

if [[ $1 == "" ]] || [[ $1 == "help" ]]; then
    help
fi

calc_bin="build/src/calculator/calculator"
lantern_bin="build/src/lantern/lantern"
calc_test="build/tests/calculator/calculator_ut"
lantern_test="build/tests/lantern/lantern_ut"

function is_build_dir_present() {
    if [[ -d "build" ]]; then
        return 0
    else
        return 1
    fi
}

function build_binaries() {
    if ! is_build_dir_present; then
        ./build.sh
    fi

    if [[ -f ${calc_bin} ]] && [[ -f ${lantern_bin} ]] && [[ -f ${calc_test} ]] && [[ -f ${lantern_test} ]]; then
        return 0
    else
        return 1
    fi
}

if [[ $1 == "calculator" ]]; then
    if build_binaries; then
        echo "Run calculator binary:"
        echo ""
        ."/${calc_bin}"
    fi
elif [[ $1 == "calculator_ut" ]]; then
    if build_binaries; then
        echo "Run calculator tests:"
        echo ""
        ."/${calc_test}"
    fi
elif [[ $1 == "lantern" ]]; then
    if build_binaries; then
        echo "Run lantern binary:"
        echo ""
        ."/${lantern_bin}"
    fi
elif [[ $1 == "lantern_ut" ]]; then
    if build_binaries; then
        echo "Run lantern tests:"
        echo ""
        ."/${lantern_test}"
    fi
elif [[ $1 == "clear" ]]; then
    if is_build_dir_present; then
        echo "Remove build directory"
        rm -r build
    fi
else
    echo "Passed wrong argument: $1"
fi
