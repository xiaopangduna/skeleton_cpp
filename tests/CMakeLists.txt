cmake_minimum_required(VERSION 3.10)

# 在测试目录中查找GTest
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# 使用自定义的查找宏
find_package(GTestCustom REQUIRED)

# # 创建测试辅助库
# add_library(test_utils STATIC
#   utils.cpp)

# # 设置测试辅助库的包含目录
# target_include_directories(test_utils PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

# 定义创建测试的函数
function(create_test TEST_NAME)
  # 创建测试可执行文件
  add_executable(${TEST_NAME} ${ARGN})
  
  # 链接库
  if(GTest_FOUND)
    if(TARGET GTest::gtest_main)
      # 如果找到了GTest目标，则使用目标链接
      target_link_libraries(${TEST_NAME} PRIVATE
          skeleton_cpp
          test_utils
          GTest::gtest_main)
    else()
      # 否则直接链接库文件
      target_include_directories(${TEST_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})
      target_link_libraries(${TEST_NAME} PRIVATE
          skeleton_cpp
          ${GTEST_MAIN_LIBRARIES}
          ${GTEST_LIBRARIES})
    endif()
  else()
    # 如果没有找到GTest，发出错误信息
    message(FATAL_ERROR "未找到Google Test库，无法编译测试程序")
  endif()
  
  # 添加到测试列表
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

# 使用函数创建测试
enable_testing()
create_test(calculator_test calculator_test.cpp)

