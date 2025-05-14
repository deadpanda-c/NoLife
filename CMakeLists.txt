cmake_minimum_required(VERSION 3.22)
project(NoLife)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)
include_directories(
  include
  lib/config_loader/include
  lib/logging/include
)

add_subdirectory(
  lib/config_loader
)

add_subdirectory(
  lib/logging
)

add_executable(NoLife ${SOURCES})
target_link_libraries(NoLife sfml-graphics sfml-window sfml-system sfml-audio config_loader logging)
