cmake_minimum_required(VERSION 2.8)

project(deiio CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS
  "-g -Wall -Wextra -Werror -Wconversion -Wold-style-cast -Wpointer-arith -Wshadow -Wno-unused-parameter -Wwrite-strings -rdynamic"
  )

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(deiio/base)
add_subdirectory(deiio/net)
