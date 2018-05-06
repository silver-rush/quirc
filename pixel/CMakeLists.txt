cmake_minimum_required(VERSION 3.5)

project(Test C)

include_directories(".")
include_directories("../lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
add_definitions(-std=c99 -g -O0 -Wall -lm)

add_executable(Test test.c ../lib/decode.c ../lib/identify.c ../lib/quirc.c ../lib/version_db.c)
target_link_libraries(Test m)
