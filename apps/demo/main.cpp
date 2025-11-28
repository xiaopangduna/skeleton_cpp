#include <iostream>
#include "skeleton_cpp/calculator/Calculator.hpp"

int main() {
    skeleton_cpp::calculator::Calculator calc;
    double result = calc.add(5.0, 3.0);
    std::cout << "5 + 3 = " << result << std::endl;
    
    return 0;
}