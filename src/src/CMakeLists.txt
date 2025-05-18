# 添加库
add_library(moduleA
    moduleA/image_loader.cpp
)

# 头文件路径：编译时和安装时分离
target_include_directories(moduleA
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/include>    # 源码编译时用
        $<INSTALL_INTERFACE:include>                           # 安装后用
        ${OpenCV_INCLUDE_DIRS}
)

# 链接依赖库
target_link_libraries(moduleA
    PUBLIC
        ${OpenCV_LIBS}
)

# 为安装创建导出目标，方便其他项目find_package时用
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# 安装库和头文件
install(TARGETS moduleA
    EXPORT moduleATargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/include/moduleA
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/moduleA
    FILES_MATCHING PATTERN "*.hpp"
)

# 生成并安装 moduleAConfigVersion.cmake，用于版本检查
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/moduleAConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# 生成并安装 moduleAConfig.cmake
configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/moduleAConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/moduleAConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/moduleAConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/moduleAConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/moduleA
)

# 安装导出文件，供 find_package 调用
install(EXPORT moduleATargets
    FILE moduleATargets.cmake
    NAMESPACE moduleA::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/moduleA
)