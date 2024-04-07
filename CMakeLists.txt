# Copyright 2024 Glen Joseph Fernandes (glenjofe@gmail.com)
# Distributed under the Boost Software License, Version 1.0.

cmake_minimum_required(VERSION 3.1)

project(pointer_in_range)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)
