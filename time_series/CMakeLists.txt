cmake_minimum_required(VERSION 3.17)
project(time_series)

set(CMAKE_CXX_STANDARD 14)

add_executable(time_series main.cpp TimeSeries.h TimeSeries.cpp)