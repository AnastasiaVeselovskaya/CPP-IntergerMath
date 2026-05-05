cmake_minimum_required(VERSION 3.14)
project(IntegerMath VERSION 1.0.0 LANGUAGES CXX)

add_library(integermath INTERFACE)

target_include_directories(integermath INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(integermath INTERFACE cxx_std_17)
