# skeleton_cpp

skeleton_cpp 是一个C++项目模板，使用CMake作为构建工具，支持多架构和多构建类型。

## 项目结构

```
.
├── apps           - 应用程序入口
├── cmake          - CMake模块和工具链文件
├── examples       - 示例代码
├── include        - 头文件目录
├── scripts        - 构建和测试脚本
├── src            - 源代码目录
├── tests          - 测试代码
└── third_party    - 第三方依赖库
```

## 构建系统

本项目使用CMakePresets.json预设配置，支持以下构建类型：

- `x86_64-debug`: x86_64架构调试版本
- `aarch64-release`: aarch64架构发布版本

### 使用构建脚本

项目提供了便捷的构建脚本：

```bash
# 使用默认预设 (x86_64-debug)
bash scripts/build.sh

# 指定预设
bash scripts/build.sh x86_64-debug
bash scripts/build.sh aarch64-release
```

### 

## 第三方库

项目通过第三方库构建脚本管理依赖，位于 `scripts/third_party_builders/` 目录。

## 测试

项目使用gtest作为测试框架，测试代码位于 `tests/` 目录。

运行测试：

```bash
bash scripts/test.sh
```

## CMakePresets.json 说明

CMakePresets.json提供了标准化的构建配置，确保构建行为的一致性。详细配置如下：

- `x86_64-debug`: 
  - 生成Debug版本
  - 使用x86_64-toolchain.cmake工具链
  - 二进制文件输出到build/x86_64-debug

- `aarch64-release`:
  - 生成Release版本
  - 使用aarch64-toolchain.cmake工具链
  - 二进制文件输出到build/aarch64-release