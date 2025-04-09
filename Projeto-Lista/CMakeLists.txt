cmake_minimum_required(VERSION 3.30)
project(ArrayList C)

set(CMAKE_C_STANDARD 11)

add_executable(ArrayList main.c
        ArrayList.h
        ArrayList.c)
