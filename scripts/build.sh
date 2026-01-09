#!/bin/bash

# 显示帮助信息
show_help() {
    echo "skeleton_cpp 项目构建脚本 (已弃用)"
    echo ""
    echo "用法:"
    echo " bash $0 --help | -h"
    echo ""
    echo "警告:"
    echo "  此脚本已弃用，因为当前CMake版本不支持 --preset 参数。"
    echo "  请使用传统的CMake命令或升级到CMake 3.19+版本。"
    echo ""
    echo "替代方法:"
    echo "  # 对于 x86_64-debug 配置:"
    echo "  mkdir -p build/x86_64-debug && cd build/x86_64-debug"
    echo "  cmake -DCMAKE_BUILD_TYPE=Debug \\"
    echo "        -DCMAKE_TOOLCHAIN_FILE=../../cmake/x86_64-toolchain.cmake \\"
    echo "        -DCMAKE_INSTALL_PREFIX=../../install/x86_64 \\"
    echo "        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \\"
    echo "        -DENABLE_TESTS=ON \\"
    echo "        ../.."
    echo "  make -j"
    echo ""
    echo "  # 对于 aarch64-release 配置:"
    echo "  mkdir -p build/aarch64-release && cd build/aarch64-release"
    echo "  cmake -DCMAKE_BUILD_TYPE=Release \\"
    echo "        -DCMAKE_TOOLCHAIN_FILE=../../cmake/aarch64-toolchain.cmake \\"
    echo "        -DCMAKE_INSTALL_PREFIX=../../install/aarch64 \\"
    echo "        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \\"
    echo "        -DENABLE_TESTS=OFF \\"
    echo "        ../.."
    echo "  make -j"
    echo ""
    echo "可选参数:"
    echo "  --help,-h                 显示此帮助信息"
    echo ""
    echo "注意:"
    echo "  此脚本使用CMakePresets.json中的预设配置进行项目构建，但需要CMake 3.19+支持"
}

# 特殊处理 --help 参数
# 检查是否有 --help 或 -h 参数
for arg in "$@"; do
    case "$arg" in
        --help|-h)
            show_help
            exit 0
            ;;
    esac
done

echo "警告: 当前CMake版本不支持 --preset 参数，此脚本已弃用。"
echo "当前CMake版本: $(cmake --version | head -n1)"
echo "需要CMake 3.19或更高版本才能使用预设功能。"
echo ""
echo "替代方法中提供的命令与 CMakePresets.json 中的配置完全匹配。"
echo "请使用传统的CMake命令或升级CMake版本。"
echo "运行 'bash $0 --help' 查看详细说明和替代方法。"
exit 1