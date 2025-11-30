#!/bin/bash

# gtest源码放在tmp目录下

# 为aarch64平台编译第三方库的脚本

set -e  # 遇到错误时停止执行

echo "开始为aarch64平台编译第三方库..."

# 获取项目根目录
PROJECT_ROOT=$(realpath "$(dirname "$0")/..")
echo "项目根目录: $PROJECT_ROOT"

# 创建aarch64平台的第三方库目录
mkdir -p ${PROJECT_ROOT}/third_party/aarch64
AARCH64_DIR=${PROJECT_ROOT}/third_party/aarch64

echo "安装目录: $AARCH64_DIR"

# 设置交叉编译工具链
export CROSS_COMPILE_PREFIX=aarch64-linux-gnu
export CC=${CROSS_COMPILE_PREFIX}-gcc
export CXX=${CROSS_COMPILE_PREFIX}-g++

echo "使用交叉编译工具链: $CROSS_COMPILE_PREFIX"

# 检查交叉编译工具是否安装
if ! command -v ${CXX} &> /dev/null
then
    echo "错误: 未找到交叉编译工具链 $CXX"
    echo "请先安装: sudo apt install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu"
    exit 1
fi

echo "交叉编译工具链检查通过"

# 编译GTest
echo "开始编译GTest..."
cd ${PROJECT_ROOT}/tmp/googletest
rm -rf build_aarch64
mkdir -p build_aarch64 && cd build_aarch64

cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${AARCH64_DIR}/gtest \
    -DCMAKE_TOOLCHAIN_FILE=${PROJECT_ROOT}/cmake/aarch64-toolchain.cmake
    
make -j$(nproc)
make install

echo "GTest编译完成"

# 编译OpenCV
echo "开始编译OpenCV..."
cd ${PROJECT_ROOT}/tmp/opencv
rm -rf build_aarch64
mkdir -p build_aarch64 && cd build_aarch64

cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${AARCH64_DIR}/opencv \
    -DOPENCV_DOWNLOAD_PATH=../../opencv_aarch64_cache \
    -DCMAKE_TOOLCHAIN_FILE=${PROJECT_ROOT}/cmake/aarch64-toolchain.cmake

make -j4  # 减少并行数以节省内存
make install

echo "OpenCV编译完成"

echo "所有第三方库编译完成，已安装到 ${AARCH64_DIR}"
echo "现在可以使用aarch64工具链进行项目构建了"