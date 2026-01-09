cmake_minimum_required(VERSION 3.15)

# 定义项目名称
project(skeleton_cpp VERSION 0.1.0 LANGUAGES CXX)

option(ENABLE_TESTS "Enable unit tests" ON)

# 指定C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CMake配置信息:")
message(STATUS "  - CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "  - CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "  - CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "  - CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "  - CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "  - CMAKE_SYSROOT: ${CMAKE_SYSROOT}")
message(STATUS "  - CMAKE_CROSSCOMPILING: ${CMAKE_CROSSCOMPILING}")
message(STATUS "  - CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")
message(STATUS "  - CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "  - CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  - CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

# 将cmake目录添加到模块查找路径
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# 包含第三方库查找模块
include(FindThirdParty)

# 定义源文件列表
set(SOURCES_FILE
    src/utils/logger_factory.cpp
    src/utils/yaml.cpp
)

# 创建库目标
add_library(skeleton_cpp STATIC ${SOURCES_FILE})

# 链接OpenCV库和spdlog到我们的库（使用PUBLIC以便链接skeleton_cpp的目标也能访问这些依赖）
target_link_libraries(skeleton_cpp PUBLIC ${OpenCV_LIBS} spdlog::spdlog yaml-cpp::yaml-cpp)

# 设置库的包含目录
target_include_directories(skeleton_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# # RGA
# if(RGA_FOUND)
#     target_sources(deploy_percept PRIVATE src/pre_process/image_pre_process_rga.cpp)
#     target_link_libraries(deploy_percept PUBLIC ${LIBRGA})
#     target_include_directories(deploy_percept PUBLIC $<BUILD_INTERFACE:${LIBRGA_INCLUDES}>)    
#     target_compile_definitions(deploy_percept PUBLIC RGA_FOUND=1)
# endif()

# 安装规则
install(TARGETS skeleton_cpp
    EXPORT skeleton_cppTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/
    DESTINATION include
)

install(EXPORT skeleton_cppTargets
    FILE skeleton_cppConfig.cmake
    NAMESPACE skeleton_cpp::
    DESTINATION lib/cmake/skeleton_cpp
)

# 添加apps目录
add_subdirectory(apps)

# 添加测试
message(STATUS "==============================================================================")
if(ENABLE_TESTS )
    if(GTest_FOUND)
        message(STATUS "测试已被启用，开始编译测试用例")
        enable_testing()
        add_subdirectory(tests)
    else()
        message(WARNING "测试已被启用，但未找到 Google Test，测试将被跳过")
    endif()
else()
    message(STATUS "测试已被禁用")
endif()