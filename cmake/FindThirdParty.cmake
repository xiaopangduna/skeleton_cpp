# FindThirdParty.cmake - 统一管理项目的所有第三方依赖

#.rst:
# FindThirdParty
# ---------------
#
# 导入和配置所有第三方依赖库
#
# 该模块会查找项目所需的所有第三方库，并设置适当的变量和目标，
# 使得主CMakeLists.txt文件保持简洁。

# 查找并配置Google Test
macro(find_googletest)
  # 查找系统安装的Google Test
  find_package(GTest QUIET)
  
  if(GTest_FOUND)
    message(STATUS "找到系统安装的Google Test: ${GTest_VERSION}")
  else()
    # 尝试查找系统级安装的库文件
    find_library(GTEST_LIBRARIES gtest PATHS /usr/lib /usr/lib/x86_64-linux-gnu)
    find_library(GTEST_MAIN_LIBRARIES gtest_main PATHS /usr/lib /usr/lib/x86_64-linux-gnu)
    find_path(GTEST_INCLUDE_DIRS gtest/gtest.h PATHS /usr/include)
    
    if(GTEST_LIBRARIES AND GTEST_MAIN_LIBRARIES AND GTEST_INCLUDE_DIRS)
      set(GTest_FOUND TRUE)
      set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
      message(STATUS "找到系统安装的Google Test库文件")
    else()
      message(WARNING "未找到系统安装的Google Test，请安装libgtest-dev或类似软件包")
    endif()
  endif()
endmacro()

# 查找所有第三方依赖
macro(find_all_third_party_dependencies)
  find_googletest()
endmacro()