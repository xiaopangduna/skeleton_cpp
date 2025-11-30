export CROSS_COMPILE_PREFIX=x86_64-linux-gnu
export CC=${CROSS_COMPILE_PREFIX}-gcc
export CXX=${CROSS_COMPILE_PREFIX}-g++


PROJECT_ROOT=$(realpath "$(dirname "$0")/..")
SAVE_DIR=${PROJECT_ROOT}/third_party/x86_64
echo "项目根目录: $PROJECT_ROOT"
echo "安装目录: $SAVE_DIR"
cd ${PROJECT_ROOT}
mkdir tmp 

# cd ${PROJECT_ROOT} && cd tmp
# git clone https://gitee.com/mirrors/googletest.git -b v1.14.0
# cd googletest/
# mkdir build && cd build
# cmake -DCMAKE_INSTALL_PREFIX=../../../third_party/x86_64/gtest/ .. 
# make -j4
# make install

cd ${PROJECT_ROOT} && cd tmp
# git clone https://gitee.com/opencv/opencv.git
cd opencv
git checkout 4.10.0
rm -rf build
mkdir -p build && cd build
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${SAVE_DIR}/opencv \
    -DOPENCV_DOWNLOAD_PATH=../../opencv_cache \
    -DCMAKE_TOOLCHAIN_FILE=${PROJECT_ROOT}/cmake/x86_64-toolchain.cmake
make -j4
make install