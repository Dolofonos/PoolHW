cmake_minimum_required(VERSION 3.19)
project(PoolHW)

set(CMAKE_CXX_STANDARD 20)

add_executable(PoolHW main.cpp GameController.h GameController.cpp Hole.cpp Hole.h Wall.cpp Wall.h Ball.h Ball.cpp)

set(SFML_ROOT C:/SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PoolHW sfml-graphics sfml-system)
endif ()