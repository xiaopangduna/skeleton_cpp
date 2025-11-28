cmake_minimum_required(VERSION 3.10)
project(skeleton_cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加cmake模块路径
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# 包含并初始化第三方库管理模块
include(FindThirdParty)
find_all_third_party_dependencies()

# 定义核心库
add_library(skeleton_cpp
    src/calculator/Calculator.cpp
)

# 配置库的包含目录
target_include_directories(skeleton_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 导出库目标以便安装
set_target_properties(skeleton_cpp PROPERTIES
    EXPORT_NAME skeleton_cpp
)

# 添加子目录
add_subdirectory(tests)
add_subdirectory(apps)

# 安装库目标
install(TARGETS skeleton_cpp
    EXPORT skeleton_cppTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# 安装头文件
install(DIRECTORY include/
    DESTINATION include
)

# 安装CMake配置文件
install(EXPORT skeleton_cppTargets
    FILE skeleton_cppConfig.cmake
    NAMESPACE skeleton_cpp::
    DESTINATION lib/cmake/skeleton_cpp
)