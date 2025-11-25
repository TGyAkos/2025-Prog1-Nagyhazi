cmake_minimum_required(VERSION 4.0)
project(morze C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")

add_executable(morze main.c
        debugmalloc.h
        morse.c
        morse.h
        file_handling.c
        file_handling.h
        tests.c
        tests.h)
