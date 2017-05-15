cmake_minimum_required(VERSION 2.8.9)
project (string_to_int)

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES string_to_int.c)

add_executable(string_to_int ${SOURCES})
