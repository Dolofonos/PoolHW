cmake_minimum_required(VERSION 3.19)
project(Pool)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Pool main.cpp GameController.cpp GameController.h Ball.cpp Ball.h Wall.cpp Wall.h Hole.cpp Hole.h)

target_link_libraries(Pool sfml-graphics sfml-audio)