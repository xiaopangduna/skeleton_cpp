cmake_minimum_required(VERSION 3.10)
project(demo_app)

add_executable(demo_app main.cpp)

target_link_libraries(demo_app PRIVATE subproject_lib moduleA)
