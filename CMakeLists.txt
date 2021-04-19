cmake_minimum_required(VERSION 3.17)
project(StegaReader)

set(CMAKE_CXX_STANDARD 17)

add_executable(StegaReader src/main.cpp src/third_party/bitmap_image.hpp)