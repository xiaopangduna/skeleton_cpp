# FindGTest.cmake - 向后兼容的Google Test库查找模块

# 为了向后兼容，包含新的第三方依赖管理模块
if(NOT COMMAND find_googletest)
  include(FindThirdParty)
endif()

# 查找并配置Google Test
macro(find_googletest)
  # 查找系统安装的Google Test
  find_package(GTest QUIET)
  
  if(GTest_FOUND)
    message(STATUS "找到系统安装的Google Test: ${GTest_VERSION}")
  else()
    message(WARNING "未找到系统安装的Google Test，请安装libgtest-dev或类似软件包")
  endif()
endmacro()