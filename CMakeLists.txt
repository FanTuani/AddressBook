cmake_minimum_required(VERSION 3.24)
project(AddressBook C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_COMPILER gcc)

add_executable(AddressBook sources/main.c
        headers/displays.h
        sources/displays.c
        sources/operations.c
        headers/operations.h
        headers/utils.h
        sources/utils.c
        sources/student.c
        headers/student.h)
