cmake_minimum_required(VERSION 3.25)
project(CrackMes C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(one_keygen one_generator.c
        one.h)
add_executable(one one.c
        one.h)
add_executable(two two.c)