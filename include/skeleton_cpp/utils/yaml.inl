#pragma once

/**
 * @file yaml.inl
 * @brief YAML处理工具函数实现
 * @details 提供从YAML节点加载矩阵和点云数据的工具函数实现
 */

namespace utils_yaml
{

    template <typename Point2T>
    std::vector<Point2T> loadVectorCVPoint2NFromYAML(const YAML::Node &node)
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

    template <typename Point3T>
    std::vector<Point3T> loadVectorCVPoint3NFromYAML(const YAML::Node &node)
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