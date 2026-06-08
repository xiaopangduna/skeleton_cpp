# FindThirdParty.cmake - 第三方库路径设置模块

#.rst:
# 设置THIRD_PARTY_DIR目录为第三方库的路径


# 设置第三方库目录 (third_party/<平台>/<库名>/)
set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party")
set(THIRD_PARTY_PLATFORM_DIR "${THIRD_PARTY_DIR}/${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "==============================================================================")
message(STATUS "第三方库配置信息:")
message(STATUS "  - THIRD_PARTY_DIR: ${THIRD_PARTY_DIR}")
message(STATUS "  - THIRD_PARTY_PLATFORM_DIR: ${THIRD_PARTY_PLATFORM_DIR}")

# # 导入自定义的查找模块
include(FindOpenCVCustom)
include(FindSpdlogCustom)
include(FindYamlCppCustom)
include(FindCnpyCustom)
include(FindZlibCustom)

include(FindRknn)
include(FindRgaCustom)

include(FindGTestCustom)

message(STATUS "已完成第三方库配置")