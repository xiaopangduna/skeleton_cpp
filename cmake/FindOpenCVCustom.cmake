# FindOpenCVCustom.cmake - 自定义OpenCV库查找模块

#.rst:
# FindOpenCVCustom
# ----------------
#
# 自定义导入和配置OpenCV库
#
# 该模块会查找OpenCV库，并设置适当的变量和目标

# 查找并配置OpenCV

# 如果指定了平台特定的OpenCV路径，则优先使用
if(DEFINED THIRD_PARTY_PLATFORM AND EXISTS "${CMAKE_SOURCE_DIR}/third_party/${THIRD_PARTY_PLATFORM}/opencv")
    # 将平台特定的OpenCV目录添加到CMAKE_PREFIX_PATH开头，确保优先查找
    list(INSERT CMAKE_PREFIX_PATH 0 ${CMAKE_SOURCE_DIR}/third_party/${THIRD_PARTY_PLATFORM}/opencv)
endif()

# 使用find_package查找OpenCV（Config模式）
find_package(OpenCV REQUIRED)