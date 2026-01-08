#pragma once

/**
 * @file yaml.inl
 * @brief YAML处理工具函数实现
 * @details 提供从YAML节点加载矩阵和点云数据的工具函数实现
 */


namespace utils_yaml
{

    /// @brief 从YAML节点加载二维矩阵数据的模板实现
    /// @tparam T 矩阵元素类型，支持double, int, float等基本类型
    /// @param node 包含矩阵信息的YAML节点，应包含rows, cols, data字段
    /// @return 加载成功的cv::Mat对象
    /// @throws std::runtime_error 当YAML节点格式不正确或数据不匹配时抛出异常
    template <typename T>
    cv::Mat loadMatrix2NFromYAML(const YAML::Node &node)
    {
        static_assert(
            std::is_same_v<T, double> ||
            std::is_same_v<T, float> ||
            std::is_same_v<T, int>,
            "T must be double, float, or int");

        // 检查必需的字段
        if (!node.IsMap() || !node["rows"] || !node["cols"] || !node["data"])
        {
            return cv::Mat();
        }

        int rows = node["rows"].as<int>();
        int cols = node["cols"].as<int>();

        cv::Mat matrix;
        const YAML::Node &data = node["data"];
        
        // 根据模板类型确定OpenCV矩阵类型
        if constexpr (std::is_same_v<T, double>) {
            matrix = cv::Mat::zeros(rows, cols, CV_64F);
            
            if (data.IsSequence() && static_cast<int>(data.size()) == rows * cols)
            {
                for (int i = 0; i < rows * cols; ++i)
                {
                    matrix.at<double>(i / cols, i % cols) = data[i].as<double>();
                }
            }
        }
        else if constexpr (std::is_same_v<T, float>) {
            matrix = cv::Mat::zeros(rows, cols, CV_32F);
            
            if (data.IsSequence() && static_cast<int>(data.size()) == rows * cols)
            {
                for (int i = 0; i < rows * cols; ++i)
                {
                    matrix.at<float>(i / cols, i % cols) = data[i].as<float>();
                }
            }
        }
        else if constexpr (std::is_same_v<T, int>) {
            matrix = cv::Mat::zeros(rows, cols, CV_32S);
            
            if (data.IsSequence() && static_cast<int>(data.size()) == rows * cols)
            {
                for (int i = 0; i < rows * cols; ++i)
                {
                    matrix.at<int>(i / cols, i % cols) = data[i].as<int>();
                }
            }
        }

        return matrix;
    }

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