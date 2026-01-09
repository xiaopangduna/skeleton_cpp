#!/usr/bin/env bash
set -euo pipefail

# =========================
# 基本路径
# =========================
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_ROOT="${PROJECT_ROOT}/build"

# =========================
# 默认参数
# =========================
DEFAULT_BUILD_TYPE="debug"   # debug | release
DEFAULT_LABEL="unit"
PRESET_PREFIX="x86_64"

# =========================
# 参数解析
# =========================
BUILD_TYPE="${1:-$DEFAULT_BUILD_TYPE}"
LABEL="${2:-$DEFAULT_LABEL}"

case "${BUILD_TYPE}" in
    debug|release)
        ;;
    *)
        echo "[ERROR] Unknown build type: ${BUILD_TYPE}"
        echo "Usage: $0 [debug|release] [label]"
        exit 1
        ;;
esac

BUILD_DIR="${BUILD_ROOT}/${PRESET_PREFIX}-${BUILD_TYPE}"

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
