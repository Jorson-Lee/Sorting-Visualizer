cmake_minimum_required(VERSION 3.10)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(SortingVisualizer src/main.cpp)
target_link_libraries(SortingVisualizer sfml-graphics sfml-window sfml-system)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)