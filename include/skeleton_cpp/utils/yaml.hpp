#pragma once

/**
 * @file yaml.hpp
 * @brief YAML处理工具函数集合
 * @details 提供从YAML节点加载矩阵和点云数据的工具函数
 */

#include <vector>
#include <string>

#include <type_traits>
#include <stdexcept>

#include <yaml-cpp/yaml.h>
#include <opencv2/opencv.hpp>

namespace utils_yaml
{

    /// @brief 从YAML节点加载二维矩阵数据
    /// @tparam T 矩阵元素类型，支持double, int, float等基本类型
    /// @param node 包含矩阵信息的YAML节点，应包含rows, cols, data字段
    /// @return 加载成功的cv::Mat对象
    /// @throws std::runtime_error 当YAML节点格式不正确或数据不匹配时抛出异常
    ///
    /// 使用示例:
    /// @code
    /// YAML::Node config = YAML::LoadFile("matrix.yaml");
    /// auto matrix_double = utils_yaml::loadMatrix2NFromYAML<double>(config["matrix_double"]);
    /// auto matrix_int = utils_yaml::loadMatrix2NFromYAML<int>(config["matrix_int"]);
    /// @endcode
    template <typename T>
    cv::Mat loadMatrix2NFromYAML(const YAML::Node &node);

    /// @brief 加载 2D 点列表，支持 cv::Point2f, cv::Point2d, cv::Point2i
    /// @tparam Point2T 点类型，必须是 cv::Point2f, cv::Point2d, 或 cv::Point2i 之一
    /// @param node YAML节点，应为序列类型，每个元素为包含[x,y]的序列
    /// @return 点向量
    /// @throws std::runtime_error 当YAML节点格式不正确时抛出异常
    ///
    /// 使用示例:
    /// @code
    /// YAML::Node config = YAML::LoadFile("points.yaml");
    /// auto points2f = utils_yaml::loadVectorPCPoint2NFromYAML<cv::Point2f>(config["points_2d"]);
    /// for (const auto& point : points2f) {
    ///     std::cout << "Point: (" << point.x << ", " << point.y << ")" << std::endl;
    /// }
    /// @endcode
    template <typename Point2T>
    std::vector<Point2T> loadVectorCVPoint2NFromYAML(const YAML::Node &node);

    /// @brief 加载 3D 点列表，支持 cv::Point3f, cv::Point3d, cv::Point3i
    /// @tparam Point3T 点类型，必须是 cv::Point3f, cv::Point3d, 或 cv::Point3i 之一
    /// @param node YAML节点，应为序列类型，每个元素为包含[x,y,z]的序列
    /// @return 点向量
    /// @throws std::runtime_error 当YAML节点格式不正确时抛出异常
    ///
    /// 使用示例:
    /// @code
    /// YAML::Node config = YAML::LoadFile("points.yaml");
    /// auto points3d = utils_yaml::loadVectorCVPoint3NFromYAML<cv::Point3d>(config["points_3d"]);
    /// for (const auto& point : points3d) {
    ///     std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
    /// }
    /// @endcode
    template <typename Point3T>
    std::vector<Point3T> loadVectorCVPoint3NFromYAML(const YAML::Node &node);
}

#include "yaml.inl"