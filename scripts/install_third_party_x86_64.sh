git clone https://github.com/google/googletest.git -b v1.14.0
git clone https://gitee.com/mirrors/googletest.git -b v1.14.0
cd googletest/
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=../../../third_party/x86_64/gtest/ .. 
make -j4
make install


git clone https://gitee.com/opencv/opencv.git
git clone https://gitee.com/opencv/opencv_contrib.git
# 5. 切换 opencv 到指定 tag
cd opencv
git checkout 4.10.0
cd ..
# 6. 切换 opencv_contrib 到相同 tag
cd opencv_contrib
git checkout 4.10.0
cd ..

cd opencv
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=../../../third_party/x86_64/opencv \
      -D OPENCV_DOWNLOAD_PATH=../../opencv_cache ..
make -j4
make install


# 安装交叉编译工具链
sudo apt install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu