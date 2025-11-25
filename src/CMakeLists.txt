cmake_minimum_required(VERSION 4.0)
project(morze C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")

option(ENABLE_TESTS "Enable test suite" ON)
option(DEBUG_MALLOC "Enable debugmalloc" ON)

set(SOURCE_FILES
        main.c
        debugmalloc.h
        morse.c
        morse.h
        file_handling.c
        file_handling.h
        split_str.c
        split_str.h
)

if (ENABLE_TESTS)
    list(APPEND SOURCE_FILES tests.c tests.h)
    add_compile_definitions(ENABLE_TESTS)
    message(STATUS "Tests enabled")
endif ()
if (DEBUG_MALLOC)
    add_compile_definitions(DEBUG_MALLOC)
    message(STATUS "Debug_malloc enabled")
endif ()

add_executable(morze ${SOURCE_FILES})
