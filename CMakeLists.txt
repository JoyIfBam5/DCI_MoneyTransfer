cmake_minimum_required(VERSION 3.17)

project(DCIMoneyTransfer C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-O3 -g -Wall -fexceptions")
  set(CMAKE_LINK_FLAGS "-pthreads")
endif()

if(WIN32)
  add_definitions(-D_WIN32_WINNT=0x0601)
endif(WIN32)

include_directories(include)

add_subdirectory(src)

