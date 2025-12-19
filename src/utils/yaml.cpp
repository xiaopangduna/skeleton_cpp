#include "skeleton_cpp/utils/yaml.hpp"

namespace utils_yaml
{

    cv::Mat loadMatrixFromYAML(const YAML::Node &node, const std::string &type)
    {
        // 检查必需的字段
        if (!node.IsMap() || !node["rows"] || !node["cols"] || !node["data"])
        {
            return cv::Mat();
        }

        int rows = node["rows"].as<int>();
        int cols = node["cols"].as<int>();

        cv::Mat matrix;
        const YAML::Node &data = node["data"];

        if (type == "double")
        {
            matrix = cv::Mat::zeros(rows, cols, CV_64F);
            if (data.IsSequence() && static_cast<int>(data.size()) == rows * cols)
            {
                for (int i = 0; i < rows * cols; ++i)
                {
                    matrix.at<double>(i / cols, i % cols) = data[i].as<double>();
                }
            }
        }
        else if (type == "int")
        {
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

} // namespace utils
