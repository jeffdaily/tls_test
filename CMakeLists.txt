cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O3 -std=c++14")

add_library(inc SHARED inc.cpp)
add_executable(tls_shared tls.cpp)
target_link_libraries(tls_shared inc)

add_executable(tls_static tls.cpp inc.cpp)
