
cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug) # Debug, Release, RelWithDebInfo

project(soc-model)
enable_testing()

include_directories(src/)

add_subdirectory(src/csp)
