
# Cycle-based Simulation Platform

cmake_minimum_required(VERSION 3.30)

project(sim-csp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS -Wall)

set(CSP_SRC_ROOT CMAKE_CURRENT_SOURCE_DIR)
include_directories(.)

add_library(sim-csp
  plat/Arguments.cc plat/Logger.cc plat/Platform.cc
  sim/Module.cc sim/Scheduler.cc)

add_subdirectory(test)
