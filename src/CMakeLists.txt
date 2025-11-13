cmake_minimum_required(VERSION 4.0)
project(nagyhazi C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")

add_executable(nagyhazi main.c
        debugmalloc.h
        morse.c
        morse.h
        file_handling.c
        file_handling.h)
