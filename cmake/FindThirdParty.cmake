# FindThirdParty.cmake - 第三方库路径设置模块

#.rst:
# FindThirdParty
# --------------
#
# 设置third_party目录为优先查找路径
#
# 该模块会将third_party目录添加到CMAKE_MODULE_PATH的开头，
# 确保在使用find_package时优先查找项目内嵌的第三方库

# # 设置third_party目录为优先查找路径

#   # 将third_party目录添加到CMAKE_MODULE_PATH的开头，确保优先查找
#   list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
  
#   # 也将特定库的路径添加到查找路径中，以支持Config模式的查找
#   list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest)
  
#   # 包含自定义的GTest查找模块

  
#   message(STATUS "已将third_party目录添加到查找路径，优先使用项目内嵌的第三方库")
