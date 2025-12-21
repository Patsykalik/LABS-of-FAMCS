#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;
    std::cout << "Result = " << calc.evaluate("11 * 13 - 113 / (13 + 43)") << std::endl;
    return 0;
}
