cmake_minimum_required(VERSION 2.8.3)
project(transmit)


INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

include_directories(serial/include/serial)
include_directories(serial/include)

find_package( Boost REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ") #-lpthread

set(serial_SRCS   serial/src/serial.cc
                  serial/include/serial/serial.h
                  serial/include/serial/v8stdint.h)

if(UNIX)
    list(APPEND serial_SRCS serial/src/impl/unix.cc)
else()
    list(APPEND serial_SRCS serial/src/impl/win.cc)
endif()

## Add serial library
add_library(serial ${serial_SRCS})
if(UNIX AND NOT APPLE)
    target_link_libraries(serial rt)
endif()

## Build your executable
add_executable(transmit transmit.cpp)

## Link your executable against the library
target_link_libraries(transmit serial)
