#pragma once

#include <vector>
#include <string>

#include <type_traits>
#include <stdexcept>

#include <opencv2/opencv.hpp>
#include <yaml-cpp/yaml.h>

namespace utils_yaml
{

    /**
     * @brief 从YAML节点加载矩阵数据
     * @param node 包含矩阵信息的YAML节点，应包含rows, cols, data字段
     * @param type 数据类型，支持"double"和"int"
     * @return 加载成功的cv::Mat对象
     */
    cv::Mat loadMatrixFromYAML(const YAML::Node &node, const std::string &type = "double");

    /// @brief 加载 2D 点列表，支持 cv::Point2f, cv::Point2d, cv::Point2i
    template <typename Point2T>
    std::vector<Point2T> loadVectorPoint2NFromYAML(const YAML::Node &node)
    {
        // 编译期检查：确保是 2D 点
        static_assert(
            std::is_same_v<Point2T, cv::Point2f> ||
                std::is_same_v<Point2T, cv::Point2d> ||
                std::is_same_v<Point2T, cv::Point2i>,
            "Point2T must be cv::Point2f, cv::Point2d, or cv::Point2i");

        if (!node.IsDefined() || !node.IsSequence())
        {
            throw std::runtime_error("YAML node is not a valid sequence.");
        }

        using T = typename Point2T::value_type;
        std::vector<Point2T> points;
        points.reserve(node.size());

        for (const auto &pt : node)
        {
            if (!pt.IsSequence() || pt.size() != 2)
            {
                throw std::runtime_error("Each 2D point must be [x, y].");
            }
            T x = pt[0].as<T>();
            T y = pt[1].as<T>();
            points.emplace_back(x, y);
        }
        return points;
    }

    /// @brief 加载 3D 点列表，支持 cv::Point3f, cv::Point3d, cv::Point3i
    template <typename Point3T>
    std::vector<Point3T> loadVectorPoint3NFromYAML(const YAML::Node &node)
    {
        static_assert(
            std::is_same_v<Point3T, cv::Point3f> ||
                std::is_same_v<Point3T, cv::Point3d> ||
                std::is_same_v<Point3T, cv::Point3i>,
            "Point3T must be cv::Point3f, cv::Point3d, or cv::Point3i");

        if (!node.IsDefined() || !node.IsSequence())
        {
            throw std::runtime_error("YAML node is not a valid sequence.");
        }

        using T = typename Point3T::value_type;
        std::vector<Point3T> points;
        points.reserve(node.size());

        for (const auto &pt : node)
        {
            if (!pt.IsSequence() || pt.size() != 3)
            {
                throw std::runtime_error("Each 3D point must be [x, y, z].");
            }
            T x = pt[0].as<T>();
            T y = pt[1].as<T>();
            T z = pt[2].as<T>();
            points.emplace_back(x, y, z);
        }
        return points;
    }
}
