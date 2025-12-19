#include <filesystem>
#include <tuple>

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <yaml-cpp/yaml.h>

#include "utils_tests/environment.hpp"
#include "skeleton_cpp/utils/yaml.hpp"

namespace fs = std::filesystem;

using namespace utils_yaml;

class UtilsYamlTest : public ::testing::Test
{
protected:
    static fs::path path_yaml;
    static YAML::Node test_data;

    static void SetUpTestSuite()
    {
        test_data = YAML::LoadFile(path_yaml);
    }

    static void TearDownTestSuite()
    {
    }
};

fs::path UtilsYamlTest::path_yaml = "examples/utils/test_yaml.yaml";
YAML::Node UtilsYamlTest::test_data;

TEST_F(UtilsYamlTest, LoadMatrixDouble)
{
    cv::Mat matrix = loadMatrixFromYAML(UtilsYamlTest::test_data["matrix_double"], "double");

    ASSERT_EQ(matrix.rows, 2);
    ASSERT_EQ(matrix.cols, 3);
    ASSERT_EQ(matrix.type(), CV_64F);

    EXPECT_DOUBLE_EQ(matrix.at<double>(0, 0), 1.1);
    EXPECT_DOUBLE_EQ(matrix.at<double>(0, 1), 2.2);
    EXPECT_DOUBLE_EQ(matrix.at<double>(0, 2), 3.3);
    EXPECT_DOUBLE_EQ(matrix.at<double>(1, 0), 4.4);
    EXPECT_DOUBLE_EQ(matrix.at<double>(1, 1), 5.5);
    EXPECT_DOUBLE_EQ(matrix.at<double>(1, 2), 6.6);
}

TEST_F(UtilsYamlTest, LoadMatrixInt)
{
    cv::Mat matrix = loadMatrixFromYAML(UtilsYamlTest::test_data["matrix_int"], "int");

    ASSERT_EQ(matrix.rows, 2);
    ASSERT_EQ(matrix.cols, 2);
    ASSERT_EQ(matrix.type(), CV_32S);

    EXPECT_EQ(matrix.at<int>(0, 0), 1);
    EXPECT_EQ(matrix.at<int>(0, 1), 2);
    EXPECT_EQ(matrix.at<int>(1, 0), 3);
    EXPECT_EQ(matrix.at<int>(1, 1), 4);
}

TEST_F(UtilsYamlTest, LoadVectorPoint2f)
{
    std::vector<cv::Point2f> points = loadVectorPoint2NFromYAML<cv::Point2f>(UtilsYamlTest::test_data["points_2d_float"]);

    ASSERT_EQ(points.size(), 3);

    EXPECT_FLOAT_EQ(points[0].x, 1.1f);
    EXPECT_FLOAT_EQ(points[0].y, 2.2f);
    EXPECT_FLOAT_EQ(points[1].x, 3.3f);
    EXPECT_FLOAT_EQ(points[1].y, 4.4f);
    EXPECT_FLOAT_EQ(points[2].x, 5.5f);
    EXPECT_FLOAT_EQ(points[2].y, 6.6f);
}

TEST_F(UtilsYamlTest, LoadVectorPoint2i)
{
    std::vector<cv::Point2i> points = loadVectorPoint2NFromYAML<cv::Point2i>(UtilsYamlTest::test_data["points_2d_int"]);

    ASSERT_EQ(points.size(), 3);

    EXPECT_EQ(points[0].x, 1);
    EXPECT_EQ(points[0].y, 2);
    EXPECT_EQ(points[1].x, 3);
    EXPECT_EQ(points[1].y, 4);
    EXPECT_EQ(points[2].x, 5);
    EXPECT_EQ(points[2].y, 6);
}

TEST_F(UtilsYamlTest, LoadVectorPoint3d)
{
    std::vector<cv::Point3d> points = loadVectorPoint3NFromYAML<cv::Point3d>(UtilsYamlTest::test_data["points_3d_double"]);

    ASSERT_EQ(points.size(), 3);

    EXPECT_DOUBLE_EQ(points[0].x, 1.1);
    EXPECT_DOUBLE_EQ(points[0].y, 2.2);
    EXPECT_DOUBLE_EQ(points[0].z, 3.3);
    EXPECT_DOUBLE_EQ(points[1].x, 4.4);
    EXPECT_DOUBLE_EQ(points[1].y, 5.5);
    EXPECT_DOUBLE_EQ(points[1].z, 6.6);
    EXPECT_DOUBLE_EQ(points[2].x, 7.7);
    EXPECT_DOUBLE_EQ(points[2].y, 8.8);
    EXPECT_DOUBLE_EQ(points[2].z, 9.9);
}

TEST_F(UtilsYamlTest, LoadVectorPoint3i)
{
    std::vector<cv::Point3i> points = loadVectorPoint3NFromYAML<cv::Point3i>(UtilsYamlTest::test_data["points_3d_int"]);

    ASSERT_EQ(points.size(), 3);

    EXPECT_EQ(points[0].x, 1);
    EXPECT_EQ(points[0].y, 2);
    EXPECT_EQ(points[0].z, 3);
    EXPECT_EQ(points[1].x, 4);
    EXPECT_EQ(points[1].y, 5);
    EXPECT_EQ(points[1].z, 6);
    EXPECT_EQ(points[2].x, 7);
    EXPECT_EQ(points[2].y, 8);
    EXPECT_EQ(points[2].z, 9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}