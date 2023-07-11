#include <iostream>
#include <memory>

#include "calculator.h"

int main() {
    std::unique_ptr<ICalculator> calc = std::make_unique<Calculator>();

    std::cout << "add: " << calc->add(100, 14) << std::endl;
    std::cout << "sub: " << calc->sub(100, 14) << std::endl;
    std::cout << "mul: " << calc->mul(100, 14) << std::endl;
    std::cout << "div: " << calc->div(100, 14) << std::endl;


    return 0;
}
