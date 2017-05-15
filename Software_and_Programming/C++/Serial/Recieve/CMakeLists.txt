cmake_minimum_required(VERSION 2.8.3)
project(SpektrumUDP)


INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER SpektrumProtobuf.proto)
ADD_LIBRARY(protobuf ${PROTO_HEADER} ${PROTO_SRC})
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

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
add_executable(SpektrumUDP main.cpp Calibrate.cpp)

## Link your executable against the library
target_link_libraries(SpektrumUDP serial)
target_link_libraries(SpektrumUDP ${Boost_LIBRARIES})
target_link_libraries(SpektrumUDP protobuf ${PROTOBUF_LIBRARY})
