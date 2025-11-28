cmake_minimum_required(VERSION 3.10)

add_executable(calculator_test
    calculator_test.cpp
)

# 链接库
if(GTest_FOUND)
  if(TARGET GTest::gtest_main)
    # 如果找到了GTest目标，则使用目标链接
    target_link_libraries(calculator_test PRIVATE
        skeleton_cpp
        GTest::gtest_main)
  else()
    # 否则直接链接库文件
    target_include_directories(calculator_test PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(calculator_test PRIVATE
        skeleton_cpp
        ${GTEST_MAIN_LIBRARIES}
        ${GTEST_LIBRARIES})
  endif()
else()
  # 如果没有找到GTest，发出错误信息
  message(FATAL_ERROR "未找到Google Test库，无法编译测试程序")
endif()

enable_testing()
add_test(NAME calculator_test COMMAND calculator_test)