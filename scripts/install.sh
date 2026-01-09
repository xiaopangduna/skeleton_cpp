#!/usr/bin/env bash
set -euo pipefail

# 显示帮助信息
show_help() {
    echo "skeleton_cpp 项目安装脚本"
    echo ""
    echo "用法:"
    echo " bash $0 [预设名]"
    echo " bash $0 --help"
    echo ""
    echo "参数:"
    echo "  [预设名]                    使用指定的构建预设 (默认: aarch64-release)"
    echo "                            支持的预设有:"
    echo "                              - x86_64-debug: x86_64架构调试版本 (支持测试)"
    echo "                              - aarch64-release: aarch64架构发布版本 (不支持测试)"
    echo ""
    echo "可选参数:"
    echo "  --help,-h                 显示此帮助信息"
    echo ""
    echo "示例:"
    echo "  # 使用默认预设 (aarch64-release)"
    echo "  bash $0"
    echo ""
    echo "  # 使用指定预设"
    echo "  bash $0 aarch64-release"
    echo "  bash $0 x86_64-debug"
    echo ""
    echo "注意:"
    echo "  1. 请先使用 VsCode CMake 构建项目，再使用此脚本安装"
    echo "  2. 此脚本使用CMakePresets.json中的预设配置进行项目安装"
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

# 解析命令行参数
if [ "$#" -gt 1 ]; then
    echo "错误: 不支持的参数数量"
    show_help
    exit 1
fi

PRESET="${1:-aarch64-release}"

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${PROJECT_ROOT}/build/${PRESET}"

echo "========================================"
echo " CMake install script"
echo "----------------------------------------"
echo " Project root : ${PROJECT_ROOT}"
echo " Preset       : ${PRESET}"
echo " Build dir    : ${BUILD_DIR}"
echo "========================================"

# =========================
# 检查构建目录是否存在
# =========================
if [ ! -d "${BUILD_DIR}" ]; then
    echo "[ERROR] Build directory does not exist: ${BUILD_DIR}"
    echo "Please build the project first using the build script."
    exit 1
fi

# =========================
# 安装
# =========================
echo "[INFO] Installing..."
cmake --install "${BUILD_DIR}"

echo "========================================"
echo "[SUCCESS] Install finished"
echo "========================================"