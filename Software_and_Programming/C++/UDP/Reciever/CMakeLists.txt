cmake_minimum_required(VERSION 2.8.3)
project(UDP_Client_Test)
# add_compile_options(-stdlib=libstdc++)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

SET (BOOST_ROOT /Users/Emmet/Downloads/boost_1_63_0)

#FIND_PACKAGE(Boost)
find_package( Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(UDP_Client_Test recieve.cpp)
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(UDP_Client_Test ${Boost_LIBRARIES})

endif()
