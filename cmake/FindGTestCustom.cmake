# FindGTestCustom.cmake - 自定义Google Test库查找模块

#.rst:
# FindGTestCustom
# ---------------
#
# 自定义导入和配置Google Test库
#
# 该模块会查找Google Test库，并设置适当的变量和目标

# 查找并配置Google Test

# 如果指定了平台特定的GTest路径，则优先使用
if(DEFINED THIRD_PARTY_PLATFORM AND EXISTS "${CMAKE_SOURCE_DIR}/third_party/${THIRD_PARTY_PLATFORM}/gtest")
    # 将平台特定的GTest目录添加到CMAKE_PREFIX_PATH开头，确保优先查找
    list(INSERT CMAKE_PREFIX_PATH 0 ${CMAKE_SOURCE_DIR}/third_party/${THIRD_PARTY_PLATFORM}/gtest)
endif()

# 使用find_package查找GTest（Config模式）
find_package(GTest REQUIRED)