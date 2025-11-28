# FindThirdParty.cmake - 统一管理项目的所有第三方依赖

#.rst:
# FindThirdParty
# ---------------
#
# 导入和配置所有第三方依赖库
#
# 该模块会查找项目所需的所有第三方库，并设置适当的变量和目标，
# 使得主CMakeLists.txt文件保持简洁。

# 查找所有第三方依赖
macro(find_all_third_party_dependencies)
  # 主库不需要第三方依赖
endmacro()