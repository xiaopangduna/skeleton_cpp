cmake_minimum_required(VERSION 3.10)
project(skeleton_cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加cmake模块路径
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# 包含并初始化第三方库管理模块
include(FindThirdParty)
find_all_third_party_dependencies()

# 添加子目录
add_subdirectory(tests)
add_subdirectory(apps)

# 创建库
add_library(skeleton_cpp
    src/calculator/Calculator.cpp
)

target_include_directories(skeleton_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 设置标准安装规则
install(TARGETS skeleton_cpp
    EXPORT skeleton_cppTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT skeleton_cppTargets
    FILE skeleton_cppConfig.cmake
    NAMESPACE skeleton_cpp::
    DESTINATION lib/cmake/skeleton_cpp
)