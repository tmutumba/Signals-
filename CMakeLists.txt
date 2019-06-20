cmake_minimum_required(VERSION 3.14)
project(signals C)

set(CMAKE_C_STANDARD 99)

add_executable(signals main.c child.c)