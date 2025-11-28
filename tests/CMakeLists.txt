cmake_minimum_required(VERSION 3.10)

add_executable(calculator_test
    calculator_test.cpp
)

target_link_libraries(calculator_test PRIVATE
    skeleton_cpp
    gtest_main
)

enable_testing()
add_test(NAME calculator_test COMMAND calculator_test)