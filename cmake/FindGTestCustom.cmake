# FindGTestCustom.cmake - 自定义Google Test库查找模块

#.rst:
# FindGTestCustom
# ---------------
#
# 自定义导入和配置Google Test库
#
# 该模块会查找Google Test库，并设置适当的变量和目标

# 查找并配置Google Test

set(GTest_DIR ${THIRD_PARTY_DIR}/gtest/${THIRD_PARTY_PLATFORM}/lib/cmake/GTest)
# list(APPEND CMAKE_PREFIX_PATH "${THIRD_PARTY_DIR}/opencv/${THIRD_PARTY_PLATFORM}")
# 使用find_package查找GTest（Config模式）
find_package(GTest REQUIRED)