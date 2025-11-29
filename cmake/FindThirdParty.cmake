# FindThirdParty.cmake - 第三方库路径设置模块

#.rst:
# FindThirdParty
# --------------
#
# 设置third_party目录为优先查找路径
#
# 该模块会将third_party目录添加到CMAKE_MODULE_PATH的开头，
# 确保在使用find_package时优先查找项目内嵌的第三方库

# 导入自定义的OpenCV查找模块
include(FindOpenCVCustom)

message(STATUS "已将third_party目录添加到查找路径，优先使用项目内嵌的第三方库")