cmake_minimum_required(VERSION 2.8)

project(deiio CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS
  "-g -Wall -Wextra -Werror -Wconversion -Wold-style-cast -Wpointer-arith -Wshadow -Wno-unused-parameter -Wwrite-strings -rdynamic"
  )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(deiio/base)
add_subdirectory(deiio/net)

