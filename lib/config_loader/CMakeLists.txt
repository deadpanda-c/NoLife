cmake_minimum_required(VERSION 3.22)
project(config_loader)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES src/*.cpp)
include_directories(include)


add_library(config_loader SHARED ${SOURCES})
