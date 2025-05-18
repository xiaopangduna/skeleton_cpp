# skeleton_cpp

1. 使用 find_package 的方式（推荐）
这是标准 CMake 生态中，使用包配置文件（package config）让其他项目「找到并使用你的库」。

编译步骤
在你的库项目中，配置并安装 package config 文件（你之前的 moduleAConfig.cmake，moduleAConfigVersion.cmake 和 moduleATargets.cmake 都是这部分）

执行：

bash
Copy
Edit
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/home/xiaopangdun/project/skeleton_cpp/third_party/moduleA
make
make install
这会把库文件、头文件和 cmake 配置文件安装到 /path/to/install（比如 /usr/local 或你自定义路径）

其他项目使用
cmake
Copy
Edit
list(APPEND CMAKE_PREFIX_PATH "/path/to/install")  # 告诉 CMake 去哪里找包

find_package(moduleA REQUIRED)

target_link_libraries(myExecutable PRIVATE moduleA::moduleA)
这样你的库 moduleA 就像 OpenCV、Boost 一样被其他模块方便调用，且自动处理依赖和头文件路径。

add_executable(app1 main.cpp)

target_include_directories(app1 PRIVATE
    ${CMAKE_SOURCE_DIR}/third_party/moduleA/include
)

target_link_libraries(app1 PRIVATE
    ${CMAKE_SOURCE_DIR}/third_party/moduleA/lib/libmoduleA.a
)

find_package(moduleA REQUIRED)
