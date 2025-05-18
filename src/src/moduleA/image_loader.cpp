#include "moduleA/image_loader.hpp"
#include <opencv2/imgcodecs.hpp>
#include <iostream>

namespace moduleA {

cv::Mat ImageLoader::loadImage(const std::string& path) {
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        std::cerr << "Failed to load image: " << path << std::endl;
    }
    return img;
}

}  // namespace moduleA
