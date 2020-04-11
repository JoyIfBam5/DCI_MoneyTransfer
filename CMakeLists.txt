cmake_minimum_required(VERSION 3.17)

project(DCIMoneyTransfer C CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-O3 -g -Wall -std=c++14 -fexceptions")
  set(CMAKE_LINK_FLAGS "-pthreads")
endif()

if(WIN32)
  add_definitions(-D_WIN32_WINNT=0x0601)
endif(WIN32)

include_directories(include)

add_subdirectory(src)

