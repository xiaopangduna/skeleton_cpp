# FindThirdParty.cmake - 第三方库路径设置模块

#.rst:
# FindThirdParty
# --------------
#
# 设置third_party目录为优先查找路径
#
# 该模块会将third_party目录添加到CMAKE_MODULE_PATH的开头，
# 确保在使用find_package时优先查找项目内嵌的第三方库

# 根据目标平台选择对应的第三方库目录
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
    set(THIRD_PARTY_PLATFORM "aarch64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
    set(THIRD_PARTY_PLATFORM "arm")
else()
    set(THIRD_PARTY_PLATFORM "x86_64")
endif()

# 检查对应平台的第三方库目录是否存在
set(THIRD_PARTY_PLATFORM_DIR "${CMAKE_SOURCE_DIR}/third_party/${THIRD_PARTY_PLATFORM}")
if(EXISTS ${THIRD_PARTY_PLATFORM_DIR})
    message(STATUS "使用 ${THIRD_PARTY_PLATFORM} 平台的第三方库: ${THIRD_PARTY_PLATFORM_DIR}")
    # 将平台特定的third_party目录添加到CMAKE_PREFIX_PATH开头
    list(INSERT CMAKE_PREFIX_PATH 0 ${THIRD_PARTY_PLATFORM_DIR})
else()
    message(WARNING "未找到 ${THIRD_PARTY_PLATFORM} 平台的第三方库目录: ${THIRD_PARTY_PLATFORM_DIR}")
endif()

# 导入自定义的查找模块
include(FindOpenCVCustom)


message(STATUS "已完成第三方库配置")