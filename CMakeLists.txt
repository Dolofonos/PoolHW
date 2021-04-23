cmake_minimum_required(VERSION 3.19)
project(Pool)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pool main.cpp GameController.cpp GameController.h GameObject.cpp GameObject.h Ball.cpp Ball.h)