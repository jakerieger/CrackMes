cmake_minimum_required(VERSION 3.28)
project(CrackMes C)

set(CMAKE_C_STANDARD 17)

add_executable(one_gen one_generator.c
        one.inl)
add_executable(one one.c
        one.inl)