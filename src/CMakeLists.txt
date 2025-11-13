cmake_minimum_required(VERSION 4.0)
project(lab10 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")

add_executable(nagyhazi main.c
        debugmalloc.h)
