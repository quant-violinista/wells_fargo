cmake_minimum_required(VERSION 3.17)
project(wells_fargo)

set(CMAKE_CXX_STANDARD 14)

add_executable(wells_fargo main.cpp utils/TimeSeries.h utils/TimeSeries.cpp)