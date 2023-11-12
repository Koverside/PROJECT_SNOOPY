cmake_minimum_required(VERSION 3.26)
project(PROJECT_SNOOPY C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJECT_SNOOPY main.c
        snoopy.h
        snoopy.c)
