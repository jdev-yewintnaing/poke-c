cmake_minimum_required(VERSION 3.31)
project(poke_c C)

set(CMAKE_C_STANDARD 17)
include_directories(src)
file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(poke ${SOURCES}
        src/util/split.h
        src/util/split.c
        src/format/format.h
        src/format/format.c
        src/core/normalize.c
        src/core/normalize.h)
