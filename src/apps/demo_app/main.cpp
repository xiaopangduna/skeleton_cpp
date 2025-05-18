// #include <iostream>
// #include "subproject/image_opener.hpp"

// int main(int argc, char** argv) {
//     if (argc < 2) {
//         std::cout << "Usage: app1 <image_path>" << std::endl;
//         return 1;
//     }

//     const std::string image_path = argv[1];

//     if (!subproject1::open_and_show_image(image_path)) {
//         std::cerr << "Open image failed." << std::endl;
//         return 1;
//     }

//     return 0;
// }

#include "moduleA/image_loader.hpp"
#include <opencv2/highgui.hpp>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./app1 <image_path>" << std::endl;
        return -1;
    }

    cv::Mat img = moduleA::ImageLoader::loadImage(argv[1]);
    if (!img.empty()) {
        cv::imshow("Loaded Image", img);
        cv::waitKey(0);
    }

    return 0;
}
