#pragma once
#include <string>
#include <opencv2/opencv.hpp>

namespace moduleA {

class ImageLoader {
public:
    static cv::Mat loadImage(const std::string& path);
};

}  // namespace moduleA
