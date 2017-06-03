cmake_minimum_required(VERSION 2.8.3)
project(JSON_Test)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ") #-lpthread

set(SRCS  main.cpp json.hh)

## Build your executable
add_executable(JSON_Test ${SRCS})
