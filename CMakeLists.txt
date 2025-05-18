cmake_minimum_required(VERSION 3.10)
project(CppSkeletonProject VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加第三方库搜索路径
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/third_party/opencv")

# 查找第三方库
# find_package(OpenCV REQUIRED)


# 2. 判断是否是 Catkin 环境
if(DEFINED ENV{CATKIN_DEVEL_PREFIX})
    message(STATUS "Detected Catkin build environment")

    find_package(catkin REQUIRED COMPONENTS roscpp)

    # 可选：查找其他库
    find_package(OpenCV REQUIRED)

    # 设置 catkin_package 导出
    catkin_package(
        INCLUDE_DIRS src/include
        LIBRARIES my_library
        CATKIN_DEPENDS roscpp
        DEPENDS OpenCV
    )

    include_directories(
        ${catkin_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        src/include
    )

else()
    message(STATUS "Using standard CMake build")

    find_package(OpenCV REQUIRED)

    include_directories(
        ${OpenCV_INCLUDE_DIRS}
        src/include
    )
endif()


# 添加子项目库
add_subdirectory(lib/subproject)

# 添加主项目源码
add_subdirectory(src)