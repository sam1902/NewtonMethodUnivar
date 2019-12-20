cmake_minimum_required(VERSION 3.13)
project(NewtonUnivar C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS “${CMAKE_CXX_FLAGS} -lm”)

add_executable(NewtonUnivar main.c RootList.h RootList.c Function.c Function.h FunctionsInit.c FunctionsInit.h)