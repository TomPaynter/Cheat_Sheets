#As taken from the Awesome Lad: shaochuan at:
# https://github.com/shaochuan/cmake-protobuf-example
PROJECT(protobuf_example)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")


INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER partbook.proto)
ADD_LIBRARY(proto ${PROTO_HEADER} ${PROTO_SRC})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main proto ${PROTOBUF_LIBRARY})
