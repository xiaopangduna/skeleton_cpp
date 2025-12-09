#include <iostream>
#include <opencv2/opencv.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main(int argc, char* argv[]) {
    // 初始化spdlog日志系统
    try {
        // 创建控制台日志记录器
        auto console = spdlog::stdout_color_mt("console");
        // 创建文件日志记录器
        auto file_logger = spdlog::basic_logger_mt("file_logger", "/workspaces/skeleton_cpp/tmp/app.log");
        
        // 设置日志级别
        spdlog::set_level(spdlog::level::debug);
        // 设置日志格式
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] %v");
        
        // 记录启动日志
        console->info("应用程序启动");
        file_logger->info("应用程序启动");
    } catch (const spdlog::spdlog_ex &ex) {
        std::cerr << "日志初始化失败: " << ex.what() << std::endl;
        return -1;
    }

    spdlog::get("console")->info("OpenCV version: {}", CV_VERSION);
    spdlog::get("file_logger")->info("OpenCV version: {}", CV_VERSION);
    
    // 图像路径
    std::string imagePath = "/workspaces/skeleton_cpp/tmp/BDD100k_00001.jpg";
    
    // 记录尝试读取图像的日志
    spdlog::get("console")->debug("尝试读取图像: {}", imagePath);
    spdlog::get("file_logger")->debug("尝试读取图像: {}", imagePath);
    
    // 读取图像
    cv::Mat image = cv::imread(imagePath);
    
    // 检查图像是否成功加载
    if (image.empty()) {
        spdlog::get("console")->error("无法读取图像 {}", imagePath);
        spdlog::get("file_logger")->error("无法读取图像 {}", imagePath);
        return -1;
    }
    
    spdlog::get("console")->info("成功读取图像: {}", imagePath);
    spdlog::get("file_logger")->info("成功读取图像: {}", imagePath);
    spdlog::get("console")->info("图像尺寸: {}x{}", image.cols, image.rows);
    spdlog::get("file_logger")->info("图像尺寸: {}x{}", image.cols, image.rows);
    spdlog::get("console")->info("通道数: {}", image.channels());
    spdlog::get("file_logger")->info("通道数: {}", image.channels());
    
    // 对图像进行一些处理 - 调整亮度和对比度
    cv::Mat processedImage;
    image.convertTo(processedImage, -1, 1.2, 30); // alpha=1.2(对比度), beta=30(亮度)
    
    // 保存处理后的图像
    std::string outputPath = "/workspaces/skeleton_cpp/tmp/processed_image.jpg";
    
    spdlog::get("console")->debug("尝试保存处理后的图像到: {}", outputPath);
    spdlog::get("file_logger")->debug("尝试保存处理后的图像到: {}", outputPath);
    
    bool saved = cv::imwrite(outputPath, processedImage);
    
    if (saved) {
        spdlog::get("console")->info("处理后的图像已保存到: {}", outputPath);
        spdlog::get("file_logger")->info("处理后的图像已保存到: {}", outputPath);
    } else {
        spdlog::get("console")->error("无法保存图像到 {}", outputPath);
        spdlog::get("file_logger")->error("无法保存图像到 {}", outputPath);
        return -1;
    }
    
    // 记录程序结束日志
    spdlog::get("console")->info("应用程序正常结束");
    spdlog::get("file_logger")->info("应用程序正常结束");

    return 0;
}