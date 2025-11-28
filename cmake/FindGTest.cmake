# FindGTest.cmake - Google Test库查找模块

#.rst:
# FindGTest
# ---------
#
# 导入和配置Google Test库
#
# 该模块会查找Google Test库，并设置适当的变量和目标

# 查找并配置Google Test
macro(find_googletest)
  # 首先尝试使用CMake的find_package查找Google Test
  find_package(GTest QUIET)
  
  if(GTest_FOUND)
    if(GTest_VERSION)
      message(STATUS "找到系统安装的Google Test: ${GTest_VERSION}")
    else()
      message(STATUS "找到系统安装的Google Test")
    endif()
    # 确保必要的变量被正确设置
    set(GTEST_LIBRARIES ${GTest_LIBRARIES})
    set(GTEST_INCLUDE_DIRS ${GTest_INCLUDE_DIRS})
    set(GTEST_BOTH_LIBRARIES ${GTest_LIBRARIES})
  else()
    # 如果find_package未成功，手动查找组件
    
    # 查找gtest库文件
    find_library(GTEST_LIBRARIES 
      NAMES gtest
      PATHS 
        /usr/lib 
        /usr/lib/x86_64-linux-gnu 
        /usr/local/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest/lib
      NO_DEFAULT_PATH
    )
    
    # 查找gtest_main库文件
    find_library(GTEST_MAIN_LIBRARIES 
      NAMES gtest_main
      PATHS 
        /usr/lib 
        /usr/lib/x86_64-linux-gnu 
        /usr/local/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest/lib
      NO_DEFAULT_PATH
    )
    
    # 查找包含目录
    find_path(GTEST_INCLUDE_DIRS 
      NAMES gtest/gtest.h
      PATHS 
        /usr/include 
        /usr/local/include
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest/include
      NO_DEFAULT_PATH
    )
    
    # 检查是否找到了所有必需的组件
    if(GTEST_LIBRARIES AND GTEST_MAIN_LIBRARIES AND GTEST_INCLUDE_DIRS)
      set(GTest_FOUND TRUE)
      set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
      message(STATUS "找到系统安装的Google Test库文件")
      
      # 创建导入的目标（如果不存在）
      if(NOT TARGET GTest::GTest)
        add_library(GTest::GTest UNKNOWN IMPORTED)
        set_target_properties(GTest::GTest PROPERTIES
          IMPORTED_LOCATION "${GTEST_LIBRARIES}"
          INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS}"
        )
      endif()
      
      if(NOT TARGET GTest::Main)
        add_library(GTest::Main UNKNOWN IMPORTED)
        set_target_properties(GTest::Main PROPERTIES
          IMPORTED_LOCATION "${GTEST_MAIN_LIBRARIES}"
          INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS}"
        )
      endif()
    else()
      message(WARNING "未找到系统安装的Google Test，请安装libgtest-dev或类似软件包")
      set(GTest_FOUND FALSE)
    endif()
  endif()
  
  # 提供一致的变量输出
  if(GTest_FOUND)
    # 确保所有标准变量都被设置
    if(NOT GTEST_INCLUDE_DIRS)
      set(GTEST_INCLUDE_DIRS ${GTest_INCLUDE_DIRS})
    endif()
    
    if(NOT GTEST_LIBRARIES)
      set(GTEST_LIBRARIES ${GTest_LIBRARIES})
    endif()
  endif()
endmacro()