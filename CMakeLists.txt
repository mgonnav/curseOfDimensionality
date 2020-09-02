project("Course of Dimensionality")

cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories($(CMAKE_CURRENT_SOURCE_DIR)/src) 

add_executable(curse_dimensionality src/main.cc)
