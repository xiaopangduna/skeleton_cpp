#include <iostream>
#include "skeleton_cpp/calculator/Calculator.hpp"

int main() {
    double result = skeleton_cpp::calculator::Calculator::add(5.0, 3.0);
    std::cout << "5 + 3 = " << result << std::endl;
    
    return 0;
}