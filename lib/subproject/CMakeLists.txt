cmake_minimum_required(VERSION 3.10)

project(subproject)

find_package(OpenCV REQUIRED)

add_library(subproject_lib
    src/image_opener.cpp
)

target_include_directories(subproject_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(subproject_lib PUBLIC
    ${OpenCV_LIBS}
)
