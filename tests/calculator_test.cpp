#include "skeleton_cpp/calculator/Calculator.hpp"
#include <cassert>
#include <iostream>

int main() {
    // 测试正数相加
    assert(skeleton_cpp::calculator::Calculator::add(2.0, 3.0) == 5.0);
    
    // 测试负数相加
    assert(skeleton_cpp::calculator::Calculator::add(-2.0, -3.0) == -5.0);
    
    // 测试正数和负数相加
    assert(skeleton_cpp::calculator::Calculator::add(5.0, -3.0) == 2.0);
    
    // 测试小数相加
    assert(skeleton_cpp::calculator::Calculator::add(1.5, 2.5) == 4.0);
    
    // 测试与零相加
    assert(skeleton_cpp::calculator::Calculator::add(5.0, 0.0) == 5.0);
    assert(skeleton_cpp::calculator::Calculator::add(0.0, 5.0) == 5.0);
    
    std::cout << "所有测试通过!" << std::endl;
    
    return 0;
}