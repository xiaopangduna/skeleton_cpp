#include <iostream>
#include "skeleton_cpp/calculator/Calculator.hpp"

int main() {
    double result_add = skeleton_cpp::calculator::Calculator::add(5.0, 3.0);
    std::cout << "5 + 3 = " << result_add << std::endl;
    
    double result_subtract = skeleton_cpp::calculator::Calculator::subtract(5.0, 3.0);
    std::cout << "5 - 3 = " << result_subtract << std::endl;
    
    return 0;
}