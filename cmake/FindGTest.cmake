# FindGTest.cmake - 管理Google Test库

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