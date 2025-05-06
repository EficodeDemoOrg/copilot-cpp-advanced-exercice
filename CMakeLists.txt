cmake_minimum_required(VERSION 3.10)
project(CarSimulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(CarSimulation src/main.cpp src/Road.cpp src/Vehicle.cpp)