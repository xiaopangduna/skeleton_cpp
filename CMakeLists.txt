cmake_minimum_required(VERSION 3.10)
project(skeleton_cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置默认安装路径为项目内的install目录
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "Default install path" FORCE)
endif()


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
add_subdirectory(apps)
add_subdirectory(tests)

# 启用测试
enable_testing()

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