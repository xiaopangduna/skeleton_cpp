#!/usr/bin/env bash
set -euo pipefail

# 显示帮助信息
show_help() {
    echo "skeleton_cpp 项目测试脚本"
    echo ""
    echo "用法:"
    echo " bash $0 [build_dir] [标签]"
    echo " bash $0 --help"
    echo ""
    echo "参数:"
    echo "  [build_dir]                指定构建目录 (默认: build/x86_64-debug)"
    echo "  [标签]                     指定测试标签 (默认: unit)"
    echo ""
    echo "可选参数:"
    echo "  --help,-h                 显示此帮助信息"
    echo ""
    echo "示例:"
    echo "  # 使用默认设置运行测试 (build/x86_64-debug 目录, unit 标签)"
    echo "  bash $0"
    echo ""
    echo "  # 指定构建目录运行测试"
    echo "  bash $0 build/x86_64-debug"
    echo ""
    echo "  # 指定构建目录和测试标签"
    echo "  bash $0 build/x86_64-debug integration"
    echo ""
    echo "注意:"
    echo "  1. 请先使用 build.sh 构建项目，再使用此脚本运行测试"
    echo "  2. 此脚本需要预先构建的项目，且构建目录中必须包含测试配置文件"
    echo "  3. 构建目录通常格式为 build/<预设名>，如 build/x86_64-debug"
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

# =========================
# 基本路径
# =========================
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# =========================
# 参数解析
# =========================
BUILD_DIR="${1:-build/x86_64-debug}"
LABEL="${2:-unit}"

# 验证参数数量
if [ $# -gt 2 ]; then
    echo "错误: 不支持的参数数量"
    show_help
    exit 1
fi

# 如果 BUILD_DIR 是相对路径，则转换为绝对路径
if [[ "$BUILD_DIR" != /* ]]; then
    BUILD_DIR="$PROJECT_ROOT/$BUILD_DIR"
fi

# =========================
# 前置检查
# =========================
if [ ! -d "${BUILD_DIR}" ]; then
    echo "[ERROR] Build directory does not exist: ${BUILD_DIR}"
    echo "Please configure & build first."
    exit 1
fi

if [ ! -f "${BUILD_DIR}/CTestTestfile.cmake" ]; then
    echo "[ERROR] No tests registered in: ${BUILD_DIR}"
    echo "Did you enable ENABLE_TESTS when configuring?"
    exit 1
fi

# =========================
# 信息输出
# =========================
echo "========================================"
echo " Running tests"
echo " Build dir  : ${BUILD_DIR}"
echo " Test label : ${LABEL}"
echo "========================================"

# =========================
# 运行测试
# =========================
cd "${BUILD_DIR}"

ctest \
    -L "${LABEL}" \
    --output-on-failure

echo "========================================"
echo "[SUCCESS] Tests finished"
echo "========================================"