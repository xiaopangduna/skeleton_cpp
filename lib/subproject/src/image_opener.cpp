#include "subproject/image_opener.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

namespace subproject1 {

bool open_and_show_image(const std::string& image_path) {
    cv::Mat img = cv::imread(image_path);
    if (img.empty()) {
        std::cerr << "Failed to open image: " << image_path << std::endl;
        return false;
    }
    cv::imshow("Image", img);
    cv::waitKey(0);
    return true;
}

}
