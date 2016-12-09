cmake_minimum_required (VERSION 2.8.11)

project (CopyAndMove)

set (CMAKE_CXX_COMPILER "g++-5")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories ("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/src")
add_subdirectory (src)
add_subdirectory (test)

add_executable (TestNode ${NODE_TEST_CURRENT})
